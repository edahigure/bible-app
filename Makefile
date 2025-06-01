

all: find_word.c
	gcc  bible.c -o bible
	gcc  find_word.c -o find_word 
	gcc  mix_gospels.c -o mix_gospels
	gcc  find_word_more.c -o find_word_more

