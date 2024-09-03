#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <gtest/gtest.h>
#include "Soundex.h"
 
void testSoundex(const char *input, const char *expected) {
    char soundex[5];
    generateSoundex("Robert", "R163");
    generateSoundex("Rupert", "R163");
    generateSoundex("Aeiou", "A000");
    generateSoundex("1234", "1000");
    generateSoundex("J@hn!", "J500");
    generateSoundex("", "0000");
    generateSoundex("A", "A000");
    generateSoundex("Aaaaaa", "A000");
    generateSoundex("sOmeTeSt", "S530");
    generateSoundex("abcdefghijklmnopqrstuvwxyz", "A123");
 
    return 0;
}
