#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// enum ElementType { string_element,
//     integer_element,
//     double_element,
//     sexp_element,
//     operator_element };
//
// struct Element {
//     enum ElementType type;
//     void *data;
// };
//
// void read_from_tokenized_string(char *input)
// {
//     struct Element mother_sexp;
//     mother_sexp.type = sexp_element;
//
//     // int read_counter = 0;
//     // char next_char;
//
// }


void tokenize(char *input)
{
    char output[4096];
    // char *output = malloc(4096);

    int read_counter = 0;
    int write_counter = 0;
    char next_char;
    while ((next_char = input[read_counter]) != '\0') {
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
    // return output;
    printf("%s\n", output);

    char *token_output[4096];
    int token_read_counter = 0;

    char *token = strtok(output, " ");
    token_output[token_read_counter] = token;
    printf("%s\n", token_output[0]);
    token_read_counter++;

    token = strtok(output, " ");
    while(token == NULL) {
        token = strtok(output, " ");
    }
    token_output[token_read_counter] = token;
    printf("%s\n", token_output[token_read_counter]);
    token_read_counter++;

    // while (token != NULL) {
    //     token_output[token_read_counter] = token;
    //     token = strtok(output, " ");
    //     token_read_counter++;
    // }

    // for (int i = 0; i < token_read_counter; i++) {
    //     printf("%s\n", token_output[i]);
    // }
}

int main(int argc, char **argv)
{
    tokenize("(+ 40 40)");
    // printf("%s\n", tokenize("(+ 40 40)"));
    // printf("%s\n", tokenize("(def x (+ 30 30 150))"));
    return 0;
}
