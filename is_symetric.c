#include<stdio.h>
#define MAX_SIZE 30
int main()
{   
    int A[MAX_SIZE][MAX_SIZE];
    printf("Input array\n");
    printf("Enter the array size: "); int n; scanf("%d", &n);
    /*-------------------------*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter value index <%d %d> ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    /*-------------------------*/
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(A[i][j] != A[j][i]){
                printf("A is not symmetric\n");
                return 0;
            }
        }
    }
    printf("A is symmetric\n");

    /*-------------------------*/
    
    return 0;
}