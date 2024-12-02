
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

        line_count = i;

        fseek(f, 0, SEEK_SET);

        char *lines[line_count];

        for (i = 0; i < line_count; i++) {
                lines[i] = (char *) malloc(bufsize * sizeof(char));
                len = getline(&(lines[i]), &bufsize, f);
                lines[i][strcspn(lines[i], "\n")] = '\0';

        }

        WINDOW *win;
        int c = 0;

        initscr();
        noecho();
        cbreak();
        mvprintw(0, 0, "File: %s, lines: %d", argv[1], line_count);
        refresh();

        int width = COLS - 2 * DX, height = LINES - 2 * DX - 2;
        win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
        keypad(win, TRUE);
        scrollok (win, TRUE);
        box(win, 0, 0);
        wmove(win, 1, 0);

        for (i = 0; i < line_count; i++) {
                free(lines[i]);
        }
        free(buffer);
        fclose(f);
}