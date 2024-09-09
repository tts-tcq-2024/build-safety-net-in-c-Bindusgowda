#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTestsuite, ReplaceConstatntsWithDigitsAfterFirstLetter) {
    char soundex[5];
    generateSoundex("Aeiou", soundex);
    ASSERT_STREQ(soundex, "A000");
}
 
TEST(SoundexTestsuite, AppendThreeZerosIfResultContainsLessThanThreeDigits) {
    char soundex[5];
    generateSoundex("N", soundex);
    ASSERT_STREQ(soundex, "N000");
}
 
TEST(SoundexTestsuite, RemoveAllExceptTheFirstLetterAndThreeDigitsAfterIt) {
    char soundex[5];
    generateSoundex("abcdefghijklmnopqrstuvwxyz", soundex);
    ASSERT_STREQ(soundex, "A123");
}
 
TEST(SoundexTestsuite, UppercasesFirstLetterAndReplaceWithDigits) {
    char soundex[5];
    generateSoundex("abcd", soundex);
    ASSERT_STREQ(soundex, "A123");
}
 
TEST(SoundexTestsuite, CheckForCaseSensitive) {
    char soundex[5];
    generateSoundex("BCDL", soundex);
    ASSERT_STREQ(soundex, "B234");
}
