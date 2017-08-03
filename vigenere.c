#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


const char minLowerAlpha = 'a';
const char minUpperAlpha = 'A';

char transformation(char letter, char regist, int key) {
    letter = (letter - regist + key) % 26;
    letter += regist;
    return letter;
}

char numberSymbol(char alpha) {
    if (alpha - 'a' >= 0) {
        return alpha - 'a';
    } else {
        return alpha - 'A';
    }
}

void addNumber(int *i, char alpha) {
    if (alpha == '\0') {
        *i = 0;
    } else {
        *i += 1; 
    }
}

char checkKey(string key) { 
    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha(key[i])) {
            return 0; 
        }
    }
    return 1;
}


int main(int argc, string argv[]) {
    string key, cipher;
    char symbol;
    int j = 0;
    
    if (argc != 2) {
        printf("error \n");
        return 1;
    }
    
    key = argv[1];
    
    if (!checkKey(key)) {
        printf("error \n");
        return 1;
    } 
    
    cipher = GetString();
    
    for (int i = 0; cipher[i] != '\0'; i++ ) {
        if (isalpha(cipher[i]) != 0) {
        
            symbol = numberSymbol(key[j]);
            
            if (islower(cipher[i]) != 0) {        
                cipher[i] = transformation(cipher[i], 'a', symbol);    
            } else {
                cipher[i] = transformation(cipher[i], 'A', symbol);    
            }
            
            addNumber(&j, key[j+1]);
        }
    }
    
    printf("%s\n", cipher);
    
    return 0;
}
