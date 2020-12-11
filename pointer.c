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
 #include<stdio.h>

 int main(){
     float a,b,c;
     float * p;
     printf("Enter the value of a: "); scanf("%f",&a);
     printf("Enter the value of b: "); scanf("%f",&b);
     printf("Enter the value of c: "); scanf("%f",&c);
     p = &a; *p += 100; printf("a + 100 = %.1f; ", a);
     p = &b; *p += 100; printf("b + 100 = %.1f; ", b);
     p = &c; *p += 100; printf("c + 100 = %.1f; ", c);
     printf("\n");
     return 0;
 }
/*------------------*/
/* Exercise 12.4 */
// #include<stdio.h>

// int main(){

//     return 0;
// }
/*------------------*/
/* Exercise 12.5 */
// #include<stdio.h>

// int main(){

//     return 0;
// }
/*------------------*/
/* Exercise 12.6 */
// #include<stdio.h>

// int main(){

//     return 0;
// }
/*------------------*/

