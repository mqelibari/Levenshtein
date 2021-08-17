.PHONY: test clean compile

compile: test

test: test_levenshtein
	./test_levenshtein

test_levenshtein.o: test_levenshtein.c levenshtein_lib.h levenshtein_lib.c
	gcc -c test_levenshtein.c -o test_levenshtein.o

./unity/unity.o: ./unity/unity.c ./unity/unity.h
	gcc -c ./unity/unity.c -o ./unity/unity.o

test_levenshtein: test_levenshtein.o levenshtein_lib.o ./unity/unity.o
	gcc -o test_levenshtein test_levenshtein.o ./unity/unity.o levenshtein_lib.o

levenshtein_lib.o: levenshtein_lib.c levenshtein_lib.h
	gcc -c levenshtein_lib.c -o levenshtein_lib.o

clean:
	rm *.o test_levenshtein
	rm ./unity/unity.o
