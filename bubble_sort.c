#include <stdio.h>
#include<stdlib.h>
int main()
{
  int input, i,j,c;
  int count=0;       //keeps track of size of array
  int *numbers=NULL;  //pointer to integer array
  int *more;          //pointer to temporary array
  printf("Enter the numbers(Enter -1000 to stop): ");
  do
  {
    scanf("%d",&input);
    count++;
    more=(int*)realloc(numbers,count*sizeof(int));
    if(more!=NULL)
     {

        //if memory allocation successful

       numbers=more;             //make "numbers" point to memory block pointed by "more"
       numbers[count-1]=input;   //store the given number in the array
     }

    else
     {
       //if there's an error allocating memory
       free(numbers);
       printf("Error reallocating memory");
       exit(1);     //exit out of the program,with return code "1"
     }
     }while(input!=-1000);   //keep asking for more numbers untill,-1000 entered by the user
 printf("Numbers entered: ");
 for(i=0;i<count-1;i++)
   printf("%d,",numbers[i]);

 printf("\n");
 for(i=0;i<count-1;i++)
   {
     for (j=0;j<count-1-1;j++)
      {
        if (numbers[j] > numbers[j+1])
          {
            c=numbers[j];
            numbers[j]=numbers[j+1];
            numbers[j+1]=c;
          }
      }
   }
  printf("\nSorted list in ascending order:\n");
  for ( i = 0 ; i < count-1 ; i++ )
    printf("%d,", numbers[i]);

    printf("\n");

  free(numbers);  //freeing the memory
  return 0;
}
