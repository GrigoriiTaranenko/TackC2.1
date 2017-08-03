#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

const char maxNumberSymbol = 9;
const char minNumberSymbol = 0;

const char minLowerAlpha = 'a';
const char minUpperAlpha = 'A';

char checkNumber(string number) {    
    for (int i = 0; number[i] != '\0'; i++) {
        char symbol = number[i] - '0';
        if (symbol > maxNumberSymbol || symbol < minNumberSymbol) {
            return 0;   
        }
    }
    return 1; 
}

char transformation(char letter, char regist, int key) {
    key = key % 26;
    letter = (letter - regist + key) % 26;
    letter += regist;
    return letter;
}

int main(int argc, string argv[]) {
    int key;
    string cipher;
    if (argc != 2) {
        printf("error \n");
        return 1;
    }
    
    if (checkNumber(argv[1]) == 0) {
        return 1;
    }
    
    key = atoi(argv[1]);
 
    cipher = GetString();
    
    for (int i = 0; cipher[i] != '\0'; i++) {
        if (isalpha(cipher[i]) != 0 && islower(cipher[i]) != 0) {
            cipher[i] = transformation(cipher[i], minLowerAlpha, key);
        } else if (isalpha(cipher[i]) !=0) {
            cipher[i] = transformation(cipher[i], minUpperAlpha, key);
        }
    }
    printf("%s\n", cipher);
    
    return 0;
}
