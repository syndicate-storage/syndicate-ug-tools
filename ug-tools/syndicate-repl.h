/*
   Copyright 2016 The Trustees of Princeton University

   Licensed under the Apache License, Version 2.0 (the "License" );
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

// file documentation
/**
 * @file syndicate-repl.h
 * @author Jude Nelson
 * @date 9 Mar 2016
 *
 * @brief syndicate-repl header file
 *
 * @author Jude Nelson
 *
 * @see syndicate-repl.cpp,
 * @ref syndicate-repl
 */

// man page and related pages documentation
/**
 * @page syndicate-repl
 * @brief Replay a series of commands from a syndicate script
 *
 * @section synopsis SYNOPSIS
 * syndicate-repl -u USERNAME -v VOLUME_NAME -g GATEWAY_NAME [OPTION]... SCRIPT
 *
 * @section description DESCRIPTION
 * Run a set of syndicate commands from an input SCRIPT.\n\n
 * Possible commands: access, chmod, chown, close, closedir, create, ftrunc, getxattr, listxattr, mkdir, open, opendir, read, readdir, removexattr, rename, rmdir, setxattr, shell, stat, sync, trunc, unlink, utime, write\n\n
 * Each command operates similar to their associated command line tool but they assume the USER, VOLUME_NAME, GATEWAY_NAME provided as inputs to this command.
 *
 * @copydetails md_common_usage()
 *
 * @section example EXAMPLES
 * syndicate-repl -u syndicate@example.com -v syndicate_volume -g syndicate_gateway -d2 -f -c "syndicate.conf" repl_script.txt\n\n
 * Example Script:\n\n
 * create /put-abcde-0 0644\n
 * write 0 0 12 foobarbazgoo\n
 * close 0\n
 * trunc /put-abcde-0 6\n
 * open /put-abcde-0 2\n
 * read 0 0 12\n
 * close 0\n
 * create /put-abcde-1 0644\n
 * write 0 0 12 foobarbazgoo\n
 * close 0\n
 * trunc /put-abcde-1 6\n
 * open /put-abcde-1 2\n
 * read 0 0 12\n
 * close 0\n
 * create /put-abcde-2 0644\n
 * write 0 0 12 foobarbazgoo\n
 * close 0\n
 * trunc /put-abcde-2 6\n
 * open /put-abcde-2 2\n
 * read 0 0 12\n
 * close 0\n
 *
 * @section author AUTHOR
 * Written by Jude Nelson
 *
 * @section bugs REPORTING BUGS
 * Online help is available at http://www.syndicate-storage.org
 *
 * @section copyright COPYRIGHT
 *
 * @copydetails md_print_copywrite()
 *
 * @copydetails md_print_license()
 *
 * @section see SEE ALSO
 * syndicate-repl.cpp(3)
 * syndicate-repl.h(3)
 */

#ifndef _SYNDICATE_RENAME_H_
#define _SYNDICATE_RENAME_H_

#include <libsyndicate-ug/client.h>
#include <libsyndicate-ug/core.h>

#include <fskit/repl.h>

#include "common.h"

#endif
