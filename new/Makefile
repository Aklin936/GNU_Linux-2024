TRASH = *.o *~ esub file*
CFLAGS=-o0 -g

.SILENT: test1 test2

all:	test

esub:	esub.o

test:	test1 test2

test1:	esub
	echo 'string' | sed -E s/str/sub/ > file1
	./esub str sub string > file2

	if cmp file1 file2; then \
		echo "Test 1 passed."; \
	fi

clean:
	rm -f ${TRASH}