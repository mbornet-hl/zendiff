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
 *   Author       :     Martial BORNET (MB) - February 18, 2013
 *
 *   File         :     al_za_dpkg.c
 *
 *   @(#)  [Zen] al_za_dpkg.c Version 1.11 of 23/09/17 - 
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
#include  <unistd.h>          // Pour gethostname()
#include  <netdb.h>           // Pour gethostbyname()
#include  <arpa/inet.h>       // Pour inet_ntoa()
#include  <sys/wait.h>        // Pour wait()

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
#include  "../e/e_data_dpkg.h"
#include  "../e/e_modules.h"
#include  "../m/m_cpub.h"
#include  "../o/o_epub.h"
#include  "../q/q_cpub.h"
#include  "../q/q_epub.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "../x/x_cpub.h"
#include  "../x/x_epub.h"
#include  "../y/y_cpub.h"
#include  "../y/y_epub.h"
#include  "../ah/ah_cpub.h"
#include  "../ah/ah_epub.h"
#include  "../ax/ax_cpub.h"
#include  "../ax/ax_epub.h"
#include  "al_epri.h"
/* Includes }}} */
/* __file__ {{{ */

static char                             *__file__      = __FILE__;
/* __file }}} */

/* main() {{{ */
/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     /* Appel de l'agent avec traitement des erreurs eventuelles
      * (violation memoire, interruption par signal, ...)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     return x_call_prgm(al_agent, argc, argv);
}
/* main() }}} */
/* al_agent() {{{ */

/******************************************************************************

                              AL_AGENT

******************************************************************************/
int al_agent(int argc, char *argv[])
{
/*   Variables {{{ */
     char                               *_logfile,
                                        *_catalog_stype;
     struct x_server                     _server;
     char                                _hostname[64], *_IP_addr;
     struct hostent                     *_hostent;
     struct in_addr                      _addr;

     struct x_module                     _module;
     b_uint32                            _lg;
     b_uint32                            _type;
     int                                 _retcode, _eor;
     struct k_ctx                        _tlv_ctx;
     char                               *_value;
     e_ref_desc_option                   _ref_opt;
     char                               *_dpkg_list_file = 0;

/*   Variables }}} */

     /* Initialisation de la gestion des logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _logfile            = ax_path_log(AX_AGENT_LOG_DPKG);
     ah_create_logfile(argv[0], _logfile);

     /* Initialisation du contexte de gestion des TLV
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
//   k_trace             = K_TRACE_TL|K_TRACE_WRITE;
     k_trace             = 0;
     k_init_ctx(&_tlv_ctx);
     _tlv_ctx.prgname              = argv[0];
     _tlv_ctx.fd_read              = 0;           // stdin
     _tlv_ctx.fd_write             = 1;           // stdout
     _tlv_ctx.flags                = 0xABCD1234;
     _tlv_ctx.flags                = 0;
     _tlv_ctx.ref_prt_ctx          = &ah_ctx;

     /* Affichage de la version de l'agent dans les logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_line(ah_ctx.fp_log, '=', X_COL, TRUE);
     AH_CTX_PRT(0, AH_TRACE, "Debut d'execution de l'agent\n");
     AH_CTX_PRT(0, AH_TRACE, "ZA DPKG : version %s du %s (serial = %d)\n", "1.11", "23/09/17", SERIAL);

     _catalog_stype                = ax_path_catalog(AX_CATALOG_STYPE);
     k_init(al_fp_log, _catalog_stype);


     /* Initialisation du hostname et de l'adresse IP
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     if (gethostname(_hostname, sizeof(_hostname)) != 0) {
          fprintf(al_fp_log, "Erreur de recuperation du hostname\n");
          exit(M_ERR_GETHOSTNAME);
     }

     if ((_hostent = gethostbyname(_hostname)) == 0) {
          fprintf(al_fp_log, "Erreur de recuperation de l'adresse IP\n");
          switch (h_errno) {
          case HOST_NOT_FOUND:
               fprintf(al_fp_log, "The specified host is unknown.\n");
               break;

          case NO_ADDRESS:
          //case    NO_DATA:
               fprintf(al_fp_log, "The requested name is valid but does not have an IP address.\n");
               break;

          case NO_RECOVERY:
               fprintf(al_fp_log, "A non-recoverable name server error occurred.\n");
               break;

          case TRY_AGAIN:
               fprintf(al_fp_log, "A temporary error occurred on an authoritative name server.  Try again later.\n");
               break;

          default:
               fprintf(al_fp_log, "h_error = %d\n", h_errno);
               break;
          }

          exit(M_ERR_GETHOSTBYNAME);
     }
     _addr.s_addr             = *(u_long *) _hostent->h_addr_list[0];
     _IP_addr                 = inet_ntoa(_addr);

     _tlv_ctx.ref_prt_ctx->server  = _hostname;

     /* Envoi des informations relatives au systeme :
      * hostname, adresse IP
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _server.hostname         = _hostname;
     _server.IP               = _IP_addr;
     AH_CTX_PRT(0, AH_TRACE, "Envoi des infos relatives au server.\n");
     AH_CTX_PRT(0, AH_TRACE, "&_server = %p.\n", &_server);
     k_send_infos(&_tlv_ctx, x_server, (char **) &_server);

     /* Envoi des informations relatives au module :
      * nom du module, version, et date de versionnement
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _module.name             = E_LBL_DPKG;
     _module.version          = "1.11";
     _module.date             = "23/09/17";
     _module.serial           = SERIAL;
     _module.protocol_serial  = AR_PROTOCOL_SERIAL;
     k_send_infos(&_tlv_ctx, x_module, (char **) &_module);

     /* Creation de l'arbre des descripteurs d'options
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     e_init_opts_tree(e_dpkg_protocol_options, &e_dpkg_opts_tree);

     /* Boucle de lecture des options en provenance du manager
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     for (_eor = FALSE; _eor == FALSE; ) {
          if ((_retcode = k_read_tlfv(&_tlv_ctx, &_type, &_lg, &_tlv_ctx.flags, (char **) &_value)) != M_RET_OK) {
               AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "read_tlfv error : retcode = %d %s\n",
                          _retcode, strerror(errno));
               exit(M_ERR_READ);
          }

          if (_type == E_EOR) {
               _eor                = TRUE;
               break;
          }
          if (_type == E_EOD) {
               break;
          }

          switch (_type) {

          case E_STYPE_DPKG_PARAM:
               AH_CTX_PRT(0, AH_TRACE, "Fichier specifie = [%s]\n", _value);
               _dpkg_list_file     = _value;
               break;

          default:
               if ((_ref_opt = e_search_opt(&e_dpkg_opts_tree, _type)) == 0) {
                    /* Option non trouvee
                       ~~~~~~~~~~~~~~~~~~ */
                    AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "TYPE = 0x%08X  LG = %u\n", _type, _lg);
               }
               else {
                    switch (_ref_opt->type) {

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
                         AH_CTX_PRT(0, AH_INTERNAL | AH_DSP_WHERE, "Erreur interne\n");
                         X
                         exit(M_ERR_INTERNAL);
                         break;
                    }
               }

               if (_value) {
                    R_FREE(&_value);
                    _value              = 0;
               }
          }
     }

     /* Initialisation du niveau de debug
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     al_debug       = e_dpkg_debug_agent;

     /* Traitement de l'option 'ALL'
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_set_if_all(e_dpkg_infos);

     if (_dpkg_list_file) {
          /* Lecture du fichier contenant la liste des packages
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          if ((AL_in = fopen(_dpkg_list_file, "r")) == NULL) {
               /* Erreur d'ouverture du fichier
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               Q_FATAL();
          }
     }
     else {
          /* Lecture de la liste des packages du systeme
             => lancement du processus de constitution de la liste
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          AL_in               = al_run_dpkg();

#if 0     /* XXX MISE AU POINT */
          /* Pas d'envoi de parametre ID
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          e_dpkg_filelist     = 0;
#endif
     }

     /* Lecture et traitement de la liste de packages
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     al_ctx         = &_tlv_ctx;
     al_param_ID    = 1;
     AL_parse();

     /* End Of Data
        ~~~~~~~~~~~ */
     if ((_retcode = k_write_t0f(&_tlv_ctx, E_EOD, 0)) != M_RET_OK) {
          AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "WRITE TLV ERROR : %d\n", _retcode);
          exit(M_ERR_WRITE);
     }

     AH_CTX_PRT(0, AH_TRACE, "Fin d'execution de l'agent\n");
     ah_line(al_fp_log, '=', X_COL, TRUE);

     return M_RET_OK;
}
/* al_agent() }}} */
/* al_send_infos() {{{ */

