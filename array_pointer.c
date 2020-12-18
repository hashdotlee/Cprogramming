// Exercise 12.1
// #include<stdio.h>

// int main()
// {
//     int A[5];
//     int *p; p = A;
//     for (int i = 0; i < 5; i++)
//     {
//         printf("Enter the value index %d: ", i+1);
//         scanf("%d", p+i);
//     }
//     printf("Array: [ ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", *(p+i));
//     }
//     printf("]\n");
//     return 0;
// }
// Exercise 12.2
// #include<stdio.h>
// int countEven(int*a, int n){
//     int count = 0;
//     printf("Even number: [ ");
//     for(int i = 0; i<n; i++){
//         if(*(a+i)%2==0){
//             printf("%d ", *(a+i));
//             count ++;
//         }
//         else{printf("  ");}
//     }
//     printf("]\n");
//     return count;
// }

// int main(){
//     int A[15] = {1,2,3,6,6,46,7,2,5,56,2,5,6,3,2};
//     int n = 15;
//     printf("Array:       [ ");
//     for(int i = 0; i<n; i++){
//         printf("%d ", A[i]);
//     }
//     printf("]\n");
//     printf("Count even: %d\n",countEven(A, n));
//     return 0;
// }
// Exercide 12.3
//  #include<stdlib.h>
//  #include<stdio.h>
// double * maximum(double*a,int size){
//     if(!a) return NULL;
//     double *max = a;
//     for(int i = 0; i<size; i++){
//         if(*(a+i)>*max) *max = *(a+i);
//     }
//     return max;
// }
//  int main(){
//      double A[100];
//      int n;
//      printf("Enter size of array: "); scanf("%d",&n);
//      printf("Enter each value of array \n");
//      for(int i=0; i<n; i++){
//          printf("Enter value index %d ", i+1);
//          scanf("%lf", &A[i]);
//      }
//      printf("Max is: %lf\n", *maximum(A,n));
//      return 0;
//  }
// Exercide 12.4
//  #include<stdio.h>
// void getSale(float *a, int n){
//     printf("Enter the sales figures in quarteur: \n");
//     for(int i = 0; i<n; i++){
//         printf("Enter month %d: ", i+1);
//         scanf("%f", a+i);
//     }
// }
// float totalSale(float *a, int n){
//     float sum;
//     for(int i =0; i<n; i++){
//         sum += *(a+i);
//     }
//     return sum;
// }
//  int main(){
//      float quarteurs1[4]; getSale(quarteurs1, 4);
//      float quarteurs2[4]; getSale(quarteurs2, 4);
//      float quarteurs3[4]; getSale(quarteurs3, 4);
//      printf("Total quarteurs 1: %.3f\n",totalSale(quarteurs1,4));
//      printf("Total quarteurs 2: %.3f\n",totalSale(quarteurs2,4));
//      printf("Total quarteurs 3: %.3f\n",totalSale(quarteurs3,4));
//      return 0;
//  }
// Exercide 12.5
//  #include<stdio.h>

//  int main(){
//      int A[4] = {1,3,4,2};
//      int n = 4;
//      for(int i = 0; i<n-1; i++){
//          for(int j = n-i; j>0; j--){
//              printf("[ ");
//              for(int k = 0; k<j; k++){
//                  printf("%d ", A[k]);
//              }
//              printf("]\n");
//          }
//      }
//      printf("\n");
//      return 0;
//  }
// Exercide 12.6
//  #include<stdio.h>

//  int main(){

//      return 0;
//  }
// Exercide 12.7
// #include<stdio.h>

// int main(){

//     return 0;
// }