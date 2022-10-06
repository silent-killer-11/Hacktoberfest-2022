/*  C Program to find area and circumference of circle  */

#include<stdio.h>

int main()
{
    float area, radius, circum;

    printf("ENTER THE RADIUS OF THE CIRCLE :: ");
    scanf("%f", &radius);
    area = 3.142 * radius * radius;
    circum = 2 * 3.142 * radius;
    printf("\nTHE AREA OF THE CIRCLE IS :: %f", area);
    printf("\n\nTHE CIRCUMFERENCE OF THE CIRCLE IS :: %f\n", circum);

    return 0;
}


