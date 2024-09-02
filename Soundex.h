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
    if (name[0] == '\0') {
        soundex[0] = '\0';
        return;
    }

    size_t len = strlen(name);
    char prevCode = '0';
    size_t index = 0;

    soundex[index++] = toupper(name[0]);
    prevCode = getSoundexCode(name[0]);

    for (size_t i = 1; i < len && index < MAX_LENGTH - 1; ++i) {
        char code = getSoundexCode(name[i]);
        if (code != '0' && code != prevCode) {
            soundex[index++] = code;
            prevCode = code;
        }
    }

    while (index < MAX_LENGTH) {
        soundex[index++] = '0';
    }
    soundex[index] = '\0'; // Null-terminate the result
}
