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
 *   Author       :     Martial BORNET (MB) - August 07, 2010
 *
 *   File         :     s_za_fs.c
 *
 *   @(#)  [Zen] s_za_fs.c Version 1.37 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/**
 *   \file
 */

/* Includes {{{ */

#include  <stdio.h>
#include  <stdlib.h>
#include  <errno.h>
#include  <pwd.h>             // Pour getpwent()
#include  <fcntl.h>
#include  <string.h>
#include  <libgen.h>          // Pour basename()
#include  <sys/types.h>       // Pour stat()
#include  <sys/stat.h>        // Pour stat()
#include  <unistd.h>          // Pour gethostname()
#include  <netdb.h>           // Pour gethostbyname()
#include  <arpa/inet.h>       // Pour inet_ntoa()
#include  <sys/wait.h>        // Pour wait()
#include  <execinfo.h>        // Pour backtrace()

#include  "../ar/ar_serial.h"
#include  "../ar/ar_protocol.h"
#include  "../b/b_types.h"
#include  "../n/n_magic.h"
#include  "../n/n_epub.h"
#include  "../i/i_cpub.h"
#include  "../i/i_epub.h"
#include  "../k/k_cpub.h"
#include  "../k/k_epub.h"
#include  "../e/e_cpub.h"
#include  "../e/e_epub.h"
#include  "../e/e_modules.h"
#include  "../m/m_cpub.h"
#include  "../h/h_cpub.h"
#include  "../h/h_epub.h"
#include  "../e/e_data_fs.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "../o/o_epub.h"
#include  "../x/x_cpub.h"
#include  "../x/x_epub.h"
#include  "../ah/ah_cpub.h"
#include  "../ah/ah_epub.h"
#include  "../aw/aw_cpub.h"
#include  "../aw/aw_epub.h"
#include  "../ax/ax_cpub.h"
#include  "../ax/ax_epub.h"
#include  "../q/q_cpub.h"
#include  "../q/q_epub.h"
#include  "s_cpri.h"
#include  "s_epri.h"

/* Includes }}} */
/* __file__ {{{ */

static char                   *__file__      = __FILE__;

/* __file__ }}} */

/* main() {{{ */

/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     /* Appel de l'agent avec traitement des erreurs eventuelles
      * (violation memoire, interruption par signal, ...)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     return x_call_prgm(s_agent, argc, argv);
}

/* main() }}} */
/* s_send_infos() {{{ */

/******************************************************************************

                              S_SEND_INFOS

******************************************************************************/
int s_send_infos(char *name, struct h_entry *entry, void *ctx)
{
     struct k_ctx                       *_ref_tlv_ctx;
     struct e_data_fs                    _data_fs;

     _ref_tlv_ctx             = (struct k_ctx *) ctx;

     /* Recopie des infos
        ~~~~~~~~~~~~~~~~~ */
     _data_fs.entry           = *entry;                     // Recopie de la structure
     _data_fs.entry.name      = name;
     _data_fs.param_ID        = s_param_ID;
     _data_fs.relative_path   = name + s_param_offset;

     AH_DEBUG(1, 0, AH_DBG_G, "FULL PATHNAME     = [%s]\n", _data_fs.entry.name);
     AH_DEBUG(1, 0, AH_DBG_G, "RELATIVE PATHNAME = [%s]\n", _data_fs.relative_path);

     /* Envoi selon la specification des descripteurs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_send_infos(_ref_tlv_ctx, e_fs_infos, (char **) &_data_fs);

//   h_clean_entry(entry);

     return H_RET_OK;
}

/* s_send_infos() }}} */
/* s_agent() {{{ */

/******************************************************************************

                              S_AGENT

******************************************************************************/
int s_agent(int argc, char *argv[])
{
/*   Variables {{{ */
     char                     *_logfile,
                              *_catalog_stype;
     struct x_server           _server;
     char                      _hostname[64], *_IP_addr;
     struct hostent           *_hostent;
     struct in_addr            _addr;

     struct x_module           _module;
     b_uint32                  _type, _lg, _flags;
     int                       _retcode;
     char                      _pwd[128];
     char                     *_value;
     struct k_ctx              _tlv_ctx;
     int                       _eor;
     e_ref_desc_option         _ref_opt;
     struct i_root             _param_root;
     struct i_trek             _param_trek;
     aw_ref_param              _param;
     i_ref_node                _node;
     struct h_params           _params;

/*   Variables }}} */

     /* Initialisation pour la gestion des backtraces
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     q_init();

     /* Initialisation de la gestion des logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _logfile            = ax_path_log(AX_AGENT_LOG_FS);
     ah_create_logfile(argv[0], _logfile);

     /* Initialisation de la gestion memoire
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     r_init_mem();

     /* Initialisation du contexte de gestion des TLV
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_trace                  = K_TRACE_TL|K_TRACE_WRITE;
     k_trace                  = 0;           // Pour ovh1
     k_init_ctx(&_tlv_ctx);
     _tlv_ctx.prgname         = argv[0];
     _tlv_ctx.fd_read         = 0;           // stdin
     _tlv_ctx.fd_write        = 1;           // stdout
     _tlv_ctx.flags           = 0xABCD1234;
     _tlv_ctx.flags           = 0;
     _tlv_ctx.ref_prt_ctx     = &ah_ctx;

     /* Affichage de la version de l'agent dans les logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_line(ah_ctx.fp_log, '=', X_COL, TRUE);
     AH_CTX_PRT(0, AH_TRACE, "Debut d'execution de l'agent\n");
     AH_CTX_PRT(0, AH_TRACE, "ZA FS    : version %s du %s (serial = %d)\n", "1.37", "23/09/18", SERIAL);

     _catalog_stype                = ax_path_catalog(AX_CATALOG_STYPE);
     k_init(ah_ctx.fp_log, _catalog_stype);

     /* Affichage du repertoire courant
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (getcwd(_pwd, sizeof(_pwd)) == 0) {
          AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "getcwd error\n");
          exit(M_ERR_GETCWD);
     }
     AH_CTX_PRT(0, AH_TRACE, "Repertoire courant = [%s]\n", _pwd);

     /* Initialisation du hostname et de l'adresse IP
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (gethostname(_hostname, sizeof(_hostname)) != 0) {
          AH_CTX_PRT(0, AH_ERR, "Erreur de recuperation du hostname\n");
          exit(M_ERR_GETHOSTNAME);
     }

     if ((_hostent = gethostbyname(_hostname)) == 0) {
          AH_CTX_PRT(0, AH_ERR, "Erreur de recuperation de l'adresse IP\n");
          switch (h_errno) {
          case HOST_NOT_FOUND:
               AH_CTX_PRT(0, AH_ERR, "The specified host is unknown.\n");
               break;

          case NO_ADDRESS:
               AH_CTX_PRT(0, AH_ERR, "The requested name is valid but does not have an IP address.\n");
               break;

          case NO_RECOVERY:
               AH_CTX_PRT(0, AH_ERR, "A non-recoverable name server error occurred.\n");
               break;

          case TRY_AGAIN:
               AH_CTX_PRT(0, AH_ERR, "A temporary error occurred on an authoritative name server.  Try again later.\n");
               break;

          default:
               AH_CTX_PRT(0, AH_ERR, "h_error = %d\n", h_errno);
               break;
          }

          exit(M_ERR_GETHOSTBYNAME);
     }
     _addr.s_addr        = *(u_long *) _hostent->h_addr_list[0];
     _IP_addr            = inet_ntoa(_addr);

     _tlv_ctx.ref_prt_ctx->server  = _hostname;

     /* Envoi des informations relatives au systeme :
      * hostname, adresse IP
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _server.hostname    = _hostname;
     _server.IP          = _IP_addr;
     AH_CTX_PRT(0, AH_TRACE, "Envoi des infos relatives au server.\n");
     k_send_infos(&_tlv_ctx, x_server, (char **) &_server);


     /* Envoi des informations relatives au module :
      * nom du module, version, et date de versionnement
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _module.name             = E_LBL_FILESYS;
     _module.version          = "1.37";
     _module.date             = "23/09/18";
     _module.serial           = SERIAL;
     _module.protocol_serial  = AR_PROTOCOL_SERIAL;
     k_send_infos(&_tlv_ctx, x_module, (char **) &_module);

     /* Creation de l'arbre des descripteurs d'options
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     e_init_opts_tree(e_fs_protocol_options, &e_fs_opts_tree);

     /* Initialisation de l'arbre des parametres
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     i_init_root(&_param_root);

AH_CTX_PRT(0, AH_TRACE, "e_com_base      = %d.\n", e_com_base);

     /* Boucle de lecture des parametres en provenance du manager
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     for (_eor = FALSE; _eor == FALSE; ) {
          if ((_retcode = k_read_tlfv(&_tlv_ctx, &_type, &_lg, &_flags, (char **) &_value)) != M_RET_OK) {
               AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "read_tlfv error : retcode = %d %s\n",
                          _retcode, strerror(errno));
               exit(M_ERR_READ);
          }

          if (_type == E_EOR) {
               _eor                = TRUE;
               break;
          }

          switch (B_VAR_TYPE(_type)) {

          case E_STYPE_FS_PARAM:
               /* Allocation d'un descripteur de parametre
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               if ((_param = (aw_ref_param) R_MALLOC(sizeof(*_param))) == 0) {
                    AH_CTX_PRT(0, AH_ERR, "Erreur d'allocation memoire\n");
                    exit(M_ERR_MALLOC);
               }

               /* Initialisation du descripteur de parametre
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               aw_init_param(_param);
               _param->value       = _value;
               _value              = 0;
               _param->seqnum      = _flags;

               /* Tentative d'insertion de l'element
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               _node               = i_add_node(&_param_root, &_param->seq_node, aw_cmp_param_seq, aw_drop_param);
               if (_node) {
                    /* Donnees incoherentes en provenance du manager
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    AH_CTX_PRT(0, AH_ERR, "Donnees incoherentes en provenance du manager\n");
               }
               else {
                    /* Ajout de l'element effectue
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    AH_CTX_PRT(0, AH_TRACE, "Parametre %d = [%s]\n", _param->seqnum, _param->value);
               }
               break;

          default:
               if ((_ref_opt = e_search_opt(&e_fs_opts_tree, _type)) == 0) {
                    /* Option non trouvee
                       ~~~~~~~~~~~~~~~~~~ */
                    AH_CTX_PRT(0, AH_ERR, "TYPE = 0x%08X  LG = %u\n", _type, _lg);
               }
               else {
                    switch (B_VAR_TYPE(_ref_opt->type)) {

                    case B_STRING:
                         *_ref_opt->s             = _value;
                         _value                   = 0;
                         break;

                    case B_UINT32:
                         *_ref_opt->ref_i32       = *((b_uint32 *) _value);
                         break;

                    case B_UINT64:
                         *_ref_opt->ref_i64       = *((b_uint64 *) _value);
                         break;

                    default:
                         AH_CTX_PRT(0, AH_INTERNAL, "Erreur interne : TYPE = 0x%08X  LG = %u\n", _type, _lg);
                         exit(M_ERR_INTERNAL);
                         break;
                    }
               }
               break;
          }

          if (_value) {
               R_FREE(&_value);
               _value              = 0;
          }
     }
