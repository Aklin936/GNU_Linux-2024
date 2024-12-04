
TRASH = *.o file* *~ range
CFLAGS = -g -o0

.SILENT: test

all:	range

range:	range.o

gdb1:	range
	gdb --batch --quiet -x gdb-script1 --args ./$< | grep @@@ | cut -c 4- > file1

gdb2:	range
	gdb --batch --quiet -x gdb-script2 --args ./$< | grep @@@ | cut -c 4- > file2


clean:
	rm -f $(TRASH)