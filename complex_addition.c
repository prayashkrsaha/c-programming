#include <stdio.h>

struct complex
{
   int real, img;
};

int main()
{
   struct complex a, b, c;

   printf("Enter a and b where a + bi is the first complex number.\n");
   scanf("%d+%di", &a.real, &a.img);
   printf("Enter c and d where c + di is the second complex number.\n");
   scanf("%d+%di", &b.real, &b.img);

   c.real = a.real + b.real;
   c.img = a.img + b.img;

   printf("Sum of the complex numbers: (%d) + (%di)\n", c.real, c.img);

   return 0;
}
