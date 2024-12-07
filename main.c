#include "lab2.h"

int main() {
    char str1[] = "hello";
    char str2[] = "HELLO";
    char str3[] = "!hello";
    printf("1.strtolower: %s\n", strtolower(str2));
    printf("2.strtoupper: %s\n", strtoupper(str1));
    printf("3.strcmp_insensitive: %d\n", strcmp_insensitive(str1, str2));
    printf("  strcmp_insensitive: %d\n", strcmp_insensitive(str1, str3));

    char str4[] = "hello";
    printf("4.strreverse: %s\n", strreverse(str4));

    char str5[] = "   hello   ";
    printf("5.strtrim: %s\n", strtrim(str5));

    char str6[] = "hello";
    printf("6.strrmchar: %s\n", strrmchar(str6, 'o'));

    char str7[] = "hello";
    printf("7.strcountchar: %zu\n", strcountchar(str7, 'l'));

    char *substring = substr("hello", 0, 4);
    printf("8.substr: %s\n", substring);
    free(substring);

    printf("9.strfindlastof: %d\n", strfindlastof("hello", "abcde"));

    char str10[] = "Go hang a salami I'm a lasagna hog";
    printf("10.strispalindrome: %d\n", strispalindrome(str10));

    char str11[] = "Was it a car or a cat I saw";
    printf("11.strcountwords: %zu\n", strcountwords("Was it a car or a cat I saw"));

    char str12[] = "Was it a car or a cat I saw?";
    size_t count = 0;

    char **words = strtowords(str12, &count);
    printf("12.strtowords: ");
    if (words) {
        for (size_t i = 0; i < count; i++) {
            printf("%s", words[i]); 
            if (i < count - 1) {
                printf(";"); 
            }
            free(words[i]);
        }
        printf("\n");
        free(words);

    printf("13.strisipv4: %d\n", strisipv4("192.168.0.1"));
    printf("   strisipv4: %d\n", strisipv4("192.168.1.0/24"));
    printf("   strisipv4: %d\n", strisipv4("192.168.0.256"));
    printf("   strisipv4: %d\n", strisipv4("092.01.0.1"));

    size_t *char_counts = strcountchars("hello");
    printf("14.strcountchars: %zu\n", char_counts['l']);
    free(char_counts);

    return 0;
    }
}

