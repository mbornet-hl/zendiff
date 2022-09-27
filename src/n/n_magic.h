/* ============================================================================
 *   (C) Copyright Martial Bornet, 2009-2022
 *
 *   Author       :     Martial BORNET (MB) - March 29, 2009
 *
 *   File         :     n_magic.h
 *
 *   @(#)  [Zen] n_magic.h Version 1.25 of 22/09/27 - 
 *
 * ============================================================================
 */

#if ! defined(N_MAGIC_H)
#  define N_MAGIC_H

#define   N_FILE                             __file__
#define   N_LINE                             __LINE__

/*   Magic numbers management macro
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#if defined(N_CONTROL)
#define   N_CHECK(a, b)                      n_check(N_FILE, N_LINE, a, b)
#define   N_INIT_MAGIC(magic, magic_number)  magic     = (magic_number);
#define   N_DEFINE_MAGIC      b_uint32       magic;
#define   N_MAGIC(magic_number)              (magic_number),
#else
#define   N_CHECK(a, b)
#define   N_INIT_MAGIC(magic, magic_number)
#define   N_DEFINE_MAGIC
#define   N_MAGIC(magic_number)
#endif

#define   N_ADDR_TO_MAGIC(addr)              (*(b_uint32 *) addr)

/*   Magic numbers for structures
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   N_MAGIC_NULL                       0x00000000
#define   N_MAGIC_k_tlf                      0xEAFC0001
#define   N_MAGIC_r_desc_mem                 0xEAFC0002
#define   N_MAGIC_c_elt_user                 0xEAFC0003
#define   N_MAGIC_c_info_user                0xEAFC0004
#define   N_MAGIC_c_desc_uint32              0xEAFC0005
#define   N_MAGIC_c_desc_str                 0xEAFC0006
#define   N_MAGIC_y_desc_msg                 0xEAFC0007
#define   N_MAGIC_c_elt_path                 0xEAFC0008
#define   N_MAGIC_c_info_path                0xEAFC0009
#define   N_MAGIC_c_desc_uint64              0xEAFC000A
#define   N_MAGIC_c_uint32_tree              0xEAFC000B
#define   N_MAGIC_c_str_tree                 0xEAFC000C
#define   N_MAGIC_c_uint64_tree              0xEAFC000D
#define   N_MAGIC_l_dyn_opt                  0xEAFC000E
#define   N_MAGIC_l_dyn_mod_opts             0xEAFC000F
#define   N_MAGIC_c_desc_module              0xEAFC0010
#define   N_MAGIC_c_desc_server              0xEAFC0011
#define   N_MAGIC_c_param_users              0xEAFC0012
#define   N_MAGIC_c_param_fs                 0xEAFC0013
#define   N_MAGIC_aj_desc_group              0xEAFC0014
#define   N_MAGIC_aj_desc_ident              0xEAFC0015
#define   N_MAGIC_aj_group_tree              0xEAFC0016
#define   N_MAGIC_aj_ident_tree              0xEAFC0017
#define   N_MAGIC_l_arg_fifo                 0xEAFC0018
#define   N_MAGIC_c_elt_rpm                  0xEAFC0019
#define   N_MAGIC_c_info_rpm                 0xEAFC0020
#define   N_MAGIC_c_param_rpm                0xEAFC0021
#define   N_MAGIC_t_keyw_node                0xEAFC0022
#define   N_MAGIC_e_desc_option              0xEAFC0023
#define   N_MAGIC_k_desc_info                0xEAFC0024
#define   N_MAGIC_c_desc_date                0xEAFC0025
#define   N_MAGIC_c_date_tree                0xEAFC0026
#define   N_MAGIC_ab_desc_fifo               0xEAFC0027
#define   N_MAGIC_ab_fifo                    0xEAFC0028
#define   N_MAGIC_as_elt                     0xEAFC0029
#define   N_MAGIC_c_elt                      0xEAFC002A
#define   N_MAGIC_ab_elt                     0xEAFC002B
#define   N_MAGIC_c_elt_fifo                 0xEAFC002C
#define   N_MAGIC_c_desc_source              0xEAFC002D
#define   N_MAGIC_c_param                    0xEAFC002E
#define   N_MAGIC_aw_param                   0xEAFC002F
#define   N_MAGIC_c_desc_display             0xEAFC0030
#define   N_MAGIC_c_param_sccs               0xEAFC0031
#define   N_MAGIC_c_elt_dupl                 0xEAFC0032
#define   N_MAGIC_c_param_sysconf            0xEAFC0033
#define   N_MAGIC_c_elt_sysconf              0xEAFC0034
#define   N_MAGIC_c_info_sysconf             0xEAFC0035
#define   N_MAGIC_c_desc_uint8               0xEAFC0036
#define   N_MAGIC_c_uint8_tree               0xEAFC0037
#define   N_MAGIC_c_desc_dsp_hdr             0xEAFC0038
#define   N_MAGIC_bl_cfg_node                0xEAFC0039
#define   N_MAGIC_c_opt_node                 0xEAFC003A
#define   N_MAGIC_c_param_dpkg               0xEAFC003B
#define   N_MAGIC_c_elt_dpkg                 0xEAFC003C
#define   N_MAGIC_c_info_dpkg                0xEAFC003D


/*   Magic number classes for messages
 *   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#define   N_MAGIC_AA_MSG                     0x10000000
#define   N_MAGIC_AA_HTM                     0x20000000
#define   N_MAGIC_AA_MAN                     0x40000000
#define   N_MAGIC_C_MSG_MAIN                 0x01010000
#define   N_MAGIC_C_MSG_COMMON               0x01020000
#define   N_MAGIC_C_MSG_USER                 0x01030000
#define   N_MAGIC_C_MSG_FS                   0x01040000
#define   N_MAGIC_C_MSG_RPM                  0x01050000
#define   N_MAGIC_C_MSG_SCCS                 0x01060000
#define   N_MAGIC_C_MSG_SYSCONF              0x01070000
#define   N_MAGIC_C_MSG_DPKG                 0x01080000

#endif    /* N_MAGIC_H */