AH_CTX_PRT(0, AH_TRACE, "e_com_base      = %d.\n", e_com_base);

     /* Traitement de l'option 'ALL'
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_set_if_all(e_fs_infos);

     bzero(&_params, sizeof(_params));
//   _params.opts        = 0;
     _params.sums        = H_SUM_NONE;
//   _params.dev         = 0;
//   _params.level       = 0;
     _params.fct         = s_send_infos;
     _params.ctx         = (void *) &_tlv_ctx;

AH_CTX_PRT(0, AH_TRACE, "e_fs_xdev = %d.\n", e_fs_xdev);
     if (e_fs_xdev) {
          _params.opts        |= H_OPT_NO_XDEV;
     }
     if (e_fs_no_dirsize) {
          _params.opts        |= H_OPT_NO_DIRSIZE;
     }

     if (e_fs_attr) {
          _params.opts        |= H_OPT_ATTR;
     }
     if (e_fs_xxx_quick_scan) {
          AH_CTX_PRT(0, AH_TRACE, "e_fs_xxx_quick_scan = %d\n", e_fs_xxx_quick_scan);
          _params.quick_scan   = TRUE;
     }
     else {
          AH_CTX_PRT(0, AH_TRACE, "e_com_base = %d\n", e_com_base);
     }

AH_CTX_PRT(0, AH_TRACE, "LEVEL = %d.\n", e_fs_level);
     h_level             = e_fs_level;

     if (e_fs_chksum) {
          _params.sums             |= H_SUM_SUM;
     }
     if (e_fs_chksum_BSD) {
          _params.sums             |= H_SUM_BSD;
     }
     if (e_fs_chksum_MD5) {
          _params.sums             |= H_SUM_MD5;
     }
     if (e_fs_chksum_sha256) {
          _params.sums             |= H_SUM_SHA256;
     }

     /* Initialisation du descripteur de parcours des modules
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     i_reset(&_param_trek, &_param_root, I_T_SYM);

     /* Boucle de lecture des parametres et traitement des arborescences associees
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     while ((_node = i_get_next(&_param_trek))) {
          _param              = (aw_ref_param) _node->data;
          N_CHECK(_param->magic, N_MAGIC_aw_param);

          /* Initialisation de l'identifiant de parametre
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          s_param_ID          = _param->seqnum;

          /* Initialisation de l'offset pour l'acces au pathname relatif
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          s_param_offset      = strlen(_param->value) + 1;

          /* Parcours de l'arborescence du filesystem
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          h_tree(_param->value, &_params, 0);
     }

     /* End Of Data
        ~~~~~~~~~~~ */
     if ((_retcode = k_write_t0f(&_tlv_ctx, E_EOD, 0)) != M_RET_OK) {
          AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "WRITE TLV ERROR : %d\n", _retcode);
          exit(M_ERR_WRITE);
     }

     AH_CTX_PRT(0, AH_TRACE | AH_DSP_WHERE, "Fin d'execution de l'agent\n");
     ah_line(ah_ctx.fp_log, '=', X_COL, TRUE);

//r_disp_used_mem();
     return 0;
}

/* s_agent() }}} */
