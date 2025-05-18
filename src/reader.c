#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    const char *prompt = ">> ";
    const char *history_file = NULL;

    for (int i = 1; i < argc; ++i) {
        if ((strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--history") == 0) && (i + 1 < argc)) {
            history_file = argv[++i];
        } else {
            prompt = argv[i];
        }
    }

    // Open /dev/tty for true terminal I/O
    int tty_fd = open("/dev/tty", O_RDWR);
    if (tty_fd == -1) {
        perror("Cannot open /dev/tty");
        return 1;
    }
    FILE *tty = fdopen(tty_fd, "r+");
    if (!tty) {
        perror("fdopen failed");
        return 1;
    }

    rl_instream = tty;
    rl_outstream = tty;

    if (history_file) {
        read_history(history_file);
    }

    char *input = readline(prompt);

    if (input) {
        if (*input && history_file) {
            add_history(input);
            write_history(history_file);
        }
        puts(input);
        free(input);
    }

    fclose(tty);
    return 0;
}
