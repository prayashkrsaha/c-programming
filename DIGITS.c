#include<stdio.h>

int sum(int);
int oddsum(int);
int evensum(int);

int sum(int num)
{
    int s=0;
    while(num!=0)
    {
        s+=num%10;
        num=num/10;
    }
    return s;
}

int oddsum(int num)
{

    int s=0;
    while(num!=0)
    {
        if((num%10)%2!=0)
        {
            s+=num%10;
        }
        num=num/10;
    }
    return s;
}

int evensum(int num)
{

    int s=0;
    while(num!=0)
    {
        if((num%10)%2==0)
        {
            s+=num%10;
        }
        num=num/10;
    }
    return s;
}

int main()
{   int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("The sum of all the digit is: %d\n",sum(num));
    printf("The sum of all the odd digit is: %d\n",oddsum(num));
    printf("The sum of all the even digit is: %d\n",evensum(num));
    return 0;
}
