#include<stdio.h>

int main()
{
    int A[5];
    int *p; p = A;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the value index %d: ", i+1);
        scanf("%d", p+i);
    }
    printf("Array: [ ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("]\n");
    return 0;
}