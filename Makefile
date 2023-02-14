###############################################################################

SHELL=/bin/sh
LN=/bin/ln -s
MAKE=/usr/bin/make
RM=/bin/rm -f
TOUCH=/usr/bin/touch
TGZ=/usr/bin/tar -cf
WC=/usr/bin/wc -l
ZIP=/usr/bin/zip -r

  DEBUGGING=-DLAStatsCollect -DLADebug
# DEBUGGING=

CPP=g++
CPPFLAGS=-c -O3 -w -g $(DEBUGGING)
LFLAGS=-O3 -g

LA_C_FILES = la.cpp DenseVector.cpp DenseMatrix.cpp
LA_H_FILES = la.h
LA_O_FILES = la.o DenseVector.o DenseMatrix.o
T_C_FILES = test1.cpp
T_O_FILES = test1.o
T_FILES = test1
U_FILES = sizeof

ALL_SRCS=$(LA_C_FILES) $(LA_H_FILES) $(T_C_FILES) $(U_C_FILES) Makefile

ZIP_FILE=la.zip

###############################################################################
#
#   Executables
#
###############################################################################

all:	$(T_FILES)

ufiles:	$(U_FILES)

###############################################################################
#
#   Utilities
#
###############################################################################

linecnt:
	$(WC) $(LA_C_FILES) $(LA_H_FILES) $(T_C_FILES)

sizeof:	sizeof.cpp Makefile
	$(CPP) $(LFLAGS) sizeof.cpp -o sizeof

###############################################################################
#
#   Library routines
#
###############################################################################

la.o:	la.h la.cpp Makefile
	$(CPP) $(CPPFLAGS) la.cpp

DenseVector.o:	la.h DenseVector.cpp Makefile
	$(CPP) $(CPPFLAGS) DenseVector.cpp

DenseMatrix.o:	la.h DenseMatrix.cpp Makefile
	$(CPP) $(CPPFLAGS) DenseMatrix.cpp
###############################################################################
#
#   Test programs
#
###############################################################################

test1.o:	la.h test1.cpp Makefile
	$(CPP) $(CPPFLAGS) test1.cpp

test1:	test1.o la.o DenseVector.o DenseMatrix.o Makefile
	$(CPP) $(LFLAGS) test1.o la.o DenseVector.o DenseMatrix.o -o test1

test1.txt:	test1
	./test1 > test1.txt

###############################################################################
#
#   Clean up
#
###############################################################################

clean:
	$(RM) *.o

veryclean:	clean
	$(RM) $(T_FILES) $(U_FILES) a.out test1.txt

###############################################################################
#
#   Package the source files
#
###############################################################################

zip:
	$(ZIP) $(ZIP_FILE) $(ALL_SRCS)

###############################################################################
#
#   C'est finis!
#
###############################################################################


