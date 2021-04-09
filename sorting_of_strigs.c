#include<stdio.h>
#include<string.h>

void swap(char *[],int,int);
void bubble_sort(char *[],int);


void swap (char *v[ ], int i, int j)
{
    char *t=v[i];
     v[i]=v[j];
     v[j]=t;
}

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

void main()
{char *names[]={"Nairobi","Rio","Denver","Tokyo","Berlin","Oslo","Moscow","Helsinki","Stockholm","Lisbon"};
printf("List of names: ");
int i;
for(i=0;i<10;i++)
    printf("\n%s",names[i]);

 bubble_sort(names,10);

 printf("\n");
 printf("\nList of names in sorted order: ");
 for(i=0;i<10;i++)
    printf("\n%s",names[i]);

}
