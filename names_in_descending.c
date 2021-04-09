#include<stdio.h>
#include<string.h>
#define max 30
struct student
{
    int roll_no;
    char name[max];
    float marks;
};
void bubble_sort(struct student arr[], int N);
int main()
{
    struct student stud[50];
    int n,i,len,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&stud[i].roll_no);
        fflush(stdin);
        scanf("%[^\n]",stud[i].name);
        scanf("%f",&stud[i].marks);
    }
    for(i=0;i<n;i++)
    {
        bubble_sort(stud,n);
    }
    printf("Merit List:\n");
    for(i=n-1;i>=0;i--)
    {
        printf("%d ",stud[i].roll_no);
        printf("%s",stud[i].name);
        len=strlen(stud[i].name);
        for(k=0;k<=(30-len);k++)
            printf(" ");
        printf("%.2f",stud[i].marks);
        printf("\n");
    }
    //return 0;
}
void bubble_sort(struct student arr[],int N)
{
    int i,j;
    struct student temp;
    for(i=0;i<N;i++)
        for(j=0;j<N-i-1;j++)
            if(arr[i].marks>arr[j+1].marks)
                {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
}
