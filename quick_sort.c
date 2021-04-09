#include<stdio.h>

int *x[100],no,i;

void display();

void sort();

void main()

{

printf("\n Enter the number of elements\n");

scanf("%d",&no);

printf("\n Enter %d numbers\n",no);

for(i=0;i<no;++i)

scanf("%d",&x[i]);

sort(0,no-1);

display();

}

void display ()

{

printf("\n Sorted elements are:\n");

for(i=0;i<no;++i)

printf("%5d",x[i]);

}
void sort(int first,int last)

{

  int *temp,*pivot,i,j;

  if (first<last)

  {

    pivot=x[first];

    i=first;

    j=last;

    while(i<j)

    {

       while(x[i]<=pivot && i<last)

       i++;

       while(x[j]>=pivot && j>first)

       j--;

       if(i<j)

       {

            temp=x[i];

            x[i]=x[j];

            x[j]=temp;

          }

    }

    temp=x[first];

    x[first]=x[j];

    x[j]=temp;

    sort(first,j-1);

    sort(j+1,last);

  }

}
