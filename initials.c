#include <stdio.h>
#include <cs50.h>

int main () {
   string fullName;
   char checkSpace = 1;
   fullName = GetString();
   for (int i = 0; fullName[i] != '\0'; i++) {
       if (checkSpace == 1) {
            if (fullName[i] >= 'a') { 
                fullName[i] = fullName[i] - 'a' + 'A';
            }
            checkSpace = 0;
            printf("%c", fullName[i]);                                     
       }
       if (fullName[i] == ' ') {
           checkSpace = 1;
       }
   }
   return 0;
} 
