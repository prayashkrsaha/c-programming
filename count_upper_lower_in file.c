#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
    FILE*f1;
    int countU=0, countL=0;
    char ch,fname[20],d;
    //clrscr();
    f1=fopen(fname,"w");
    //printf("\nEnter File Name :");
    scanf("%s",&fname);
    f1=fopen(fname,"r");
    if(f1==NULL)
    {
    printf("ERROR");
    exit(1);
    }
    while(ch!=EOF)
    {
    if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
        {
            if((ch>='A' && ch<='Z'))
            {
                countU++;
            }
            else
            {
                countL++;
            }
        }
    }
    fclose(f1);
}
