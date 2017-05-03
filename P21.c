/*********************************
run: ./P21.c data_5.txt
**********************************/

#include<stdio.h>
#include <string.h>
#include <sys/timeb.h>

int search(char *fileText,char *search);
int shifts =0;

int search(char *fileText,char *search)
{
  int searchNum = strlen(search);
  int textNum = strlen(fileText);
  int total=0;

  for (int i = 0; i <= textNum - searchNum; i++)
  {
    int j;
    for (j = 0; j < searchNum; j++)
    {
      shifts++;
      if (fileText[i+j] != search[j])
      {
        break;
      }
    }
    if (j == searchNum)
    {
      total++;
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
  ftime(&timestart);
  while(fgets(txt,256,file) != NULL)
  {
    total += search(txt,input);
  }
  fclose(file);
  ftime(&timeend);
  timediff = (int)(1000.0 * (timeend.time - timestart.time) + (timeend.millitm - timestart.millitm));
  printf("Time:%d milliseconds\n",timediff);
  printf("Shifts:%d\n",shifts);
  printf("%d occurrences of \"%s\"\n",total,input);
  return 0;
}
