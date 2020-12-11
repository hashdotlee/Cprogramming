/* Exercise 12.1 */
// #include<stdio.h>

// int main(){
//     int a = 1, b = 2, c = 3;
//     int * p;
//     p = &a; printf("The value of \"a\": %d\n", *p);
//     p = &b; printf("The value of \"b\": %d\n", *p);
//     p = &c; printf("The value of \"c\": %d\n", *p);
//     return 0;
// }
/*-----------------*/
/* Exercise 12.2 */
//  #include<stdio.h>

//  int main(){
//      int a[7] = {13,-355,235,47,67,943,1222};
//         for(int i = 0; i<5; i++)
//      {
//          printf("The adress of index %d is: %ld and the size of it is: %ld Byte\n", i+1, &a[i], sizeof(&a[i]));
//      }
//      return 0;
//  }
/*-----------------*/
/* Exercise 12.3 */
//  #include<stdio.h>

//  int main(){
//      float a,b,c;
//      float * p;
//      printf("Enter the value of a: "); scanf("%f",&a);
//      printf("Enter the value of b: "); scanf("%f",&b);
//      printf("Enter the value of c: "); scanf("%f",&c);
//      p = &a; *p += 100; printf("a + 100 = %.1f; ", a);
//      p = &b; *p += 100; printf("b + 100 = %.1f; ", b);
//      p = &c; *p += 100; printf("c + 100 = %.1f; ", c);
//      printf("\n");
//      return 0;
//  }
/*------------------*/
/* Exercise 12.4 */
//  #include<stdio.h>

//  int swap(int *a, int *b, int *c){
//      int temp = *a;
//      *a = *b;
//      *b = *c;
//      *c = temp;
//  }
//  int main(){
//      printf("Input value of three variables\n");
//      int a,b,c;
//      printf("Enter value of a: "); scanf("%d", &a);
//      printf("Enter value of b: "); scanf("%d", &b);
//      printf("Enter value of c: "); scanf("%d", &c);
//      printf("Before: %d %d %d\n",a,b,c);
//      swap(&a,&b,&c);
//      printf("After:  %d %d %d\n",a,b,c);
//      return 0;
//  }
/*------------------*/
/* Exercise 12.5 */
//   #include<stdio.h>

//   int swap1(int *a, int *b, int *c){
//       int temp = *a;
//       *a = *b;
//       *b = *c;
//       *c = temp;
//   }
//   int swap2(int **a, int **b, int **c){
//       int * temp = *a;
//       *a = *b;
//       *b = *c;
//       *c = temp;
//   }
//   int main(){
//       printf("Input value of three variables\n");
//       int *p,*q,*r,x,y,z;
//       printf("Enter value of x: "); scanf("%d", &x);
//       printf("Enter value of y: "); scanf("%d", &y);
//       printf("Enter value of z: "); scanf("%d", &z);
//       p = &x; q = &y; r = &z;
//       printf("x: %d, y: %d, z: %d, p: %ld, q: %ld, r: %ld, *p: %d, *q: %d, *r: %d\n",x, y, z, (long int)p, (long int)q, (long int)r, *p, *q, *r);
//       swap1(&x,&y,&z);
//       printf("x: %d, y: %d, z: %d, p: %ld, q: %ld, r: %ld, *p: %d, *q: %d, *r: %d\n",x, y, z, (long int)p, (long int)q, (long int)r, *p, *q, *r);
//       swap2(&p,&q,&r);
//       printf("x: %d, y: %d, z: %d, p: %ld, q: %ld, r: %ld, *p: %d, *q: %d, *r: %d\n",x, y, z, (long int)p, (long int)q, (long int)r, *p, *q, *r);
//       return 0;
//   }
/*------------------*/
/* Exercise 12.6 */
// #include<stdio.h>
// void incomeplus(int *salary, int year)
// {
//     if (year>3) *salary += 1500*year;
// }
// int main(){
//     printf("Enter current salary: "); int salary; scanf("%d", &salary);
//     printf("Enter number years have passed: "); int year; scanf("%d", &year);
//     incomeplus(&salary, year);
//     year>3&&printf("The new salary (current + $1500/year): $%d\n", salary);
//     return 0;
// }
/*------------------*/

