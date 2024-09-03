#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <gtest/gtest.h>
#include "Soundex.h"
 
void testSoundex(const char *input, const char *expected) {
    char soundex[5];
    generateSoundex(input, soundex);
}
 
int main() {
    testSoundex("Robert", "R163");
    testSoundex("Rupert", "R163");
    testSoundex("Aeiou", "A000");
    testSoundex("1234", "1000");
    testSoundex("J@hn!", "J500");
    testSoundex("", "0000");
    testSoundex("A", "A000");
    testSoundex("Aaaaaa", "A000");
    testSoundex("sOmeTeSt", "S530");
    testSoundex("abcdefghijklmnopqrstuvwxyz", "A123");
 
    return 0;
}
