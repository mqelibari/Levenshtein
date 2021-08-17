#include "levenshtein_lib.h"
#include "string.h"

#define MAX(a,b) (((a)>(b))?(a):(b))


int levenshtein(char* word_one, char* word_two){
	if(strlen(word_one) == 0 || strlen(word_two) == 0){
		return MAX(strlen(word_one), strlen(word_two));
	}
	return 0;
}
