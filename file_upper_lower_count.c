#include<stdio.h>
int main()
{
    FILE *fp;
    char a[50];
    int ch;
    int capital=0, small=0;

    scanf("%[^\n]",a);
    fp=fopen(a,"r");

    printf("Reading file: %s\n",a);
    do
    {
        ch=fgetc(fp);
        if(ch>=65 && ch<=90)
            capital++;
        else if(ch>=97 && ch<=122)
            small++;
    }
    while(ch!=EOF);
    fclose(fp);
    printf("Uppercase count: %d\n",capital);
    printf("Lowercase count: %d\n",small);
    return 0;
}
