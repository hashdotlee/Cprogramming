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
	if(argc != 2){printf("Try ./filesplit origin offset file1 file2"); exit(1);}
	FILE * fileIn= fopen(argv[1], "rb");
	if(fileIn== NULL){printf("Cannot open output file 2\n"); exit(1);}
	copyFile(fileIn, stdout);
	fclose(fileIn);
	return 0;
}


