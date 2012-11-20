# This little Makefile should work with any versions of make.
ARCHIVE=liblist.a
LIBRARY=liblist.so
SOURCES=list.c tree.c

OBJECTS=$(SOURCES:.c=.o)

all: $(OBJECTS)
	$(AR) $(ARFLAGS) $(ARCHIVE) $(OBJECTS)
	$(LD) $(LDFLAGS) -o $(LIBRARY) $(OBJECTS)

clean:
	$(RM) $(OBJECTS)

realclean: clean
	$(RM) $(ARCHIVE)
	$(RM) $(LIBRARY)

.PHONY: all clean realclean
