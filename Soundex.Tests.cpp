#include <gtest/gtest.h>
#include "Soundex.h"
 
TEST(SoundexTestsuite, ReplaceAlphabetsWithDigitAfterFirstLetter) {
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

TEST(SoudexTestsuite, IgnoresNumbersAndEncodesRemainingCharacters) {
  char soundex[5];
  generateSoundex("17AK", soundex);
  EXPECT_STREQ(soundex,"1200");
  
}

TEST(SoudexTestsuite, ReturnsZerosForDigitOnlyInput) {
  char soundex[5];
  generateSoundex("63619156", soundex);
  EXPECT_STREQ(soundex,"6000");
  
}

TEST(SoudexTestsuite, IgnoresSpecialCharactersAndDigits) {
  char soundex[5];
  generateSoundex("q@!18", soundex);
  EXPECT_STREQ(soundex,"Q000");
  
}

TEST(SoudexTestsuite, EncodesFirstCharacterAndIgnoresDuplicates) {
  char soundex[5];
  generateSoundex("FFFFF", soundex);
  EXPECT_STREQ(soundex,"F100");
  
}
