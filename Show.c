
int main(int argc, char* argv[]) {
        if (argc < 2) {
                printf("Too few arguments. Specify path to file you wan to display\n");
                return 1;
        }
        setlocale(LC_ALL, "");

        FILE *f = fopen(argv[1], "rt");

        int line_count = 0, i = 0;

        size_t bufsize = 100;
        char *buffer = (char *)malloc(bufsize * sizeof(char));

        while ((len = getline(&buffer, &bufsize, f)) != -1) {
                i++;
        }

        for (i = 0; i < line_count; i++) {
                free(lines[i]);
        }
        free(buffer);
        fclose(f);
}