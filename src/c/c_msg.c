/* ============================================================================
 * Copyright (C) 2010-2023, Martial Bornet
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
 *   Author       :     Martial BORNET (MB) - August 31, 2010
 *
 *   File         :     c_msg.c
 *
 *   @(#)  [Zen] c_msg.c Version 1.58 of 23/09/02 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */


/**
 *	\file
 */
/* Includes {{{ */
#include	<stdio.h>
#include	<pthread.h>
#include	<mysql/mysql.h>

#include	"../b/b_types.h"
#include	"../n/n_magic.h"
#include	"../i/i_cpub.h"
#include	"../k/k_cpub.h"
#include	"../e/e_modules.h"
#include	"../e/e_cpub.h"
#include	"../ac/ac_cpub.h"
#include	"../ab/ab_cpub.h"
#include	"../ab/ab_epub.h"
#include	"../ah/ah_cpub.h"
#include	"../ah/ah_epub.h"
#include	"../l/l_cpub.h"
#include	"../y/y_cpub.h"
#include	"../aa/aa_cpub.h"
#include	"../g/g_cpub.h"
#include	"../at/at_cpub.h"
#include	"../aw/aw_cpub.h"
#include	"../aw/aw_epub.h"
#include	"c_cpri.h"
#include	"c_epri.h"
#include	"c_msg.h"
#include	"c_opts.h"
/* }}} */

