GCC=g++
PRG=rummikub
BUILDDIR=test
GCCFLAGS=-Wall -Werror -Wextra -std=c++11 -pedantic -Wconversion -O2 -Wno-unused-result

OBJECTS0=rummikub.cpp
DRIVER0=driver.cpp
HEADER0=rummikub.h

VALGRIND_OPTIONS=-q --leak-check=full
DIFF_OPTIONS=-y --strip-trailing-cr --suppress-common-lines -b

.PRECIOUS: $(DRIVER0) $(OBJECTS0) $(HEADER0)

OSTYPE := $(shell uname)
ifeq ($(OSTYPE),Linux)
CYGWIN=
else
CYGWIN=-Wl,--enable-auto-import
endif

$(BUILDDIR):
	mkdir -p $(BUILDDIR)
	
.PHONY: copy_sources gcc0 clean

copy_sources: $(BUILDDIR)
	@echo "Copying latest source file to test/..."
	cp $(DRIVER0) $(BUILDDIR)/
	cp $(OBJECTS0) $(BUILDDIR)/
	cp $(HEADER0) $(BUILDDIR)/

gcc0: copy_sources
	cd $(BUILDDIR) && $(GCC) -o $(PRG) $(CYGWIN) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS)
	#$(GCC) -o $(PRG) $(CYGWIN) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS)
	#$(GCC) -o $(PRG2) $(CYGWIN) $(DRIVER0) $(OBJECTS0) $(GCCFLAGS) -m32
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46:
	#echo "running test$@"
	#@echo "should run in less than 200 ms"
	@echo "should run in less than 200 ms"
	watchdog 300 ./$(PRG) $@ >studentout$@
	diff out$@ studentout$@ $(DIFF_OPTIONS) > difference$@
clean : 
	#rm *.exe student* difference*
	rm -f $(PRG) student* difference*
	rm -rf $(BUILDDIR)
