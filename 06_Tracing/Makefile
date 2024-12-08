TRASH = *.o *~ o.* *.so move file*
CFLAGS=-Wall

all:	move remove.so

move:	move.o

remove.so:	remove.c
	cc -shared -o remove.so remove.c

test5:	move
	echo "Hello world!\n" > filePROTECT
	LD_PRELOAD=`pwd`/remove.so ./move filePROTECT file2 2> /dev/null
	if [ -f filePROTECT ]; then \
		echo "Test 5 passed."; \
	fi

test: test1 test2 test3 test4 test5

clean:
	rm -rf $(TRASH)