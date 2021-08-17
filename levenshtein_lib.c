#include "levenshtein_lib.h"
#include "string.h"
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))


int levenshtein(char* word_one, char* word_two){
	if(strlen(word_one) == 0 || strlen(word_two) == 0){
		return MAX(strlen(word_one), strlen(word_two));
	}
	return 0;
}


char* remove_whitespaces(char* word){
	char* new_string = malloc(sizeof(char) * strlen(word));
    if(new_string == NULL){
        exit(1);
    }
    int i, j;
    for(i = 0, j = 0; i < strlen(word); i++, j++){
        if(word[i] != ' '){
            new_string[j] = word[i];
        }else{
            j--;
        }
    }
    new_string[j] = '\0';
    return new_string;

}
