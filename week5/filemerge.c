#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char phone[11];
	char name[40];
	char email[40];
} phonebook_t;
void copyFile(FILE *fileIn, FILE *fileOut){
	phonebook_t * buff = (phonebook_t *)malloc(sizeof(phonebook_t));
	fseek(fileIn, 0, SEEK_SET);
while(!feof(fileIn)){
fread(buff, sizeof(phonebook_t), 1, fileIn);
fwrite(buff, sizeof(phonebook_t), 1, fileOut);
};
free(buff);
};
int main(int argc, char ** argv){
	if(argc != 4){printf("Try ./filesplit origin offset file1 file2"); exit(1);}
	FILE * fileOut = fopen(argv[3], "wb+");
	if(fileOut == NULL){printf("Cannot open original file\n"); exit(1);}
	FILE * fileIn1 = fopen(argv[1], "rb");
	if(fileIn1== NULL){printf("Cannot open output file 1 \n"); exit(1);}
	FILE * fileIn2= fopen(argv[2], "rb");
	if(fileIn2== NULL){printf("Cannot open output file 2\n"); exit(1);}
	copyFile(fileIn1, fileOut);
	copyFile(fileIn2, fileOut);
	fclose(fileOut);
	fclose(fileIn1);
	fclose(fileIn2);
	return 0;
}


