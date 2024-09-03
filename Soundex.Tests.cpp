#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Soundex.h"

char getSoundexCode(char c);
char getValidCode(char currentCode, char lastCode);
void generateSoundex(const char *name, char *soundex);

void test_getSoundexCode() {
   
    assert(getSoundexCode('B') == '1');
    assert(getSoundexCode('J') == '2');
    assert(getSoundexCode('L') == '4');
    assert(getSoundexCode('M') == '5');
    assert(getSoundexCode('A') == '0');
    assert(getSoundexCode(' ') == '0');
    assert(getSoundexCode('b') == '1');
    assert(getSoundexCode('j') == '2');
}

void test_getValidCode() {
    assert(getValidCode('1', '2') == '1');
    assert(getValidCode('2', '2') == '0');
    assert(getValidCode('0', '1') == '0');
}

void test_generateSoundex() {
    char soundex[5];

    generateSoundex("Robert", soundex);
    assert(strcmp(soundex, "R163") == 0);

    generateSoundex("Jackson", soundex);
    assert(strcmp(soundex, "J252") == 0);

    generateSoundex("Li", soundex);
    assert(strcmp(soundex, "L000") == 0);

    generateSoundex("O'Neill", soundex);
    assert(strcmp(soundex, "O541") == 0);

    generateSoundex("", soundex);
    assert(strcmp(soundex, "0000") == 0);
}

int main() {
    test_getSoundexCode();
    test_getValidCode();
    test_generateSoundex();
    return 0;
}
