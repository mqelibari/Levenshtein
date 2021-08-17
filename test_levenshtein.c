#include "./unity/unity.h"
#include "levenshtein_lib.h"

void setUp(){}
void tearDown(){}

void test_levenshtein_with_empty_strings(){
	int result = levenshtein("", "");
	TEST_ASSERT_EQUAL_INT(0, result);
}


int main(){
	UNITY_BEGIN();
	RUN_TEST(test_levenshtein_with_empty_strings);
	return UNITY_END();
}

