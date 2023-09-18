# zendiff
Tool that displays differences between objects.

It may be used to find inconsistencies between configurations or between servers, and to
detect changes between states, for example before and after a package installation,
before and after a program execution, or to detect files corruption or meta-data modifications.

This tool, in its distributed version, has been created in 2009.
It can produce a list of differences between :
- filesystems,
- users databases,
- Red Hat packages,
- Debian packages,
- system configuration,
- SCCS archives,
- and many other types of objects.

It's written in C, LEX and YACC, and is currently made of more that 60,000 lines of code.
Its output is either in HTML/CSS or in ASCII (as a command line output).

You can compare objects on a same machine or between several machines, but since metadata
can be stored in a database, you also can compare a current state with one or different
previous states.

## Warning
It is still in development and the source code is still being reworked.
It works for me and I've been using it since 2010 to find inconsistencies between
different machines or evolution of elements through time, but it's not industrialized yet,
so not ready for everybody to use.
The modules I'm currently working on are :
- Module FS : adding regex to filter the elements to be compared
- Module FS : adding different colorizations for specific elements (directories, root, ...)
- Module SCCS : currently being developped
- Module SSHKEYS : design (check consistency and locate security flaws)

Currently usable modules are :
- FS
- USERS
- RPM
- DPKG
- SYSCONF
- SCCS

Future modules are :
- sshkeys
- network
- security
- mail
- inventory
- backups
- performance

but that's a lot for one only person : I'm the designer and sole developer ...

I'll put some screenshots in the **results** directory to show you possible outputs.

