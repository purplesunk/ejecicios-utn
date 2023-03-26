#ifndef STRINGRE_H
#define STRINGRE_H

int strlen(const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int strcmp(const char *str_one, const char *str_two) 
{
    int lenght;
    if (strlen(str_one) > strlen(str_two)) {
        lenght = strlen(str_one);
    }
    else {
        lenght = strlen(str_two);
    }

    for (int i = 0; i < lenght; i++) {
        if (str_one[i] > str_two[i]) {
            return 1;
        } 
        else if (str_one[i] < str_two[i]) {
            return -1;
        }
    }  

    return 0;
}

void strcpy(char *dest, const char *src) {
    int i;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

void strcat(char *dest, const char *src) {
    int i;
    for (i = 0; dest[i] != '\0'; i++);
    
    int j;
    for (j = 0; src[j] != '\0'; j++, i++) {
        dest[i] = src[j];
    }
    dest[i] = '\0';
}

#endif /* STRINGRE_H */