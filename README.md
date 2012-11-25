list
====

This code should compile everywhere and survive to all warning flags (*).

## How to build ##

### Make goals ###

* all (default) : Build static/dynamic library.
* clean         : Delete object files. 
* realclean     : Delete object files and targets.

### Makefile variables ###

* CC            : Compiler (default `cc').
* AR            : Archiver (default `ar').
* LD            : Linker (default `ld').
* CFLAGS        : Compiler flags.
* ARFLAGS       : Archiver flags (default `rv').
* LDFLAGS       : Linker flags.
* RM            : Binary used to delete files (default `rm').

#### Example ####

`make CC="gcc" LD="gcc" CFLAGS="-Wall -pedantic" LDFLAGS="-shared"`

(*) Almost
