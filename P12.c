/*********************************8
Samuel Tracz
0927451
run: ./P12.c data_4.txt
**************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/timeb.h>

struct str{
  char realNum[15];
  char orderedNum[15];
};
typedef struct str str;

void MergeSort(char *array, int left, int right);
void Merge(char *array, int left, int mid, int right);
void MergeStruct(str *arr, int low, int mid, int high);
void MergeSortStruct(str *arr, int low, int high);

void Merge(char *array, int left, int mid, int right){

    char tempArray[right-left+1];
    int pos=0,lpos = left,rpos = mid + 1;

    while(lpos <= mid && rpos <= right)
    {
            if(array[lpos] <= array[rpos])
            {
              tempArray[pos++] = array[lpos++];
            }
            else
            {
              tempArray[pos++] = array[rpos++];
            }
    }

    while(lpos <= mid)
    {
      tempArray[pos++] = array[lpos++];
    }
    while(rpos <= right)
    {
      tempArray[pos++] = array[rpos++];
    }
    for(int i = 0;i < pos; i++)
    {
      array[i+left] = tempArray[i];
    }

    return;
}

void MergeSort(char *array, int left, int right){
    int mid = (left+right)/2;

    if(left<right)
    {
      MergeSort(array,left,mid);
      MergeSort(array,mid+1,right);
      Merge(array,left,mid,right);
    }
    return;
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
  str list[30000];
  char string[256];
  char word1[15];
  char word2[15];
  char word3[15];
  char word4[15];
  char word5[15];
  char input[256];
  int total=0;
  int turn =0;
  printf("Please enter word: ");
  scanf("%s",input);
  ftime(&timestart);
  MergeSort(input,0,strlen(input)-1);
  while(fgets(string,256,file) != NULL)
  {
    sscanf(string,"%s %s %s %s %s",word1,word2,word3,word4,word5);
    strcpy(list[turn].realNum,word1);
    MergeSort(word1,0,strlen(word1)-1);
    strcpy(list[turn].orderedNum,word1);
    if(strcmp(list[turn].orderedNum,input)==0)
    {
      printf("%s\n",list[turn].realNum);
      total++;
    }
    turn++;
    strcpy(list[turn].realNum,word2);
    MergeSort(word2,0,strlen(word2)-1);
    strcpy(list[turn].orderedNum,word2);
    if(strcmp(list[turn].orderedNum,input)==0)
    {
      printf("%s\n",list[turn].realNum);
      total++;
    }
    turn++;
    strcpy(list[turn].realNum,word3);
    MergeSort(word3,0,strlen(word3)-1);
    strcpy(list[turn].orderedNum,word3);
    if(strcmp(list[turn].orderedNum,input)==0)
    {
      printf("%s\n",list[turn].realNum);
      total++;
    }
    turn++;
    strcpy(list[turn].realNum,word4);
    MergeSort(word4,0,strlen(word4)-1);
    strcpy(list[turn].orderedNum,word4);
    if(strcmp(list[turn].orderedNum,input)==0)
    {
      printf("%s\n",list[turn].realNum);
      total++;
    }
    turn++;
    strcpy(list[turn].realNum,word5);
    MergeSort(word5,0,strlen(word5)-1);
    strcpy(list[turn].orderedNum,word5);
    if(strcmp(list[turn].orderedNum,input)==0)
    {
      printf("%s\n",list[turn].realNum);
      total++;
    }
    turn++;

  }
  fclose(file);
  ftime(&timeend);
  timediff = (int)(1000.0 * (timeend.time - timestart.time) + (timeend.millitm - timestart.millitm));
  printf("Time:%d milliseconds\n",timediff);
  printf("Total anagrams: %d\n",total);
  return 0;
}
