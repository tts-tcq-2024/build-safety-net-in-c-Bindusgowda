#include "Soundex.h"

TEST(SoudexTestsuite, testSoundex) {
	char soundex[MAX_CODE_LENGTH + 1];
	generateSoundex("Robert", soundex);
	ASSERT_EQ(strcmp(soundex, "R163"), 0);

	generateSoundex("Rupert", soundex);
	ASSERT_EQ(strcmp(soundex, "R163"), 0);

	generateSoundex("Aeiou", soundex);
	ASSERT_EQ(strcmp(soundex, "A000"), 0);

	generateSoundex("1234", soundex);
	ASSERT_EQ(strcmp(soundex, "1000"), 0);

	generateSoundex("J@hn!", soundex);
	ASSERT_EQ(strcmp(soundex, "J500"), 0);
    
	generateSoundex(",", soundex);
	ASSERT_EQ(strcmp(soundex, "0000"), 0);
    
	generateSoundex("A", soundex);
	ASSERT_EQ(strcmp(soundex, "A000"), 0);
    
	generateSoundex("Aaaaaa", soundex);
	ASSERT_EQ(strcmp(soundex, "A000"), 0);
    
    generateSoundex("sOmeTeSt", soundex);
	ASSERT_EQ(strcmp(soundex, "S530"), 0);
    
    generateSoundex("abcdefghijklmnopqrstuvwxyz", soundex);
	ASSERT_EQ(strcmp(soundex, "A123"), 0);

}
