/*********************************
run: ./P23.c data_5.txt
**********************************/

#include<stdio.h>
#include <string.h>
#include <sys/timeb.h>
void preprocess(char* string, int length,int table[]);
int BM(char *input,int length,char *txt,int txtLen,int table[],int table2[]);
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

void suffixes(char *string, int length, int *suff)
{
   int i,j,k;
   suff[length - 1] = length;
   j = length - 1;
   for (i = length - 2; i >= 0; i--)
   {
      if (i > j && suff[i + length - 1 - k] < i - j)
         suff[i] = suff[i + length - 1 - k];
      else
      {
         if (i < j)
            j = i;
         k = i;
         while (j >= 0 && string[j] == string[j + length - 1 - k])
            j--;
         suff[i] = k - j;
      }
   }
}

void preBM(char *string, int length, int table2[])
{
   int i, j, suff[256];

   suffixes(string, length, suff);

   for (i = 0; i < length; i++)
      table2[i] = length;
   j = 0;
   for (i = length - 1; i >= 0; i--)
   {
     if (suff[i] == i + 1)
     {
         for (j=0; j < length - 1 - i; j++)
         {
            if (table2[j] == length)
            {
               table2[j] = length - 1 - i;
            }
         }
     }
   }
   for (i = 0; i <= length - 2; i++)
      table2[length - 1 - suff[i]] = length - 1 - i;
}

int BM(char *input, int length, char *txt, int txtLen,int table[],int table2[])
{
   int i, j;
   int total = 0;
   j = 0;
   while (j <= txtLen - length)
   {
      for (i = length - 1; i >= 0 && input[i] == txt[i + j]; i--);
      if (i < 0) {
         total++;
         j += table2[0];
      }
      else
         if((table2[(int)i]>0) &&(table2[(int)i]<=length))
         {
           j += table2[i];
           j += table[(int)txt[i + j]] - length + 1 + i;
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
  int table2[265];
  ftime(&timestart);
  preBM(input, length, table2);
  preprocess(input,length,table);
  while(fgets(txt,256,file) != NULL)
  {
    int txtLen = strlen(txt);
    total += BM(input,length,txt,txtLen,table,table2);
  }
  fclose(file);
  ftime(&timeend);
  timediff = (int)(1000.0 * (timeend.time - timestart.time) + (timeend.millitm - timestart.millitm));
  printf("Time:%d milliseconds\n",timediff);
  printf("Shifts:%d\n",shifts);
  printf("%d occurrences of \"%s\"\n",total,input);
  return 0;
}
