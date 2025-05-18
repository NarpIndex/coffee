#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

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

    if (history_file) {
        read_history(history_file);
    }

    char *input = readline(prompt);

    if (input) {
        if (*input && history_file) {
            add_history(input);
            write_history(history_file);
        }

        // Only print the input!
        puts(input);
        free(input);
    }

    return 0;
}
