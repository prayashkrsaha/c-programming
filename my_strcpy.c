#include<stdio.h>
char *my_strcpy(char *destination, char *source);

int main()
{
    char ch_arr1[20];
    char ch_arr2[20];

    printf("Enter first string (ch_arr_1): ");
    gets(ch_arr1);
    printf("Enter second string(ch_arr_1): ");
    gets(ch_arr2);
    printf("\nCopying \"Berlin\" string into ch_arr1 ... \n");
    my_strcpy(ch_arr1, "Berlin");
    printf("\nCopying \"Nairobi\" string into ch_arr2 ... \n\n");
    my_strcpy(ch_arr2, "Nairobi");
    printf("First string (ch_arr_1) = %s\n", ch_arr1);
    printf("Second string (ch_arr_2) = %s\n", ch_arr2);
    return 0;
}

char *my_strcpy(char *destination, char *source)
{
    char *start = destination;
    while(*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return start;
}