/* c_tab_msg[] {{{ */
struct y_desc_msgs		 c_tab_msg[] = {
	/* C_MSG_MAIN {{{ */
	{	AA_MSG(C_MSG_MAIN_00000),		c_msg_main_00000	},
	{	AA_MSG(C_MSG_MAIN_00001),		c_msg_main_00001	},
	{	AA_MSG(C_MSG_MAIN_00002),		c_msg_main_00002	},
	{	AA_MSG(C_MSG_MAIN_00003),		c_msg_main_00003	},
	{	AA_MSG(C_MSG_MAIN_00004),		c_msg_main_00004	},
	{	AA_MSG(C_MSG_MAIN_00005),		c_msg_main_00005	},
	{	AA_MSG(C_MSG_MAIN_00006),		c_msg_main_00006	},
	{	AA_MSG(C_MSG_MAIN_00007),		c_msg_main_00007	},
	{	AA_MSG(C_MSG_MAIN_00008),		c_msg_main_00008	},
	{	AA_MSG(C_MSG_MAIN_00009),		c_msg_main_00009	},
	{	AA_MSG(C_MSG_MAIN_00010),		c_msg_main_00010	},
	{	AA_MSG(C_MSG_MAIN_00011),		c_msg_main_00011	},
	{	AA_MSG(C_MSG_MAIN_00012),		c_msg_main_00012	},
	{	AA_MSG(C_MSG_MAIN_00013),		c_msg_main_00013	},
	{	AA_MSG(C_MSG_MAIN_00014),		c_msg_main_00014	},
	{	AA_MSG(C_MSG_MAIN_00015),		c_msg_main_00015	},
	{	AA_MSG(C_MSG_MAIN_00016),		c_msg_main_00016	},
	{	AA_MSG(C_MSG_MAIN_00017),		c_msg_main_00017	},
	{	AA_MSG(C_MSG_MAIN_00018),		c_msg_main_00018	},
	{	AA_MSG(C_MSG_MAIN_00019),		c_msg_main_00019	},
	{	AA_MSG(C_MSG_MAIN_00020),		c_msg_main_00020	},
	{	AA_MSG(C_MSG_MAIN_00021),		c_msg_main_00021	},
	{	AA_MSG(C_MSG_MAIN_00022),		c_msg_main_00022	},
	{	AA_MSG(C_MSG_MAIN_00023),		c_msg_main_00023	},
	{	AA_MSG(C_MSG_MAIN_00024),		c_msg_main_00024	},
	{	AA_MSG(C_MSG_MAIN_00025),		c_msg_main_00025	},
	{	AA_MSG(C_MSG_MAIN_00026),		c_msg_main_00026	},
	{	AA_MSG(C_MSG_MAIN_00027),		c_msg_main_00027	},
	{	AA_MSG(C_MSG_MAIN_00028),		c_msg_main_00028	},
	{	AA_MSG(C_MSG_MAIN_00029),		c_msg_main_00029	},
	{	AA_MSG(C_MSG_MAIN_00030),		c_msg_main_00030	},
	{	AA_MSG(C_MSG_MAIN_00031),		c_msg_main_00031	},
	{	AA_MSG(C_MSG_MAIN_00032),		c_msg_main_00032	},
	{	AA_MSG(C_MSG_MAIN_00033),		c_msg_main_00033	},
	{	AA_MSG(C_MSG_MAIN_00034),		c_msg_main_00034	},
	{	AA_MSG(C_MSG_MAIN_00035),		c_msg_main_00035	},
	{	AA_MSG(C_MSG_MAIN_00036),		c_msg_main_00036	},
	{	AA_MSG(C_MSG_MAIN_00037),		c_msg_main_00037	},
	{	AA_MSG(C_MSG_MAIN_00038),		c_msg_main_00038	},
	{	AA_MSG(C_MSG_MAIN_00039),		c_msg_main_00039	},
	{	AA_MSG(C_MSG_MAIN_00040),		c_msg_main_00040	},
	{	AA_MSG(C_MSG_MAIN_00041),		c_msg_main_00041	},
	{	AA_MSG(C_MSG_MAIN_00042),		c_msg_main_00042	},
	{	AA_MSG(C_MSG_MAIN_00043),		c_msg_main_00043	},
	{	AA_MSG(C_MSG_MAIN_00044),		c_msg_main_00044	},
	{	AA_MSG(C_MSG_MAIN_00045),		c_msg_main_00045	},
	{	AA_MSG(C_MSG_MAIN_00046),		c_msg_main_00046	},
	{	AA_MSG(C_MSG_MAIN_00047),		c_msg_main_00047	},
	{	AA_MSG(C_MSG_MAIN_00048),		c_msg_main_00048	},
	{	AA_MSG(C_MSG_MAIN_00049),		c_msg_main_00049	},
	{	AA_MSG(C_MSG_MAIN_00050),		c_msg_main_00050	},
	{	AA_MSG(C_MSG_MAIN_00051),		c_msg_main_00051	},
	{	AA_MSG(C_MSG_MAIN_00052),		c_msg_main_00052	},
	{	AA_MSG(C_MSG_MAIN_00053),		c_msg_main_00053	},
	{	AA_MSG(C_MSG_MAIN_00054),		c_msg_main_00054	},
	{	AA_MSG(C_MSG_MAIN_00055),		c_msg_main_00055	},
	{	AA_MSG(C_MSG_MAIN_00056),		c_msg_main_00056	},
	{	AA_MSG(C_MSG_MAIN_00057),		c_msg_main_00057	},
	{	AA_MSG(C_MSG_MAIN_00058),		c_msg_main_00058	},
	{	AA_MSG(C_MSG_MAIN_00059),		c_msg_main_00059	},
	{	AA_MSG(C_MSG_MAIN_00060),		c_msg_main_00060	},
	{	AA_MSG(C_MSG_MAIN_00061),		c_msg_main_00061	},
	{	AA_MSG(C_MSG_MAIN_00062),		c_msg_main_00062	},
	{	AA_MSG(C_MSG_MAIN_00063),		c_msg_main_00063	},
	{	AA_MSG(C_MSG_MAIN_00064),		c_msg_main_00064	},
	{	AA_MSG(C_MSG_MAIN_00065),		c_msg_main_00065	},
	{	AA_MSG(C_MSG_MAIN_00066),		c_msg_main_00066	},
	{	AA_MSG(C_MSG_MAIN_00067),		c_msg_main_00067	},
	{	AA_MSG(C_MSG_MAIN_00068),		c_msg_main_00068	},
	{	AA_MSG(C_MSG_MAIN_00069),		c_msg_main_00069	},
	{	AA_MSG(C_MSG_MAIN_00070),		c_msg_main_00070	},
	{	AA_MSG(C_MSG_MAIN_00071),		c_msg_main_00071	},
	{	AA_MSG(C_MSG_MAIN_00072),		c_msg_main_00072	},
	{	AA_MSG(C_MSG_MAIN_00073),		c_msg_main_00073	},
	{	AA_MSG(C_MSG_MAIN_00074),		c_msg_main_00074	},
	{	AA_MSG(C_MSG_MAIN_00075),		c_msg_main_00075	},
	{	AA_MSG(C_MSG_MAIN_00076),		c_msg_main_00076	},
	{	AA_MSG(C_MSG_MAIN_00077),		c_msg_main_00077	},
	{	AA_MSG(C_MSG_MAIN_00078),		c_msg_main_00078	},
	{	AA_MSG(C_MSG_MAIN_00079),		c_msg_main_00079	},
	{	AA_MSG(C_MSG_MAIN_00080),		c_msg_main_00080	},
	{	AA_MSG(C_MSG_MAIN_00081),		c_msg_main_00081	},
	{	AA_MSG(C_MSG_MAIN_00082),		c_msg_main_00082	},
	{	AA_MSG(C_MSG_MAIN_00083),		c_msg_main_00083	},
	{	AA_MSG(C_MSG_MAIN_00084),		c_msg_main_00084	},
	{	AA_MSG(C_MSG_MAIN_00085),		c_msg_main_00085	},
	{	AA_MSG(C_MSG_MAIN_00086),		c_msg_main_00086	},
	{	AA_MSG(C_MSG_MAIN_00087),		c_msg_main_00087	},
	{	AA_MSG(C_MSG_MAIN_00088),		c_msg_main_00088	},
	{	AA_MSG(C_MSG_MAIN_00089),		c_msg_main_00089	},
	{	AA_MSG(C_MSG_MAIN_00090),		c_msg_main_00090	},
	{	AA_MSG(C_MSG_MAIN_00091),		c_msg_main_00091	},
	{	AA_MSG(C_MSG_MAIN_00092),		c_msg_main_00092	},
	/* }}} */
	/* C_MSG_COMMON {{{ */
	{	AA_MSG(C_MSG_COMMON_00000),		c_msg_common_00000	},
	{	AA_MSG(C_MSG_COMMON_00001),		c_msg_common_00001	},
	{	AA_MSG(C_MSG_COMMON_00002),		c_msg_common_00002	},
	{	AA_MSG(C_MSG_COMMON_00003),		c_msg_common_00003	},
	{	AA_MSG(C_MSG_COMMON_00004),		c_msg_common_00004	},
	{	AA_MSG(C_MSG_COMMON_00005),		c_msg_common_00005	},
	{	AA_MSG(C_MSG_COMMON_00006),		c_msg_common_00006	},
	{	AA_MSG(C_MSG_COMMON_00007),		c_msg_common_00007	},
	{	AA_MSG(C_MSG_COMMON_00008),		c_msg_common_00008	},
	{	AA_MSG(C_MSG_COMMON_00009),		c_msg_common_00009	},
	{	AA_MSG(C_MSG_COMMON_00010),		c_msg_common_00010	},
	{	AA_MSG(C_MSG_COMMON_00011),		c_msg_common_00011	},
	{	AA_MSG(C_MSG_COMMON_00012),		c_msg_common_00012	},
	{	AA_MSG(C_MSG_COMMON_00013),		c_msg_common_00013	},
	{	AA_MSG(C_MSG_COMMON_00014),		c_msg_common_00014	},
	{	AA_MSG(C_MSG_COMMON_00015),		c_msg_common_00015	},
	{	AA_MSG(C_MSG_COMMON_00016),		c_msg_common_00016	},
	{	AA_MSG(C_MSG_COMMON_00017),		c_msg_common_00017	},
	{	AA_MSG(C_MSG_COMMON_00018),		c_msg_common_00018	},
	{	AA_MSG(C_MSG_COMMON_00019),		c_msg_common_00019	},
	{	AA_MSG(C_MSG_COMMON_00020),		c_msg_common_00020	},
	{	AA_MSG(C_MSG_COMMON_00021),		c_msg_common_00021	},
	{	AA_MSG(C_MSG_COMMON_00022),		c_msg_common_00022	},
	{	AA_MSG(C_MSG_COMMON_00023),		c_msg_common_00023	},
	{	AA_MSG(C_MSG_COMMON_00024),		c_msg_common_00024	},
	{	AA_MSG(C_MSG_COMMON_00025),		c_msg_common_00025	},
	{	AA_MSG(C_MSG_COMMON_00026),		c_msg_common_00026	},
	{	AA_MSG(C_MSG_COMMON_00027),		c_msg_common_00027	},
	{	AA_MSG(C_MSG_COMMON_00028),		c_msg_common_00028	},
	{	AA_MSG(C_MSG_COMMON_00029),		c_msg_common_00029	},
	/* }}} */
	/* C_MSG_USER {{{ */
	{	AA_MSG(C_MSG_USER_00000),		c_msg_users_00000	},
	{	AA_MSG(C_MSG_USER_00001),		c_msg_users_00001	},
	{	AA_MSG(C_MSG_USER_00002),		c_msg_users_00002	},
	{	AA_MSG(C_MSG_USER_00003),		c_msg_users_00003	},
	{	AA_MSG(C_MSG_USER_00004),		c_msg_users_00004	},
	{	AA_MSG(C_MSG_USER_00005),		c_msg_users_00005	},
	{	AA_MSG(C_MSG_USER_00006),		c_msg_users_00006	},
	{	AA_MSG(C_MSG_USER_00007),		c_msg_users_00007	},
	{	AA_MSG(C_MSG_USER_00008),		c_msg_users_00008	},
	{	AA_MSG(C_MSG_USER_00009),		c_msg_users_00009	},
	{	AA_MSG(C_MSG_USER_00010),		c_msg_users_00010	},
	{	AA_MSG(C_MSG_USER_00011),		c_msg_users_00011	},
	{	AA_MSG(C_MSG_USER_00012),		c_msg_users_00012	},
	{	AA_MSG(C_MSG_USER_00013),		c_msg_users_00013	},
	{	AA_MSG(C_MSG_USER_00014),		c_msg_users_00014	},
	{	AA_MSG(C_MSG_USER_00015),		c_msg_users_00015	},
	{	AA_MSG(C_MSG_USER_00016),		c_msg_users_00016	},
	{	AA_MSG(C_MSG_USER_00017),		c_msg_users_00017	},
	{	AA_MSG(C_MSG_USER_00018),		c_msg_users_00018	},
	{	AA_MSG(C_MSG_USER_00019),		c_msg_users_00019	},
	{	AA_MSG(C_MSG_USER_00020),		c_msg_users_00020	},
	{	AA_MSG(C_MSG_USER_00021),		c_msg_users_00021	},
	{	AA_MSG(C_MSG_USER_00022),		c_msg_users_00022	},
	{	AA_MSG(C_MSG_USER_00023),		c_msg_users_00023	},
	{	AA_MSG(C_MSG_USER_00024),		c_msg_users_00024	},
	{	AA_MSG(C_MSG_USER_00025),		c_msg_users_00025	},
	{	AA_MSG(C_MSG_USER_00026),		c_msg_users_00026	},
	{	AA_MSG(C_MSG_USER_00027),		c_msg_users_00027	},
	{	AA_MSG(C_MSG_USER_00028),		c_msg_users_00028	},
	{	AA_MSG(C_MSG_USER_00029),		c_msg_users_00029	},
	{	AA_MSG(C_MSG_USER_00030),		c_msg_users_00030	},
	{	AA_MSG(C_MSG_USER_00031),		c_msg_users_00031	},
	{	AA_MSG(C_MSG_USER_00032),		c_msg_users_00032	},
	{	AA_MSG(C_MSG_USER_00033),		c_msg_users_00033	},
	{	AA_MSG(C_MSG_USER_00034),		c_msg_users_00034	},
	{	AA_MSG(C_MSG_USER_00035),		c_msg_users_00035	},
	{	AA_MSG(C_MSG_USER_00036),		c_msg_users_00036	},
	{	AA_MSG(C_MSG_USER_00037),		c_msg_users_00037	},
	{	AA_MSG(C_MSG_USER_00038),		c_msg_users_00038	},
	{	AA_MSG(C_MSG_USER_00039),		c_msg_users_00039	},
	{	AA_MSG(C_MSG_USER_00040),		c_msg_users_00040	},
	{	AA_MSG(C_MSG_USER_00041),		c_msg_users_00041	},
	{	AA_MSG(C_MSG_USER_00042),		c_msg_users_00042	},
	{	AA_MSG(C_MSG_USER_00043),		c_msg_users_00043	},
	{	AA_MSG(C_MSG_USER_00044),		c_msg_users_00044	},
	{	AA_MSG(C_MSG_USER_00045),		c_msg_users_00045	},
	{	AA_MSG(C_MSG_USER_00046),		c_msg_users_00046	},
	{	AA_MSG(C_MSG_USER_00047),		c_msg_users_00047	},
	{	AA_MSG(C_MSG_USER_00048),		c_msg_users_00048	},
	{	AA_MSG(C_MSG_USER_00049),		c_msg_users_00049	},
	{	AA_MSG(C_MSG_USER_00050),		c_msg_users_00050	},
	{	AA_MSG(C_MSG_USER_00051),		c_msg_users_00051	},
	{	AA_MSG(C_MSG_USER_00052),		c_msg_users_00052	},
	{	AA_MSG(C_MSG_USER_00053),		c_msg_users_00053	},
	{	AA_MSG(C_MSG_USER_00054),		c_msg_users_00054	},
	{	AA_MSG(C_MSG_USER_00055),		c_msg_users_00055	},
	{	AA_MSG(C_MSG_USER_00056),		c_msg_users_00056	},
	{	AA_MSG(C_MSG_USER_00057),		c_msg_users_00057	},
	{	AA_MSG(C_MSG_USER_00058),		c_msg_users_00058	},
	{	AA_MSG(C_MSG_USER_00059),		c_msg_users_00059	},
	{	AA_MSG(C_MSG_USER_00060),		c_msg_users_00060	},
	/* }}} */
	/* C_MSG_FS {{{ */
	{	AA_MSG(C_MSG_FS_00000),			c_msg_fs_00000		},
	{	AA_MSG(C_MSG_FS_00001),			c_msg_fs_00001		},
	{	AA_MSG(C_MSG_FS_00002),			c_msg_fs_00002		},
	{	AA_MSG(C_MSG_FS_00003),			c_msg_fs_00003		},
	{	AA_MSG(C_MSG_FS_00004),			c_msg_fs_00004		},
	{	AA_MSG(C_MSG_FS_00005),			c_msg_fs_00005		},
	{	AA_MSG(C_MSG_FS_00006),			c_msg_fs_00006		},
	{	AA_MSG(C_MSG_FS_00007),			c_msg_fs_00007		},
	{	AA_MSG(C_MSG_FS_00008),			c_msg_fs_00008		},
	{	AA_MSG(C_MSG_FS_00009),			c_msg_fs_00009		},
	{	AA_MSG(C_MSG_FS_00010),			c_msg_fs_00010		},
	{	AA_MSG(C_MSG_FS_00011),			c_msg_fs_00011		},
	{	AA_MSG(C_MSG_FS_00012),			c_msg_fs_00012		},
	{	AA_MSG(C_MSG_FS_00013),			c_msg_fs_00013		},
	{	AA_MSG(C_MSG_FS_00014),			c_msg_fs_00014		},
	{	AA_MSG(C_MSG_FS_00015),			c_msg_fs_00015		},
	{	AA_MSG(C_MSG_FS_00016),			c_msg_fs_00016		},
	{	AA_MSG(C_MSG_FS_00017),			c_msg_fs_00017		},
	{	AA_MSG(C_MSG_FS_00018),			c_msg_fs_00018		},
	{	AA_MSG(C_MSG_FS_00019),			c_msg_fs_00019		},
	{	AA_MSG(C_MSG_FS_00020),			c_msg_fs_00020		},
	{	AA_MSG(C_MSG_FS_00021),			c_msg_fs_00021		},
	{	AA_MSG(C_MSG_FS_00022),			c_msg_fs_00022		},
	{	AA_MSG(C_MSG_FS_00023),			c_msg_fs_00023		},
	{	AA_MSG(C_MSG_FS_00024),			c_msg_fs_00024		},
	{	AA_MSG(C_MSG_FS_00025),			c_msg_fs_00025		},
	{	AA_MSG(C_MSG_FS_00026),			c_msg_fs_00026		},
	{	AA_MSG(C_MSG_FS_00027),			c_msg_fs_00027		},
	{	AA_MSG(C_MSG_FS_00028),			c_msg_fs_00028		},
	{	AA_MSG(C_MSG_FS_00029),			c_msg_fs_00029		},
	{	AA_MSG(C_MSG_FS_00030),			c_msg_fs_00030		},
	{	AA_MSG(C_MSG_FS_00031),			c_msg_fs_00031		},
	{	AA_MSG(C_MSG_FS_00032),			c_msg_fs_00032		},
	{	AA_MSG(C_MSG_FS_00033),			c_msg_fs_00033		},
	{	AA_MSG(C_MSG_FS_00034),			c_msg_fs_00034		},
	{	AA_MSG(C_MSG_FS_00035),			c_msg_fs_00035		},
	{	AA_MSG(C_MSG_FS_00036),			c_msg_fs_00036		},
	{	AA_MSG(C_MSG_FS_00037),			c_msg_fs_00037		},
	{	AA_MSG(C_MSG_FS_00038),			c_msg_fs_00038		},
	{	AA_MSG(C_MSG_FS_00039),			c_msg_fs_00039		},
	{	AA_MSG(C_MSG_FS_00040),			c_msg_fs_00040		},
	{	AA_MSG(C_MSG_FS_00041),			c_msg_fs_00041		},
	{	AA_MSG(C_MSG_FS_00042),			c_msg_fs_00042		},
	{	AA_MSG(C_MSG_FS_00043),			c_msg_fs_00043		},
	{	AA_MSG(C_MSG_FS_00044),			c_msg_fs_00044		},
	{	AA_MSG(C_MSG_FS_00045),			c_msg_fs_00045		},
	{	AA_MSG(C_MSG_FS_00046),			c_msg_fs_00046		},
	{	AA_MSG(C_MSG_FS_00047),			c_msg_fs_00047		},
	{	AA_MSG(C_MSG_FS_00048),			c_msg_fs_00048		},
	{	AA_MSG(C_MSG_FS_00049),			c_msg_fs_00049		},
	{	AA_MSG(C_MSG_FS_00050),			c_msg_fs_00050		},
	{	AA_MSG(C_MSG_FS_00051),			c_msg_fs_00051		},
	{	AA_MSG(C_MSG_FS_00052),			c_msg_fs_00052		},
	{	AA_MSG(C_MSG_FS_00053),			c_msg_fs_00053		},
	{	AA_MSG(C_MSG_FS_00054),			c_msg_fs_00054		},
	{	AA_MSG(C_MSG_FS_00055),			c_msg_fs_00055		},
	{	AA_MSG(C_MSG_FS_00056),			c_msg_fs_00056		},
	{	AA_MSG(C_MSG_FS_00057),			c_msg_fs_00057		},
	{	AA_MSG(C_MSG_FS_00058),			c_msg_fs_00058		},
	{	AA_MSG(C_MSG_FS_00059),			c_msg_fs_00059		},
	{	AA_MSG(C_MSG_FS_00060),			c_msg_fs_00060		},
	{	AA_MSG(C_MSG_FS_00061),			c_msg_fs_00061		},
	{	AA_MSG(C_MSG_FS_00062),			c_msg_fs_00062		},
	{	AA_MSG(C_MSG_FS_00063),			c_msg_fs_00063		},
	{	AA_MSG(C_MSG_FS_00064),			c_msg_fs_00064		},
	{	AA_MSG(C_MSG_FS_00065),			c_msg_fs_00065		},
	{	AA_MSG(C_MSG_FS_00066),			c_msg_fs_00066		},
	{	AA_MSG(C_MSG_FS_00067),			c_msg_fs_00067		},
	{	AA_MSG(C_MSG_FS_00068),			c_msg_fs_00068		},
	{	AA_MSG(C_MSG_FS_00069),			c_msg_fs_00069		},
	{	AA_MSG(C_MSG_FS_00070),			c_msg_fs_00070		},
	{	AA_MSG(C_MSG_FS_00071),			c_msg_fs_00071		},
	{	AA_MSG(C_MSG_FS_00072),			c_msg_fs_00072		},
	{	AA_MSG(C_MSG_FS_00073),			c_msg_fs_00073		},
	{	AA_MSG(C_MSG_FS_00074),			c_msg_fs_00074		},
	{	AA_MSG(C_MSG_FS_00075),			c_msg_fs_00075		},
	{	AA_MSG(C_MSG_FS_00076),			c_msg_fs_00076		},
	{	AA_MSG(C_MSG_FS_00077),			c_msg_fs_00077		},
	{	AA_MSG(C_MSG_FS_00078),			c_msg_fs_00078		},
	{	AA_MSG(C_MSG_FS_00079),			c_msg_fs_00079		},
	{	AA_MSG(C_MSG_FS_00080),			c_msg_fs_00080		},
	{	AA_MSG(C_MSG_FS_00081),			c_msg_fs_00081		},
	{	AA_MSG(C_MSG_FS_00082),			c_msg_fs_00082		},
	{	AA_MSG(C_MSG_FS_00083),			c_msg_fs_00083		},
	{	AA_MSG(C_MSG_FS_00084),			c_msg_fs_00084		},
	{	AA_MSG(C_MSG_FS_00085),			c_msg_fs_00085		},
	{	AA_MSG(C_MSG_FS_00086),			c_msg_fs_00086		},
	{	AA_MSG(C_MSG_FS_00087),			c_msg_fs_00087		},
	{	AA_MSG(C_MSG_FS_00088),			c_msg_fs_00088		},
	{	AA_MSG(C_MSG_FS_00089),			c_msg_fs_00089		},
	{	AA_MSG(C_MSG_FS_00090),			c_msg_fs_00090		},
	{	AA_MSG(C_MSG_FS_00091),			c_msg_fs_00091		},
	{	AA_MSG(C_MSG_FS_00092),			c_msg_fs_00092		},
	{	AA_MSG(C_MSG_FS_00093),			c_msg_fs_00093		},
	{	AA_MSG(C_MSG_FS_00094),			c_msg_fs_00094		},
	{	AA_MSG(C_MSG_FS_00095),			c_msg_fs_00095		},
	{	AA_MSG(C_MSG_FS_00096),			c_msg_fs_00096		},
	{	AA_MSG(C_MSG_FS_00097),			c_msg_fs_00097		},
	{	AA_MSG(C_MSG_FS_00098),			c_msg_fs_00098		},
	{	AA_MSG(C_MSG_FS_00099),			c_msg_fs_00099		},
	{	AA_MSG(C_MSG_FS_00100),			c_msg_fs_00100		},
	{	AA_MSG(C_MSG_FS_00101),			c_msg_fs_00101		},
	{	AA_MSG(C_MSG_FS_00102),			c_msg_fs_00102		},
	{	AA_MSG(C_MSG_FS_00103),			c_msg_fs_00103		},
	{	AA_MSG(C_MSG_FS_00104),			c_msg_fs_00104		},
	{	AA_MSG(C_MSG_FS_00105),			c_msg_fs_00105		},
	{	AA_MSG(C_MSG_FS_00106),			c_msg_fs_00106		},
	{	AA_MSG(C_MSG_FS_00107),			c_msg_fs_00107		},
	{	AA_MSG(C_MSG_FS_00108),			c_msg_fs_00108		},
	{	AA_MSG(C_MSG_FS_00109),			c_msg_fs_00109		},
	{	AA_MSG(C_MSG_FS_00110),			c_msg_fs_00110		},
	{	AA_MSG(C_MSG_FS_00111),			c_msg_fs_00111		},
	{	AA_MSG(C_MSG_FS_00112),			c_msg_fs_00112		},
	{	AA_MSG(C_MSG_FS_00113),			c_msg_fs_00113		},
	/* }}} */
	/* C_MSG_RPM {{{ */
	{	AA_MSG(C_MSG_RPM_00000),			c_msg_rpm_00000	},
	{	AA_MSG(C_MSG_RPM_00001),			c_msg_rpm_00001	},
	{	AA_MSG(C_MSG_RPM_00002),			c_msg_rpm_00002	},
	{	AA_MSG(C_MSG_RPM_00003),			c_msg_rpm_00003	},
	{	AA_MSG(C_MSG_RPM_00004),			c_msg_rpm_00004	},
	{	AA_MSG(C_MSG_RPM_00005),			c_msg_rpm_00005	},
	{	AA_MSG(C_MSG_RPM_00006),			c_msg_rpm_00006	},
	{	AA_MSG(C_MSG_RPM_00007),			c_msg_rpm_00007	},
	{	AA_MSG(C_MSG_RPM_00008),			c_msg_rpm_00008	},
	{	AA_MSG(C_MSG_RPM_00009),			c_msg_rpm_00009	},
	{	AA_MSG(C_MSG_RPM_00010),			c_msg_rpm_00010	},
	{	AA_MSG(C_MSG_RPM_00011),			c_msg_rpm_00011	},
	{	AA_MSG(C_MSG_RPM_00012),			c_msg_rpm_00012	},
	{	AA_MSG(C_MSG_RPM_00013),			c_msg_rpm_00013	},
	{	AA_MSG(C_MSG_RPM_00014),			c_msg_rpm_00014	},
	{	AA_MSG(C_MSG_RPM_00015),			c_msg_rpm_00015	},
	{	AA_MSG(C_MSG_RPM_00016),			c_msg_rpm_00016	},
	{	AA_MSG(C_MSG_RPM_00017),			c_msg_rpm_00017	},
	{	AA_MSG(C_MSG_RPM_00018),			c_msg_rpm_00018	},
	{	AA_MSG(C_MSG_RPM_00019),			c_msg_rpm_00019	},
	{	AA_MSG(C_MSG_RPM_00020),			c_msg_rpm_00020	},
	{	AA_MSG(C_MSG_RPM_00021),			c_msg_rpm_00021	},
	{	AA_MSG(C_MSG_RPM_00022),			c_msg_rpm_00022	},
	{	AA_MSG(C_MSG_RPM_00023),			c_msg_rpm_00023	},
	{	AA_MSG(C_MSG_RPM_00024),			c_msg_rpm_00024	},
	{	AA_MSG(C_MSG_RPM_00025),			c_msg_rpm_00025	},
	{	AA_MSG(C_MSG_RPM_00026),			c_msg_rpm_00026	},
	{	AA_MSG(C_MSG_RPM_00027),			c_msg_rpm_00027	},
	{	AA_MSG(C_MSG_RPM_00028),			c_msg_rpm_00028	},
	{	AA_MSG(C_MSG_RPM_00029),			c_msg_rpm_00029	},
	{	AA_MSG(C_MSG_RPM_00030),			c_msg_rpm_00030	},
	{	AA_MSG(C_MSG_RPM_00031),			c_msg_rpm_00031	},
	{	AA_MSG(C_MSG_RPM_00032),			c_msg_rpm_00032	},
	{	AA_MSG(C_MSG_RPM_00033),			c_msg_rpm_00033	},
	{	AA_MSG(C_MSG_RPM_00034),			c_msg_rpm_00034	},
	{	AA_MSG(C_MSG_RPM_00035),			c_msg_rpm_00035	},
	{	AA_MSG(C_MSG_RPM_00036),			c_msg_rpm_00036	},
	{	AA_MSG(C_MSG_RPM_00037),			c_msg_rpm_00037	},
	{	AA_MSG(C_MSG_RPM_00038),			c_msg_rpm_00038	},
	{	AA_MSG(C_MSG_RPM_00039),			c_msg_rpm_00039	},
	{	AA_MSG(C_MSG_RPM_00040),			c_msg_rpm_00040	},
	{	AA_MSG(C_MSG_RPM_00041),			c_msg_rpm_00041	},
	{	AA_MSG(C_MSG_RPM_00042),			c_msg_rpm_00042	},
	{	AA_MSG(C_MSG_RPM_00043),			c_msg_rpm_00043	},
	{	AA_MSG(C_MSG_RPM_00044),			c_msg_rpm_00044	},
	/* }}} */
	/* C_MSG_SYSCONF {{{ */
	{	AA_MSG(C_MSG_SYSCONF_00001),		c_msg_sysconf_00001	},
	{	AA_MSG(C_MSG_SYSCONF_00002),		c_msg_sysconf_00002	},
	{	AA_MSG(C_MSG_SYSCONF_00003),		c_msg_sysconf_00003	},
	{	AA_MSG(C_MSG_SYSCONF_00004),		c_msg_sysconf_00004	},
	{	AA_MSG(C_MSG_SYSCONF_00005),		c_msg_sysconf_00005	},
	{	AA_MSG(C_MSG_SYSCONF_00006),		c_msg_sysconf_00006	},
	{	AA_MSG(C_MSG_SYSCONF_00007),		c_msg_sysconf_00007	},
	{	AA_MSG(C_MSG_SYSCONF_00008),		c_msg_sysconf_00008	},
	{	AA_MSG(C_MSG_SYSCONF_00009),		c_msg_sysconf_00009	},
	{	AA_MSG(C_MSG_SYSCONF_00010),		c_msg_sysconf_00010	},
	{	AA_MSG(C_MSG_SYSCONF_00011),		c_msg_sysconf_00011	},
	{	AA_MSG(C_MSG_SYSCONF_00012),		c_msg_sysconf_00012	},
	{	AA_MSG(C_MSG_SYSCONF_00013),		c_msg_sysconf_00013	},
	{	AA_MSG(C_MSG_SYSCONF_00014),		c_msg_sysconf_00014	},
	/* }}} */
	/* C_MSG_DPKG {{{ */
	{	AA_MSG(C_MSG_DPKG_00001),		c_msg_dpkg_00001	},
	{	AA_MSG(C_MSG_DPKG_00002),		c_msg_dpkg_00002	},
	{	AA_MSG(C_MSG_DPKG_00003),		c_msg_dpkg_00003	},
	{	AA_MSG(C_MSG_DPKG_00004),		c_msg_dpkg_00004	},
	{	AA_MSG(C_MSG_DPKG_00005),		c_msg_dpkg_00005	},
	{	AA_MSG(C_MSG_DPKG_00006),		c_msg_dpkg_00006	},
	{	AA_MSG(C_MSG_DPKG_00007),		c_msg_dpkg_00007	},
	{	AA_MSG(C_MSG_DPKG_00008),		c_msg_dpkg_00008	},
	{	AA_MSG(C_MSG_DPKG_00009),		c_msg_dpkg_00009	},
	{	AA_MSG(C_MSG_DPKG_00010),		c_msg_dpkg_00010	},
	/* }}} */
	/* C_MSG_SCCS {{{ */
	{	AA_MSG(C_MSG_SCCS_00001),		c_msg_sccs_00001	},
	{	AA_MSG(C_MSG_SCCS_00002),		c_msg_sccs_00002	},
	{	AA_MSG(C_MSG_SCCS_00003),		c_msg_sccs_00003	},
	{	AA_MSG(C_MSG_SCCS_00004),		c_msg_sccs_00004	},
	{	AA_MSG(C_MSG_SCCS_00005),		c_msg_sccs_00005	},
	{	AA_MSG(C_MSG_SCCS_00006),		c_msg_sccs_00006	},
	{	AA_MSG(C_MSG_SCCS_00007),		c_msg_sccs_00007	},
	{	AA_MSG(C_MSG_SCCS_00008),		c_msg_sccs_00008	},
	{	AA_MSG(C_MSG_SCCS_00009),		c_msg_sccs_00009	},
	{	AA_MSG(C_MSG_SCCS_00010),		c_msg_sccs_00010	},
	{	AA_MSG(C_MSG_SCCS_00011),		c_msg_sccs_00011	},
	{	AA_MSG(C_MSG_SCCS_00012),		c_msg_sccs_00012	},
	{	AA_MSG(C_MSG_SCCS_00013),		c_msg_sccs_00013	},
	/* }}} */
	{	0,							(char **) 0		}
};
/* }}} */
/* c_tab_htm[] {{{ */
struct y_desc_msgs		 c_tab_htm[] = {
	/* C_MSG_MAIN {{{ */
	{	AA_HTM(C_MSG_MAIN_00001),		c_htm_main_00001	},
	{	AA_HTM(C_MSG_MAIN_00002),		c_htm_main_00002	},
	{	AA_HTM(C_MSG_MAIN_00003),		c_htm_main_00003	},
	{	AA_HTM(C_MSG_MAIN_00004),		c_htm_main_00004	},
	{	AA_HTM(C_MSG_MAIN_00005),		c_htm_main_00005	},
	{	AA_HTM(C_MSG_MAIN_00006),		c_htm_main_00006	},
	{	AA_HTM(C_MSG_MAIN_00007),		c_htm_main_00007	},
	{	AA_HTM(C_MSG_MAIN_00008),		c_htm_main_00008	},
	{	AA_HTM(C_MSG_MAIN_00009),		c_htm_main_00009	},
	{	AA_HTM(C_MSG_MAIN_00010),		c_htm_main_00010	},
	{	AA_HTM(C_MSG_MAIN_00011),		c_htm_main_00011	},
	{	AA_HTM(C_MSG_MAIN_00012),		c_htm_main_00012	},
	{	AA_HTM(C_MSG_MAIN_00013),		c_htm_main_00013	},
	{	AA_HTM(C_MSG_MAIN_00014),		c_htm_main_00014	},
	{	AA_HTM(C_MSG_MAIN_00015),		c_htm_main_00015	},
	{	AA_HTM(C_MSG_MAIN_00016),		c_htm_main_00016	},
	{	AA_HTM(C_MSG_MAIN_00017),		c_htm_main_00017	},
	{	AA_HTM(C_MSG_MAIN_00018),		c_htm_main_00018	},
	{	AA_HTM(C_MSG_MAIN_00019),		c_htm_main_00019	},
	{	AA_HTM(C_MSG_MAIN_00020),		c_htm_main_00020	},
	{	AA_HTM(C_MSG_MAIN_00021),		c_htm_main_00021	},
	{	AA_HTM(C_MSG_MAIN_00022),		c_htm_main_00022	},
	{	AA_HTM(C_MSG_MAIN_00023),		c_htm_main_00023	},
	{	AA_HTM(C_MSG_MAIN_00024),		c_htm_main_00024	},
	{	AA_HTM(C_MSG_MAIN_00025),		c_htm_main_00025	},
	{	AA_HTM(C_MSG_MAIN_00026),		c_htm_main_00026	},
	{	AA_HTM(C_MSG_MAIN_00027),		c_htm_main_00027	},
	{	AA_HTM(C_MSG_MAIN_00028),		c_htm_main_00028	},
	{	AA_HTM(C_MSG_MAIN_00029),		c_htm_main_00029	},
	{	AA_HTM(C_MSG_MAIN_00030),		c_htm_main_00030	},
	{	AA_HTM(C_MSG_MAIN_00031),		c_htm_main_00031	},
	{	AA_HTM(C_MSG_MAIN_00032),		c_htm_main_00032	},
	{	AA_HTM(C_MSG_MAIN_00033),		c_htm_main_00033	},
	{	AA_HTM(C_MSG_MAIN_00034),		c_htm_main_00034	},
	{	AA_HTM(C_MSG_MAIN_00035),		c_htm_main_00035	},
	{	AA_HTM(C_MSG_MAIN_00036),		c_htm_main_00036	},
	{	AA_HTM(C_MSG_MAIN_00037),		c_htm_main_00037	},
	{	AA_HTM(C_MSG_MAIN_00038),		c_htm_main_00038	},
	{	AA_HTM(C_MSG_MAIN_00039),		c_htm_main_00039	},
	{	AA_HTM(C_MSG_MAIN_00040),		c_htm_main_00040	},
	{	AA_HTM(C_MSG_MAIN_00041),		c_htm_main_00041	},
	{	AA_HTM(C_MSG_MAIN_00042),		c_htm_main_00042	},
	{	AA_HTM(C_MSG_MAIN_00043),		c_htm_main_00043	},
	{	AA_HTM(C_MSG_MAIN_00044),		c_htm_main_00044	},
	{	AA_HTM(C_MSG_MAIN_00045),		c_htm_main_00045	},
	{	AA_HTM(C_MSG_MAIN_00046),		c_htm_main_00046	},
	{	AA_HTM(C_MSG_MAIN_00047),		c_htm_main_00047	},
	{	AA_HTM(C_MSG_MAIN_00048),		c_htm_main_00048	},
	{	AA_HTM(C_MSG_MAIN_00049),		c_htm_main_00049	},
	{	AA_HTM(C_MSG_MAIN_00050),		c_htm_main_00050	},
	{	AA_HTM(C_MSG_MAIN_00051),		c_htm_main_00051	},
	{	AA_HTM(C_MSG_MAIN_00052),		c_htm_main_00052	},
	{	AA_HTM(C_MSG_MAIN_00053),		c_htm_main_00053	},
	{	AA_HTM(C_MSG_MAIN_00054),		c_htm_main_00054	},
	{	AA_HTM(C_MSG_MAIN_00055),		c_htm_main_00055	},
	{	AA_HTM(C_MSG_MAIN_00056),		c_htm_main_00056	},
	{	AA_HTM(C_MSG_MAIN_00057),		c_htm_main_00057	},
	{	AA_HTM(C_MSG_MAIN_00058),		c_htm_main_00058	},
	{	AA_HTM(C_MSG_MAIN_00059),		c_htm_main_00059	},
	{	AA_HTM(C_MSG_MAIN_00060),		c_htm_main_00060	},
	{	AA_HTM(C_MSG_MAIN_00061),		c_htm_main_00061	},
	{	AA_HTM(C_MSG_MAIN_00062),		c_htm_main_00062	},
	{	AA_HTM(C_MSG_MAIN_00063),		c_htm_main_00063	},
	{	AA_HTM(C_MSG_MAIN_00064),		c_htm_main_00064	},
	{	AA_HTM(C_MSG_MAIN_00065),		c_htm_main_00065	},
	{	AA_HTM(C_MSG_MAIN_00066),		c_htm_main_00066	},
	{	AA_HTM(C_MSG_MAIN_00067),		c_htm_main_00067	},
	{	AA_HTM(C_MSG_MAIN_00068),		c_htm_main_00068	},
	{	AA_HTM(C_MSG_MAIN_00069),		c_htm_main_00069	},
	{	AA_HTM(C_MSG_MAIN_00070),		c_htm_main_00070	},
	{	AA_HTM(C_MSG_MAIN_00071),		c_htm_main_00071	},
	{	AA_HTM(C_MSG_MAIN_00072),		c_htm_main_00072	},
	{	AA_HTM(C_MSG_MAIN_00073),		c_htm_main_00073	},
	{	AA_HTM(C_MSG_MAIN_00074),		c_htm_main_00074	},
	{	AA_HTM(C_MSG_MAIN_00075),		c_htm_main_00075	},
	{	AA_HTM(C_MSG_MAIN_00076),		c_htm_main_00076	},
	{	AA_HTM(C_MSG_MAIN_00077),		c_htm_main_00077	},
	{	AA_HTM(C_MSG_MAIN_00078),		c_htm_main_00078	},
	{	AA_HTM(C_MSG_MAIN_00079),		c_htm_main_00079	},
	{	AA_HTM(C_MSG_MAIN_00080),		c_htm_main_00080	},
	{	AA_HTM(C_MSG_MAIN_00081),		c_htm_main_00081	},
	{	AA_HTM(C_MSG_MAIN_00082),		c_htm_main_00082	},
	{	AA_HTM(C_MSG_MAIN_00083),		c_htm_main_00083	},
	{	AA_HTM(C_MSG_MAIN_00084),		c_htm_main_00084	},
	{	AA_HTM(C_MSG_MAIN_00085),		c_htm_main_00085	},
	{	AA_HTM(C_MSG_MAIN_00086),		c_htm_main_00086	},
	{	AA_HTM(C_MSG_MAIN_00087),		c_htm_main_00087	},
	{	AA_HTM(C_MSG_MAIN_00088),		c_htm_main_00088	},
	{	AA_HTM(C_MSG_MAIN_00089),		c_htm_main_00089	},
	{	AA_HTM(C_MSG_MAIN_00090),		c_htm_main_00090	},
	{	AA_HTM(C_MSG_MAIN_00091),		c_htm_main_00091	},
	{	AA_HTM(C_MSG_MAIN_00092),		c_htm_main_00092	},
	/* }}} */
	/* C_MSG_COMMON {{{ */
	{	AA_HTM(C_MSG_COMMON_00000),		c_htm_common_00000	},
	{	AA_HTM(C_MSG_COMMON_00001),		c_htm_common_00001	},
	{	AA_HTM(C_MSG_COMMON_00002),		c_htm_common_00002	},
	{	AA_HTM(C_MSG_COMMON_00003),		c_htm_common_00003	},
	{	AA_HTM(C_MSG_COMMON_00004),		c_htm_common_00004	},
	{	AA_HTM(C_MSG_COMMON_00005),		c_htm_common_00005	},
	{	AA_HTM(C_MSG_COMMON_00006),		c_htm_common_00006	},
	{	AA_HTM(C_MSG_COMMON_00007),		c_htm_common_00007	},
	{	AA_HTM(C_MSG_COMMON_00008),		c_htm_common_00008	},
	{	AA_HTM(C_MSG_COMMON_00009),		c_htm_common_00009	},
	{	AA_HTM(C_MSG_COMMON_00010),		c_htm_common_00010	},
	{	AA_HTM(C_MSG_COMMON_00011),		c_htm_common_00011	},
	{	AA_HTM(C_MSG_COMMON_00012),		c_htm_common_00012	},
	{	AA_HTM(C_MSG_COMMON_00013),		c_htm_common_00013	},
	{	AA_HTM(C_MSG_COMMON_00014),		c_htm_common_00014	},
	{	AA_HTM(C_MSG_COMMON_00015),		c_htm_common_00015	},
	{	AA_HTM(C_MSG_COMMON_00016),		c_htm_common_00016	},
	{	AA_HTM(C_MSG_COMMON_00017),		c_htm_common_00017	},
	{	AA_HTM(C_MSG_COMMON_00018),		c_htm_common_00018	},
	{	AA_HTM(C_MSG_COMMON_00019),		c_htm_common_00019	},
	{	AA_HTM(C_MSG_COMMON_00020),		c_htm_common_00020	},
	{	AA_HTM(C_MSG_COMMON_00021),		c_htm_common_00021	},
	{	AA_HTM(C_MSG_COMMON_00022),		c_htm_common_00022	},
	{	AA_HTM(C_MSG_COMMON_00023),		c_htm_common_00023	},
	{	AA_HTM(C_MSG_COMMON_00024),		c_htm_common_00024	},
	{	AA_HTM(C_MSG_COMMON_00025),		c_htm_common_00025	},
	{	AA_HTM(C_MSG_COMMON_00026),		c_htm_common_00026	},
	{	AA_HTM(C_MSG_COMMON_00027),		c_htm_common_00027	},
	{	AA_HTM(C_MSG_COMMON_00028),		c_htm_common_00028	},
	{	AA_HTM(C_MSG_COMMON_00029),		c_htm_common_00029	},
	/* }}} */
	/* C_MSG_USER {{{ */
	{	AA_HTM(C_MSG_USER_00001),		c_htm_users_00001	},
	{	AA_HTM(C_MSG_USER_00002),		c_htm_users_00002	},
	{	AA_HTM(C_MSG_USER_00003),		c_htm_users_00003	},
	{	AA_HTM(C_MSG_USER_00004),		c_htm_users_00004	},
	{	AA_HTM(C_MSG_USER_00005),		c_htm_users_00005	},
	{	AA_HTM(C_MSG_USER_00006),		c_htm_users_00006	},
	{	AA_HTM(C_MSG_USER_00007),		c_htm_users_00007	},
	{	AA_HTM(C_MSG_USER_00008),		c_htm_users_00008	},
	{	AA_HTM(C_MSG_USER_00009),		c_htm_users_00009	},
	{	AA_HTM(C_MSG_USER_00010),		c_htm_users_00010	},
	{	AA_HTM(C_MSG_USER_00011),		c_htm_users_00011	},
	{	AA_HTM(C_MSG_USER_00012),		c_htm_users_00012	},
	{	AA_HTM(C_MSG_USER_00013),		c_htm_users_00013	},
	{	AA_HTM(C_MSG_USER_00014),		c_htm_users_00014	},
	{	AA_HTM(C_MSG_USER_00015),		c_htm_users_00015	},
	{	AA_HTM(C_MSG_USER_00016),		c_htm_users_00016	},
	{	AA_HTM(C_MSG_USER_00017),		c_htm_users_00017	},
	{	AA_HTM(C_MSG_USER_00018),		c_htm_users_00018	},
	{	AA_HTM(C_MSG_USER_00019),		c_htm_users_00019	},
	{	AA_HTM(C_MSG_USER_00020),		c_htm_users_00020	},
	{	AA_HTM(C_MSG_USER_00021),		c_htm_users_00021	},
	{	AA_HTM(C_MSG_USER_00022),		c_htm_users_00022	},
	{	AA_HTM(C_MSG_USER_00023),		c_htm_users_00023	},
	{	AA_HTM(C_MSG_USER_00024),		c_htm_users_00024	},
	{	AA_HTM(C_MSG_USER_00025),		c_htm_users_00025	},
	{	AA_HTM(C_MSG_USER_00026),		c_htm_users_00026	},
	{	AA_HTM(C_MSG_USER_00027),		c_htm_users_00027	},
	{	AA_HTM(C_MSG_USER_00028),		c_htm_users_00028	},
	{	AA_HTM(C_MSG_USER_00029),		c_htm_users_00029	},
	{	AA_HTM(C_MSG_USER_00030),		c_htm_users_00030	},
	{	AA_HTM(C_MSG_USER_00031),		c_htm_users_00031	},
	{	AA_HTM(C_MSG_USER_00032),		c_htm_users_00032	},
	{	AA_HTM(C_MSG_USER_00033),		c_htm_users_00033	},
	{	AA_HTM(C_MSG_USER_00034),		c_htm_users_00034	},
	{	AA_HTM(C_MSG_USER_00035),		c_htm_users_00035	},
	{	AA_HTM(C_MSG_USER_00036),		c_htm_users_00036	},
	{	AA_HTM(C_MSG_USER_00037),		c_htm_users_00037	},
	{	AA_HTM(C_MSG_USER_00038),		c_htm_users_00038	},
	{	AA_HTM(C_MSG_USER_00039),		c_htm_users_00039	},
	{	AA_HTM(C_MSG_USER_00040),		c_htm_users_00040	},
	{	AA_HTM(C_MSG_USER_00041),		c_htm_users_00041	},
	{	AA_HTM(C_MSG_USER_00042),		c_htm_users_00042	},
	{	AA_HTM(C_MSG_USER_00043),		c_htm_users_00043	},
	{	AA_HTM(C_MSG_USER_00044),		c_htm_users_00044	},
	{	AA_HTM(C_MSG_USER_00045),		c_htm_users_00045	},
	{	AA_HTM(C_MSG_USER_00046),		c_htm_users_00046	},
	{	AA_HTM(C_MSG_USER_00047),		c_htm_users_00047	},
	{	AA_HTM(C_MSG_USER_00048),		c_htm_users_00048	},
	{	AA_HTM(C_MSG_USER_00049),		c_htm_users_00049	},
	{	AA_HTM(C_MSG_USER_00050),		c_htm_users_00050	},
	{	AA_HTM(C_MSG_USER_00051),		c_htm_users_00051	},
	{	AA_HTM(C_MSG_USER_00052),		c_htm_users_00052	},
	{	AA_HTM(C_MSG_USER_00053),		c_htm_users_00053	},
	{	AA_HTM(C_MSG_USER_00054),		c_htm_users_00054	},
	{	AA_HTM(C_MSG_USER_00055),		c_htm_users_00055	},
	{	AA_HTM(C_MSG_USER_00056),		c_htm_users_00056	},
	{	AA_HTM(C_MSG_USER_00057),		c_htm_users_00057	},
	{	AA_HTM(C_MSG_USER_00058),		c_htm_users_00058	},
	{	AA_HTM(C_MSG_USER_00059),		c_htm_users_00059	},
	{	AA_HTM(C_MSG_USER_00060),		c_htm_users_00060	},
	/* }}} */
	/* C_MSG_FS {{{ */
	{	AA_HTM(C_MSG_FS_00001),			c_htm_fs_00001		},
	{	AA_HTM(C_MSG_FS_00002),			c_htm_fs_00002		},
	{	AA_HTM(C_MSG_FS_00003),			c_htm_fs_00003		},
	{	AA_HTM(C_MSG_FS_00004),			c_htm_fs_00004		},
	{	AA_HTM(C_MSG_FS_00005),			c_htm_fs_00005		},
	{	AA_HTM(C_MSG_FS_00006),			c_htm_fs_00006		},
	{	AA_HTM(C_MSG_FS_00007),			c_htm_fs_00007		},
	{	AA_HTM(C_MSG_FS_00008),			c_htm_fs_00008		},
	{	AA_HTM(C_MSG_FS_00009),			c_htm_fs_00009		},
	{	AA_HTM(C_MSG_FS_00010),			c_htm_fs_00010		},
	{	AA_HTM(C_MSG_FS_00011),			c_htm_fs_00011		},
	{	AA_HTM(C_MSG_FS_00012),			c_htm_fs_00012		},
	{	AA_HTM(C_MSG_FS_00013),			c_htm_fs_00013		},
	{	AA_HTM(C_MSG_FS_00014),			c_htm_fs_00014		},
	{	AA_HTM(C_MSG_FS_00015),			c_htm_fs_00015		},
	{	AA_HTM(C_MSG_FS_00016),			c_htm_fs_00016		},
	{	AA_HTM(C_MSG_FS_00017),			c_htm_fs_00017		},
	{	AA_HTM(C_MSG_FS_00018),			c_htm_fs_00018		},
	{	AA_HTM(C_MSG_FS_00019),			c_htm_fs_00019		},
	{	AA_HTM(C_MSG_FS_00020),			c_htm_fs_00020		},
	{	AA_HTM(C_MSG_FS_00021),			c_htm_fs_00021		},
	{	AA_HTM(C_MSG_FS_00022),			c_htm_fs_00022		},
	{	AA_HTM(C_MSG_FS_00023),			c_htm_fs_00023		},
	{	AA_HTM(C_MSG_FS_00024),			c_htm_fs_00024		},
	{	AA_HTM(C_MSG_FS_00025),			c_htm_fs_00025		},
	{	AA_HTM(C_MSG_FS_00026),			c_htm_fs_00026		},
	{	AA_HTM(C_MSG_FS_00027),			c_htm_fs_00027		},
	{	AA_HTM(C_MSG_FS_00028),			c_htm_fs_00028		},
	{	AA_HTM(C_MSG_FS_00029),			c_htm_fs_00029		},
	{	AA_HTM(C_MSG_FS_00030),			c_htm_fs_00030		},
	{	AA_HTM(C_MSG_FS_00031),			c_htm_fs_00031		},
	{	AA_HTM(C_MSG_FS_00032),			c_htm_fs_00032		},
	{	AA_HTM(C_MSG_FS_00033),			c_htm_fs_00033		},
	{	AA_HTM(C_MSG_FS_00034),			c_htm_fs_00034		},
	{	AA_HTM(C_MSG_FS_00035),			c_htm_fs_00035		},
	{	AA_HTM(C_MSG_FS_00036),			c_htm_fs_00036		},
	{	AA_HTM(C_MSG_FS_00037),			c_htm_fs_00037		},
	{	AA_HTM(C_MSG_FS_00038),			c_htm_fs_00038		},
	{	AA_HTM(C_MSG_FS_00039),			c_htm_fs_00039		},
	{	AA_HTM(C_MSG_FS_00040),			c_htm_fs_00040		},
	{	AA_HTM(C_MSG_FS_00041),			c_htm_fs_00041		},
	{	AA_HTM(C_MSG_FS_00042),			c_htm_fs_00042		},
	{	AA_HTM(C_MSG_FS_00043),			c_htm_fs_00043		},
	{	AA_HTM(C_MSG_FS_00044),			c_htm_fs_00044		},
	{	AA_HTM(C_MSG_FS_00045),			c_htm_fs_00045		},
	{	AA_HTM(C_MSG_FS_00046),			c_htm_fs_00046		},
	{	AA_HTM(C_MSG_FS_00047),			c_htm_fs_00047		},
	{	AA_HTM(C_MSG_FS_00048),			c_htm_fs_00048		},
	{	AA_HTM(C_MSG_FS_00049),			c_htm_fs_00049		},
	{	AA_HTM(C_MSG_FS_00050),			c_htm_fs_00050		},
	{	AA_HTM(C_MSG_FS_00051),			c_htm_fs_00051		},
	{	AA_HTM(C_MSG_FS_00052),			c_htm_fs_00052		},
	{	AA_HTM(C_MSG_FS_00053),			c_htm_fs_00053		},
	{	AA_HTM(C_MSG_FS_00054),			c_htm_fs_00054		},
	{	AA_HTM(C_MSG_FS_00055),			c_htm_fs_00055		},
	{	AA_HTM(C_MSG_FS_00056),			c_htm_fs_00056		},
	{	AA_HTM(C_MSG_FS_00057),			c_htm_fs_00057		},
	{	AA_HTM(C_MSG_FS_00058),			c_htm_fs_00058		},
	{	AA_HTM(C_MSG_FS_00059),			c_htm_fs_00059		},
	{	AA_HTM(C_MSG_FS_00060),			c_htm_fs_00060		},
	{	AA_HTM(C_MSG_FS_00061),			c_htm_fs_00061		},
	{	AA_HTM(C_MSG_FS_00062),			c_htm_fs_00062		},
	{	AA_HTM(C_MSG_FS_00063),			c_htm_fs_00063		},
	{	AA_HTM(C_MSG_FS_00064),			c_htm_fs_00064		},
	{	AA_HTM(C_MSG_FS_00065),			c_htm_fs_00065		},
	{	AA_HTM(C_MSG_FS_00066),			c_htm_fs_00066		},
	{	AA_HTM(C_MSG_FS_00067),			c_htm_fs_00067		},
	{	AA_HTM(C_MSG_FS_00068),			c_htm_fs_00068		},
	{	AA_HTM(C_MSG_FS_00069),			c_htm_fs_00069		},
	{	AA_HTM(C_MSG_FS_00070),			c_htm_fs_00070		},
	{	AA_HTM(C_MSG_FS_00071),			c_htm_fs_00071		},
	{	AA_HTM(C_MSG_FS_00072),			c_htm_fs_00072		},
	{	AA_HTM(C_MSG_FS_00073),			c_htm_fs_00073		},
	{	AA_HTM(C_MSG_FS_00074),			c_htm_fs_00074		},
	{	AA_HTM(C_MSG_FS_00075),			c_htm_fs_00075		},
	{	AA_HTM(C_MSG_FS_00076),			c_htm_fs_00076		},
	{	AA_HTM(C_MSG_FS_00077),			c_htm_fs_00077		},
	{	AA_HTM(C_MSG_FS_00078),			c_htm_fs_00078		},
	{	AA_HTM(C_MSG_FS_00079),			c_htm_fs_00079		},
	{	AA_HTM(C_MSG_FS_00080),			c_htm_fs_00080		},
	{	AA_HTM(C_MSG_FS_00081),			c_htm_fs_00081		},
	{	AA_HTM(C_MSG_FS_00082),			c_htm_fs_00082		},
	{	AA_HTM(C_MSG_FS_00083),			c_htm_fs_00083		},
	{	AA_HTM(C_MSG_FS_00084),			c_htm_fs_00084		},
	{	AA_HTM(C_MSG_FS_00085),			c_htm_fs_00085		},
	{	AA_HTM(C_MSG_FS_00086),			c_htm_fs_00086		},
	{	AA_HTM(C_MSG_FS_00087),			c_htm_fs_00087		},
	{	AA_HTM(C_MSG_FS_00088),			c_htm_fs_00088		},
	{	AA_HTM(C_MSG_FS_00089),			c_htm_fs_00089		},
	{	AA_HTM(C_MSG_FS_00090),			c_htm_fs_00090		},
	{	AA_HTM(C_MSG_FS_00091),			c_htm_fs_00091		},
	{	AA_HTM(C_MSG_FS_00092),			c_htm_fs_00092		},
	{	AA_HTM(C_MSG_FS_00093),			c_htm_fs_00093		},
	{	AA_HTM(C_MSG_FS_00094),			c_htm_fs_00094		},
	{	AA_HTM(C_MSG_FS_00095),			c_htm_fs_00095		},
	{	AA_HTM(C_MSG_FS_00096),			c_htm_fs_00096		},
	{	AA_HTM(C_MSG_FS_00097),			c_htm_fs_00097		},
	{	AA_HTM(C_MSG_FS_00098),			c_htm_fs_00098		},
	{	AA_HTM(C_MSG_FS_00099),			c_htm_fs_00099		},
	{	AA_HTM(C_MSG_FS_00100),			c_htm_fs_00100		},
	{	AA_HTM(C_MSG_FS_00101),			c_htm_fs_00101		},
	{	AA_HTM(C_MSG_FS_00102),			c_htm_fs_00102		},
	{	AA_HTM(C_MSG_FS_00103),			c_htm_fs_00103		},
	{	AA_HTM(C_MSG_FS_00104),			c_htm_fs_00104		},
	{	AA_HTM(C_MSG_FS_00105),			c_htm_fs_00105		},
	{	AA_HTM(C_MSG_FS_00106),			c_htm_fs_00106		},
	{	AA_HTM(C_MSG_FS_00107),			c_htm_fs_00107		},
	{	AA_HTM(C_MSG_FS_00108),			c_htm_fs_00108		},
	{	AA_HTM(C_MSG_FS_00109),			c_htm_fs_00109		},
	{	AA_HTM(C_MSG_FS_00110),			c_htm_fs_00110		},
	{	AA_HTM(C_MSG_FS_00111),			c_htm_fs_00111		},
	{	AA_HTM(C_MSG_FS_00112),			c_htm_fs_00112		},
	{	AA_HTM(C_MSG_FS_00113),			c_htm_fs_00113		},
	/* }}} */
	/* C_MSG_RPM {{{ */
	{	AA_HTM(C_MSG_RPM_00001),			c_htm_rpm_00001	},
	{	AA_HTM(C_MSG_RPM_00002),			c_htm_rpm_00002	},
	{	AA_HTM(C_MSG_RPM_00003),			c_htm_rpm_00003	},
	{	AA_HTM(C_MSG_RPM_00004),			c_htm_rpm_00004	},
	{	AA_HTM(C_MSG_RPM_00005),			c_htm_rpm_00005	},
	{	AA_HTM(C_MSG_RPM_00006),			c_htm_rpm_00006	},
	{	AA_HTM(C_MSG_RPM_00007),			c_htm_rpm_00007	},
	{	AA_HTM(C_MSG_RPM_00008),			c_htm_rpm_00008	},
	{	AA_HTM(C_MSG_RPM_00009),			c_htm_rpm_00009	},
	{	AA_HTM(C_MSG_RPM_00010),			c_htm_rpm_00010	},
	{	AA_HTM(C_MSG_RPM_00011),			c_htm_rpm_00011	},
	{	AA_HTM(C_MSG_RPM_00012),			c_htm_rpm_00012	},
	{	AA_HTM(C_MSG_RPM_00013),			c_htm_rpm_00013	},
	{	AA_HTM(C_MSG_RPM_00014),			c_htm_rpm_00014	},
	{	AA_HTM(C_MSG_RPM_00015),			c_htm_rpm_00015	},
	{	AA_HTM(C_MSG_RPM_00016),			c_htm_rpm_00016	},
	{	AA_HTM(C_MSG_RPM_00017),			c_htm_rpm_00017	},
	{	AA_HTM(C_MSG_RPM_00018),			c_htm_rpm_00018	},
	{	AA_HTM(C_MSG_RPM_00019),			c_htm_rpm_00019	},
	{	AA_HTM(C_MSG_RPM_00020),			c_htm_rpm_00020	},
	{	AA_HTM(C_MSG_RPM_00021),			c_htm_rpm_00021	},
	{	AA_HTM(C_MSG_RPM_00022),			c_htm_rpm_00022	},
	{	AA_HTM(C_MSG_RPM_00023),			c_htm_rpm_00023	},
	{	AA_HTM(C_MSG_RPM_00024),			c_htm_rpm_00024	},
	{	AA_HTM(C_MSG_RPM_00025),			c_htm_rpm_00025	},
	{	AA_HTM(C_MSG_RPM_00026),			c_htm_rpm_00026	},
	{	AA_HTM(C_MSG_RPM_00027),			c_htm_rpm_00027	},
	{	AA_HTM(C_MSG_RPM_00028),			c_htm_rpm_00028	},
	{	AA_HTM(C_MSG_RPM_00029),			c_htm_rpm_00029	},
	{	AA_HTM(C_MSG_RPM_00030),			c_htm_rpm_00030	},
	{	AA_HTM(C_MSG_RPM_00031),			c_htm_rpm_00031	},
	{	AA_HTM(C_MSG_RPM_00032),			c_htm_rpm_00032	},
	{	AA_HTM(C_MSG_RPM_00033),			c_htm_rpm_00033	},
	{	AA_HTM(C_MSG_RPM_00034),			c_htm_rpm_00034	},
	{	AA_HTM(C_MSG_RPM_00035),			c_htm_rpm_00035	},
	{	AA_HTM(C_MSG_RPM_00036),			c_htm_rpm_00036	},
	{	AA_HTM(C_MSG_RPM_00037),			c_htm_rpm_00037	},
	{	AA_HTM(C_MSG_RPM_00038),			c_htm_rpm_00038	},
	{	AA_HTM(C_MSG_RPM_00039),			c_htm_rpm_00039	},
	{	AA_HTM(C_MSG_RPM_00040),			c_htm_rpm_00040	},
	{	AA_HTM(C_MSG_RPM_00041),			c_htm_rpm_00041	},
	{	AA_HTM(C_MSG_RPM_00042),			c_htm_rpm_00042	},
	{	AA_HTM(C_MSG_RPM_00043),			c_htm_rpm_00043	},
	{	AA_HTM(C_MSG_RPM_00044),			c_htm_rpm_00044	},
	/* }}} */
	/* C_MSG_SYSCONF {{{ */
	{	AA_HTM(C_MSG_SYSCONF_00001),		c_htm_sysconf_00001	},
	{	AA_HTM(C_MSG_SYSCONF_00002),		c_htm_sysconf_00002	},
	{	AA_HTM(C_MSG_SYSCONF_00003),		c_htm_sysconf_00003	},
	{	AA_HTM(C_MSG_SYSCONF_00004),		c_htm_sysconf_00004	},
	{	AA_HTM(C_MSG_SYSCONF_00005),		c_htm_sysconf_00005	},
	{	AA_HTM(C_MSG_SYSCONF_00006),		c_htm_sysconf_00006	},
	{	AA_HTM(C_MSG_SYSCONF_00007),		c_htm_sysconf_00007	},
	{	AA_HTM(C_MSG_SYSCONF_00008),		c_htm_sysconf_00008	},
	{	AA_HTM(C_MSG_SYSCONF_00009),		c_htm_sysconf_00009	},
	{	AA_HTM(C_MSG_SYSCONF_00010),		c_htm_sysconf_00010	},
	{	AA_HTM(C_MSG_SYSCONF_00011),		c_htm_sysconf_00011	},
	{	AA_HTM(C_MSG_SYSCONF_00012),		c_htm_sysconf_00012	},
	{	AA_HTM(C_MSG_SYSCONF_00013),		c_htm_sysconf_00013	},
	{	AA_HTM(C_MSG_SYSCONF_00014),		c_htm_sysconf_00014	},
	/* }}} */
	/* C_MSG_DPKG {{{ */
	{	AA_HTM(C_MSG_DPKG_00001),		c_htm_dpkg_00001	},
	{	AA_HTM(C_MSG_DPKG_00002),		c_htm_dpkg_00002	},
	{	AA_HTM(C_MSG_DPKG_00003),		c_htm_dpkg_00003	},
	{	AA_HTM(C_MSG_DPKG_00004),		c_htm_dpkg_00004	},
	{	AA_HTM(C_MSG_DPKG_00005),		c_htm_dpkg_00005	},
	{	AA_HTM(C_MSG_DPKG_00006),		c_htm_dpkg_00006	},
	{	AA_HTM(C_MSG_DPKG_00007),		c_htm_dpkg_00007	},
	{	AA_HTM(C_MSG_DPKG_00008),		c_htm_dpkg_00008	},
	{	AA_HTM(C_MSG_DPKG_00009),		c_htm_dpkg_00009	},
	{	AA_HTM(C_MSG_DPKG_00010),		c_htm_dpkg_00010	},
	/* }}} */
	/* C_MSG_SCCS {{{ */
	{	AA_HTM(C_MSG_SCCS_00001),		c_htm_sccs_00001	},
	{	AA_HTM(C_MSG_SCCS_00002),		c_htm_sccs_00002	},
	{	AA_HTM(C_MSG_SCCS_00003),		c_htm_sccs_00003	},
	{	AA_HTM(C_MSG_SCCS_00004),		c_htm_sccs_00004	},
	{	AA_HTM(C_MSG_SCCS_00005),		c_htm_sccs_00005	},
	{	AA_HTM(C_MSG_SCCS_00006),		c_htm_sccs_00006	},
	{	AA_HTM(C_MSG_SCCS_00007),		c_htm_sccs_00007	},
	{	AA_HTM(C_MSG_SCCS_00008),		c_htm_sccs_00008	},
	{	AA_HTM(C_MSG_SCCS_00009),		c_htm_sccs_00009	},
	{	AA_HTM(C_MSG_SCCS_00010),		c_htm_sccs_00010	},
	{	AA_HTM(C_MSG_SCCS_00011),		c_htm_sccs_00011	},
	{	AA_HTM(C_MSG_SCCS_00012),		c_htm_sccs_00012	},
	{	AA_HTM(C_MSG_SCCS_00013),		c_htm_sccs_00013	},
	/* }}} */
	{	0,							(char **) 0		}
};
/* }}} */
/* c_tab_man[] {{{ */
struct y_desc_msgs		 c_tab_man[] = {
	/* C_MSG_USER {{{ */
	{	AA_MAN(C_MSG_USER_00001),		c_man_users_00001	},
	{	AA_MAN(C_MSG_USER_00013),		c_man_users_00013	},
	{	AA_MAN(C_MSG_USER_00014),		c_man_users_00014	},
	{	AA_MAN(C_MSG_USER_00015),		c_man_users_00015	},
	{	0,							(char **) 0		}
	/* }}} */
};
/* }}} */

