/* ============================================================================
 * Copyright (C) 2009-2023, Martial Bornet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *   Author       :     Martial BORNET (MB) - April 09, 2011
 *
 *   File         :     y_funct.c
 *
 *   @(#)  [Zen] y_funct.c Version 1.9 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>
#include  <fcntl.h>

#include  "../ah/ah_cpub.h"        // Pour les traces (debug)
#include  "../ah/ah_epub.h"        // Pour les traces (debug)

#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../n/n_epub.h"
#include  "../m/m_cpub.h"
#include  "../i/i_cpub.h"
#include  "../i/i_epub.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "y_cpub.h"
#include  "y_epub.h"

/* Includes }}} */
/* __file__ {{{ */

static char                             *__file__      = __FILE__;

/* __file__ }}} */

/* y_read_catalog() {{{ */

/******************************************************************************

                              Y_READ_CATALOG

******************************************************************************/
int y_read_catalog(char *catalog, i_ref_root *ref_root_msg)
{
     int                            _fd, _retcode;
     bool                           _eof;
     struct y_tlv                   _tlv;

     /* Ouverture du catalogue en lecture
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_fd = open(catalog, O_RDONLY)) == -1) {
          fprintf(stderr, "open error\n");
          return M_ERR_OPEN;
     }

     if (*ref_root_msg == 0) {
          /* Allocation memoire d'un descripteur de racine d'arbre
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if ((*ref_root_msg = R_MALLOC(sizeof(**ref_root_msg))) == 0) {
               /* Erreur d'allocation memoire
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               fprintf(stderr, "malloc error\n");
               return M_ERR_MALLOC;
          }
     }

     /* Initialisation du descripteur d'arbre
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     i_init_root(*ref_root_msg);

     _eof                = FALSE;
     while (!_eof) {
          /* Lecture de l'en-tete TL
             ~~~~~~~~~~~~~~~~~~~~~~~ */
          if ((_retcode = read(_fd, &_tlv.TL, sizeof(_tlv.TL))) != sizeof(_tlv.TL)) {
               if (_retcode == 0) {
                    _eof           = TRUE;
                    continue;
               }
               else {
                    fprintf(stderr, "read error\n");
                    return M_ERR_READ;
               }
          }

          /* Allocation memoire pour la valeur
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if ((_tlv.V = R_MALLOC(_tlv.TL.length)) == 0) {
               fprintf(stderr, "malloc error\n");
               return M_ERR_MALLOC;
          }

          /* Lecture de la valeur
             ~~~~~~~~~~~~~~~~~~~~ */
          if ((_retcode = read(_fd, _tlv.V, _tlv.TL.length)) != _tlv.TL.length) {
               fprintf(stderr, "read error\n");
               return M_ERR_READ;
          }

          /* Ajout du message dans l'arbre
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          y_msg_add(*ref_root_msg, _tlv.TL.type, _tlv.V);
     }

     /* Fermeture du catalogue
        ~~~~~~~~~~~~~~~~~~~~~~ */
     close(_fd);

     return M_RET_OK;
}

/* y_read_catalog() }}} */
/* y_msg_add() {{{ */

