#include <ctype.h>
#include <string.h>

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
void initializeSoundex(const char* name, char* soundex) {
    if (name[0] != '\0') {
        soundex[0] = toupper(name[0]);
        char secondex = getSoundexCode(name[1]);
        soundex[1] = (secondex != '0') ? secondex : '\0';
        soundex[2] = '\0'; // Null-terminate the string
    }
}


char getFirstCharCode(const char* name) {
    if (name[0] != '\0') {
        return toupper(name[0]);
    }
    return '\0';
}

void addSoundexCode(char* soundex, char code, char* prevCode) {
    if (code != '0' && code != *prevCode) {
        size_t len = strlen(soundex);
        if (len < SOUNDDEX_LENGTH - 1) {
            soundex[len] = code;
            soundex[len + 1] = '\0';
        }
        *prevCode = code;
    }
}


void processName(const char* name, char* soundex) {
    initializeSoundex(name, soundex);
    char prevCode = soundex[1];
    
    for (size_t i = 2; i < strlen(name) && strlen(soundex) < SOUNDDEX_LENGTH; ++i) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(soundex, code, &prevCode);
    }
}


void padSoundex(char* soundex) {
    size_t len = strlen(soundex);
    while (len < SOUNDDEX_LENGTH - 1) {
        soundex[len++] = '0';
    }
    soundex[SOUNDDEX_LENGTH - 1] = '\0'; // Null-terminate
}


void generateSoundex(const char* name, char* result) {
    if (name[0] != '\0') {
        char processedName[SOUNDDEX_LENGTH] = {0};
        char firstChar = getFirstCharCode(name);
        processName(name, processedName);
        padSoundex(processedName);
        strcpy(result, processedName);
    } else {
        result[0] = '\0'; // Empty result for empty name
    }
}
