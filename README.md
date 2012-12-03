list
====

This code should compile everywhere and survive to all warning flags (*).

## How to build ##

To build the library invoke `make' binary.

### Goals ###

* all (default) : Build static/dynamic library.
* clean         : Delete object files. 
* realclean     : Delete object files and targets.

### Variables ###

* CC            : Compiler (default `cc').
* AR            : Archiver (default `ar').
* LD            : Linker (default `ld').
* CFLAGS        : Compiler flags.
* ARFLAGS       : Archiver flags (default `rv').
* LDFLAGS       : Linker flags.
* RM            : Binary used to delete files (default `rm').

## How to use ##



(*) Almost
