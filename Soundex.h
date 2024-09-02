#include <stdio.h>
#include <ctype.h>
#include <string.h>

char getSoundexCode(char c) {
    static const char soundexCodes[] = "BFPV:1;CGJKQ:2;SZ:2;DT:3;L:4;MN:5;R:6;";
    
    c = toupper(c);
    for (const char *p = soundexCodes; *p; p += 4) {
        if (*p == c) {
            return *(p + 2);
        }
    }
    return '0'; 
}

void initializeSoundex(const char *name, char *soundex) {
    soundex[0] = toupper(name[0]);
    soundex[1] = getSoundexCode(name[1]);
    if (soundex[1] == '0') {
        soundex[1] = '\0'; 
    }
    soundex[2] = '\0'; 
}

char getFirstCharCode(const char *name) {
    if (name[0] == '\0') return '\0';
    return toupper(name[0]);
}

void addSoundexCode(char *soundex, char code, char *prevCode) {
    if (code != '0' && code != *prevCode) {
        size_t len = strlen(soundex);
        if (len < 3) { // Ensure room for at most 3 codes
            soundex[len] = code;
            soundex[len + 1] = '\0';
            *prevCode = code;
        }
    }
}

void processName(const char *name, char *soundex, char firstChar) {
    initializeSoundex(name, soundex);
    char prevCode = soundex[1];
    size_t length = strlen(name);

    for (size_t i = 2; i < length && strlen(soundex) < 4; ++i) {
        char code = getSoundexCode(name[i]);
        addSoundexCode(soundex, code, &prevCode);
    }
}

void padSoundex(char *soundex) {
    size_t len = strlen(soundex);
    if (len < 4) {
        for (size_t i = len; i < 4; ++i) {
            soundex[i] = '0';
        }
        soundex[4] = '\0';
    }
}

void generateSoundex(const char *name, char *result) {
    if (name[0] == '\0') {
        result[0] = '\0';
        return;
    }
    char firstChar = getFirstCharCode(name);
    char processedName[5] = {0}; 
    processName(name, processedName, firstChar);
    padSoundex(processedName);
    strcpy(result, processedName);
}

int main() {
    const char *name = "Example";
    char soundex[5]; 
    generateSoundex(name, soundex);
    printf("Soundex code for '%s' is '%s'\n", name, soundex);
    return 0;
}
