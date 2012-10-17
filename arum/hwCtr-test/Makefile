obj-m := HwCtr.o

# SRY	= Interrupts.tab.y
# SRL	= Interrupts.lex.l
SRC	= test-module.c $(SRY:.y=.c) $(SRL:.l=.x)

#HDR	= $(SRC:.c=.h)
OBJ	= $(SRC:.c=.o)
LIBDIR	= ../lib
INCDIR	= ../include
LIB	= timer
INC	= -I $(INCDIR)
EXE	= test-module

RM	= /bin/rm
MV	= /bin/mv
YACC	= /usr/bin/yacc
LEX	= /usr/bin/lex
SED	= /usr/bin/sed

EXA	= $(EX1) $(EX2) $(EX3) $(EX4) $(EX5) $(EX6)
CXX	= gcc
CXXFLAGS=-O3 

.c.o:
	$(CXX) $(CXXFLAGS) -c $<

.l.c:
	$(LEX) $<
	$(SED) -e s/yy/$(<:.lex.l=)_/g -e s/lex.yy.c/$</g lex.yy.c > $(<:.l=).c
	$(RM)  lex.yy.c

.y.c:
	$(YACC) $<
	$(SED) -e s/yy/$(<:.tab.y=)_/g -e s/y.tab.c/$</g y.tab.c > $(<:.y=).c
	$(RM)  y.tab.c

.y.h:
	$(YACC) -d $<
	$(SED) -e s/yy/$(<:.tab.y=)_/g -e s/y.tab.c/$</g y.tab.h > $(<:.y=).h
	$(RM)  y.tab.c y.tab.h

$(EXE):	$(OBJ)
	$(CXX) -o $(EXE) $(CXXFLAGS) $(OBJ)
	$(RM) -rf $(EXA)
	for i in $(EXA) ; do /bin/ln $(EXE) $$i ; done

#$(OBJ):	$(HDR)

rmexe:
	$(RM) -rf $(EXE)

rmobj:
	$(RM) -rf $(OBJ) $(SRY:.y=.C) $(SRY:.y=.h) $(SRL:.l=.C)

rmmod:
	$(RM) -rf HwCtr.ko HwCtr.mod.c HwCtr.mod.o HwCtr.o .HwCtr.ko.cmd .HwCtr.mod.o.cmd .HwCtr.o.cmd .tmp_versions/

Interrupts.lex.C:	Interrupts.lex.l
Interrupts.tab.h:	Interrupts.tab.y
Interrupts.tab.C:	Interrupts.tab.y
