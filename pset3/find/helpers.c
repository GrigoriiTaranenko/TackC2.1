/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    for (int i = 0; i < n; i++) {
        if (n < 0) return false;
        if (values[i] == value) {
            return true;
        }
    } 
    return false;
}
/**
* Swap variables
*/
void swap(int* i, int* j) 
{
    int Intermediate = *i;
    *i = *j;
    *j = Intermediate;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i = 1; i<n-1; i++) {
        for (int j = 0; j<i; j++ ) {
            if (values[j] > values[j + 1]) {
                swap(&values[j], &values[j+1]);
            }
        }
    }
    return;
}
