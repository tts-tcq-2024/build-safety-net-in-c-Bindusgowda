#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTestsuite, ReplaceConstatntsWithDigitAfterFirstLetter) {
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

TEST(SoudexTestsuite, NumbersWithCharacters) {
  char soundex[5];
  generateSoundex("17AK", soundex);
  EXPECT_STREQ(soundex,"1200");
  
}

TEST(SoudexTestsuite, SpecialCharactersWithDigits) {
  char soundex[5];
  generateSoundex("q@!18", soundex);
  EXPECT_STREQ(soundex,"Q000");
  
}

TEST(SoudexTestsuite, SameCharactersRepeating) {
  char soundex[5];
  generateSoundex("FFFFF", soundex);
  EXPECT_STREQ(soundex,"F100");
  
}
 
TEST(SoundexTestsuite, CheckForCaseSensitive) {
    char soundex[5];
    generateSoundex("BCDL", soundex);
    ASSERT_STREQ(soundex, "B234");
}
