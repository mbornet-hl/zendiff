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
 *   Author       :     Martial BORNET (MB) - August 19, 2023
 *
 *   File         :     u_za_sccs.c
 *
 *   @(#)  [Zen] u_za_sccs.c Version 1.10 of 23/09/17 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/* Includes {{{ */
#include  <stdio.h>
#include  <stdlib.h>
#include  <pwd.h>             // Pour getpwent()
#include  <fcntl.h>
#include  <string.h>
#include  <libgen.h>          // Pour basename()
#include  <unistd.h>          // Pour gethostname()
#include  <netdb.h>           // Pour gethostbyname()
#include  <arpa/inet.h>       // Pour inet_ntoa()
#include  <errno.h>
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
#include  "../e/e_data_sccs.h"
#include  "../e/e_modules.h"
#include  "../m/m_cpub.h"
#include  "../h/h_cpub.h"
#include  "../h/h_epub.h"
#include  "../o/o_epub.h"
#include  "../r/r_cpub.h"
#include  "../r/r_epub.h"
#include  "../x/x_cpub.h"
#include  "../x/x_epub.h"
#include  "../ah/ah_cpub.h"
#include  "../ah/ah_epub.h"
#include  "../ai/ai_cpub.h"
#include  "../ai/ai_epub.h"
#include  "../aw/aw_cpub.h"
#include  "../aw/aw_epub.h"
#include  "../ax/ax_cpub.h"
#include  "../ax/ax_epub.h"
#include  "../q/q_cpub.h"
#include  "../q/q_epub.h"
#include  "u_cpri.h"
#include  "u_cpub.h"
#include  "u_epri.h"
#include  "u_epub.h"
/* Includes }}} */
/* __file__ {{{ */

static char                   *__file__      = __FILE__;
/* __file__ }}} */

#undef    X
#define   X    fprintf(stderr, "%s (%d)\n", __file__, __LINE__);

/* main() {{{ */
/******************************************************************************

                              MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     /* Appel de l'agent avec traitement des erreurs eventuelles
      * (violation memoire, interruption par signal, ...)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     return x_call_prgm(u_agent, argc, argv);
}
/* main() }}} */
/* u_init_sccs() {{{ */

/******************************************************************************

                              U_INIT_SCCS

******************************************************************************/
void u_init_sccs(struct u_sccs *sccs)
{
     bzero((void *) sccs, sizeof(*sccs));
}

/* u_init_sccs() }}} */
/* u_disp_sccs() {{{ */

/******************************************************************************

                              U_DISP_SCCS

******************************************************************************/
void u_disp_sccs(struct u_sccs *sccs)
{
     AH_CTX_PRT(0, AH_TRACE, "archive       = %s\n",   sccs->archive);
     AH_CTX_PRT(0, AH_TRACE, "last_version  = %s\n",   sccs->last_vers);
     AH_CTX_PRT(0, AH_TRACE, "author        = %s\n",   sccs->author);
     AH_CTX_PRT(0, AH_TRACE, "module type   = %s\n",   sccs->module_type);
     AH_CTX_PRT(0, AH_TRACE, "creation date = %s\n",   sccs->creation_date);
     AH_CTX_PRT(0, AH_TRACE, "creation time = %s\n",   sccs->creation_time);
     AH_CTX_PRT(0, AH_TRACE, "var Q         = %s\n",   sccs->var_Q);
     AH_CTX_PRT(0, AH_TRACE, "comment       = %s\n",   sccs->comment);
     AH_CTX_PRT(0, AH_TRACE, "size          = %llu\n", sccs->size);
     AH_CTX_PRT(0, AH_TRACE, "MD5           = %s\n",   sccs->md5);
     AH_CTX_PRT(0, AH_TRACE, "SHA256        = %s\n",   sccs->sha256);
}

/* u_disp_sccs() }}} */
/* u_free_sccs() {{{ */

/******************************************************************************

                              U_FREE_SCCS

******************************************************************************/
void u_free_sccs(struct u_sccs *sccs)
{
X
     U_COND_FREE(sccs->archive);
X
     U_COND_FREE(sccs->last_vers);
X
     U_COND_FREE(sccs->creation_date);
X
     U_COND_FREE(sccs->creation_time);
X
     U_COND_FREE(sccs->author);
X
     U_COND_FREE(sccs->md5);
X
     U_COND_FREE(sccs->sha256);
X
     U_COND_FREE(sccs->comment);
X
     U_COND_FREE(sccs->module_type);
X
     U_COND_FREE(sccs->var_Q);
X

     u_init_sccs(sccs);
X
}

/* u_free_sccs() }}} */
/* u_init_ctx() {{{ */

/******************************************************************************

                         U_INIT_CTX

******************************************************************************/
void u_init_ctx(u_ref_ctx ctx)
{
     bzero(ctx, sizeof(*ctx));

     N_INIT_MAGIC(ctx->magic, N_MAGIC_u_ctx);
}

/* u_init_ctx() }}} */
/* u_gen_prs_desc() {{{ */

/******************************************************************************

                         U_GEN_PRS_DESC

******************************************************************************/
char *u_gen_prs_desc(struct u_prs_kw_desc *u_desc_array)
{
     struct u_prs_kw_desc          *_p;
     char                           _prs_desc[512], _tmp_desc[64];

X
     _prs_desc[0]                  = 0;
     strcpy(_prs_desc, "-d");

     for (_p = u_desc_array; _p->ref_flag != 0; _p++) {
          if (*_p->ref_flag) {
               if (_p->multi_line) {
                    sprintf(_tmp_desc, "%s:%s\\n%s%s\\n",
                            _p->KW_lex,  U_KW_BEGIN_MULTI,
                            _p->KW_SCCS, U_KW_END_MULTI);
               }
               else {
                    sprintf(_tmp_desc, "%s:%s\\n", _p->KW_lex, _p->KW_SCCS);
               }
               strcat(_prs_desc, _tmp_desc);
          }
     }

X
     return strdup(_prs_desc);
}

/* u_gen_prs_desc() }}} */
/* u_gen_get_args() {{{ */

/******************************************************************************

                         U_GEN_GET_ARGS

******************************************************************************/
void u_gen_get_args(char *archive, char *version, char **argp)
{
     /* Generate an arguments array to retrieve a specific version of
      * the specified archive on stdout.
      * If version is NULL, no version is specified in the array, so the
      * last version is retrieved.
      */
     int                       _i;
     static char               _opt_vers[32];

     if (version) {
          if (strlen(version) > 20) {
               AH_CTX_PRT(0, AH_ERR, "%s() : length of version (%s) > 20 !\n",
                          __func__, version);
               Q_FATAL();
          }
          sprintf(_opt_vers, "-r%s", version);
     }

     _i                       = 0;
     argp[_i++]               = U_PATHNAME_GET;
     argp[_i++]               = "-s";
     if (version) {
          argp[_i++]               = _opt_vers;
     }
     argp[_i++]               = "-k";
     argp[_i++]               = "-p";
     argp[_i++]               = archive;
     argp[_i++]               = NULL;
}

/* u_gen_get_args() }}} */
/* u_get_delta_other_info() {{{ */

/******************************************************************************

                         U_GET_DELTA_OTHER_INFO

******************************************************************************/
void u_get_delta_other_info(char *archive_path, char *version,
                            b_uint32 sums, ai_ref_chksums ref_chksums)
{
     char                     *_argp[10], *_get_pathname;
     int                       _status, _fd[2];
     FILE                     *_pipe_r;

     _get_pathname            = U_PATHNAME_GET;

     u_gen_get_args(archive_path, version, _argp);
ah_disp_exec_args(_get_pathname, _argp);

     if (pipe(_fd) != 0) {
          fprintf(stderr, "Pipe error !\n");
          exit(M_ERR_PIPE);
     }

X
     switch (fork()) {

     case -1:
          AH_CTX_PRT(0, AH_ERR, "Cannot fork !\n");
          exit(M_ERR_FORK);
          break;

     case  0:
          /* Processus fils
             ~~~~~~~~~~~~~~ */
X
          close(1);
          dup(_fd[1]);
          close(_fd[1]);
          close(_fd[0]);

          execv(_get_pathname, _argp);
          printf("Cannot exec \"%s\"\n", _get_pathname);
          AH_CTX_PRT(0, AH_ERR, "Cannot exec \"%s\"\n", _get_pathname);
          exit(M_ERR_EXEC);
          break;

     default:
          /* Processus pere
             ~~~~~~~~~~~~~~ */
X
          close(_fd[1]);

          if ((_pipe_r = fdopen(_fd[0], "r")) == 0) {
               Q_FATAL();
          }
          break;
     }
X

     /* Compute checksums
        ~~~~~~~~~~~~~~~~~ */
     ai_checksums(_pipe_r, 0, (b_uint64) 0, sums, ref_chksums);
AH_CTX_PRT(0, AH_TRACE, "ARCHIVE [%s] MD5 = [%s] SHA256 = [%s]\n",
           archive_path, ref_chksums->MD5, ref_chksums->SHA256);
     close(_fd[0]);

#if 0
     for (_cpt = 0; (_c = getc(_pipe_r)) != EOF; _cpt++) {
AH_CTX_PRT(0, AH_TRACE, "_c = '%c'\n", _c);
     }
     AH_CTX_PRT(0, AH_TRACE, "Nombre de caracteres du delta : %ld\n", _cpt);
#endif    /* 0 */

     /* Analyse du resultat de la commande "get"
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
X
     wait(&_status);
X

     if (WIFEXITED(_status)) {
          AH_CTX_PRT(0, AH_TRACE, "Normal exit code = %d\n", WEXITSTATUS(_status));
     }
     else if (WIFSIGNALED(_status)) {
          AH_CTX_PRT(0, AH_TRACE, "Terminated by signal %d\n", WTERMSIG(_status));
          if (WCOREDUMP(_status)) {
               AH_CTX_PRT(0, AH_TRACE, "Core dumped\n");
          }
     }
}

/* u_get_delta_other_info() }}} */
/* u_get_delta_info() {{{ */

/******************************************************************************

                              U_GET_DELTA_INFO

******************************************************************************/
void u_get_delta_info(char *archive_path)
{
     char                          *_argp[10];
     int                            _i, _fd[2];
     int                            _status;
     char                          *_prs_pathname, *_opts_string;

X
     _prs_pathname                 = U_PATHNAME_PRS;
     _opts_string                  = u_prs_opt;

     _i                            = 0;
     _argp[_i++]                   = U_BASENAME_PRS;
     _argp[_i++]                   = _opts_string;
     _argp[_i++]                   = archive_path;
     _argp[_i++]                   = NULL;

     if (pipe(_fd) != 0) {
          fprintf(stderr, "Pipe error !\n");
          exit(M_ERR_PIPE);
     }

     switch (fork()) {

     case -1:
          AH_CTX_PRT(0, AH_ERR, "Cannot fork !\n");
          exit(M_ERR_FORK);
          break;

     case  0:
          /* Processus fils
             ~~~~~~~~~~~~~~ */
          close(1);
          dup(_fd[1]);
          close(_fd[1]);
          close(_fd[0]);
if (fcntl(1, F_GETFD) == -1) {
     Q_FATAL();
};

fprintf(stderr, "%s '%s' %s\n", U_BASENAME_PRS, _opts_string, archive_path);

          ah_tabprt(stderr, __FILE__, __LINE__, AH_DBG, _argp);
          execv(_prs_pathname, _argp);
          printf("Cannot exec \"%s\"\n", _prs_pathname);
          AH_CTX_PRT(0, AH_ERR, "Cannot exec \"%s\"\n", _prs_pathname);
          exit(M_ERR_EXEC);
          break;

     default:
          /* Processus pere
             ~~~~~~~~~~~~~~ */
          close(0);
          dup(_fd[0]);
          close(_fd[0]);
          close(_fd[1]);
          break;
     }

     U_restart(stdin);
// X
     U_parse();
// X

     /* Analyse du resultat de la commande "prs"
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
X
     wait(&_status);
X

     if (WIFEXITED(_status)) {
          AH_CTX_PRT(0, AH_TRACE, "Normal exit code = %d\n", WEXITSTATUS(_status));
     }
     else if (WIFSIGNALED(_status)) {
          AH_CTX_PRT(0, AH_TRACE, "Terminated by signal %d\n", WTERMSIG(_status));
          if (WCOREDUMP(_status)) {
               AH_CTX_PRT(0, AH_TRACE, "Core dumped\n");
          }
     }
X
}

/* u_get_delta_info() }}} */
/* u_send_infos() {{{ */

/******************************************************************************

                              U_SEND_INFOS

******************************************************************************/
int u_send_infos(char *archive_path, struct h_entry *entry, void *ctx)
{
     struct u_ctx                  *_ctx;
     struct k_ctx                  *_ref_tlv_ctx;
     struct e_data_sccs             _data_sccs;
     struct ai_chksums              _chksums;

X
     _ctx                          = (struct u_ctx *) ctx;
     N_CHECK(_ctx->magic, N_MAGIC_u_ctx);

     _ref_tlv_ctx                  = &_ctx->tlv_ctx;

     fprintf(stderr, "%s() : name = [%s]\n", __func__, entry->name);
     fprintf(stderr, "%s() : mode = %o\n",   __func__, entry->mode);
     fprintf(stderr, "%s() : type = %s\n",   __func__, entry->filetype);

     if ((entry->st_mode & S_IFMT) == S_IFREG) {
          if (!strncmp(entry->name, "s.", 2)) {
               fprintf(stderr, "%s() : SCCS archive = [%s]\n", __func__, entry->name);

               /* Get archive information
                  ~~~~~~~~~~~~~~~~~~~~~~~ */
               u_get_delta_info(archive_path);

               if (e_sccs_all_infos
               ||  e_sccs_size
               ||  e_sccs_md5sum
               ||  e_sccs_sha256sum) {
                    /* Get information not retrieved by "prs"
                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
                    u_get_delta_other_info(archive_path, NULL, _ctx->sums, &_chksums);
               }

               /* Copy retrieved information
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   U_COPY_INFO(dest, src)             \
               if (u_info.src == 0) {                            \
                    _data_sccs.sccs.dest          = strdup("");  \
               }                                                 \
               else {                                            \
                    _data_sccs.sccs.dest          = u_info.src;  \
               }

#define   U_SUM_INFO(dest, src)             \
               if (_chksums.src == 0) {                            \
                    _data_sccs.sccs.dest          = strdup("");    \
               }                                                   \
               else {                                              \
                    _data_sccs.sccs.dest          = _chksums.src;  \
               }

               _data_sccs.param_ID           = u_param_ID;
               _data_sccs.relative_path      = archive_path + u_param_offset;
               _data_sccs.sccs.archive       = archive_path;

               U_COPY_INFO(last_vers,     last_vers);
               U_COPY_INFO(author,        author);
               U_COPY_INFO(creation_date, creation_date);
               U_COPY_INFO(creation_time, creation_time);
               U_COPY_INFO(D_year,        D_year);
               U_COPY_INFO(D_month,       D_month);
               U_COPY_INFO(D_day,         D_day);
               U_COPY_INFO(module_type,   module_type);
               U_COPY_INFO(var_Q,         var_Q);
               U_COPY_INFO(comment,       comment);
               _data_sccs.sccs.size          = _chksums.size;
               U_SUM_INFO(md5,            MD5);
               U_SUM_INFO(sha256,         SHA256);

               /* Reset u_info members
                  ~~~~~~~~~~~~~~~~~~~~ */
               u_init_sccs(&u_info);

               AH_DEBUG(1, 0, AH_DBG_G, "PARAM ID          = [%d]\n",   _data_sccs.param_ID);
               AH_DEBUG(1, 0, AH_DBG_G, "ARCHIVE NAME      = [%s]\n",   _data_sccs.sccs.archive);
               AH_DEBUG(1, 0, AH_DBG_G, "LAST VERSION      = [%s]\n",   _data_sccs.sccs.last_vers);
               AH_DEBUG(1, 0, AH_DBG_G, "AUTHOR            = [%s]\n",   _data_sccs.sccs.author);
               AH_DEBUG(1, 0, AH_DBG_G, "CREATION DATE     = [%s]\n",   _data_sccs.sccs.creation_date);
               AH_DEBUG(1, 0, AH_DBG_G, "CREATION TIME     = [%s]\n",   _data_sccs.sccs.creation_time);
               AH_DEBUG(1, 0, AH_DBG_G, "DELTA YEAR        = [%s]\n",   _data_sccs.sccs.D_year);
               AH_DEBUG(1, 0, AH_DBG_G, "DELTA MONTH       = [%s]\n",   _data_sccs.sccs.D_month);
               AH_DEBUG(1, 0, AH_DBG_G, "DELTA DAY         = [%s]\n",   _data_sccs.sccs.D_day);
               AH_DEBUG(1, 0, AH_DBG_G, "MODULE TYPE       = [%s]\n",   _data_sccs.sccs.module_type);
               AH_DEBUG(1, 0, AH_DBG_G, "VAR Q             = [%s]\n",   _data_sccs.sccs.var_Q);
               AH_DEBUG(1, 0, AH_DBG_G, "COMMENT           = [%s]\n",   _data_sccs.sccs.comment);
               AH_DEBUG(1, 0, AH_DBG_G, "SIZE              = [%llu]\n", _data_sccs.sccs.size);
               AH_DEBUG(1, 0, AH_DBG_G, "MD5SUM            = [%s]\n",   _data_sccs.sccs.md5);
               AH_DEBUG(1, 0, AH_DBG_G, "SHA256            = [%s]\n",   _data_sccs.sccs.sha256);

               /* Envoi selon la specification des descripteurs
                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
               k_send_infos(_ref_tlv_ctx, e_sccs_infos, (char **) &_data_sccs);
          }
          else {
               fprintf(stderr, "%s() : [%s] not an archive => skipped\n", __func__, entry->name);
          }
     }
     else {
          fprintf(stderr, "%s() : [%s] not a regular file => skipped\n", __func__, entry->name);
     }

X
     return H_RET_OK;
}

/* u_send_infos() }}} */
/* u_agent() {{{ */

/******************************************************************************

                              U_AGENT

******************************************************************************/
int u_agent(int argc, char *argv[])
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
     b_uint32                            _type, _flags = 0;
     int                                 _retcode, _eor;
     char                                _pwd[128];
     struct u_ctx                        _ctx;
     char                               *_value;
     e_ref_desc_option                   _ref_opt;
     struct i_root                       _param_root;
     struct i_trek                       _param_trek;
     aw_ref_param                        _param;
     i_ref_node                          _node;
     struct h_params                     _params;

/*   Variables }}} */

     /* Initialisation pour la gestion des backtraces
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     q_init();

     /* Initialisation de la gestion des logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _logfile            = ax_path_log(AX_AGENT_LOG_SCCS);
     ah_create_logfile(argv[0], _logfile);
     u_fp_log            = ah_ctx.fp_log;

     /* Initialisation de la gestion memoire
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     r_init_mem();
     u_init_sccs(&u_info);
     u_init_ctx(&_ctx);

     /* Initialisation du contexte de gestion des TLV
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_trace             = K_TRACE_TL;
     k_init_ctx(&_ctx.tlv_ctx);
     _ctx.tlv_ctx.prgname              = argv[0];
     _ctx.tlv_ctx.fd_read              = 0;           // stdin
     _ctx.tlv_ctx.fd_write             = 1;           // stdout
     _ctx.tlv_ctx.flags                = 0xABCD1234;
     _ctx.tlv_ctx.flags                = 0;
     _ctx.tlv_ctx.ref_prt_ctx          = &ah_ctx;

     /* Affichage de la version de l'agent dans les logs
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     ah_line(ah_ctx.fp_log, '=', X_COL, TRUE);
     AH_CTX_PRT(0, AH_TRACE, "Debut d'execution de l'agent\n");
     AH_CTX_PRT(0, AH_TRACE, "ZA SCCS : version %s du %s (serial = %d)\n", "1.10", "23/09/17", SERIAL);

     _catalog_stype                = ax_path_catalog(AX_CATALOG_STYPE);
     k_init(u_fp_log, _catalog_stype);

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
          fprintf(u_fp_log, "Erreur de recuperation du hostname\n");
          exit(M_ERR_GETHOSTNAME);
     }

     if ((_hostent = gethostbyname(_hostname)) == 0) {
          fprintf(u_fp_log, "Erreur de recuperation de l'adresse IP\n");
          switch (h_errno) {
          case HOST_NOT_FOUND:
               fprintf(u_fp_log, "The specified host is unknown.\n");
               break;

          case NO_ADDRESS:
          //case    NO_DATA:
               fprintf(u_fp_log, "The requested name is valid but does not have an IP address.\n");
               break;

          case NO_RECOVERY:
               fprintf(u_fp_log, "A non-recoverable name server error occurred.\n");
               break;

          case TRY_AGAIN:
               fprintf(u_fp_log, "A temporary error occurred on an authoritative name server.  Try again later.\n");
               break;

          default:
               fprintf(u_fp_log, "h_error = %d\n", h_errno);
               break;
          }

          exit(M_ERR_GETHOSTBYNAME);
     }
     _addr.s_addr             = *(u_long *) _hostent->h_addr_list[0];
     _IP_addr                 = inet_ntoa(_addr);

     _ctx.tlv_ctx.ref_prt_ctx->server  = _hostname;

     /* Envoi des informations relatives au systeme :
      * hostname, adresse IP
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _server.hostname         = _hostname;
     _server.IP               = _IP_addr;
     AH_CTX_PRT(0, AH_TRACE, "Envoi des infos relatives au server.\n");
     AH_CTX_PRT(0, AH_TRACE, "&_server = %p.\n", &_server);
     k_send_infos(&_ctx.tlv_ctx, x_server, (char **) &_server);

     /* Envoi des informations relatives au module :
      * nom du module, version, et date de versionnement
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     _module.name             = E_LBL_SCCS;
     _module.version          = "1.10";
     _module.date             = "23/09/17";
     _module.serial           = SERIAL;
     _module.protocol_serial  = AR_PROTOCOL_SERIAL;
     k_send_infos(&_ctx.tlv_ctx, x_module, (char **) &_module);

     /* Creation de l'arbre des descripteurs d'options
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     e_init_opts_tree(e_sccs_protocol_options, &e_sccs_opts_tree);

     /* Initialisation de l'arbre des parametres
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     i_init_root(&_param_root);

     /* Boucle de lecture des options en provenance du manager
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     for (_eor = FALSE; _eor == FALSE; ) {
          if ((_retcode = k_read_tlfv(&_ctx.tlv_ctx, &_type, &_lg,
                                      &_ctx.tlv_ctx.flags, (char **) &_value)) != M_RET_OK) {
               AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "reau_tlfv error : retcode = %d %s\n",
                                                                                _retcode, strerror(errno));
               exit(M_ERR_READ);
          }

          if (_type == E_EOR) {
X
               _eor                = TRUE;
               break;
          }
          if (_type == E_EOD) {
X
               break;
          }

X

          switch (B_VAR_TYPE(_type)) {

          case E_STYPE_SCCS_PARAM:
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
               if ((_ref_opt = e_search_opt(&e_sccs_opts_tree, _type)) == 0) {
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


          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_all_infos    = 0x%08X\n", e_sccs_all_infos);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_all_elts     = 0x%08X\n", e_sccs_all_elts);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_disp_lex     = 0x%08X\n", e_sccs_disp_lex);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_disp_yacc    = 0x%08X\n", e_sccs_disp_yacc);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_xdev         = 0x%08X\n", e_sccs_xdev);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_level        = 0x%08X\n", e_sccs_level);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_size         = 0x%08X\n", e_sccs_size);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_timestamp    = 0x%08X\n", e_sccs_timestamp);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_md5sum       = 0x%08X\n", e_sccs_md5sum);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_sha256sum    = 0x%08X\n", e_sccs_sha256sum);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_archive      = 0x%08X\n", e_sccs_archive);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_last_version = 0x%08X\n", e_sccs_last_version);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_author       = 0x%08X\n", e_sccs_author);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_creat_date   = 0x%08X\n", e_sccs_creat_date);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_creat_time   = 0x%08X\n", e_sccs_creat_time);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_D_year       = 0x%08X\n", e_sccs_D_year);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_D_month      = 0x%08X\n", e_sccs_D_month);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_D_day        = 0x%08X\n", e_sccs_D_day);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_module_type  = 0x%08X\n", e_sccs_module_type);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_var_Q        = 0x%08X\n", e_sccs_var_Q);
          AH_CTX_PRT(0, AH_WARN | AH_DSP_WHERE, "e_sccs_comment      = 0x%08X\n", e_sccs_comment);
     }

     /* Initialisation des flags de trace de l'analyseur (lexical / grammatical)
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     u_disp_lex     = e_sccs_disp_lex;
     u_disp_yacc    = e_sccs_disp_yacc;

     /* Generation de la chaine d'option pour "prs"
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     u_prs_opt           = u_gen_prs_desc(u_prs_desc);
fprintf(stderr, "prs option string : [%s]\n", u_prs_opt);

AH_CTX_PRT(0, AH_TRACE, "e_com_base      = %d.\n", e_com_base);

     /* Traitement de l'option 'ALL'
        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
     k_set_if_all(e_sccs_infos);

     bzero(&_params, sizeof(_params));
     _params.sums        = H_SUM_NONE;
     _params.fct         = u_send_infos;
     _params.ctx         = (void *) &_ctx;

AH_CTX_PRT(0, AH_TRACE, "e_sccs_xdev = %d.\n", e_sccs_xdev);
     if (e_sccs_xdev) {
          _params.opts        |= H_OPT_NO_XDEV;
     }

AH_CTX_PRT(0, AH_TRACE, "e_com_base = %d\n", e_com_base);
AH_CTX_PRT(0, AH_TRACE, "LEVEL = %d.\n",     e_sccs_level);
     h_level             = e_sccs_level;

     _ctx.sums           = 0;
     if (e_sccs_md5sum)       _ctx.sums      |= AI_MD5;
     if (e_sccs_sha256sum)    _ctx.sums      |= AI_SHA256;

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
          u_param_ID          = _param->seqnum;

          /* Initialisation de l'offset pour l'acces au pathname relatif
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          u_param_offset      = strlen(_param->value) + 1;

          /* Parcours de l'arborescence du filesystem
             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
          h_tree(_param->value, &_params, 0);
     }

     /* End Of Data
        ~~~~~~~~~~~ */
     if ((_retcode = k_write_t0f(&_ctx.tlv_ctx, E_EOD, 0)) != M_RET_OK) {
          AH_CTX_PRT(0, AH_ERR | AH_DSP_WHERE, "WRITE TLV ERROR : %d\n", _retcode);
          exit(M_ERR_WRITE);
     }

     AH_CTX_PRT(0, AH_TRACE, "Fin d'execution de l'agent\n");
     ah_line(ah_ctx.fp_log, '=', X_COL, TRUE);

     return M_RET_OK;
}
/* u_agent() }}} */
