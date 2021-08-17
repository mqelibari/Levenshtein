#include "./unity/unity.h"
#include "levenshtein_lib.h"
#include "string.h"

void setUp(){}
void tearDown(){}

void test_levenshtein_with_empty_strings(void){
	int result = levenshtein("", "");
	TEST_ASSERT_EQUAL_INT(0, result);
}


void test_levenshtein_with_one_empty_string(void){
	int result = levenshtein("s", "");
	TEST_ASSERT_EQUAL_INT(1, result);
}

void test_remove_whitespaces(void){
	char* length_four = "    ";
	char* length_zero = remove_whitespaces(length_four);
	int length = (int) strlen(length_zero);
	TEST_ASSERT_EQUAL_INT(0, length);
}


void test_levenshtein_with_one_different_char(void){
	int result = levenshtein("a", "b");
	TEST_ASSERT_EQUAL_INT(1, result);
}

void test_levenshtein_full_algorithm(void){
	int result = levenshtein("Fisch", "Fleisch");
	TEST_ASSERT_EQUAL_INT(2, result);
	int second_result = levenshtein("Baumarkt", "Autobahn");
	TEST_ASSERT_EQUAL_INT(8, second_result);
}


void test_string_slice(void){
	char* word = "abcdef";
	char* sliced = string_slice(word, 0, 2);
	TEST_ASSERT_EQUAL_STRING("ab", sliced);	
}


int main(){
	UNITY_BEGIN();
	RUN_TEST(test_levenshtein_with_empty_strings);
	RUN_TEST(test_levenshtein_with_one_empty_string);
	RUN_TEST(test_remove_whitespaces);
	RUN_TEST(test_levenshtein_with_one_different_char);
	RUN_TEST(test_string_slice);
	RUN_TEST(test_levenshtein_full_algorithm);
	return UNITY_END();
}

