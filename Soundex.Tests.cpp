#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <gtest/gtest.h>
#include "Soundex.h"

TEST(SoudexTestsuite, ReplacesConsonantsWithAppropriateDigits) {
    char soundex[5];
    generateSoundex("AX", soundex);
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

}
