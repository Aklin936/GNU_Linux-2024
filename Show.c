#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ncurses.h>

#define DX 1

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Too few arguments. Specify path to file you want to display\n");
        return 1;
    }

    setlocale(LC_ALL, "");

    FILE *f = fopen(argv[1], "rt");
    if (!f) {
        perror("Error opening file");
        return 1;
    }

    int line_count = 0;
    size_t bufsize = 100;
    char *buffer = malloc(bufsize * sizeof(char));
    ssize_t len;

    if (!buffer) {
        perror("Unable to allocate buffer");
        fclose(f);
        return 1;
    }

    while ((len = getline(&buffer, &bufsize, f)) != -1) {
        line_count++;
    }

    fseek(f, 0, SEEK_SET);

    char **lines = malloc(line_count * sizeof(char *));
    if (!lines) {
        perror("Unable to allocate lines");
        free(buffer);
        fclose(f);
        return 1;
    }

    for (int i = 0; i < line_count; i++) {
        lines[i] = malloc(bufsize * sizeof(char));
        if (!lines[i]) {
            perror("Unable to allocate line");
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) free(lines[j]);
            free(lines);
            free(buffer);
            fclose(f);
            return 1;
        }
        len = getline(&(lines[i]), &bufsize, f);
        lines[i][strcspn(lines[i], "\n")] = '\0';
    }

    fclose(f);

    WINDOW *win;
    int c = 0;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    mvprintw(0, 0, "File: %s, lines: %d", argv[1], line_count);
    refresh();

    int width = COLS - 2 * DX, height = LINES - 2 * DX - 2;
    win = newwin(LINES - 2 * DX, COLS - 2 * DX, DX, DX);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    box(win, 0, 0);
    wmove(win, 1, 0);

    int line = 0, offset = 0;

    while (1) {
        werase(win);
        box(win, 0, 0);

        for (int i = 0; i < height && (line + i) < line_count; i++) {
            mvwprintw(win, i + 1, 1, "%5d: %.*s", line + i + 1, width - 10, lines[line + i] + offset);
        }

        wrefresh(win);
        c = wgetch(win);
        if (c == 27)  // Escape key to exit
            break;

        switch (c) {
            case KEY_DOWN:
                line = ((line + height) >= line_count) ? line : line + 1;
                break;
            case KEY_UP:
                line = (line > 0) ? line - 1 : 0;
                break;
            case KEY_RIGHT:
                offset++;
                break;
            case KEY_LEFT:
                offset = (offset > 0) ? offset - 1 : 0;
                break;
            case KEY_NPAGE:
                line = ((line + height) >= line_count) ? line_count - height : line + height;
                break;
            case KEY_PPAGE:
                line = (line < height) ? 0 : line - height;
                break;
            default:
                continue;
        }
    }

    endwin();

    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }
    free(lines);
    free(buffer);

    return 0;
}

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

        int line = 0, offset = 0;

        while (1) {
                werase(win);
                box(win, 0, 0);
                wrefresh(win);

                for (i = 1; i <= height; i++) {
                        mvwprintw(win, i, 1, "%5d: %.*s", line + i, width - 10, lines[line + i] + offset);
                }

                c = wgetch(win);
                if (c == 27)
                        break;

                switch(c) {
                case KEY_DOWN: line = ((line + height + 2) > line_count) ? line : line + 1; break;
                case KEY_UP: line = ((line < 1) ? line : line - 1); break;
                case KEY_RIGHT: offset++; break;
                case KEY_LEFT: offset = ((offset < 1) ? offset: offset - 1); break;
                case KEY_NPAGE: line = ((line + 2 * height + 1) > line_count) ? line_count - height - 1 : line + height;; break;
                case KEY_PPAGE: line = ((line < height) ? 0 : line - height); break;
                default: continue;
                }
        }

        endwin();

        for (i = 0; i < line_count; i++) {
                free(lines[i]);
        }
        free(buffer);
        fclose(f);
}