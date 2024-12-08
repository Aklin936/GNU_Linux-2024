#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <sys/stat.h>

#define BUFSIZE 1000


int main(int argc, char const *argv[])
{
	if (argc < 3) {
		fprintf(stdout, "%s\n", "help");
	}

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

	struct stat file_status;
	if (stat(argv[1], &file_status) < 0) {
        perror("Error. Could not get input file size");
        remove(argv[2]);
        return 3;
    }
    long infile_size = file_status.st_size;

		return 6;
	}

    if (infile_size != total_bytes * sizeof(char)) {
    	remove(argv[2]);
    	fprintf(stderr, "%s\n", "Error. File sizes do not match. Abort moving");
    	return 7;
    }

	fclose(f_in);
	fclose(f_out);

	remove(argv[1]);

	return 0;
}