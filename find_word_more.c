#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>
#include <math.h>

/*Merge SAC binary */

int read_s(FILE *in, char *string);
char ** split_name(char *str_name);
int my_eval(char *command);
float **matrixf( long nrh,  long nch);
int split_date(char str_time[3][10],char str_name_cp[300]);
int read_f(FILE *in, float *numb);
void read_book(char * book,int i_chap_num,int i_ver_num,char *word);
void find_word(char *book,char *word);
void find_word_more(char *book,char **word,int word_num);
char * newstr(int N);

int read_s(FILE *in, char *string)
{
    char dum, dummy[300];
    int ok=-1;
    
    for(;;)
    {ok=fscanf(in,"%s", dummy);
        if(dummy[0]=='#' && strlen(dummy)>1 && dummy[strlen(dummy)-1]=='#') {}
        else if(dummy[0]=='#') {do{ok=fscanf(in,"%c", &dum);} while(dum!='#');}
        else                   {strcpy(string, dummy); break;} }
    return  ok;
}

int my_eval(char *command)
{
    int status;
    status=system(command);
    fprintf(stderr,"command: %s\n",command);
    if(status==-1){
        fprintf(stderr,"cannot execute command: %s\n",command);
        return -1;
    }
    return 1;
}

char * newstr(int N)
{
  return (char*) malloc((N)*sizeof(char) );
}

int * new_array_i(int N)
{
  return (int*) malloc((N)*sizeof(int) );
}

char ** newstr_array(int N)
{
  return (char**) malloc((N)*sizeof(char*) );
}

int isDigit(char c)
{
	char digit[500];
   int ans;
   ans =0;
   strcpy(digit,"1234567890");
   for(int k=0;k<(int)strlen(digit);k++){
      if(c==digit[k]){
         ans=1;
      }
   }
   return ans;
}

int read_f(FILE *in, float *numb)
{
 char dum, dummy[128];
 int ok=-1;

 for(;;)
  {ok=fscanf(in,"%s", dummy);
   if(dummy[0]=='#' && strlen(dummy)>1 && dummy[strlen(dummy)-1]=='#') {}
   else if(dummy[0]=='#') {do{ok=fscanf(in,"%c", &dum);} while(dum!='#');}
   else                   {*numb=atof(dummy); break;} }
 return  ok;   
}

int split_count(char *str)
{
   int n=0;
   int j=0;
   int count=0;
   while( str[j] != '\0' ){       
       if(str[j]==' ' || str[j]=='-' || str[j]=='.' ) count++;
       j++;
   }
   return count;
}

char** split_name(char *str_name_cp)
{
    char * pch;
    char str_name[300];
    int split_num;
    char **str_words;

    split_num = split_count(str_name_cp);        
    strcpy(str_name,str_name_cp);
    pch = strtok (str_name,".- ");
    str_words=newstr_array(split_num+1);
    str_words[0] = strdup(pch);
    
    for(int k=1;k<split_num+1;k++)
    {
        pch = strtok (NULL, ".- ");        
        str_words[k] = strdup(pch);
        strcpy(str_words[k],pch);        
    }
    return str_words;
}

