#include<stdio.h>
#define SIZE 3
void input_array(int A[][3]){
    printf("###### Input matrix wizard ######\n");
    printf("Input first row: "); scanf("%d",&A[0][0]);scanf("%d", &A[0][1]); scanf("%d", &A[0][2]);
    printf("Input second row: "); scanf("%d",&A[1][0]);scanf("%d", &A[1][1]); scanf("%d", &A[1][2]);
    printf("Input third row: "); scanf("%d",&A[2][0]);scanf("%d", &A[2][1]); scanf("%d", &A[2][2]);
}
void multiply(int A[][3], int B[][3], int C[][3]){
    for(int i = 0; i< 3; i++){
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j]*B[j][i];
        }
    }
}
void print_matrix (int A[][3], char * c)
{
    printf("--The matrix %c--\n", c);
    for(int i = 0; i<3; i++)
    {
        printf("| %3d ", A[i][0]);
        printf("| %3d ", A[i][1]);
        printf("| %3d |", A[i][2]);
        printf("\n");
    }
    printf("--------------\n");
}
int main(){
    int A[3][3], B[3][3], C[3][3];
    while(1){
        printf("Please choose the option 1-5\n");
        printf("1. Input A\n");
        printf("2. Input B\n");
        printf("3. Multiply\n");
        printf("4. Exit\n");
        printf("1-4: "); int check; scanf("%d", &check);
        switch(check){
            case 1:
                input_array(A);
                break; 
            case 2:
                input_array(B);
                break;
            case 3:
                multiply(A,B,C);
                print_matrix(A, 'A');
                print_matrix(B, 'B');
                print_matrix(C, 'C');
            default:
                return 0;
        }
    }
    return 0; 
}
