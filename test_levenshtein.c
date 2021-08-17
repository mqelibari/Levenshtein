#include "./unity/unity.h"
#include "levenshtein_lib.h"

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


int main(){
	UNITY_BEGIN();
	RUN_TEST(test_levenshtein_with_empty_strings);
	RUN_TEST(test_levenshtein_with_one_empty_string);
	return UNITY_END();
}

