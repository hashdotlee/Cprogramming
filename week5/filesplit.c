#include<stdio.h>
#include<stdlib.h>
typedef struct {
	char phone[11];
	char name[40];
	char email[40];
} phonebook_t;
int main(int argc, char ** argv){
	if(argc != 5){printf("Try ./filesplit origin offset file1 file2"); exit(1);}
	FILE * fileIn = fopen(argv[1], "rb");
	if(fileIn == NULL){printf("Cannot open original file\n"); exit(1);}
	FILE * fileOut1 = fopen(argv[3], "wb+");
	if(fileOut1 == NULL){printf("Cannot open output file 1 \n"); exit(1);}
	FILE * fileOut2= fopen(argv[4], "wb+");
	if(fileOut2 == NULL){printf("Cannot open output file 2\n"); exit(1);}
	int n = atoi(argv[2]);
	phonebook_t * phonebook = (phonebook_t *)malloc(sizeof(phonebook_t)*n);
	phonebook_t * buff = (phonebook_t *)malloc(sizeof(phonebook_t)*n);
	fread(phonebook, sizeof(phonebook_t), n, fileIn);
	fwrite(phonebook, sizeof(phonebook_t), n,fileOut1);
	while(!feof(fileIn)){
		fread(buff, sizeof(phonebook_t), 1, fileIn);
		printf("what\n");
		fwrite(buff, sizeof(phonebook_t), 1, fileOut2);
	}
	free(phonebook);
	fclose(fileIn);
	fclose(fileOut1);
	fclose(fileOut2);
	return 0;
}