/******************************************************************************

                              Y_MSG_ADD

******************************************************************************/
void y_msg_add(i_ref_root root, b_uint32 id, char *msg)
{
     y_ref_desc_msg                 _ref_msg;
     i_ref_node                     _node;

     /* Allocation memoire pour le message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_ref_msg = y_msg_alloc()) == 0) {
          fprintf(stderr, "ERREUR D'ALLOCATION MEMOIRE\n");
          exit(M_ERR_MALLOC);
     }

     /* Initialisation de la valeur
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _ref_msg->id        = id;
     _ref_msg->msg       = msg;

     /* Recherche de la valeur
        ~~~~~~~~~~~~~~~~~~~~~~ */
     if ((_node = i_search(root, &_ref_msg->node, y_msg_cmp)) == 0) {
          /* Tentative d'insertion de l'element
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          _node     = i_add_node(root, &_ref_msg->node, y_msg_cmp, y_msg_drop);
          if (_node) {
               /* Incoherence : element non trouve a la recherche
                * mais trouve a l'insertion
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               fprintf(stderr, "%s (%d) : Incoherence interne\n", __file__, __LINE__);
               exit(M_ERR_INTERNAL);
          }
          else {
               /* Ajout du noeud : OK
                  ~~~~~~~~~~~~~~~~~~~ */
//fprintf(stderr, "Insert : add node OK\n");
          }
     }
     else {
          /* Element deja dans l'arbre : incrementation du compteur
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          fprintf(stderr, "Insert : incoherence dans le catalogue : message 0x%08X deja present\n", id);
          fprintf(stderr, "Message = [%s]\n", msg);
     }
}

/* y_msg_add() }}} */
/* y_msg_alloc() {{{ */

/******************************************************************************

                              Y_MSG_ALLOC

******************************************************************************/
y_ref_desc_msg y_msg_alloc()
{
     int                            _size;
     y_ref_desc_msg                 _ref_msg;

     /* Calcul de la taille de l'element a allouer
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _size               = sizeof(struct y_desc_msg);

     /* Allocation memoire pour l'element
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _ref_msg            = (y_ref_desc_msg) R_MALLOC(_size);

     if (_ref_msg != 0) {
          /* Initialisation de la zone allouee
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          y_msg_init(_ref_msg);
     }
     else {
     }

     return _ref_msg;
}

/* y_msg_alloc() }}} */
/* y_msg_init() {{{ */

/******************************************************************************

                              Y_MSG_INIT

******************************************************************************/
void y_msg_init(y_ref_desc_msg ref_msg)
{
     /* Initialisation de la structure principale
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     N_INIT_MAGIC(ref_msg->magic, N_MAGIC_y_desc_msg);
     ref_msg->id                   = 0;
     ref_msg->msg                  = 0;

     i_init_node(&ref_msg->node);
     ref_msg->node.data            = (fpvoid) ref_msg;
}

/* y_msg_init() }}} */
/* y_msg_cmp() {{{ */

/******************************************************************************

                              Y_MSG_CMP

******************************************************************************/
word y_msg_cmp(i_ref_node e1, i_ref_node e2)
{
     y_ref_desc_msg                 _msg_1, _msg_2;
     b_uint32                       _id_1, _id_2;

     _msg_1              = (y_ref_desc_msg) e1->data;
     _msg_2              = (y_ref_desc_msg) e2->data;

     N_CHECK(_msg_1->magic, N_MAGIC_y_desc_msg);
     N_CHECK(_msg_2->magic, N_MAGIC_y_desc_msg);

     _id_1               = _msg_1->id;
     _id_2               = _msg_2->id;
//fprintf(stderr, "Y_MSG_CMP : id1:0x%08X id2:0x%08X\n", _id_1, _id_2);

     if (_id_2 < _id_1)       return I_CMP_LT;
     if (_id_2 > _id_1)       return I_CMP_GT;
     return I_CMP_EQ;
}

/* y_msg_cmp() }}} */
/* y_msg_drop() {{{ */

/*******************************************************************************

                              Y_MSG_DROP

*******************************************************************************/
void y_msg_drop(i_ref_node e1, i_ref_node e2)
{
     y_ref_desc_msg                 _msg_1, _msg_2;

     _msg_1              = (y_ref_desc_msg) e1->data;
     _msg_2              = (y_ref_desc_msg) e2->data;

     N_CHECK(_msg_1->magic, N_MAGIC_y_desc_msg);
     N_CHECK(_msg_2->magic, N_MAGIC_y_desc_msg);

//fprintf(stderr, "STR_DROP: i1 = %d   i2 = %d\n", _str_1->cpt, _str_2->cpt);
}

/* y_msg_drop() }}} */
/* y_msg_search() {{{ */

/******************************************************************************

                              Y_MSG_SEARCH

******************************************************************************/
char *y_msg_search(i_ref_root root, b_uint32 id)
{
/*   TODO: probleme liberation memoire
 *   RAJOUTER UN PARAMETRE INDIQUANT SI LE POINTEUR RETOURNE DOIT ETRE LIBERE APRES USAGE !!!
 *   Les messages des catalogues doivent etre liberes en fin de processus, alors que
 *   les messages d'erreurs "UNKNOWN MESSAGE" doivent etre liberes apres affichage,
 *   car ils sont alloues pour chaque message inconnu.
 *
 *   Envisager peut-etre de faire une recherche du message "UNKNOWN MESSAGE dans le
 *   catalogue systeme => ne pas allouer de memoire pour le message "UNKNOWN MESSAGE"
 *   a chaque fois, mais une fois pour toute.
 *   Appeler abort() des le debuts du processus si le catalogue systeme n'est pas trouve.
 */

     struct y_desc_msg              _msg, *_m;
     i_ref_node                     _node;
     char                          *_label, *_dyn_msg;

     /* Initialisation du descripteur de message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     y_msg_init(&_msg);
     _msg.id             = id;

     /* Recherche du message dans l'arbre
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (root == 0 || root->root == 0
     || (_node = i_search(root, &_msg.node, y_msg_cmp)) == 0) {
//        fprintf(stderr, "MESSAGE 0x%08X NOT FOUND !!!\n", _msg.id);
          if ((_dyn_msg = R_MALLOC(32)) == 0) {
               /* Erreur d'allocation memoire
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               fprintf(stderr, "malloc error\n");
               exit(M_ERR_MALLOC);
          }

          sprintf(_dyn_msg, "UNKNOWN MESSAGE : 0x%08X", id);
          _label              = _dyn_msg;
     }
     else {
          /* Message trouve
             ~~~~~~~~~~~~~~ */
          _m                  = (y_ref_desc_msg) _node->data;
          N_CHECK(_m->magic, N_MAGIC_y_desc_msg);

          _label              = _m->msg;
     }

     return _label;
}

/* y_msg_search() }}} */
/* y_msg_tree_free() {{{ */

/******************************************************************************

                              Y_MSG_TREE_FREE

******************************************************************************/
void y_msg_tree_free(i_ref_root root_msg)
{
     /* Parcours de l'arbre pour liberation de la memoire des elements
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     i_parcours(root_msg, y_msg_free, I_T_APRES);

     R_FREE(&root_msg);
}

/* y_msg_tree_free() }}} */
/* y_msg_free() {{{ */

/******************************************************************************

                              Y_MSG_FREE

******************************************************************************/
void y_msg_free(i_ref_node node)
{
     y_ref_desc_msg                 _ref_msg;

     _ref_msg                      = (y_ref_desc_msg) node->data;
     N_CHECK(_ref_msg->magic, N_MAGIC_y_desc_msg);

     R_FREE(&_ref_msg->msg);
     R_FREE(&_ref_msg);
}

/* y_msg_free() }}} */
/* y_msg_disp_node() {{{ */

/******************************************************************************

                              Y_MSG_DISP_NODE

******************************************************************************/
void y_msg_disp_node(i_ref_node node)
{
     y_ref_desc_msg                 _ref_msg;

     _ref_msg                      = (y_ref_desc_msg) node->data;
     N_CHECK(_ref_msg->magic, N_MAGIC_y_desc_msg);

     /* Appel de la fonction d'affichage du message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     y_msg_disp(_ref_msg);
}

/* y_msg_disp_node() }}} */
/* y_msg_disp() {{{ */

/******************************************************************************

                              Y_MSG_DISP

******************************************************************************/
void y_msg_disp(y_ref_desc_msg ref_msg)
{
     /* Affichage du contenu du message
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     printf("[0x%08X]  ==>  [%s]\n", ref_msg->id, ref_msg->msg);
}

/* y_msg_disp() }}} */
