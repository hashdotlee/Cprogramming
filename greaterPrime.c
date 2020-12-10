#include<stdio.h>

int checkPrime(int k){
    for(int i = 2; i<k;i++){
        if(k%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    printf("Enter k: ");
    int k; scanf("%d",&k);
    for(;;){
        k += 1;
        if(checkPrime(k)){
                printf("%d\n", k);
                break;
        }
    }
    return 0;

}

