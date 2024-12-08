#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFSIZE 1000

int main(int argc, char const *argv[])
{

    long infile_size = file_status.st_size;

	char buffer[BUFSIZE];
	size_t nmemb = sizeof(buffer) / sizeof(char);
	size_t bytes_read, total_bytes = 0;

	FILE *f_in = fopen(argv[1], "rb");
	if (f_in == NULL) {
		perror("Error. Could not open infile");
		return 1;
	}

	FILE *f_out = fopen(argv[2], "w");
	if (f_out == NULL) {
		perror("Error. Could not open outfile");
		return 2;
	}

	fclose(f_in);
	fclose(f_out);

	remove(argv[1]);
	return 0;
}