/******************************************************************************

                              AL_SEND_INFOS

******************************************************************************/
void al_send_infos(void *ctx, struct al_dpkg *dpkg)
{
     struct k_ctx                  *_ref_tlv_ctx;
     struct e_data_dpkg             _data_dpkg;

     _ref_tlv_ctx             = (struct k_ctx *) ctx;

     AH_DEBUG(al_debug, 0, AH_DBG_G, "%-35s %-40s %s\n",
              dpkg->pkgname, dpkg->version, dpkg->descr);

     /* Recopie des infos
        ~~~~~~~~~~~~~~~~~ */
     _data_dpkg.dpkg          = *dpkg;                      // Recopie de la structure
     _data_dpkg.param_ID      = al_param_ID;


     /* Envoi selon la specification des descripteurs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_send_infos(_ref_tlv_ctx, e_dpkg_infos, (char **) &_data_dpkg);
}
/* al_send_infos() }}} */
/* al_run_dpkg() {{{ */

/******************************************************************************

                              AL_RUN_DPKG

******************************************************************************/
FILE *al_run_dpkg()
{
     int                                 _i, _fd[2];
     char                               *_argp[4];

     _i             = 0;
     _argp[_i++]    = "dpkg";
     _argp[_i++]    = "-l";
     _argp[_i++]    = (char *) 0;

     if (pipe(_fd) == -1) {
          AH_CTX_PRT(0, AH_ERR, "Pipe error\n");
          exit(M_ERR_PIPE);
     }

     switch (fork()) {

     case -1:
          AH_CTX_PRT(0, AH_ERR, "Cannot fork\n");
          exit(M_ERR_FORK);
          break;

     case 0:
          /* Processus fils
             ~~~~~~~~~~~~~~ */
          close(1);
          dup(_fd[1]);
          close(_fd[1]);
          close(_fd[0]);

          execv(al_dpkg_pathname, _argp);
          AH_CTX_PRT(0, AH_ERR, "Cannot exec \"%s\"\n", al_dpkg_pathname);
          exit(M_ERR_EXEC);
          break;

     default:
          /* Processus pere
             ~~~~~~~~~~~~~~ */
          close(_fd[1]);
          close(0);
          dup(_fd[0]);
          close(_fd[0]);
          break;
     }

     return fdopen(0, "r");
}

/* al_run_dpkg() }}} */
