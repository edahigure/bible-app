#include<string.h>
#include<stdio.h>
#include<stdlib.h>



#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>
#include <math.h>

/*Merge SAC binary */

int read_s(FILE *in, char *string);
int split_name(char str_time[11][300],char *str_name);
int my_eval(char *command);
float **matrixf( long nrh,  long nch);
int split_date(char str_time[3][10],char str_name_cp[300]);
int read_f(FILE *in, float *numb);
void read_book(char * book,int i_chap_num,int i_ver_num,char *word);
void find_word(char *book,char *word);
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
  return (char**) malloc((N)*sizeof(char[500]) );
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


int main(int num_arg,char **av)
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
    return 1;
    }


    if (num_arg==2 ){
    book=newstr(100);
    word=newstr(100);
    strcpy(word,av[1]);
    for(int k=0;k<66;k++){
    find_word(all_books[k],word);
    }

    return 1;
    }


    if (num_arg==3 ){
    book=newstr(100);
    word=newstr(100);
    strcpy(book,av[1]);
    strcpy(word,av[2]);

    find_word(book,word);

    return 1;
    }
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
