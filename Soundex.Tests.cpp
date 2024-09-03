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

    getSoundexCode('B'); 
    getSoundexCode('J'); 
    getSoundexCode('L'); 
    getSoundexCode('M'); 

    getSoundexCode('A'); 
    getSoundexCode(' '); 
    
    getSoundexCode('b'); 
    getSoundexCode('j'); 
}

void test_getValidCode() {

    getValidCode('1', '2');

    getValidCode('2', '2'); 

    getValidCode('0', '1'); 

void test_generateSoundex() {
    char soundex[5];
    
    generateSoundex("Robert", soundex);
    
    generateSoundex("Jackson", soundex);
    
    generateSoundex("Li", soundex);

    generateSoundex("O'Neill", soundex);
    
    generateSoundex("", soundex);
}
