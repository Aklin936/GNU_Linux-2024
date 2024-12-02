clean:
	rm -f *~ *.o Show

Show: Show.c
	cc -Wall Show.c -o Show -lncursesw
