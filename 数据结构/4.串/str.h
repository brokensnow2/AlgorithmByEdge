#ifndef STR_H
#define STR_H

typedef struct { 
    char *ch; 
    int length; 
}Str;

void initString(Str* str, const char* source);

void destroyString(Str* str);

Str* concat(const Str* str1, const Str* str2) ;

#endif