# Usage
```
-M main
--help                 | -u : display usage
--version              | -V : display version
--verbose              | -v : verbose
--no-log               | -x : do not generate logs
--lang                 | -_ : language
--config               | -C : configuration
--list-conf            | -c : display options configurations
--list-groups          | -G : display defined groups
--list-group           | -g : display the servers in a group
--db-host              | -h : server hosting the database
--db-name              | -n : database name
--db-list              | -d : display tables of the database
      --collects             | -C : display collects list
      --TS                   | -T : list timestamps
      --servers              | -S : list servers
      --users                | -U : list users
      --pathnames            | -P : list pathnames
      --RPM                  | -R : list RPM
      --dpkg                 | -D : list Debian packages
      --sccs                 | -S : list SCCS archives
--log                  | -l : log options
      --hires-ts             | -T : display high resolution timestamps
      --ts                   | -t : display timestapms
      --delta-t              | -d : display durations (delta T)
      --duration             | -D : display times
      --where                | -w : display message source
      --origin-full          | -f : display programme's full pathname
      --origin-base          | -b : display programme's basename
      --pid                  | -p : display PID
      --tid                  | -H : display TID (Thread ID)
      --protocol             | -P : display protocol
      --sql-req              | -S : display SQL requests
      --disp-insert          | -i : display elements insertions
      --no-tty-err           | -E : redirection of stderr to the log file
--trace                | -T : trace activation
      --k-fct                | -f : K: trace functions
      --k-ctx                | -c : K: trace contexts
      --k-read               | -r : K: trace read
      --k-write              | -w : K: trace write
      --k-tl                 | -t : K: trace types/lengths
      --k-v                  | -v : K: trace values
      --k-dump               | -d : K: trace dump
      --mutex                | -m : trace mutex operations
--debug                | -D : debug
      --options              | -O : trace options parsing
      --opts-infos           | -I : display options corresponding to informations
      --opts-all             | -A : display all options
      --opts-todo            | -t : display unimplemented options
      --watch-mem            | -w : periodic display of memory informations
      --mem                  | -m : display memory informations
      --show-free            | -f : show memory free
      --no-free              | -N : no memory free
      --infinite             | -8 : infinite loop
      --num-loops            | -L : specify number of loops
      --intl-chk             | -I : internal check
      --infos                | -i : informations
      --sizes                | -s : display elements sizes
      --links                | -l : generate mark-up for page links (tests)
--lex                  | -L : trace lexical analyzers
      --AT                   | -s : source names management
      --AJ                   | -S : servers groups management
      --BL                   | -C : configuration file management
      --AP                   | -c : colours management
--yacc                 | -Y : trace parsers
      --AT                   | -s : source names management
      --AJ                   | -S : servers groups management
      --BL                   | -C : configuration file management
      --AP                   | -c : colours management
--module               | -M users
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --delta                |    : display numeric deltas
      --passwd               | -p : password
      --uid                  | -u : UID
      --gid                  | -g : GID
      --comment              | -c : comment
      --directory            | -d : home directory
      --shell                | -s : shell
      --uniq                 |    : search for uniq users
            --name                 | -n : user name
            --uid                  | -u : UID
      --dupl                 |    : search for duplicate users
            --name                 | -n : user name
            --uid                  | -u : UID
      --U                    |    : check /etc/passwd
            --name                 | -n : username
            --passwd               | -p : user's encrypted password
            --uid                  | -u : UID
            --gid                  | -g : GID
            --comment              | -c : comment
            --homedir              | -h : home directory
            --shell                | -s : shell
--module              -M fs
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --base                 |    : quick scan
      --RE-ignore            |    : ignore files matching the regex
      --RE-only              |    : select files matching the regex
      --digits-separator     | -3 : 3 digits grouping
      --no-implicit-display  |    : no implicit display of informations
      --delta                |    : display numeric deltas
      --filetype             | -t : filetype
      --dev                  | -D : dev
      --ino                  | -i : inode
      --mode                 | -m : mode
      --attr                 | -A : attributes
      --nlinks               | -l : nlink
      --uid                  | -u : uid
      --gid                  | -g : gid
      --user                 | -U : owner name
      --group                | -G : group owner name
      --rdev                 |    : rdev
      --size                 | -s : size
      --blksize              |    : blksize
      --blocks               |    : blocks
      --at                   |    : access time
      --mt                   |    : modification time
      --ct                   |    : inode change time
      --chksum               | -k : checksum
      --BSD                  | -B : checksum BSD
      --md5                  |    : checksum MD5
      --sha256               | -S : checksum SHA256
      --d-nb-f               |    : number of files in the directory
      --d-nb-d               |    : number of directories in the directory
      --d-nb-F               |    : number of FIFO in the directory
      --d-nb-c               |    : number of character devices in the directory
      --d-nb-b               |    : number of block devices in the directory
      --d-nb-l               |    : number of symbolic links in the directory
      --d-nb-s               |    : number of sockets in the directory
      --d-nb-U               |    : number of unknown tyep files in the directory
      --d-nb-B               |    : number of data blocks in the directory
      --t-nb-f               |    : number of files in the file tree
      --t-nb-d               |    : number of directories in the file tree
      --t-nb-F               |    : number of FIFO in the file tree
      --t-nb-c               |    : number of character devices in the file tree
      --t-nb-b               |    : number of block devices in the file tree
      --t-nb-l               |    : number of symbolic links in the file tree
      --t-nb-s               |    : number of sockets in the file tree
      --t-nb-U               |    : number of unknown tyep files in the file tree
      --t-nb-B               |    : number of data blocks in the file tree
      --pathname             | -P : pathname
      --uniq                 |    : search for uniq files
            --basename             | -n : file basename
            --relative-path        | -r : relative pathname
            --filetype             | -t : filetype
            --inode                | -i : i-node number
            --size                 | -s : file size
            --chksum               | -k : checksum
            --BSD                  | -B : BSD checksum
            --md5                  | -M : MD5 checksum
            --sha256               | -S : checksum SHA256
      --mono-src             |    : search for files localized on only one source
            --basename             | -n : file basename
            --relative-path        | -r : relative pathname
            --filetype             | -t : filetype
            --inode                | -i : i-node number
            --size                 | -s : file size
            --chksum               | -k : checksum
            --BSD                  | -B : BSD checksum
            --md5                  | -M : MD5 checksum
            --sha256               | -S : checksum SHA256
      --not-on-ref           |    : search for files not localized on any reference tree
            --basename             | -n : file basename
            --relative-path        | -r : relative pathname
            --filetype             | -t : filetype
            --inode                | -i : i-node number
            --size                 | -s : file size
            --chksum               | -k : checksum
            --BSD                  | -B : BSD checksum
            --md5                  | -M : MD5 checksum
            --sha256               | -S : checksum SHA256
      --dupl                 |    : search for duplicate files
            --basename             | -n : file basename
            --relative-path        | -r : relative pathname
            --filetype             | -t : filetype
            --hard-links           | -H : take hard links into account
            --inode                | -i : i-node number
            --size                 | -s : file size
            --chksum               | -k : checksum
            --BSD                  | -B : BSD checksum
            --md5                  | -M : MD5 checksum
            --sha256               | -S : checksum SHA256
      --locate               |    : files locate
            --basename             | -n : specification of a database source for an optimized collect
            --relative-path        | -r : relative pathname
            --filetype             | -t : filetype
            --hard-links           | -H : take hard links into account
            --inode                | -i : i-node number
            --size                 | -s : file size
            --chksum               | -k : checksum
            --BSD                  | -B : BSD checksum
            --md5                  | -M : MD5 checksum
            --sha256               | -S : checksum SHA256
      --list                 |    : list elements
      --xdev                 |    : don't descend directories on other filesystem
      --no-dirsize           |    : no directory size
      --no-dir               |    : no retrieval of directory attributes
      --level                | -L : depth level
      --reorg                |    : reorganize occording to reference tree
      --debug                | -D : debug mode management
            --agent                | -a : activate agent debug
--module              -M rpm
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --delta                |    : display numeric deltas
      --version              | -v : RPM version
      --release              | -r : RPM release
      --inst-date            |    : installation date
      --rpmgroup             | -g : RPM group
      --rpmsize              | -s : RPM size
      --vendor               |    : vendor
      --bd                   |    : build date
      --bh                   |    : build host
      --src                  |    : source RPM
      --lic                  |    : license
      --sig                  |    : signature
      --summary              |    : summary
      --desc                 |    : description
      --arch                 |    : architecture
      --dirnames             |    : dirnames
      --filemtimes           |    : files modification times
      --fileusername         |    : files owner
      --filegroupname        |    : files group owner
      --rpmversion           |    : version of RPM used to build the package
      --distribution         |    : distribution
      --optflags             |    : options flags
      --packager             |    : package creator
      --sha1header           |    : SHA1 header
      --sigMD5               |    : MD5 signature
      --!R                   |    : reference (replace)
      --#L                   |    : trace lex
      --#Y                   |    : trace yacc
      --uniq                 |    : search for uniq RPM
      --dupl                 |    : search for uniq RPM
--module              -M sysconf
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --service              | -s : service
      --run-0                | -0 : run level 0
      --run-1                | -1 : run level 1
      --run-2                | -2 : run level 2
      --run-3                | -3 : run level 3
      --run-4                | -4 : run level 4
      --run-5                | -5 : run level 5
      --run-6                | -6 : run level 6
--module              -M dpkg
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --package              | -p : packages
      --version              | -v : version
      --descr                | -d : description
      --debug                | -D : agent debug
            --agent                | -a : agent debug
--module              -M sccs
      --help                 |    : display usage
      --all-elts             | -E : display all elements
      --all-infos            | -I : display all informations
      --config               | -C : configuration
      --reference            | -R : reference (add)
      --srvgroup             |    : servers group(s) name(s)
      --store                |    : store collected informations in a database
      --no-disp              |    : no display
      --html-out             | -o : HTML output file
      --title                |    : results page title
      --label                |    : associate a name to a collect
      --lex                  | -L : trace lex
      --yacc                 | -Y : trace yacc
      --xdev                 | -x : don't descend directories on other filesystem
      --level                |    : SCCS archive
      --size                 | -s : delta size
      --md5                  | -M : MD5 sum
      --sha256               | -S : SHA256 sum
      --archive              | -a : SCCS archive
      --last-version         | -l : last version
      --author               | -A : author
      --date                 | -d : delta creation date
      --time                 | -t : delta creation time
      --module-type          | -m : module type
      --var-Q                | -Q : Q variable
      --comment              | -c : comment
      --year                 |    : delta creation year
      --month                |    : delta creation month
      --day                  |    : delta creation day
```

# Donation
If you want to help develop this software, please consider donating [here](https://paypal.me/MartialBornet).

This software is only developed during my free time, and development would go much master if I had more free time ...  ;-)

I have many ideas to enhance this product, but implementing ideas in C is not quick, and this tool needs to be implemented in C for efficiency.

I would be very happy if it could help you.

Thank you for reading.
