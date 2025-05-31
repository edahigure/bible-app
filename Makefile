all:bible find_ver

bible:bible.c
	gcc  bible.c -o bible 

find_ver: find_word.c
	gcc  find_word.c -o find_word 
	gcc  mix_gospels.c -o mix_gospels
	gcc  find_word_more.c -o find_word_more
