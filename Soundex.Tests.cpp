#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <ctype.h>
#include <string.h>
#include "Soundex.h"

// Test cases
void test_getSoundexCode(void) {
    CU_ASSERT_EQUAL(getSoundexCode('B'), '1');
    CU_ASSERT_EQUAL(getSoundexCode('F'), '1');
    CU_ASSERT_EQUAL(getSoundexCode('P'), '1');
    CU_ASSERT_EQUAL(getSoundexCode('V'), '1');
    CU_ASSERT_EQUAL(getSoundexCode('C'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('G'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('J'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('K'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('Q'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('S'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('X'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('Z'), '2');
    CU_ASSERT_EQUAL(getSoundexCode('D'), '3');
    CU_ASSERT_EQUAL(getSoundexCode('T'), '3');
    CU_ASSERT_EQUAL(getSoundexCode('L'), '4');
    CU_ASSERT_EQUAL(getSoundexCode('M'), '5');
    CU_ASSERT_EQUAL(getSoundexCode('N'), '5');
    CU_ASSERT_EQUAL(getSoundexCode('R'), '6');
    CU_ASSERT_EQUAL(getSoundexCode('A'), '0'); // testing a non-mapped character
}

void test_getValidCode(void) {
    CU_ASSERT_EQUAL(getValidCode('1', '0'), '1');
    CU_ASSERT_EQUAL(getValidCode('1', '1'), '0');
    CU_ASSERT_EQUAL(getValidCode('2', '1'), '2');
    CU_ASSERT_EQUAL(getValidCode('2', '2'), '0');
    CU_ASSERT_EQUAL(getValidCode('3', '2'), '3');
    CU_ASSERT_EQUAL(getValidCode('0', '3'), '0');
}

void test_generateSoundex(void) {
    char result[5];

    generateSoundex("Robert", result);
    CU_ASSERT_STRING_EQUAL(result, "R163");

    generateSoundex("Jackson", result);
    CU_ASSERT_STRING_EQUAL(result, "J250");

    generateSoundex("Smith", result);
    CU_ASSERT_STRING_EQUAL(result, "S530");

    generateSoundex("Fritz", result);
    CU_ASSERT_STRING_EQUAL(result, "F320");

    generateSoundex("MacDonald", result);
    CU_ASSERT_STRING_EQUAL(result, "M325");

    generateSoundex("", result); // Edge case: empty input
    CU_ASSERT_STRING_EQUAL(result, "0000");
}

int main() {
    CU_initialize_registry();
    CU_pSuite pSuite = CU_add_suite("SoundexTestSuite", 0, 0);

    CU_add_test(pSuite, "test_getSoundexCode", test_getSoundexCode);
    CU_add_test(pSuite, "test_getValidCode", test_getValidCode);
    CU_add_test(pSuite, "test_generateSoundex", test_generateSoundex);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    
    return 0;
}
