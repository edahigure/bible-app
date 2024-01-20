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







void main(int ac,char **av)
{

    FILE *fd;
    int k,N_words,chap_num,ver_num,num_arg;
    char *str;
    char *book;
    int  i_chap_num,i_ver_num,all_chap=0,all_book=0,f_ver_num;


    num_arg=ac;
//    printf("num_arg: %d\n",num_arg);

    if (num_arg==1 ){
    return;
    }

    if (num_arg==2 ){
      book=newstr(100);
      strcpy(book,av[1]);
      all_book=1;
      all_chap=1;
      i_chap_num=1;
      i_ver_num=1;
      f_ver_num=0;
    }



    if (num_arg==3){
      book=newstr(100);
      strcpy(book,av[1]);

      all_book=0;
      all_chap=1;
      i_chap_num=atoi(av[2]);
      i_ver_num=1;
      f_ver_num=0;
    }


    if (num_arg==4){
      book=newstr(100);
      strcpy(book,av[1]);

      all_book=0;
      all_chap=0;
      i_chap_num=atoi(av[2]);
      i_ver_num=atoi(av[3]);
      f_ver_num=0;
    }


    if (num_arg==5){
      book=newstr(100);
      strcpy(book,av[1]);

      all_book=0;
      all_chap=0;
      i_chap_num=atoi(av[2]);
      i_ver_num=atoi(av[3]);
      f_ver_num=atoi(av[4]);
    }
    

    fd=fopen(book,"r");

    if(f_ver_num==0){
       printf("\033[1;34m%s %d : %d\n\033[0m ",book,i_chap_num,i_ver_num);
//    printf("%s  %d : %d \n",book,i_chap_num,i_ver_num);
    }

    if(f_ver_num!=0){
//                  printf("%s  %d : %d - %d\n",book,i_chap_num,i_ver_num,f_ver_num);
       printf("\033[1;34m%s  %d : %d - %d\n\033[0m ",book,i_chap_num,i_ver_num,f_ver_num);
    }



    //cuenta cuantos palabras hay
    str=newstr(10000);
   
    N_words=0;


    
    while(1){
      if(read_s(fd,str)==-1)
      { break; } 
      else {
		    if(strcmp(str,"CHAPTER")==0){
		      read_s(fd,str);
          chap_num=atoi(str);
          if( chap_num ==i_chap_num){
				    read_s(fd,str);
	          while(isDigit(str[0])==0 ){
	            if( i_ver_num==1 )
					      printf("%s ",str);
					    read_s(fd,str);
	          }
            while( strcmp(str,"CHAPTER")!=0 ){
                     if(isDigit(str[0])==1){
                       ver_num=atoi(str);  
                       if( all_chap==0){}
//                       printf("%d\n",ver_num);
                       else printf("\n");
//                       printf("ver_num: %d   str:%s\n",ver_num,str);             
//                       getchar();

                     }
			            read_s(fd,str);
                     if( (isDigit(str[0])==0 && ver_num==i_ver_num   ) || all_chap==1 || (ver_num>=i_ver_num && ver_num<=f_ver_num)    ){
                      
                              
                      printf("\033[0;93m%s\033[0m ",str);
                     }
			                 

	                }                   

               }
		     }
           N_words++;
        }
   }


   printf("\n");

    


}




