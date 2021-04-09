#include<stdio.h>

typedef struct COMPLEX{

    int real;
    int img;

}Complex;

Complex multiply(Complex, Complex);

int main(){

    int a1, b1, a2, b2;
    Complex x, y, z;
    printf("Enter first complex number : ");
    scanf("%d+%di", &a1, &b1);
    printf("\nEnter second complex number : ");
    scanf("%d+%di", &a2, &b2);
    x.real = a1;
    x.img = b1;
    y.real = a2;
    y.img = b2;
    z = multiply(x, y);
    printf("\nThe Product: %d+%di", z.real, z.img);
    return 0;
}
Complex multiply(Complex x, Complex y)
{
    Complex z;
    z.real = x.real * y.real - x.img * y.img;
    z.img = x.real * y.img + x.img * y.real;
    return z;
}
