#include "lab2.h"

char* strtolower(char *str) {
    char *ptr = str;
    while (*ptr) {
        *ptr = tolower((unsigned char)*ptr);
        ptr++;
    }
    return str;
}

char* strtoupper(char *str) {
    char *ptr = str;
    while (*ptr) {
        *ptr = toupper((unsigned char)*ptr);
        ptr++;
    }
    return str;
}

int strcmp_insensitive(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = tolower((unsigned char)*str1);
        char c2 = tolower((unsigned char)*str2);
        if (c1 != c2) return c1 - c2;
        str1++;
        str2++;
    }
    return tolower((unsigned char)*str1) - tolower((unsigned char)*str2);
}

char* strreverse(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    return str;
}

char* strtrim(char *str) {
    if (!str) return str;
    char *end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char* strrmchar(char *str, char symbol) {
    char *src = str, *dst = str;
    while (*src) {
        if (*src != symbol) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
    return str;
}

size_t strcountchar(const char *str, char symbol) {
    size_t count = 0;
    const char *ptr = str;
    while ((ptr = strchr(ptr, symbol)) != NULL) {
        count++;
        ptr++;
    }
    return count;
}

char* substr(const char *str, size_t pos, size_t count) {
    size_t len = strlen(str);
    if (pos >= len) return NULL;
    size_t max_count = len - pos;
    count = count > max_count ? max_count : count;
    char *result = (char*)malloc(count + 1);
    if (!result) return NULL;
    strncpy(result, str + pos, count);
    result[count] = '\0';
    return result;
}

int strfindlastof(const char *str, const char *symbols) {
    int last_index = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (strchr(symbols, str[i]) != NULL) {
            last_index = i;
        }
    }
    return last_index;
}

int strispalindrome(const char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (!isalnum((unsigned char)str[left])) {
            left++;
            continue;
        }
        if (!isalnum((unsigned char)str[right])) {
            right--;
            continue;
        }
        if (tolower((unsigned char)str[left]) != tolower((unsigned char)str[right])) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

size_t strcountwords(const char *str) {
    size_t count = 0;
    int in_word = 0;
    while (*str) {
        if (isspace((unsigned char)*str)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
        str++;
    }
    return count;
}

// Вспомогательная функция для сравнения строк (чувствительность к регистру отключена)
int case_insensitive_compare(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    return strcasecmp(str1, str2);
}

// Основная функция
char** strtowords(const char *str, size_t *count) {
    *count = 0;
    if (!str || strlen(str) == 0) return NULL;

    // Создаем копию строки, чтобы использовать strtok
    char *copy = strdup(str);
    if (!copy) return NULL;

    char **words = NULL;
    char *token = strtok(copy, " \t\n.,!?;:\"'()[]{}<>"); // Разделители

    // Разбиваем строку на слова
    while (token) {
        // Увеличиваем массив под новое слово
        char **new_words = realloc(words, (*count + 1) * sizeof(char *));
        if (!new_words) {
            free(copy);
            for (size_t i = 0; i < *count; i++) free(words[i]);
            free(words);
            return NULL;
        }
        words = new_words;

        // Сохраняем слово в массив
        words[*count] = strdup(token);
        if (!words[*count]) {
            free(copy);
            for (size_t i = 0; i < *count; i++) free(words[i]);
            free(words);
            return NULL;
        }

        (*count)++;
        token = strtok(NULL, " \t\n.,!?;:\"'()[]{}<>");
    }

    free(copy);

    // Сортируем массив слов в алфавитном порядке
    if (*count > 1) {
        qsort(words, *count, sizeof(char *), case_insensitive_compare);
    }

    return words;
}

int strisipv4(const char *str) {
    int segments = 0;
    int value;
    char *copy = strdup(str);
    if (!copy) return 0;
    char *token = strtok(copy, ".");
    while (token) {
        if (!isdigit(*token) || (value = atoi(token)) < 0 || value > 255) {
            free(copy);
            return 0;
        }
        segments++;
        token = strtok(NULL, ".");
    }
    free(copy);
    return segments == 4;
}

size_t* strcountchars(const char *str) {
    size_t *counts = calloc(256, sizeof(size_t));
    if (!counts) return NULL;
    while (*str) {
        counts[(unsigned char)*str]++;
        str++;
    }
    return counts;
}
