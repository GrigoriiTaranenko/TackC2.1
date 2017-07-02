#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool checkIntInText(string text) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (((int)text[i] > 47 && (int)text[i] < 58) ||
            ((int)text[i] == 45 && i == 0)) {
            continue;       
        } else {
           return false;   
        }
    }
    return true;
}

int main(int argc, string argv[]) {
    int length, key;
    string cipher;
    
    if (argc != 2) {
        printf("error \n");
        return 1;
    }
    
    if (!checkIntInText(argv[1])) {
        printf("error \n");
        return 1;
    }
   
    key = atoi (argv[1]);
    if (key < 1) {
        printf("error \n");
        return 1;
    }
    printf("key = %i \n", key);
    
    printf("Enter string \n");
    cipher = GetString();
    
    printf("%s \n", cipher);
    length = strlen(cipher);

    
    for (int i = 0; i<length; i++) {
        if (isalpha(cipher[i]) && (int)cipher[i] > 96) {
            cipher[i] = ((int)cipher[i] - 97 + key) % 26 + 97;
        } else if (isalpha(cipher[i])) {
            cipher[i] = (((int)cipher[i] + key - 65) % 26) + 65;
        }
        printf("%c \n", cipher[i]);
    }
     
    return 0;
}


