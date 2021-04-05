#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE * file1 = fopen("ml1", "r");
	if(file1 == NULL){ printf("Cannot open ml1"); return 1;}
	FILE * file2 = fopen("ml2", "r");
	if(file2 == NULL){printf("Cannot open the file2"); return 1;}
	FILE * file3 = fopen("ml3", "w+");
char rs1[81],rs2[81];
	while(1){
char * n1 = fgets(rs1, 81, file1);
if(n1) fputs(rs1, file3);
char * n2 =fgets(rs2, 81, file2);
if(n2) fputs(rs2, file3);
if(!n1 && !n2) break;
	}

	fclose(file1);
	fclose(file2);
	fclose(file3);
return 0;
}
