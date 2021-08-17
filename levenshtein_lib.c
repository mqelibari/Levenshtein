#include "levenshtein_lib.h"
#include "string.h"
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

int levenshtein(char* word_one, char* word_two){
	word_one = remove_whitespaces(word_one);
	word_two = remove_whitespaces(word_two);
	int l_word_one = strlen(word_one);
	int l_word_two = strlen(word_two);
	if(strlen(word_one) == 0 || strlen(word_two) == 0){
		return MAX(strlen(word_one), strlen(word_two));
	}
	int distance = 0;
	if(word_one[l_word_one - 1] != word_two[l_word_two -1]){
		distance = 1;
	}else{
		distance = 0;
	}
	
	int delete = levenshtein(string_slice(word_one, 0, l_word_one -1), word_two) + 1;
	int insert = levenshtein(word_one, string_slice(word_two, 0, l_word_two -1)) +1;
	int same = levenshtein(string_slice(word_one, 0, l_word_one -1), string_slice(word_two, 0, l_word_two - 1)) + distance;

	int check = MIN(delete, insert);
	return MIN(check, same);
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


char* string_slice(char* word, int left_boarder, int right_boarder){
	char* sliced = malloc((right_boarder - left_boarder) * sizeof(char));
	if(sliced == NULL){
		exit(1);
	}
	int j = 0;
	for(int i = 0; i < strlen(word); i++){
		if(i >= left_boarder && i< right_boarder){
			sliced[j] = word[i];
			j++;
		}
	}
	return sliced;
}
