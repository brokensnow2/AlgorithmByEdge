#include "str.h"
#include <stdio.h>
#include <stdlib.h>

void initString(Str* str, const char* source) {
    str->length = strlen(source);
    str->ch = (char*)malloc((str->length + 1) * sizeof(char));
    strcpy(str->ch, source);
}

void destroyString(Str* str) {
    free(str->ch);
    str->ch = NULL;
    str->length = 0;
}

int isEqual(const Str* str1, const Str* str2) {
    if (str1->length != str2->length) {
        return 0;  // 长度不相等，直接返回不相等
    }
    return strcmp(str1->ch, str2->ch) == 0;
}

Str* concat(const Str* str1, const Str* str2) {
    Str* result = (Str*)malloc(sizeof(Str));
    int totalLength = str1->length + str2->length;
    result->ch = (char*)realloc(result->ch, (totalLength + 1) * sizeof(char));
    strcpy(result->ch, str1->ch);
    strcat(result->ch, str2->ch);
    result->length = totalLength;
}