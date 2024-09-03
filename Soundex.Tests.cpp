#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Soundex.h"

void test_getSoundexCode();
void test_getValidCode();
void test_generateSoundex();

int main() {
    test_getSoundexCode();
    test_getValidCode();
    test_generateSoundex();
    return 0;
}

void test_getSoundexCode() {
    printf("Testing getSoundexCode:\n");
    
    // Test valid input characters
    printf("B -> %c\n", getSoundexCode('B')); // Expected: 1
    printf("J -> %c\n", getSoundexCode('J')); // Expected: 2
    printf("L -> %c\n", getSoundexCode('L')); // Expected: 4
    printf("M -> %c\n", getSoundexCode('M')); // Expected: 5

    // Test invalid input characters
    printf("A -> %c\n", getSoundexCode('A')); // Expected: 0
    printf("  -> %c\n", getSoundexCode(' ')); // Expected: 0

    // Test case insensitivity
    printf("b -> %c\n", getSoundexCode('b')); // Expected: 1
    printf("j -> %c\n", getSoundexCode('j')); // Expected: 2
}

void test_getValidCode() {
    printf("Testing getValidCode:\n");

    // Test different current code
    printf("1, 2 -> %c\n", getValidCode('1', '2')); // Expected: 1

    // Test same current code as last code
    printf("2, 2 -> %c\n", getValidCode('2', '2')); // Expected: 0

    // Test invalid current code
    printf("0, 1 -> %c\n", getValidCode('0', '1')); // Expected: 0
}

void test_generateSoundex() {
    printf("Testing generateSoundex:\n");
    char soundex[5];
    
    // Test simple name
    generateSoundex("Robert", soundex);
    printf("Robert -> %s\n", soundex); // Expected: R163

    // Test name with multiple identical consonants
    generateSoundex("Jackson", soundex);
    printf("Jackson -> %s\n", soundex); // Expected: J252

    // Test short name
    generateSoundex("Li", soundex);
    printf("Li -> %s\n", soundex); // Expected: L000

    // Test name with non-alphabet characters
    generateSoundex("O'Neill", soundex);
    printf("O'Neill -> %s\n", soundex); // Expected: O541

    // Test empty name
    generateSoundex("", soundex);
    printf("Empty -> %s\n", soundex); // Expected: 0000
}
