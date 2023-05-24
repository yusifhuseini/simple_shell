Simple Shell
Overview

The Simple Shell is a custom UNIX command interpreter developed as part of the ALX Software Engineering program. It aims to replicate the functionality of the standard /bin/sh shell, including both the regular output and error messages. The primary difference is that error messages should display the name of the program as equivalent to argv[0].

General Requirements
Editors allowed: vi, vim, emacs
All files will be compiled on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89
All files should end with a new line
A README.md file is mandatory and should be placed at the root of the project folder
Code should adhere to the Betty style, which will be checked using betty-style.pl and betty-doc.pl
The shell should be free of memory leaks
Each file should contain no more than 5 functions
Header files should be include guarded
System calls should only be used when necessary
Allowed Functions and System Calls

The Simple Shell implementation can use the following functions and system calls:

access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
Compilation

To compile the Simple Shell, use the following command:

c
Copy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

How to Use

To use the Simple Shell, open a terminal and run the program:

shell
Copy code
prompt$ ./hsh


The shell will display a simple prompt and wait for commands.

ruby
Copy code
$

List of Built-in Commands

The Simple Shell currently supports the following built-in commands:

cd [directory]: Switches to the specified directory (path).
env: Displays the environment variables.
exit [exitstatus]: Exits the program with the specified exit status. Defaults to 0.
getenv NAME: Returns the value of the specified environment variable (NAME) if it exists.
help [command]: Displays the syntax for the specified command or all commands.
history: Displays the most recent user input.
echo [$$] or [$?] or [$PATH]: Returns the process ID, exit status, or PATH respectively.
Command Handling

The Simple Shell can handle various types of commands:

Basic commands: It supports single-word commands like "ls".
Path handling: It can handle commands with explicit paths, such as "/tmp/ls".

Option handling: It can handle commands with options, such as "ls -l".
Combination of command, options, and path: It can handle commands with options and paths together, such as "/bin/ls -l /var".
Comment handling: It can handle comments indicated by the "#" symbol.
Example Commands

Here are a few examples of commands that can be executed using the Simple Shell:

Example 1:

ruby
Copy code
Username@your-regular-prompt:~$ ./hsh
$ pwd
/home/username/
$ ^D
Username@your-regular-prompt:~$


Example 2:

ruby
Copy code
Username@your-regular-prompt:~$ ./hsh
$ ls -l /tmp 
-rw------- 1 username username    0 Nov  1 12:09 config-err-aAMZrR
drwx------ 3 root   root   4096 Nov  1 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-colord.service-V7DUzr
drwx------ 3 root   root   4096 Nov  1 12:09 systemd-private-062a0eca7f2a44349733e78cb4abdff4-rtkit-daemon.service-ANGvoV
drwx------ 3 root   root   4096 Nov  1 12:07 systemd-private-062a0eca7f2a44349733e78cb4abdff4-systemd-timesyncd.service-CdXUtH
-rw-rw-r-- 1 username username    0 Nov  1 12:09 unity_support_test.0
$ ^D
Username@your-regular-prompt:~$


For more information about the Simple Shell, refer to the manual page by running:

ruby
Copy code
Username@your-regular-prompt:~$ man ./man_1_simple_shell

Authors

The Simple Shell project was developed by the following authors:
1. [Huseini Yusif](https://github.com/yusifhuseini) 
2. [Bennet Aboagye-Asare](https://github.com/bennet489)
