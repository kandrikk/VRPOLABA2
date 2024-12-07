#ifndef LAB2_H
#define LAB2_H
 
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// Прототипы функций
char* strtolower(char *str);
char* strtoupper(char *str);
int strcmp_insensitive(const char *str1, const char *str2);
char* strreverse(char *str);
char* strtrim(char *str);
char* strrmchar(char *str, char symbol);
size_t strcountchar(const char *str, char symbol);
char* substr(const char *str, size_t pos, size_t count);
int strfindlastof(const char *str, const char *symbols);
int strispalindrome(const char *str);
size_t strcountwords(const char *str);
char** strtowords(const char *str, size_t *count);
int strisipv4(const char *str);
size_t* strcountchars(const char *str);

#endif
