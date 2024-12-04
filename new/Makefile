GENERATES = prog prog-a prog-so README
TRASH = *.o *~ o.* *.a *.so file*
CFLAGS=-fPIC

PARAMS0 = ""
PARAMS1 = "abc"
PARAMS2 = "abc def ghi"
PARAMS =  $(PARAMS0) $(PARAMS1) $(PARAMS2)

.SILENT: test

all:    README prog prog-a prog-so

prog:   const.o fun.o prog.o

clean:	distclean
	rm -f $(TRASH)

distclean:
	rm -rf $(GENERATES)