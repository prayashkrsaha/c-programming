#include<stdio.h>
#include<string.h>

void quick_sort (char *v[ ], int left, int right)
{
     int  last, i;
     if (left >= right)
           return;
     last=left;
     swap(v, left, (left+right)/2);
     for (i=left+1; i<=right; i++)
             if (strcmp(v[i], v[left])<0)
                                 swap(v, ++last, i);
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
/*
void bubble_sort (char *v[ ], int n)
{
    int  i, j, flag=1;
    for (i=0; i<n-1 && flag ; i++)
          for (j=0, flag=0; j<n-i-1; j++)
                if ( strcmpi (v[j], v[j+1])>0)
                   {
                          flag=1;
                           swap(v, j, j+1);
                   }
}
*/
void main( )
{
char  *names[ ]={"Samir", "John", "Rajibul", "Alka", "Binita", "Chandrima", "Aliya"};
int i;
printf("\n List of names:");
for (i=0; i<7; i++)
      printf ("\n%s", names[i]);

quick_sort (names, 0, 6);
printf("\n List of names in sorted order:");
for (i=0; i<7; i++)
      printf ("\n%s", names[i]);
}
