/*********************************
run: ./P22.c data_5.txt
**********************************/

#include<stdio.h>
#include <string.h>
#include <sys/timeb.h>
void preprocess(char* string, int length,int table[]);
int horspool(char *input,int length,char *txt,int txtLen,int table[]);
int shifts =0;
void preprocess(char* string, int length,int table[])
{
  for(int i=0;i<127;i++)
  {
    table[i] = length;
  }
  for (int i = 0; i < length-1; i++)
  {
      table[(int)string[i]] = length - i-1;
  }
}

int horspool(char *input,int length,char *txt,int txtLen,int table[]) {
   int j;
   char c;
   int total=0;
   j = 0;
   while (j <= txtLen - length)
   {
      c = txt[j + length-1];
      if (input[length - 1] == c && memcmp(input, txt + j, length - 1) == 0)
      {
         total++;
      }
      if((table[(int)c]>0) &&(table[(int)c]<=length))
      {
        j += table[(int)c];
        shifts++;
      }
      else
      {
        j += length;
        shifts++;
      }
   }

   return total;
}

int main(int argc, char *argv[])
{
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
  char txt[256];
  char input[256];
  int total=0;
  printf("Please enter word: ");
  scanf("%s",input);
  int length = strlen(input);
  int table[127];
  ftime(&timestart);
  preprocess(input,length,table);
  while(fgets(txt,256,file) != NULL)
  {
    int txtLen = strlen(txt);
    total += horspool(input,length,txt,txtLen,table);
  }
  fclose(file);
  ftime(&timeend);
  timediff = (int)(1000.0 * (timeend.time - timestart.time) + (timeend.millitm - timestart.millitm));
  printf("Time:%d milliseconds\n",timediff);
  printf("Shifts:%d\n",shifts);
  printf("%d occurrences of \"%s\"\n",total,input);
  return 0;
}
