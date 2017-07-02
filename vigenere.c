#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

bool checkIntInText(string text) {
    int length = strlen(text);
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            continue;       
        } else {
           return false;  
        }
    }
    return true;
}

int registerText(char letter) {
    if ((int)letter>96) {
        return (int)letter - 97;
    } else {
        return (int)letter - 65;
    }
}

int signSize(char letter) {
    if ((int)letter>96) {
        return 97;
    } else {
        return 65;
    }
}


int main(int argc, string argv[]) {
    string key, cipher;
    int lengthKey, lengthCifre, numberKey;
    if (argc != 2 || !checkIntInText(argv[1])) {
        printf("error \n");
        return 1;
    }
    key = argv[1];
    lengthKey = strlen(key);
    printf("%s, \n", key);
    numberKey = 0;
    
    printf("Enter string \n");
    cipher = GetString();
    lengthCifre = strlen(cipher);
    

    for (int i = 0; i<lengthCifre; i++) {
        if (isalpha(cipher[i])) {
            cipher[i] = (registerText(cipher[i]) + registerText(key[numberKey])) % 26 + signSize(cipher[i]);
        }
        numberKey = (numberKey + 1) % lengthKey;
    }
    printf("cipher = %s \n", cipher);
}