int main(int num_arg,char **av)
{
  char *book,*word; 
  char **words; 
  char all_books[100][100]={
    "genesis",
    "exodus",
    "leviticus",
    "numbers",
    "deuteronomy",
    "joshua",
    "judges",
    "ruth",
    "samuel1",
    "samuel2",
    "kings1",
    "kings2",
    "chronicles1",
    "chronicles2",
    "ezra",
    "nehemiah",
    "esther",
    "job",
    "psalm",
    "proverbs",
    "ecclesiastes",
    "song_of_songs",
    "isaiah",
    "jeremiah",
    "lamentations",
    "ezekiel",
    "daniel",
    "hosea",
    "joel",
    "amos",
    "obadiah",
    "jonah",
    "micah",
    "nahum",
    "habakkuk",
    "zephaniah",
    "haggai",
    "zechariah",
    "malachi",
    "matthew",
    "mark",
    "luke",
    "john",
    "acts",
    "romans",
    "corinthians1",
    "corinthians2",
    "galatians",
    "ephesians",
    "philippians",
    "colossians",
    "thessalonians1",
    "thessalonians2",
    "timothy1",
    "timothy2",
    "titus",
    "philemon",
    "hebrews",
    "james",
    "peter1",
    "peter2",
    "john1",
    "john2",
    "john3",
    "jude",
    "revelation",
    };
    int split_num;
   
    if (num_arg==1 ){
      return 0;
    }

    if (num_arg==2 ){
      book=newstr(100);
      word=newstr(100);
      strcpy(word,av[1]);
      split_num = split_count(word);      
      words=split_name(word);
        for(int k=0;k<split_num+1;k++)
        {     
        printf("word --: %s\n",words[k]) ;
        }
      for(int k=0;k<66;k++){
        find_word_more(all_books[k],words,split_num+1);
      }
    return 0;
    }
}

int main_2(int num_arg,char **av)
{
    char *book,*word;
    char all_books[100][100]={
"genesis",
"exodus",
"leviticus",
"numbers",
"deuteronomy",
"joshua",
"judges",
"ruth",
"samuel1",
"samuel2",
"kings1",
"kings2",
"chronicles1",
"chronicles2",
"ezra",
"nehemiah",
"esther",
"job",
"psalm",
"proverbs",
"ecclesiastes",
"song_of_songs",
"isaiah",
"jeremiah",
"lamentations",
"ezequiel",
"daniel",
"hosea",
"joel",
"amos",
"obadiah",
"jonah",
"micah",
"nahum",
"habakkuk",
"zephaniah",
"haggai",
"zechariah",
"malachi",
"matthew",
"mark",
"luke",
"john",
"acts",
"romans",
"corinthians1",
"corinthians2",
"galatians",
"ephesians",
"philippians",
"colossians",
"thessalonians1",
"thessalonians2",
"timothy1",
"timothy2",
"titus",
"philemon",
"hebrews",
"james",
"peter1",
"peter2",
"epistle_john1",
"epistle_john2",
"epistle_john3",
"jude",
"revelation",
};
    if (num_arg==1 ){
    return 0;
    }

    if (num_arg==2 ){
    book=newstr(100);
    word=newstr(100);
    strcpy(word,av[1]);
    
    for(int k=0;k<66;k++){
      find_word(all_books[k],word);
    }

    return 0;
    }

    if (num_arg==3 ){
    book=newstr(100);
    word=newstr(100);
    strcpy(book,av[1]);
    strcpy(word,av[2]);

    find_word(book,word);

    return 0;
    }
    return 0;
}

