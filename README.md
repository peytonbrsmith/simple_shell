# Simple Shell

This repository is just a slight fork from its original by [Peyton](https://github.com/peytonbrsmith) (me) and [Allen](https://github.com/ranicholson) (project partner) found [here](https://github.com/ranicholson/simple_shell).

This is a simple UNIX shell program built in C. Supported built-in commands are listed below, otherwise this shell is capable of searching for and executing programs on the PATH.

### Features

cd - built-in to change directory

```
cd [DIRECTORY]
```

env - built-in to print the current environment

```
env
```

exit - built-in to exit the shell

```
exit
```

## Installation

Simply clone the repo below and compile!

```
https://github.com/peytonbrsmith/simple_shell
```

## Environment
Created and tested with **Ubuntu 14.04 LTS**

Compiled with **GCC 4.8.4** with flags: **-Wall -Werror -Wextra -pedantic -std=gnu89**

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Usage

```
peytonbrsmith@penguin:~/simple_shell$ ./a.out
($) /bin/ls
a.out  builtins.c  execute.c  holberton.h  parse.c  path.c  _printf.c  README.md  simpshell.c  strtools2.c  strtools.c
($) ls -la /usr/
total 0
drwxr-xr-x 1 root root    80 Jul 21 23:26 .
drwxrwxrwx 1 root root   172 Nov  4 11:54 ..
drwxr-xr-x 1 root root 22188 Nov  4 11:53 bin
drwxr-xr-x 1 root root    10 Oct 27 11:00 games
drwxr-xr-x 1 root root  2262 Nov  3 18:50 include
drwxr-xr-x 1 root root  1880 Nov  3 19:34 lib
drwxr-xr-x 1 root root     6 Jul 21 23:26 lib64
drwxr-xr-x 1 root root    72 Jul 21 00:26 local
drwxr-xr-x 1 root root  4122 Nov  3 19:32 sbin
drwxr-xr-x 1 root root  2592 Nov  4 11:53 share
drwxr-xr-x 1 root root     0 May  2  2020 src
($) pwd
/home/peytonbrsmith/simple_shell
($) cd /home/
($) pwd
/home
($) ls
peytonbrsmith
($) exit
```

## Support

Reach out to [Peyton](https://github.com/peytonbrsmith) or [Allen](https://github.com/ranicholson)

## Project Status

Checked using Valgrind. No known memory leaks or bugs. 

Currently there are no plans to continue working on the simple shell after completion of the project.
