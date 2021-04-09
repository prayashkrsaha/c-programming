#include <stdio.h>
#include <string.h>
#define MAX 100

void main( )
{
  FILE *fs, *ft;
  char word[MAX][10];
  int i=0, n;
  fs=fopen("Words.txt", "r+");
  while(fscanf(fs,  "%s", word[i])) /* word[i]: address of i th word */
      i++;
  fclose(fs);
  n=i;  /* n = total no. of words in the source file.*/
  quick_sort (word, 0, n-1);
  ft=fopen("SW.txt", "w+"); /* open the target text file in write mode.*/

  for(i=0; i<n; i++)
      fprintf(ft,"\n%s", word[i]);
 /* ft (target file pointer) will be incremented by string length for each successful        execution of fprintf(ft,"\n%s", word[i]).*/
  fclose(ft); /* closing of target text file opened in write mode.*/
 ft=fopen("SW.txt", "r");
 printf("\n List of words in sorted order:");
 i=0;
 while(fscanf(ft,"%s", word[i]))
   {
               printf("\n%s", word[i]);
               i++;
   }
 fclose(ft);
}

void quick_sort (char *v[ ], int left, int right)
{
     int  last, i;
     if (left >= right)
           return;
     last=left;
     swap(v, left, (left+right)/2);
     for (i=left+1; i<=right; i++)
             if (strcmp(v[i], v[left])<0)
             {
                swap(v, ++last, i);
             }
     swap(v, last, left);
     quick_sort (v, left, last-1);
     quick_sort (v, last+1, right);
}


void swap (char *v[ ], int i, int j)
{
    char *t=v[i];
     v[i]=v[j];
     v[j]=t;
}