void read_book(char * book,int i_chap_num,int i_ver_num,char* word)
{
    FILE *fd;
    int k,N_words,chap_num,ver_num,num_arg;
    char *str;
    char *str_1;
    int all_chap=0,all_book=0,f_ver_num;
    all_book=0;
    all_chap=0;
    f_ver_num=0;
    fd=fopen(book,"r");
//    printf("book:%s  chap:%d ver: %d - %d\n",book,i_chap_num,i_ver_num,f_ver_num);
    //cuenta cuantos palabras hay
    str=newstr(1000);
    str_1=newstr(1000);
    N_words=0;
    while(1){
        if(read_s(fd,str)==-1){ break; } 
        else {
		     if(strcmp(str,"CHAPTER")==0){
		         read_s(fd,str);
               chap_num=atoi(str);
//               printf("chap_num: %d\n",chap_num);
               if( chap_num ==i_chap_num){
				       read_s(fd,str);
	                 while(isDigit(str[0])==0 ){
					        read_s(fd,str);
	                    if( i_ver_num==1 )
                       {
//					             printf("%s ",str);
									 printf("\033[1;34m%s\033[0m ",str);  
                       }
	                 }
//					     printf("here begins second verse %s  strcmp(str,CHAPTER)==0 %d \n",str,strcmp(str,"CHAPTER")==0 );
                    while( strcmp(str,"CHAPTER")!=0 ){
//                     printf("if(isDigit(str[0])==1):   %d\n",isDigit(str[0])==1);
                     if(isDigit(str[0])==1){
                       ver_num=atoi(str);  
                       if( all_chap==0){}
//                       printf("%d\n",ver_num);
                       else printf("\n");
//                       printf("ver_num: %d   str:%s\n",ver_num,str);             
//                       getchar();
                    }
			        read_s(fd,str);
                    strcpy(str_1,str);
                    if(strlen(str_1)-1>=0)
                    str_1[strlen(str_1)-1]='\0';
                    if( (isDigit(str[0])==0 && ver_num==i_ver_num   ) || all_chap==1 || (ver_num>=i_ver_num && ver_num<=f_ver_num)    ){
                          if(strcmp(str,word)==0 || strcmp(str_1,word)==0){
  		                       printf("\033[1;32m%s\033[0m ",str);  
                          }else{
				  			printf("\033[1;37m%s\033[0m ",str);  
                          }                               
                                
                        }

	                }                   

               }
		     }
           N_words++;
        }
   }
   fclose(fd);
   printf("\n");
}

void find_word(char *book,char *word)
{
    FILE *fd;
    int k,N_words,chap_num,ver_num;
    char *str,*str_1,*str_2,*str_3,*str_4,*str_5;
    int  i_chap_num,i_ver_num,all_chap=0,all_book=0,f_ver_num;
    fd=fopen(book,"r");
//    printf("%s  word:%s\n",book,word);
	 printf("\033[1;33m%s  word:%s\n\033[0m ",book,word);
    //cuenta cuantos palabras hay
    str=newstr(1000);
    str_1=newstr(1000);
    str_2=newstr(1000);
    str_3=newstr(1000);
    str_4=newstr(1000);
    str_5=newstr(1000);
   
    N_words=0;

    ver_num=1;
    chap_num=1;
    
    while(1){
        if(read_s(fd,str)==-1){ break; } 
        else {
           if(strcmp(str,word)==0 )
           {
//              printf("%s %d : %d\n",book,chap_num,ver_num);

	           printf("\033[1;34m%s %d : %d\n\033[0m ",book,chap_num,ver_num);

              read_book(book,chap_num,ver_num,word);
           }
           strcpy(str_1,str);
           str_1[strlen(str_1)-1]='\0';
           if(strcmp(str_1,word)==0 )
           {
//              printf("%s %d : %d\n",book,chap_num,ver_num);

	           printf("\033[1;34m%s %d : %d\n\033[0m ",book,chap_num,ver_num);

              read_book(book,chap_num,ver_num,word);
           }
		   if(strcmp(str,"CHAPTER")==0){
		         read_s(fd,str);
               chap_num=atoi(str);
           }
           if( isDigit(str[0])==1){
           ver_num=atoi(str);
           }
       }
   }
   printf("\n");   
}


