#include <ctype.h>
#include<string.h>

typedef struct {
    char sound;
    char value;
} SoundexMapping;

static const SoundexMapping soundexMappings[] = {
    {'B', '1'}, {'F', '1'}, {'P', '1'}, {'V', '1'},
    {'C', '2'}, {'G', '2'}, {'J', '2'}, {'K', '2'}, {'Q', '2'},
    {'S', '2'}, {'X', '2'}, {'Z', '2'},
    {'D', '3'}, {'T', '3'},
    {'L', '4'},
    {'M', '5'}, {'N', '5'},
    {'R', '6'}
};

#define MAPPING_COUNT (sizeof(soundexMappings) / sizeof(SoundexMapping))

char getSoundexCode(char c) {
    c = toupper(c);

    for (int i = 0; i < MAPPING_COUNT; i++) {
        if (soundexMappings[i].sound == c) {
            return soundexMappings[i].value;
        }
    }

        return '0'; 
}

void generateSoundex(const char *name, char *soundex) {
    if (!name || !soundex) {
        return; 
    }

    soundex[0] = toupper(name[0]);
    soundex[1] = soundex[2] = soundex[3] = '0';
    soundex[4] = '\0'; 
    int soundexIndex = 1;
    char previousCode = '0';

    for (int i = 1; name[i] != '\0' && soundexIndex < 4; ++i) {
        char currentCode = getSoundexCode(name[i]);

        if (currentCode != '0' && currentCode != previousCode) {
            soundex[soundexIndex++] = currentCode;
        }

        previousCode = currentCode;
    }
}