/*	Messages of the MAIN module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00000
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_main_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00001[] = {
	"boucle infinie",
	"infinite loop",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00001[] = {
	"boucle infinie",
	"infinite loop",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00002[] = {
	"debug",
	"debug",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00002[] = {
	"debug",
	"debug",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00003[] = {
	"pas de liberation memoire",
	"no memory free",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00003[] = {
	"pas de lib&eacute;ration m&eacute;moire",
	"no memory free",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00004[] = {
	"informations",
	"informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00004[] = {
	"informations",
	"informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00005[] = {
	"affichage des informations memoire",
	"display memory informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00005[] = {
	"affichage des informations m&eacute;moire",
	"display memory informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00006[] = {
	"specification du nombre de boucles",
	"specify number of loops",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00006[] = {
	"specification du nombre de boucles",
	"specify number of loops",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00007[] = {
	"affichage de tailles d'elements",
	"display elements sizes",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00007[] = {
	"affichage de tailles d'&eacute;l&eacute;ments",
	"display elements sizes",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00008[] = {
	"affichage des durees",
	"display times",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00008[] = {
	"affichage des durees",
	"display times",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00009[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00009[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00010[] = {
	"augmentation de la verbosite",
	"verbose",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00010[] = {
	"augmentation de la verbosit&eacute;",
	"verbose",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00011[] = {
	"affichage de la version",
	"display version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00011[] = {
	"affichage de la version",
	"display version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00012[] = {
	"affichage periodique des informations memoire",
	"periodic display of memory informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00012[] = {
	"affichage p&eacute;riodique des informations m&eacute;moire",
	"periodic display of memory informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00013[] = {
	"affichage des groupes definis",
	"display defined groups",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00013[] = {
	"affichage des groupes definis",
	"display defined groups",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00014[] = {
	"affichage de l'origine d'un message",
	"display message source",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00014[] = {
	"affichage de l'origine d'un message",
	"display message source",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00015
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00015[] = {
	"affichage des serveurs d'un groupe",
	"display the servers in a group",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00015[] = {
	"affichage des serveurs d'un groupe",
	"display the servers in a group",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00016
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00016[] = {
	"affichage des temps haute resolution",
	"display high resolution timestamps",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00016[] = {
	"affichage des temps haute resolution",
	"display high resolution timestamps",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00017
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00017[] = {
	"affichage des temps",
	"display timestapms",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00017[] = {
	"affichage des temps",
	"display timestapms",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00018
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00018[] = {
	"affichage des durees (delta T)",
	"display durations (delta T)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00018[] = {
	"affichage des durees (delta T)",
	"display durations (delta T)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00019
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00019[] = {
	"affichage du pathname complet du programme",
	"display programme's full pathname",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00019[] = {
	"affichage du pathname complet du programme",
	"display programme's full pathname",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00020
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00020[] = {
	"affichage du nom reduit du programme",
	"display programme's basename",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00020[] = {
	"affichage du nom reduit du programme",
	"display programme's basename",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00021
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00021[] = {
	"generation de marqueurs pour le chainage des pages (tests)",
	"generate mark-up for page links (tests)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00021[] = {
	"g&eacute;n&eacute;ration de marqueurs pour le cha&icirc;nage des pages (tests)",
	"generate mark-up for page links (tests)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00022
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00022[] = {	/* A REUTILISER */
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_main_00022[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00023
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00023[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00023[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00024
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00024[] = {
	"langue",
	"language",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00024[] = {
	"langue",
	"language",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00025
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00025[] = {
	"Numero de serie du manager",
	"Manager's serial number",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00025[] = {
	"Num&eacute;ro de s&eacute;rie du manager",
	"Manager's serial number",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00026
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00026[] = {
	"Date de lancement",
	"Launch date",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00026[] = {
	"Date de lancement",
	"Launch date",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00027
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00027[] = {
	"Date de generation de rapport",
	"Report generation date",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00027[] = {
	"Date de g&eacute;n&eacute;ration de rapport",
	"Report generation date",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00028
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00028[] = {
	"Date de fin de generation de rapport",
	"End of report generation date",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00028[] = {
	"Date de fin de g&eacute;n&eacute;ration de rapport",
	"End of report generation date",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00029
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00029[] = {
	"affichage du protocole",
	"display protocol",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00029[] = {
	"affichage du protocole",
	"display protocol",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00030
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00030[] = {
	"affichage du PID",
	"display PID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00030[] = {
	"affichage du PID",
	"display PID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00031
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00031[] = {
	"liste des timestamps",
	"list timestamps",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00031[] = {
	"liste des timestamps",
	"list timestamps",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00032
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00032[] = {
	"controle de coherence interne",
	"internal check",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00032[] = {
	"controle de coherence interne",
	"internal check",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00033
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00033[] = {
	"liste des serveurs",
	"list servers",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00033[] = {
	"liste des serveurs",
	"list servers",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00034
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00034[] = {
	"liste des utilisateurs",
	"list users",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00034[] = {
	"liste des utilisateurs",
	"list users",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00035
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00035[] = {
	"liste des pathnames",
	"list pathnames",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00035[] = {
	"liste des pathnames",
	"list pathnames",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00036
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00036[] = {
	"affichage des requetes SQL",
	"display SQL requests",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00036[] = {
	"affichage des requ&ecirc;tes SQL",
	"display SQL requests",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00037
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00037[] = {
	"serveur hebergeant la base de donnees",
	"server hosting the database",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00037[] = {
	"serveur h&eacute;bergeant la base de donn&eacute;es",
	"server hosting the database",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00038
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00038[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00038[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00039
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00039[] = {
	"affichage des insertions d'elements",
	"display elements insertions",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00039[] = {
	"affichage des insertions d'elements",
	"display elements insertions",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00040
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00040[] = {
	"specification d'un module",
	"specify one module",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00040[] = {
	"sp&eacute;cification d'un module",
	"specify one module",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00041
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00041[] = {
	"Recherche de fichiers uniques",
	"Search for unique files",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00041[] = {
	"Recherche de fichiers uniques",
	"Search for unique files",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00042
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00042[] = {
	"Recherche de fichiers dupliques",
	"Search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00042[] = {
	"Recherche de fichiers dupliqu&eacute;s",
	"Search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00043
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00043[] = {
	"Statut collecte",
	"Collect status",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00043[] = {
	"Statut collecte",
	"Collect status",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00044
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00044[] = {
	"Origine",
	"Origin",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00044[] = {
	"Origine",
	"Origin",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00045
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00045[] = {
	"ID timestamp",
	"ID timestamp",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00045[] = {
	"ID timestamp",
	"ID timestamp",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00046
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00046[] = {
	"Serveur",
	"Server",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00046[] = {
	"Serveur",
	"Server",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00047
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00047[] = {
	"Spec ID TS",
	"Spec ID TS",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00047[] = {
	"Spec ID TS",
	"Spec ID TS",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00048
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00048[] = {
	"Params",
	"Params",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00048[] = {
	"Params",
	"Params",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00049
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00049[] = {
	"Nombre d'elements",
	"Number of elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00049[] = {
	"Nombre d'&eacute;l&eacute;ments",
	"Number of elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00050
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00050[] = {
	"Nombre d'informations",
	"Number of informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00050[] = {
	"Nombre d'informations",
	"Number of informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00051
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00051[] = {
	"Label",
	"Label",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00051[] = {
	"Label",
	"Label",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00052
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00052[] = {
	"Recherche de fichiers dupliques",
	"Search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00052[] = {
	"Recherche de fichiers dupliqu&eacute;s",
	"Search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00053
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00053[] = {
	"Recherche d'utilisateurs dupliques",
	"Search for duplicate users",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00053[] = {
	"Recherche d'utilisateurs dupliqu&eacute;s",
	"Search for duplicate users",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00054
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00054[] = {
	"Recherche de RPM dupliques",
	"Search for duplicate RPM",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00054[] = {
	"Recherche de RPM dupliqu&eacute;s",
	"Search for duplicate RPM",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00055
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00055[] = {
	"redirection de stderr vers le fichier de log",
	"redirection of stderr to the log file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00055[] = {
	"Redirection de stderr vers le fichier de log",
	"Redirection of stderr to the log file",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00056
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00056[] = {
	"liste des RPM",
	"list RPM",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00056[] = {
	"liste des RPM",
	"list RPM",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00057
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00057[] = {
	"nom de la base de donnees",
	"database name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00057[] = {
	"nom de la base de donn&eacute;es",
	"database name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00058
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00058[] = {
	"trace des analyseurs lexicaux",
	"trace lexical analyzers",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00058[] = {
	"trace des analyseurs lexicaux",
	"trace lexical analyzers",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00059
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00059[] = {
	"trace des analyseurs grammaticaux",
	"trace parsers",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00059[] = {
	"trace des analyseurs grammaticaux",
	"trace parsers",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00060
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00060[] = {
	"K: trace des fonctions",
	"K: trace functions",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00060[] = {
	"K: trace des fonctions",
	"K: trace functions",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00061
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00061[] = {
	"K: trace des contextes",
	"K: trace contexts",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00061[] = {
	"K: trace des contextes",
	"K: trace contexts",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00062
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00062[] = {
	"K: trace des lectures",
	"K: trace read",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00062[] = {
	"K: trace des lectures",
	"K: trace read",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00063
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00063[] = {
	"K: trace des ecritures",
	"K: trace write",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00063[] = {
	"K: trace des &eacute;critures",
	"K: trace write",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00064
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00064[] = {
	"K: trace des types/longueurs",
	"K: trace types/lengths",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00064[] = {
	"K: trace des types/longueurs",
	"K: trace types/lengths",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00065
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00065[] = {
	"K: trace des valeurs",
	"K: trace values",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00065[] = {
	"K: trace des valeurs",
	"K: trace values",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00066
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00066[] = {
	"K: trace dump",
	"K: trace dump",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00066[] = {
	"K: trace dump",
	"K: trace dump",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00067
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00067[] = {
	"gestion des groupes de serveurs",
	"servers groups management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00067[] = {
	"gestion des groupes de serveurs",
	"servers groups management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00068
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00068[] = {
	"gestion des couleurs",
	"colours management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00068[] = {
	"gestion des couleurs",
	"colours management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00069
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00069[] = {
	"gestion des noms de sources",
	"source names management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00069[] = {
	"gestion des noms de sources",
	"source names management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00070
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00070[] = {
	"gestion des groupes de serveurs",
	"servers groups management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00070[] = {
	"gestion des groupes de serveurs",
	"servers groups management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00071
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00071[] = {
	"gestion des couleurs",
	"colours management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00071[] = {
	"gestion des couleurs",
	"colours management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00072
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00072[] = {
	"gestion des noms de sources",
	"source names management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00072[] = {
	"gestion des noms de sources",
	"source names management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00073
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00073[] = {
	"activation de traces",
	"trace activation",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00073[] = {
	"activation de traces",
	"trace activation",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00074
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00074[] = {
	"affichage des options correspondant aux infos",
	"display options corresponding to informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00074[] = {
	"affichage des options correspondant aux infos",
	"display options corresponding to informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00075
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00075[] = {
	"affichage de toutes les options",
	"display all options",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00075[] = {
	"affichage de toutes les options",
	"display all options",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00076
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00076[] = {
	"affichage des options non implementees",
	"display unimplemented options",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00076[] = {
	"affichage des options non implement&eacute;es",
	"display unimplemented options",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00077
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00077[] = {
	"trace des operations sur les mutex",
	"trace mutex operations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00077[] = {
	"trace des op&eacute;rations sur les mutex",
	"trace mutex operations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00078
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00078[] = {
	"affichage du TID (Thread ID)",
	"display TID (Thread ID)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00078[] = {
	"affichage du TID (Thread ID)",
	"display TID (Thread ID)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00079
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00079[] = {
	"Version du manager",
	"Manager's version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00079[] = {
	"Version du manager",
	"Manager's version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00080
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00080[] = {
	"trace du decodage des options",
	"trace options parsing",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00080[] = {
	"trace du d&eacute;codage des options",
	"trace options parsing",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00081
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00081[] = {
	"affichage des configurations d'options",
	"display options configurations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00081[] = {
	"affichage des configurations d'options",
	"display options configurations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00082
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00082[] = {
	"gestion du fichier de configuration",
	"configuration file management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00082[] = {
	"gestion du fichier de configuration",
	"configuration file management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00083
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00083[] = {
	"gestion du fichier de configuration",
	"configuration file management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00083[] = {
	"gestion du fichier de configuration",
	"configuration file management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00084
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00084[] = {
	"options de log",
	"log options",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00084[] = {
	"options de log",
	"log options",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00085
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00085[] = {
	"affichage de tables de la base de donnees",
	"display tables of the database",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00085[] = {
	"affichage de tables de la base de donn&eacute;es",
	"display tables of the database",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00086
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00086[] = {
	"visualisation des liberations memoire",
	"show memory free",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00086[] = {
	"visualisation des lib&eacute;rations m&eacute;moire",
	"show memory free",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00087
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00087[] = {
	"affichage de messages de debug (commentaires)",
	"display debug messages (comments)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00087[] = {
	"affichage de messages de debug (commentaires)",
	"display debug messages (comments)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00088
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00088[] = {
	"liste des paquets Debian",
	"list Debian packages",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00088[] = {
	"liste des paquets Debian",
	"list Debian packages",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00089
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00089[] = {
	"Commande lancee",
	"Executed command",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00089[] = {
	"Commande lanc&eacute;e",
	"Executed command",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00090
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00090[] = {
	"pas de generation de logs",
	"do not generate logs",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00090[] = {
	"pas de g&eacute;n&eacute;ration de logs",
	"do not generate logs",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00091
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00091[] = {
	"variations en pourcentage",
	"percent delta",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00091[] = {
	"variations en pourcentage",
	"percent delta",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00092
 *	~~~~~~~~~~~~~ */
char					*c_msg_main_00092[] = {
	"affichage des deltas dans la synthese",
	"display delta in the synthesis",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_main_00092[] = {
	"affichage des deltas dans la synth&egrave;se",
	"display delta in the synthesis",
	"??? (Deutsch)",
	(char *) 0
};

/* }}} */
/*	Common messages {{{
 *	~~~~~~~~~~~~~~~ */

/*	Message 00000
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00001[] = {
	"stockage des infos collectees en base de donnees",
	"store collected informations in a database",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00001[] = {
	"stockage des infos collect&eacute;es en base de donn&eacute;es",
	"store collected informations in a database",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00002[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00002[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00003[] = {
	"reference (ajout)",
	"reference (add)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00003[] = {
	"r&eacute;f&eacute;rence (ajout)",
	"reference (add)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00004[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00004[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00005[] = {
	"titre des pages de resultats",
	"results page title",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00005[] = {
	"titre des pages de r&eacute;sultats",
	"results page title",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00006[] = {
	"Serveur",
	"Server",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00006[] = {
	"Serveur",
	"Server",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00007[] = {
	"Origine",
	"Origin",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00007[] = {
	"Origine",
	"Origin",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00008[] = {
	"Statut collecte",
	"Collect status",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00008[] = {
	"Statut collecte",
	"Collect status",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00009[] = {
	"Timestamp",
	"Timestamp",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00009[] = {
	"Timestamp",
	"Timestamp",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00010[] = {
	"ID Timestamp",
	"ID Timestamp",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00010[] = {
	"ID Timestamp",
	"ID Timestamp",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00011[] = {
	"Parametres",
	"Parameters",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00011[] = {
	"Param&egrave;tres",
	"Parameters",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00012[] = {
	"Nombre d'elements",
	"Number of elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00012[] = {
	"Nombre d'&eacute;l&eacute;ments",
	"Number of elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00013[] = {
	"Nombre d'informations",
	"Number of informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00013[] = {
	"Nombre d'informations",
	"Number of informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00014[] = {
	"DB label",
	"DB label",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00014[] = {
	"DB label",
	"DB label",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00015
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00015[] = {
	"Version agent",
	"Agent version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00015[] = {
	"Version agent",
	"Agent version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00016
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00016[] = {
	"Serial agent",
	"Agent serial",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00016[] = {
	"Serial agent",
	"Agent serial",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00017
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00017[] = {
	"Duree de collecte",
	"Collect duration",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00017[] = {
	"Dur&eacute;e de collecte",
	"Collect duration",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00018
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00018[] = {
	"Elements supplementaires",
	"Additional elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00018[] = {
	"El&eacute;ments suppl&eacute;mentaires",
	"Additional elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00019
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00019[] = {
	"Elements manquants",
	"Missing elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00019[] = {
	"El&eacute;ments manquants",
	"Missing elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00020
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00020[] = {
	"Elements modifies",
	"Modified elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00020[] = {
	"El&eacute;ments modifi&eacute;s",
	"Modified elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00021
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00021[] = {
	"Infos modifiees",
	"Modified informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00021[] = {
	"Infos modifi&eacute;es",
	"Modified informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00022
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00022[] = {
	"Source",
	"Source",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00022[] = {
	"Source",
	"Source",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00023
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00023[] = {
	"Version manager",
	"Manager version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00023[] = {
	"Version manager",
	"Manager version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00024
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00024[] = {
	"Serial manager",
	"Manager serial",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00024[] = {
	"Serial manager",
	"Manager serial",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00025
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00025[] = {
	"Serveur de base de donnees",
	"Database host",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00025[] = {
	"Serveur de base de donn&eacute;es",
	"Database host",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00026
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00026[] = {
	"Nom de la base",
	"Database name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00026[] = {
	"Nom de la base",
	"Database name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00027
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00027[] = {
	"specification d'un nom associe a une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00027[] = {
	"sp&eacute;cification d'un nom associ&eacute; &agrave; une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00028
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00028[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00028[] = {
	"pas de g&eacute;n&eacute;ration d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00029
 *	~~~~~~~~~~~~~ */
char					*c_msg_common_00029[] = {
	"configuration",
	"configuration",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_common_00029[] = {
	"configuration",
	"configuration",
	"??? (Deutsch)",
	(char *) 0
};

/* }}} */
/*	Messages of the USERS module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00000
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_users_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_man_users_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00002[] = {
	"mot de passe",
	"password",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00002[] = {
	"mot de passe",
	"password",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00003[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00003[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00004[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00004[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00005[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00005[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00006[] = {
	"repertoire d'accueil",
	"home directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00006[] = {
	"r&eacute;pertoire d'accueil",
	"home directory",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00007[] = {
	"interpreteur de commandes",
	"shell",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00007[] = {
	"interpreteur de commandes",
	"shell",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00008[] = {
	"selection de numero(s) d'utilisateur(s)",
	"select specific user IDs",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00008[] = {
	"selection de numero(s) d'utilisateur(s)",
	"select specific user IDs",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00009[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00009[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00010[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00010[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00011[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00011[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00012[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00012[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00013[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00013[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_man_users_00013[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00014[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00014[] = {
	"affichage de tous les &eacute;l&eacute;ments si incoh&eacute;rence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_man_users_00014[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00015
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00015[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00015[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_man_users_00015[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00016
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00016[] = {	/* A REUTILISER */
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_users_00016[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00017
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00017[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00017[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00018
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00018[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00018[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00019
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00019[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00019[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00020
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00020[] = {
	"recherche d'utilisateurs uniques",
	"search for uniq users",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00020[] = {
	"recherche d'utilisateurs uniques",
	"search for uniq users",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00021
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00021[] = {
	"recherche d'utilisateurs dupliques",
	"search for duplicate users",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00021[] = {
	"recherche d'utilisateurs dupliqu&eacute;s",
	"search for duplicate users",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00022
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00022[] = {
	"specification d'un nom associe a une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00022[] = {
	"sp&eacute;cification d'un nom associ&eacute; &agrave; une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00023
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00023[] = {
	"affichage du nom d'utilisateur",
	"display username",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00023[] = {
	"affichage du nom d'utilisateur",
	"display username",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00024
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00024[] = {
	"affichage du mot de passe chiffre",
	"display encrypted passwd",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00024[] = {
	"affichage du mot de passe chiffr&eacute;",
	"display encrypted passwd",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00025
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00025[] = {
	"affichage du UID",
	"display UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00025[] = {
	"affichage du UID",
	"display UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00026
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00026[] = {
	"affichage du GID",
	"display UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00026[] = {
	"affichage du GID",
	"display UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00027
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00027[] = {
	"affichage du commentaire",
	"display comment",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00027[] = {
	"affichage du commentaire",
	"display comment",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00028
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00028[] = {
	"affichage du home directory",
	"display home directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00028[] = {
	"affichage du home directory",
	"display home directory",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00029
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00029[] = {
	"affichage du shell",
	"display shell",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00029[] = {
	"affichage du shell",
	"display shell",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00030
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00030[] = {
	"controle de /etc/passwd",
	"check /etc/passwd",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00030[] = {
	"contr&ocirc;le de /etc/passwd",
	"check /etc/passwd",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00031
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00031[] = {
	"controle de /etc/group",
	"check /etc/group",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00031[] = {
	"contr&ocirc;le de /etc/group",
	"check /etc/group",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00032
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00032[] = {
	"controle de /etc/shadow",
	"check /etc/shadow",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00032[] = {
	"contr&ocirc;le de /etc/shadow",
	"check /etc/shadow",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00033
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00033[] = {
	"nom d'utilisateur",
	"username",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00033[] = {
	"nom d'utilisateur",
	"username",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00034
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00034[] = {
	"Utilisateurs",
	"Users",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00034[] = {
	"Utilisateurs",
	"Users",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00035
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00035[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00035[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00036
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00036[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00036[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00037
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00037[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00037[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00038
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00038[] = {
	"home directory",
	"home directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00038[] = {
	"home directory",
	"home directory",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00039
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00039[] = {
	"shell",
	"shell",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00039[] = {
	"shell",
	"shell",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00040
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00040[] = {
	"nom de groupe",
	"groupname",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00040[] = {
	"nom de groupe",
	"groupname",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00041
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00041[] = {
	"mot de passe chiffre du groupe",
	"group's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00041[] = {
	"mot de passe chiffr&eacute; du groupe",
	"group's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00042
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00042[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00042[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00043
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00043[] = {
	"membres du groupe",
	"group members",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00043[] = {
	"membres du groupe",
	"group members",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00044
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00044[] = {
	"nom de l'utilisateur",
	"username",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00044[] = {
	"nom de l'utilisateur",
	"username",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00045
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00045[] = {
	"mot de passe chiffre de l'utilisateur",
	"user's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00045[] = {
	"mot de passe chiffr&eacute; de l'utilisateur",
	"user's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00046
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00046[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00046[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00047
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00047[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00047[] = {
	"GID",
	"GID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00048
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00048[] = {
	"date de dernier changement du mot de passe (depuis 01-01-1970)",
	"days since Jan 1, 1970 that password was last changed",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00048[] = {
	"date de dernier changement du mot de passe (depuis 01-01-1970)",
	"days since Jan 1, 1970 that password was last changed",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00049
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00049[] = {
	"nombre de jours avant de pouvoir changer le mot de passe",
	"days before password may be changed ",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00049[] = {
	"nombre de jours avant de pouvoir changer le mot de passe",
	"days before password may be changed ",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00050
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00050[] = {
	"nombre de jours avant obligation de changer le mot de passe",
	"days after which password must be changed",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00050[] = {
	"nombre de jours avant obligation de changer le mot de passe",
	"days after which password must be changed",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00051
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00051[] = {
	"nombre de jours pour prevenir l'utilisateur avant expiration",
	"days before password is to expire that user is warned",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00051[] = {
	"nombre de jours pour pr&eacute;v&eacute;nir l'utilisateur avant expiration",
	"days before password is to expire that user is warned",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00052
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00052[] = {
	"nombre de jours apres lequel un compte expire est desactive",
	"days after password expires that account is disabled",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00052[] = {
	"nombre de jours apr&egrave;s lequel un compte expir&eacute; est d&eacute;sactiv&eacute;",
	"days after password expires that account is disabled",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00053
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00053[] = {
	"date de desactivation du compte (depuis le 01-01-1970)",
	"days since Jan 1, 1970 that account is disabled",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00053[] = {
	"date de desactivation du compte (depuis le 01-01-1970)",
	"days since Jan 1, 1970 that account is disabled",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00054
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00054[] = {
	"mot de passe chiffre de l'utilisateur",
	"user's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00054[] = {
	"mot de passe chiffr&eacute; de l'utilisateur",
	"user's encrypted password",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00055
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00055[] = {
	"champ reserve",
	"reserved field",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00055[] = {
	"champ r&eacute;serv&eacute;",
	"reserved field",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00056
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00056[] = {
	"nom d'utilisateur",
	"user name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00056[] = {
	"nom d'utilisateur",
	"user name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00057
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00057[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00057[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00058
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00058[] = {
	"nom d'utilisateur",
	"user name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00058[] = {
	"nom d'utilisateur",
	"user name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00059
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00059[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00059[] = {
	"UID",
	"UID",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00060
 *	~~~~~~~~~~~~~ */
char					*c_msg_users_00060[] = {
	"affichage des deltas numeriques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_users_00060[] = {
	"affichage des deltas num&eacute;riques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};
/* }}} */
/*	Messages of the FS module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00000
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_fs_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00002[] = {
	"recuperation des attributs des repertoires",
	"get directories attributes",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00002[] = {
	"r&eacute;cup&eacute;ration des attributs des r&eacute;pertoires",
	"get directories attributes",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00003[] = {
	"dev",
	"dev",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00003[] = {
	"dev",
	"dev",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00004[] = {
	"inode",
	"inode",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00004[] = {
	"inode",
	"inode",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00005[] = {
	"mode",
	"mode",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00005[] = {
	"mode",
	"mode",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00006[] = {
	"nlink",
	"nlink",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00006[] = {
	"nlink",
	"nlink",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00007[] = {
	"uid",
	"uid",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00007[] = {
	"uid",
	"uid",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00008[] = {
	"gid",
	"gid",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00008[] = {
	"gid",
	"gid",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00009[] = {
	"rdev",
	"rdev",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00009[] = {
	"rdev",
	"rdev",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00010[] = {
	"size",
	"size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00010[] = {
	"size",
	"size",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00011[] = {
	"blksize",
	"blksize",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00011[] = {
	"blksize",
	"blksize",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00012[] = {
	"blocks",
	"blocks",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00012[] = {
	"blocks",
	"blocks",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00013[] = {
	"access time",
	"access time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00013[] = {
	"access time",
	"access time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00014[] = {
	"modification time",
	"modification time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00014[] = {
	"modification time",
	"modification time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00015
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00015[] = {
	"inode change time",
	"inode change time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00015[] = {
	"inode change time",
	"inode change time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00016
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00016[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00016[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00017
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00017[] = {
	"checksum MD5",
	"checksum MD5",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00017[] = {
	"checksum MD5",
	"checksum MD5",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00018
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00018[] = {
	"checksum SHA1",
	"checksum SHA1",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00018[] = {
	"checksum SHA1",
	"checksum SHA1",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00019
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00019[] = {
	"checksum SHA256",
	"checksum SHA256",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00019[] = {
	"checksum SHA256",
	"checksum SHA256",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00020
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00020[] = {
	"checksum SHA512",
	"checksum SHA512",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00020[] = {
	"checksum SHA512",
	"checksum SHA512",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00021
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00021[] = {
	"groupe(s) de serveur(s)",
	"servers group",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00021[] = {
	"groupe(s) de serveur(s)",
	"servers group",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00022
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00022[] = {
	"pathname",
	"pathname",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00022[] = {
	"pathname",
	"pathname",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00023
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00023[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00023[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00024
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00024[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00024[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00025
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00025[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00025[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00026
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00026[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00026[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00027
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00027[] = {
	"retablissement du mode",
	"set mode",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00027[] = {
	"retablissement du mode",
	"set mode",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00028
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00028[] = {
	"retablissement du proprietaire",
	"set owner",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00028[] = {
	"retablissement du proprietaire",
	"set owner",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00029
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00029[] = {
	"retablissement du groupe",
	"set group",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00029[] = {
	"retablissement du groupe",
	"set group",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00030
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00030[] = {
	"retablissement de la date d'acces",
	"set access time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00030[] = {
	"retablissement de la date d'acces",
	"set access time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00031
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00031[] = {
	"retablissement de la date de modification",
	"set modification time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00031[] = {
	"retablissement de la date de modification",
	"set modification time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00032
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00032[] = {
	"retablissement de la date de modification d'i-node",
	"set i-node modification time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00032[] = {
	"retablissement de modification",
	"set i-node modification time",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00033
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00033[] = {
	"retablissement des dates",
	"set dates",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00033[] = {
	"retablissement des dates",
	"set dates",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00034
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00034[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00034[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00035
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00035[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00035[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00036
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00036[] = {
	"type de fichier",
	"filetype",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00036[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00037
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00037[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00037[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00038
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00038[] = {
	"checksum SHA224",
	"checksum SHA224",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00038[] = {
	"checksum SHA224",
	"checksum SHA224",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00039
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00039[] = {
	"checksum SHA384",
	"checksum SHA384",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00039[] = {
	"checksum SHA384",
	"checksum SHA384",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00040
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00040[] = {	/* A REUTILISER */
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00040[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00041
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00041[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00041[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00042
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00042[] = {
	"Systemes de fichiers",
	"Filesystems",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00042[] = {
	"Syst&egrave;mes de fichiers",
	"Filesystems",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00043
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00043[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00043[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00044
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00044[] = {
	"nombre de fichiers dans le repertoire",
	"number of files in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00044[] = {
	"nombre de fichiers dans le r&eacute;pertoire",
	"number of files in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00045
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00045[] = {
	"nombre de repertoires dans le repertoire",
	"number of directories in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00045[] = {
	"nombre de r&eacute;pertoires dans le r&eacute;pertoire",
	"number of directories in the directory",
	"??? (Deutsch)",
	(char *) 0
};



/*	Message 00046
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00046[] = {
	"nombre de FIFOs dans le repertoire",
	"number of FIFO in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00046[] = {
	"nombre de FIFOs dans le repertoire",
	"number of FIFO in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00047
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00047[] = {
	"nombre de character devices dans le repertoire",
	"number of character devices in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00047[] = {
	"nombre de character devices dans le repertoire",
	"number of character devices in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00048
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00048[] = {
	"nombre de block devices dans le repertoire",
	"number of block devices in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00048[] = {
	"nombre de block devices dans le repertoire",
	"number of block devices in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00049
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00049[] = {
	"nombre de liens symboliques dans le repertoire",
	"number of symbolic links in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00049[] = {
	"nombre de liens symboliques dans le r&eacute;pertoire",
	"number of symbolic links in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00050
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00050[] = {
	"nombre de sockets dans le repertoire",
	"number of sockets in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00050[] = {
	"nombre de sockets dans le repertoire",
	"number of sockets in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00051
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00051[] = {
	"nombre de fichiers de type inconnu dans le repertoire",
	"number of unknown tyep files in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00051[] = {
	"nombre de fichiers de type inconnu dans le repertoire",
	"number of unknown tyep files in the directory",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00052
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00052[] = {
	"nombre de fichiers dans l'arborescence",
	"number of files in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00052[] = {
	"nombre de fichiers dans l'arborescence",
	"number of files in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00053
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00053[] = {
	"nombre de repertoires dans l'arborescence",
	"number of directories in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00053[] = {
	"nombre de repertoires dans l'arborescence",
	"number of directories in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00054
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00054[] = {
	"nombre de FIFOs dans l'arborescence",
	"number of FIFO in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00054[] = {
	"nombre de FIFOs dans l'arborescence",
	"number of FIFO in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00055
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00055[] = {
	"nombre de character devices dans l'arborescence",
	"number of character devices in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00055[] = {
	"nombre de character devices dans l'arborescence",
	"number of character devices in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00056
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00056[] = {
	"nombre de block devices dans l'arborescence",
	"number of block devices in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00056[] = {
	"nombre de block devices dans l'arborescence",
	"number of block devices in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00057
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00057[] = {
	"nombre de liens symboliques dans l'arborescence",
	"number of symbolic links in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00057[] = {
	"nombre de liens symboliques dans l'arborescence",
	"number of symbolic links in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00058
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00058[] = {
	"nombre de sockets dans l'arborescence",
	"number of sockets in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00058[] = {
	"nombre de sockets dans l'arborescence",
	"number of sockets in the file tree",
	"??? (Deutsch)",
	(char *) 0
};


/*	Message 00059
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00059[] = {
	"nombre de fichiers de type inconnu dans l'arborescence",
	"number of unknown tyep files in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00059[] = {
	"nombre de fichiers de type inconnu dans l'arborescence",
	"number of unknown tyep files in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00060
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00060[] = {
	"nombre de blocs de donnees dans le repertoire",
	"number of data blocks in the directory",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00060[] = {
	"nombre de blocs de donn&eacute;es dans le r&eacute;pertoire",
	"number of data blocks in the directory",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00061
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00061[] = {
	"nombre de blocs de donnees dans l'arborescence",
	"number of data blocks in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00061[] = {
	"nombre de blocs de donn&eacute;es dans l'arborescence",
	"number of data blocks in the file tree",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00062
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00062[] = {
	"nom du proprietaire",
	"owner name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00062[] = {
	"nom du propri&eacute;taire",
	"owner name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00063
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00063[] = {
	"nom du groupe proprietaire",
	"group owner name",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00063[] = {
	"nom du groupe propri&eacute;taire",
	"group owner name",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00064
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00064[] = {
	"checksum BSD",
	"checksum BSD",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00064[] = {
	"checksum BSD",
	"checksum BSD",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00065
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00065[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00065[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00066
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00066[] = {
	"recherche de fichiers uniques",
	"search for uniq files",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00066[] = {
	"recherche de fichiers uniques",
	"search for uniq files",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00067
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00067[] = {
	"recherche de fichiers dupliques",
	"search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00067[] = {
	"recherche de fichiers dupliqu&eacute;s",
	"search for duplicate files",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00068
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00068[] = {
	"specification d'un nom associe a une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00068[] = {
	"sp&eacute;cification d'un nom associ&eacute; &agrave; une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00069
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00069[] = {
	"pas de parcours d'arborescence en cas de changement de filesystem",
	"don't descend directories on other filesystem",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00069[] = {
	"pas de parcours d'arborescence en cas de changement de filesystem",
	"don't descend directories on other filesystem",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00070
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00070[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00070[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00071
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00071[] = {
	"pas de taille des repertoires",
	"no directory size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00071[] = {
	"pas de taille des r&eacute;pertoires",
	"no directory size",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00072
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00072[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00072[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00073
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00073[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00073[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00074
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00074[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00074[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00075
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00075[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00075[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00076
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00076[] = {
	"niveau de profondeur",
	"depth level",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00076[] = {
	"niveau de profondeur",
	"depth level",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00077
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00077[] = {
	"basename du fichier",
	"file basename",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00077[] = {
	"basename du fichier",
	"file basename",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00078
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00078[] = {
	"checksum BSD",
	"BSD checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00078[] = {
	"checksum BSD",
	"BSD checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00079
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00079[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00079[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00080
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00080[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00080[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00081
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00081[] = {
	"pathname relatif",
	"relative pathname",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00081[] = {
	"pathname relatif",
	"relative pathname",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00082
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00082[] = {
	"taille du fichier",
	"file size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00082[] = {
	"taille du fichier",
	"file size",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00083
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00083[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00083[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00084
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00084[] = {
	"checksum MD5",
	"MD5 checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00084[] = {
	"checksum MD5",
	"MD5 checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00085
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00085[] = {
	"numero d'i-node",
	"i-node number",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00085[] = {
	"num&eacute;ro d'i-node",
	"i-node number",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00086
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00086[] = {
	"type du fichier",
	"filetype",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00086[] = {
	"type du fichier",
	"filetype",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00087
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00087[] = {
	"affichage des deltas numeriques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00087[] = {
	"affichage des deltas num&eacute;riques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00088
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00088[] = {
	"pas d'affichage implicite des informations",
	"no implicit display of informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00088[] = {
	"pas d'affichage implicite des informations",
	"no implicit display of informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00089
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00089[] = {
	"attributs",
	"attributes",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00089[] = {
	"attributs",
	"attributes",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00090
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00090[] = {
	"prise en compte des liens hard",
	"take hard links into account",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00090[] = {
	"prise en compte des liens hard",
	"take hard links into account",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00091
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00091[] = {
	"activation du debug de l'agent",
	"activate agent debug",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00091[] = {
	"activation du debug de l'agent",
	"activate agent debug",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00092
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00092[] = {
	"gestion du mode debug",
	"debug mode management",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00092[] = {
	"gestion du mode debug",
	"debug mode management",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00093
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00093[] = {
	"separation des nombres en groupes de 3 chiffres",
	"3 digits grouping",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00093[] = {
	"s&eacute;paration des nombres en groupes de 3 chiffres",
	"3 digits grouping",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00094
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00094[] = {
	"reorganisation par rapport a l'arborescence de reference",
	"reorganize occording to reference tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00094[] = {
	"r&eacute;organisation par rapport &agrave; l'arborescence de r&eacute;f&eacute;rence",
	"reorganize occording to reference tree",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00095
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00095[] = {
	"recherche de fichiers presents sur une seule source",
	"search for files localized on only one source",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00095[] = {
	"recherche de fichiers pr&eacute;sents sur une seule source",
	"search for files localized on only one source",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00096
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00096[] = {
	"recherche de fichiers absents de la (des) reference(s)",
	"search for files not localized on any reference tree",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00096[] = {
	"recherche de fichiers absents de la (des) r&eacute;f&eacute;rence(s)",
	"search for files not localized on any reference tree",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00097
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00097[] = {
	"specification de source en base de donnees pour collecte optimisee",
	"specification of a database source for an optimized collect",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00097[] = {
	"sp&eacute;cification de source en base de donn&eacute;es pour collecte optimis&eacute;e",
	"specification of a database source for an optimized collect",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00098
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00098[] = {
	"pathname relatif",
	"relative pathname",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00098[] = {
	"pathname relatif",
	"relative pathname",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00099
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00099[] = {
	"type du fichier",
	"filetype",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00099[] = {
	"type du fichier",
	"filetype",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00100
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00100[] = {
	"prise en compte des liens hard",
	"take hard links into account",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00100[] = {
	"prise en compte des liens hard",
	"take hard links into account",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00101
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00101[] = {
	"numero d'i-node",
	"i-node number",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00101[] = {
	"num&eacute;ro d'i-node",
	"i-node number",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00102
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00102[] = {
	"taille du fichier",
	"file size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00102[] = {
	"taille du fichier",
	"file size",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00103
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00103[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00103[] = {
	"checksum",
	"checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00104
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00104[] = {
	"checksum BSD",
	"BSD checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00104[] = {
	"checksum BSD",
	"BSD checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00105
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00105[] = {
	"checksum MD5",
	"MD5 checksum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00105[] = {
	"checksum MD5",
	"MD5 checksum",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00106
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00106[] = {
	"checksum SHA256",
	"checksum SHA256",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00106[] = {
	"checksum SHA256",
	"checksum SHA256",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00107
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00107[] = {
	"localisation de fichiers",
	"files locate",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00107[] = {
	"localisation de fichiers",
	"files locate",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00108
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00108[] = {
	"source de base",
	"base source",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00108[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00109
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00109[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00109[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00110
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00110[] = {
	"pas de traitement des repertoires",
	"no retrieval of directory attributes",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00110[] = {
	"pas de traitement des r&eacute;pertoires",
	"no retrieval of directory attributes",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00111
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00111[] = {
	"scan rapide",
	"quick scan",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00111[] = {
	"scan rapide",
	"quick scan",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00112
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00112[] = {
	"ignorer les fichiers correspondant a la regex",
	"ignore files matching the regex",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00112[] = {
	"ignorer les fichiers correspondant a la regex",
	"ignore files matching the regex",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00113
 *	~~~~~~~~~~~~~ */
char					*c_msg_fs_00113[] = {
	"selectionner les fichiers correspondant a la regex",
	"select files matching the regex",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_fs_00113[] = {
	"selectionner les fichiers correspondant a la regex",
	"select files matching the regex",
	"??? (Deutsch)",
	(char *) 0
};

/* }}} */
/*	Messages of the RPM module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00000
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_rpm_00000[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00001[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00002[] = {
	"version du RPM",
	"RPM version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00002[] = {
	"version du RPM",
	"RPM version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00003[] = {
	"release du RPM",
	"RPM release",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00003[] = {
	"release du RPM",
	"RPM release",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00004[] = {
	"date d'installation",
	"installation date",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00004[] = {
	"date d'installation",
	"installation date",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00005[] = {
	"groupe du RPM",
	"RPM group",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00005[] = {
	"groupe du RPM",
	"RPM group",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00006[] = {
	"taille du RPM",
	"RPM size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00006[] = {
	"taille du RPM",
	"RPM size",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00007[] = {
	"relocations",
	"relocations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00007[] = {
	"relocations",
	"relocations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00008[] = {
	"vendeur",
	"vendor",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00008[] = {
	"vendeur",
	"vendor",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00009[] = {
	"date de construction",
	"build date",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00009[] = {
	"date de construction",
	"build date",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00010[] = {
	"serveur de construction du RPM",
	"build host",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00010[] = {
	"serveur de construction du RPM",
	"build host",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00011[] = {
	"relocations",
	"relocations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00011[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00012[] = {
	"RPM source",
	"source RPM",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00012[] = {
	"RPM source",
	"source RPM",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00013[] = {
	"licence",
	"license",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00013[] = {
	"licence",
	"license",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00014[] = {
	"signature",
	"signature",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00014[] = {
	"signature",
	"signature",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00015
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00015[] = {
	"resume",
	"summary",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00015[] = {
	"resume",
	"summary",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00016
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00016[] = {
	"description",
	"description",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00016[] = {
	"description",
	"description",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00017
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00017[] = {
	"architecture",
	"architecture",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00017[] = {
	"architecture",
	"architecture",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00018
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00018[] = {
	"dirnames",
	"dirnames",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00018[] = {
	"dirnames",
	"dirnames",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00019
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00019[] = {
	"dates de modification des fichiers",
	"files modification times",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00019[] = {
	"dates de modification des fichiers",
	"files modification times",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00020
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00020[] = {
	"nom du proprietaire des fichiers",
	"files owner",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00020[] = {
	"nom du proprietaire des fichiers",
	"files owner",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00021
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00021[] = {
	"nom du groupe proprietaire des fichiers",
	"files group owner",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00021[] = {
	"nom du groupe proprietaire des fichiers",
	"files group owner",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00022
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00022[] = {
	"version de RPM utilise pour la construction du package",
	"version of RPM used to build the package",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00022[] = {
	"version de RPM utilis&eacute; pour la construction du package",
	"version of RPM used to build the package",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00023
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00023[] = {
	"distribution",
	"distribution",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00023[] = {
	"distribution",
	"distribution",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00024
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00024[] = {
	"options de generation",
	"options flags",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00024[] = {
	"options de generation",
	"options flags",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00025
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00025[] = {
	"createur du package",
	"package creator",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00025[] = {
	"cr&eacute;ateur du package",
	"package creator",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00026
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00026[] = {
	"en-tete SHA1",
	"SHA1 header",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00026[] = {
	"en-t&ecirc;te SHA1",
	"SHA1 header",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00027
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00027[] = {
	"signature MD5",
	"MD5 signature",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00027[] = {
	"signature MD5",
	"MD5 signature",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00028
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00028[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00028[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00029
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00029[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00029[] = {
	"groupe(s) de serveurs",
	"servers group(s) name(s)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00030
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00030[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00030[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00031
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00031[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00031[] = {
	"reference (remplacement)",
	"reference (replace)",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00032
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00032[] = {
	"trace lex",
	"trace lex",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00032[] = {
	"trace yacc",
	"trace yacc",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00033
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00033[] = {
	"trace yacc",
	"trace yacc",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00033[] = {
	"trace yacc",
	"trace yacc",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00034
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00034[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00034[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00035
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00035[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00035[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00036
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00036[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00036[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00037
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00037[] = {	/* A REUTILISER */
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

char					*c_htm_rpm_00037[] = {
	"[01;31m*** A INITIALISER ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"[01;31m*** A INITIALISER ***[0m",
	(char *) 0
};

/*	Message 00038
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00038[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00038[] = {
	"pas de generation d'affichage",
	"no display",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00039
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00039[] = {
	"Paquets RPM installes",
	"Installed RPM packages",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00039[] = {
	"Paquets RPM install&eacute;s",
	"Installed RPM packages",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00040
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00040[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00040[] = {
	"liste les elements",
	"list elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00041
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00041[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00041[] = {
	"affichage de la liste des collectes",
	"display collects list",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00042
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00042[] = {
	"recherche de RPM uniques",
	"search for uniq RPM",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00042[] = {
	"recherche de RPM uniques",
	"search for uniq RPM",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00043
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00043[] = {
	"specification d'un nom associe a une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00043[] = {
	"sp&eacute;cification d'un nom associ&eacute; &agrave; une collecte",
	"associate a name to a collect",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00044
 *	~~~~~~~~~~~~~ */
char					*c_msg_rpm_00044[] = {
	"affichage des deltas numeriques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_rpm_00044[] = {
	"affichage des deltas num&eacute;riques",
	"display numeric deltas",
	"??? (Deutsch)",
	(char *) 0
};
/* }}} */
/*	Messages of the SYSCONF module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00001[] = {
	"Services",
	"Services",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00001[] = {
	"Services",
	"Services",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00003[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00003[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00004[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00004[] = {
	"affichage de tous les &eacute;l&eacute;ments si incoh&eacute;rence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00005[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00005[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00006[] = {
	"service",
	"service",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00006[] = {
	"service",
	"service",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00007[] = {
	"run level 0",
	"run level 0",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00007[] = {
	"run level 0",
	"run level 0",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00008[] = {
	"run level 1",
	"run level 1",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00008[] = {
	"run level 1",
	"run level 1",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00009[] = {
	"run level 2",
	"run level 2",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00009[] = {
	"run level 2",
	"run level 2",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00010[] = {
	"run level 3",
	"run level 3",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00010[] = {
	"run level 3",
	"run level 3",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00011[] = {
	"run level 4",
	"run level 4",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00011[] = {
	"run level 4",
	"run level 4",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00012[] = {
	"run level 5",
	"run level 5",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00012[] = {
	"run level 5",
	"run level 5",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00013[] = {
	"run level 6",
	"run level 6",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00013[] = {
	"run level 6",
	"run level 6",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00014
 *	~~~~~~~~~~~~~ */
char					*c_msg_sysconf_00014[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sysconf_00014[] = {
	"nom du fichier HTML de sortie",
	"HTML output file",
	"??? (Deutsch)",
	(char *) 0
};

/* }}} */
/*	Messages of the DPKG module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00001[] = {
	"Paquets Debian",
	"Debian packages",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00001[] = {
	"Paquets Debian",
	"Debian packages",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00003[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00003[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00004[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00004[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00005[] = {
	"affichage de tous les elements si incoherence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00005[] = {
	"affichage de tous les &eacute;l&eacute;ments si incoh&eacute;rence",
	"display all elements in case of inconsistency",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00006[] = {
	"paquets",
	"packages",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00006[] = {
	"paquets",
	"packages",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00007[] = {
	"version",
	"version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00007[] = {
	"version",
	"version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00008[] = {
	"description",
	"description",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00008[] = {
	"description",
	"description",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00009[] = {
	"debug de l'agent",
	"agent debug",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00009[] = {
	"debug de l'agent",
	"agent debug",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_dpkg_00010[] = {
	"debug de l'agent",
	"agent debug",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_dpkg_00010[] = {
	"debug de l'agent",
	"agent debug",
	"??? (Deutsch)",
	(char *) 0
};

/* }}} */
/*	Messages of the SCCS module {{{
 *	~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*	Message 00001
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00001[] = {
	"Archives SCCS",
	"SCCS archives",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00001[] = {
	"Archives SCCS",
	"SCCS archives",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00002
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00002[] = {
	"affichage de l'usage",
	"display usage",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00003
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00003[] = {
	"affichage de tous les elements",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00003[] = {
	"affichage de tous les &eacute;l&eacute;ments",
	"display all elements",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00004
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00004[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00004[] = {
	"affichage de toutes les informations",
	"display all informations",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00005
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00005[] = {
	"[01;31m*** A INITIALISER 005 ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00005[] = {
	"[01;31m*** A INITIALISER HTM 005 ***[0m",
	"[01;31m*** NOT INITIALIZED ***[0m",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00006
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00006[] = {
	"archive SCCS",
	"SCCS archive",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00006[] = {
	"archive SCCS",
	"SCCS archive",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00007
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00007[] = {
	"derniere version",
	"last version",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00007[] = {
	"derniere version",
	"last version",
	"??? (Deutsch)",
	(char *) 0
};

/*	Message 00008
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00008[] = {
	"date et heure",
	"date and time",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00008[] = {
	"date et heure",
	"date and time",
	"??? (Deutsch)",
	(char *) 0
};
/*	Message 00009
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00009[] = {
	"auteur",
	"author",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00009[] = {
	"auteur",
	"author",
	"??? (Deutsch)",
	(char *) 0
};
/*	Message 00010
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00010[] = {
	"checksum MD5",
	"MD5 sum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00010[] = {
	"checksum MD5",
	"MD5 sum",
	"??? (Deutsch)",
	(char *) 0
};
/*	Message 00011
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00011[] = {
	"checksum SHA256",
	"SHA256 sum",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00011[] = {
	"checksum SHA256",
	"SHA256 sum",
	"??? (Deutsch)",
	(char *) 0
};
/*	Message 00012
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00012[] = {
	"taille",
	"size",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00012[] = {
	"taille",
	"size",
	"??? (Deutsch)",
	(char *) 0
};
/*	Message 00013
 *	~~~~~~~~~~~~~ */
char					*c_msg_sccs_00013[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};

char					*c_htm_sccs_00013[] = {
	"commentaire",
	"comment",
	"??? (Deutsch)",
	(char *) 0
};
/* }}} */