void read_book_more(char * book,int i_chap_num,int i_ver_num,char* word)
{
    FILE *fd;
    int k,N_words,chap_num,ver_num,num_arg;
    char *str;
    char *str_1;
    int all_chap=0,all_book=0,f_ver_num;
    all_book=0;
    all_chap=0;
    f_ver_num=0;
    fd=fopen(book,"r");
//    printf("book:%s  chap:%d ver: %d - %d\n",book,i_chap_num,i_ver_num,f_ver_num);
    //cuenta cuantos palabras hay
    str=newstr(1000);
    str_1=newstr(1000);
    N_words=0;
    while(1){
        if(read_s(fd,str)==-1){ break; } 
        else {
		    if(strcmp(str,"CHAPTER")==0){
		       read_s(fd,str);
               chap_num=atoi(str);
//             printf("chap_num: %d\n",chap_num);
               if( chap_num ==i_chap_num){
				    read_s(fd,str);
	                while(isDigit(str[0])==0 ){
					   read_s(fd,str);
	                   if( i_ver_num==1 )
                       {
//				           printf("%s ",str);
		 				   printf("\033[1;34m%s\033[0m ",str);  
                       }
	                 }
//					     printf("here begins second verse %s  strcmp(str,CHAPTER)==0 %d \n",str,strcmp(str,"CHAPTER")==0 );
                    while( strcmp(str,"CHAPTER")!=0 ){
//                     printf("if(isDigit(str[0])==1):   %d\n",isDigit(str[0])==1);
                     if(isDigit(str[0])==1){
                       ver_num=atoi(str);  
                       if( all_chap==0){}
//                       printf("%d\n",ver_num);
                       else printf("\n");
//                       printf("ver_num: %d   str:%s\n",ver_num,str);             
//                       getchar();
                    }
			        read_s(fd,str);
                    strcpy(str_1,str);
                    if(strlen(str_1)-1>=0)
                    str_1[strlen(str_1)-1]='\0';
                    if( (isDigit(str[0])==0 && ver_num==i_ver_num   ) || all_chap==1 || (ver_num>=i_ver_num && ver_num<=f_ver_num)    ){
                          if(strcmp(str,word)==0 || strcmp(str_1,word)==0){
  		                       printf("\033[1;32m%s\033[0m ",str);  
                          }else{
				  			printf("\033[1;37m%s\033[0m ",str);  
                          }                                                               
                        }
	                }                   
               }
		     }
           N_words++;
        }
   }
   fclose(fd);
   printf("\n");
}

void find_word_more(char *book,char **word,int word_num)
{
    FILE *fd;
    int k,N_words,chap_num,ver_num;
    char *str,*str_1,*str_2,*str_3,*str_4,*str_5;
    int  i_chap_num,i_ver_num,all_chap=0,all_book=0,f_ver_num;
    int flag;
    int flag_cp;
    fd=fopen(book,"r"); 
    printf("\033[1;33m%s\n\033[0m ",book);
    for(int k=0; k < word_num; k++ ){
       printf("\033[1;33mword:%s\n\033[0m ",word[k]);
    }

//cuenta cuantos palabras hay
    str=newstr(1000);
    str_1=newstr(1000);
    str_2=newstr(1000);
    str_3=newstr(1000);
    str_4=newstr(1000);
    str_5=newstr(1000);
   
    N_words=0;

    ver_num=1;
    chap_num=1;
    
    while(1){
        if(read_s(fd,str)==-1){ break; } 
        else {

          flag = 1;

          
          for(int k=0; k < word_num; k++ ){
             if( strcmp(str,word[k]) == 0 ){                
                printf("\033[1;34m%s %d : %d\n\033[0m ",book,chap_num,ver_num);
                read_book_more(book,chap_num,ver_num,word[k]);
             }else
             {
                flag=0;
             }
             
          }

    
          
          strcpy(str_1,str);
          str_1[strlen(str_1)-1]='\0';

          flag = 1;
          for(int k=0; k < word_num; k++ ){
             if( strcmp(str_1,word[k]) == 0 ){
                printf("\033[1;34m%s %d : %d\n\033[0m ",book,chap_num,ver_num);
                read_book_more(book,chap_num,ver_num,word[k]);
             }else
             {
                flag=0;
             }
          }

          if( flag == 1 )
          {
//              printf("%s %d : %d\n",book,chap_num,ver_num);
	          
           }
           if(strcmp(str,"CHAPTER")==0){
		         read_s(fd,str);
               chap_num=atoi(str);
           }
           if( isDigit(str[0])==1){
           ver_num=atoi(str);
           }

        }
    }
    printf("\n");    
    return;	
}
