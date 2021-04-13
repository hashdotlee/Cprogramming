#include<stdio.h>
#include<stdlib.h>
#define MAX_LINE 81
typedef struct {
	char vi[30];
	char eng[30];
} words_t;
int lineNumber(FILE * fileIn){
	char buff[MAX_LINE];
	fseek(fileIn, 0, SEEK_SET);
	fgets(buff, MAX_LINE, fileIn);
	int n = 0;
	while(fgets(buff, MAX_LINE, fileIn) != NULL){
		n++;
	}
	fseek(fileIn, 0, SEEK_SET);
	fgets(buff, MAX_LINE, fileIn);
	return n;
}
int main(){
	FILE * fileIn = fopen("vnedict.txt", "r");
	FILE * fileOut = fopen("vnedict.dat", "w+b");
	if(fileIn==NULL){printf("Cannot read the file vnedict.txt\n"); exit(1);};
	if(fileOut==NULL){printf("Cannot write the file vnedict.dat\n"); exit(1);};
	char buff[MAX_LINE];
	int n = lineNumber(fileIn);
	words_t * dict = (words_t *) malloc(sizeof(words_t)*n);
	int i = 0;
	while(fgets(buff, MAX_LINE, fileIn)!=NULL){
		sscanf(buff, "%[^\n:]:%[^\n:]", dict[i].vi, dict[i].eng);
		i++;
	} 	
	fwrite(dict, sizeof(words_t), n, fileOut);
	fclose(fileOut);
	FILE * fileOut2 = fopen("vnedict.dat", "rb");
	printf("Read from: "); int begin = 0; scanf("%d", &begin);
	printf("to: "); int end = 0; scanf("%d", &end);
	words_t * temp_dict = (words_t *) malloc(sizeof(words_t)*(end-begin+1));
	fseek(fileOut2, begin*sizeof(words_t), SEEK_SET);
	fread(temp_dict, sizeof(words_t), end-begin+1, fileOut2);
	for(int i = 0; i < end-begin+1; i++){
		printf("%s - %s\n", temp_dict[i].vi,temp_dict[i].eng);	
	}
	fclose(fileOut2);
	free(dict);
	fclose(fileIn);
	return 0;
}

