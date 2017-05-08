#include <stdio.h>
#include <string.h>

// My own extension to structs and pointers

char* substitute(char* string, char* pattern, char* replacement)
{
    // print position of each pattern match
        // find by finding pattern[i] with strchr
        // if following sequence of characters match
        // if not strchr again with string[+already searched offset]
    // int search_position = 0;

    // char *character_match = strchr(string, pattern[0]);
    char *result = strstr(string, pattern);
    int position = result - string;
    if (result != NULL) {
        printf("match found at %d\n", position);
    }

    char first[50];
    strncpy(first, string, position);
    first[position] = '\0';
    printf("copied: %s\n", first);

    strcat(first, replacement);
    strcat(first, result);

    // printf("result: %s", result);
    printf("final: %s", first);

    return "";
}

int main(int argc, char** argv)
{
    printf("%s\n", substitute("one and one and two three one", "and", "twelve"));
}
