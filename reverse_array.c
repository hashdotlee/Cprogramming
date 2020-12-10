#include<stdio.h>
#define MAX_SIZE 30
int main()
{
    float A[MAX_SIZE];
    printf("Input array\n");
    printf("Enter array size: "); int n; scanf("%d", &n);
    /*----- Begin input Array--------*/
    for (int i = 0; i < n; i++)
    {
        printf("Enter value index %d: ", i+1);
        scanf("%f", &A[i]);
    }
    /*------End input Array----------*/
    /*------End reverse Array----------*/
    for (int i = 0; i < n/2; i++)
    {
        int temp = A[i];
        A[i] = A[n-1-i];
        A[n-1-i] = temp;
    }
    /*------End reverse Array----------*/
    /*------End print Array----------*/
    printf("The reverse Matrix: ");
    for (int i = 0; i < n; i++)
    {
        printf("%2.1f, ", A[i]);
    }
    printf("\n");
    /*------End print Array----------*/
    return 0;
}