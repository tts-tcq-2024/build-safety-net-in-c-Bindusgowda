#include <assert.h>
#include <stdio.h>

void testGenerateSoundex(const char *name, const char *expectedSoundex) {
    char soundex[5];
    generateSoundex(name, soundex);
    assert(strcmp(soundex, expectedSoundex) == 0);
}

int main() {
    
    testGenerateSoundex("Robert", "R163");
    testGenerateSoundex("Rupert", "R163");
    testGenerateSoundex("Rubin", "R150");
    testGenerateSoundex("Ashcraft", "A261");
    testGenerateSoundex("Tymczak", "T252");

    // Edge Cases
    testGenerateSoundex("", "0000");
    testGenerateSoundex("Xyz", "X020");
    testGenerateSoundex("123", "0000");  

    testGenerateSoundex("robert", "R163");
    testGenerateSoundex("RuBeRt", "R163");
    testGenerateSoundex("ASHCRAFT", "A261");

    testGenerateSoundex("Alexander", "A425");

    return 0;
}

