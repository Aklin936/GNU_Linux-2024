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

prog-a: prog.o liboutput_static.a
	cc -L . $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	cc -L . $< -loutput -o $@

fun.o:  outlib.h

clean:	distclean
	rm -f $(TRASH)

distclean:
	rm -rf $(GENERATES)