#include <stdio.h>

int main(int argc, char **argv)
{
    char *example_string = "(def x (+ 30 30 150))";
    char output[4096];

    int read_counter = 0;
    int write_counter = 0;
    char next_char;
    while ((next_char = example_string[read_counter]) != '\0') {
        if (next_char == '(' || next_char == ')') {
            output[write_counter] = ' ';
            output[write_counter + 1] = next_char;
            output[write_counter + 2] = ' ';
            write_counter = write_counter + 3;
        } else {
            output[write_counter] = next_char;
            write_counter++;
        }
        read_counter++;
    }

    output[write_counter + 1] = '\0';
    printf("%s\n", output);
    return 0;
}
