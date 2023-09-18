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
 *   Author       :     Martial BORNET (MB) - August 25, 2010
 *
 *   File         :     m_cpub.h
 *
 *   @(#)  [Zen] m_cpub.h Version 1.16 of 23/09/18 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/zendiff
 *
 * ============================================================================
 */

/*	Return codes definitions
 *	~~~~~~~~~~~~~~~~~~~~~~~~ */
#define	M_RET_OK					  0
#define	M_ERR_OPEN				  1
#define	M_ERR_CLOSE				  2
#define	M_ERR_READ				  3
#define	M_ERR_WRITE				  4
#define	M_ERR_MALLOC				  5
#define	M_ERR_INTERNAL				  6
#define	M_ERR_BAD_MAGIC			  7
#define	M_ERR_MYSQL_CNX			  8
#define	M_ERR_GET_TIME				  9
#define	M_ERR_BAD_PARAM			 10
#define	M_ERR_STAT				 11
#define	M_ERR_MMAP				 12
#define	M_ERR_PIPE				 13
#define	M_ERR_FORK				 14
#define	M_ERR_EXEC				 15
#define	M_ERR_FOPEN				 16
#define	M_ERR_SETVBUF				 17
#define	M_ERR_GETHOSTNAME			 18
#define	M_ERR_GETHOSTBYNAME			 19
#define	M_ERR_CONNECT				 20
#define	M_ERR_CORE_DUMPED			 21
#define	M_ERR_SIGNAL				 22
#define	M_ERR_USAGE				 23
#define	M_ERR_CREATE				 24
#define	M_ERR_SYNTAX				 25
#define	M_ERR_MYSQL_CONNECT			 26
#define	M_ERR_MYSQL_QUERY			 27
#define	M_ERR_MYSQL_STORE_RESULT		 28
#define	M_ERR_THREAD_CREATE			 29
#define	M_ERR_THREAD_JOIN			 30
#define	M_ERR_DISP_VERSION			 31
#define	M_ERR_MUNMAP				 32
#define	M_ERR_DUPLICATE_VALUE		 33
#define	M_ERR_GETCWD				 34
#define	M_ERR_CONF				 35
#define	M_ERR_FCLOSE				 36
#define	M_ERR_READLINK				 37
#define	M_ERR_TESTS				 38
#define	M_ERR_OPT					 39
#define	M_ERR_UNKNOWN_OPT			 40
#define	M_ERR_OVERFLOW				 41
#define	M_ERR_LINK				 42
#define	M_ERR_SEGV				 43

#define	M_ERR_WRITE_01				101
#define	M_ERR_WRITE_02				102
#define	M_ERR_WRITE_03				103

#define	M_ERR_NOT_IMPLEMENTED		126
