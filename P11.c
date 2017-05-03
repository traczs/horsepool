/*********************************8
Samuel Tracz
0927451
run: ./P11.c data_4.txt
**************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>

int main(int argc, char *argv[]) {
  struct timeb timestart, timeend;
  int timediff;
  FILE* file;
  char* filename = argv[1];
  file = fopen(filename,"r");
  if(!file)
  {
    printf("no such file\n");
    return 0;
  }
  char string[256];
  char word1[15];
  char word2[15];
  char word3[15];
  char word4[15];
  char word5[15];
  char input[256];
  int anagram;
  int total=0;
  printf("Please enter word: ");
  scanf("%s",input);
  ftime(&timestart);
  while(fgets(string,256,file) != NULL)
  {

    char temp[256];
    char temp2[256];
    sscanf(string,"%s %s %s %s %s",word1,word2,word3,word4,word5);
    anagram =1;
    strcpy(temp2,input);
    strcpy(temp,word1);
    for(int i=0;i<strlen(temp);i++)
    {
      for (int j = 0; j < strlen(temp2); j++)
      {
        if(temp[i]==temp2[j])
        {
          temp[i]='~';
          temp2[j] = '!';

        }
      }
    }
    for(int i=0;i<strlen(temp);i++)
    {
      if(temp[i] != '~')
        anagram =0;
    }
    for(int i=0;i<strlen(temp2);i++)
    {
      if(temp2[i] != '!')
        anagram =0;
    }
    if(anagram==1)
    {
      total++;
      printf("%s\n",word1);
    }
    //repeating code for the other 4 words because of the way I parse
    anagram =1;
    strcpy(temp2,input);
    strcpy(temp,word2);
    for(int i=0;i<strlen(temp);i++)
    {
      for (int j = 0; j < strlen(temp2); j++)
      {
        if(temp[i]==temp2[j])
        {
          temp[i]='~';
          temp2[j] = '!';

        }
      }
    }
    for(int i=0;i<strlen(temp);i++)
    {
      if(temp[i] != '~')
        anagram =0;
    }
    for(int i=0;i<strlen(temp2);i++)
    {
      if(temp2[i] != '!')
        anagram =0;
    }
    if(anagram==1)
    {
      total++;
      printf("%s\n",word2);
    }

    anagram =1;
    strcpy(temp2,input);
    strcpy(temp,word3);
    for(int i=0;i<strlen(temp);i++)
    {
      for (int j = 0; j < strlen(temp2); j++)
      {
        if(temp[i]==temp2[j])
        {
          temp[i]='~';
          temp2[j] = '!';

        }
      }
    }
    for(int i=0;i<strlen(temp);i++)
    {
      if(temp[i] != '~')
        anagram =0;
    }
    for(int i=0;i<strlen(temp2);i++)
    {
      if(temp2[i] != '!')
        anagram =0;
    }
    if(anagram==1)
    {
      total++;
      printf("%s\n",word3);
    }


    anagram =1;
    strcpy(temp2,input);
    strcpy(temp,word4);
    for(int i=0;i<strlen(temp);i++)
    {
      for (int j = 0; j < strlen(temp2); j++)
      {
        if(temp[i]==temp2[j])
        {
          temp[i]='~';
          temp2[j] = '!';

        }
      }
    }
    for(int i=0;i<strlen(temp);i++)
    {
      if(temp[i] != '~')
        anagram =0;
    }
    for(int i=0;i<strlen(temp2);i++)
    {
      if(temp2[i] != '!')
        anagram =0;
    }
    if(anagram==1)
    {
      total++;
      printf("%s\n",word4);
    }


    anagram =1;
    strcpy(temp2,input);
    strcpy(temp,word5);
    for(int i=0;i<strlen(temp);i++)
    {
      for (int j = 0; j < strlen(temp2); j++)
      {
        if(temp[i]==temp2[j])
        {
          temp[i]='~';
          temp2[j] = '!';

        }
      }
    }
    for(int i=0;i<strlen(temp);i++)
    {
      if(temp[i] != '~')
        anagram =0;
    }
    for(int i=0;i<strlen(temp2);i++)
    {
      if(temp2[i] != '!')
        anagram =0;
    }
    if(anagram==1)
    {
      total++;
      printf("%s\n",word5);
    }
  }
  ftime(&timeend);
  timediff = (int)(1000.0 * (timeend.time - timestart.time) + (timeend.millitm - timestart.millitm));
  printf("Time:%d milliseconds\n",timediff);

  printf("Total anagrams: %d\n",total);
  return 0;
}
