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
    // Testing getSoundexCode

    // Test valid input characters
    getSoundexCode('B'); // Expected: 1
    getSoundexCode('J'); // Expected: 2
    getSoundexCode('L'); // Expected: 4
    getSoundexCode('M'); // Expected: 5

    // Test invalid input characters
    getSoundexCode('A'); // Expected: 0
    getSoundexCode(' '); // Expected: 0

    // Test case insensitivity
    getSoundexCode('b'); // Expected: 1
    getSoundexCode('j'); // Expected: 2
}

void test_getValidCode() {
    // Testing getValidCode

    // Test different current code
    getValidCode('1', '2'); // Expected: 1

    // Test same current code as last code
    getValidCode('2', '2'); // Expected: 0

    // Test invalid current code
    getValidCode('0', '1'); // Expected: 0
}

void test_generateSoundex() {
    char soundex[5];
    
    // Test simple name
    generateSoundex("Robert", soundex);
    
    // Test name with multiple identical consonants
    generateSoundex("Jackson", soundex);
    
    // Test short name
    generateSoundex("Li", soundex);
    
    // Test name with non-alphabet characters
    generateSoundex("O'Neill", soundex);
    
    // Test empty name
    generateSoundex("", soundex);
}
