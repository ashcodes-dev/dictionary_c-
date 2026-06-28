#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include<string.h>
char words_list[5000][100];
void display();
void find_big();
void search();
void search_rank();

void load_data(FILE* fp, int data_size);
void menu();

int main() {
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL) {
		printf("failed to load data");
		return 1;

	}
	else {
		printf("data loaded succesfully\n ");
	}

	printf("welcome to most popluar words dictionary\n");
	load_data(fp, 4000);
	menu();

	return 0;
}

void load_data(FILE* fp, int data_size) {
	for (int i = 0; i < data_size; i++) {
		fscanf(fp, "%s", words_list[i]);

	}
}
void menu() {
	bool running = true;
	while (running == true) {
		int choice;
		printf("what do you want to do \n");
		printf("1.display the words by popluarity 2.search a word 3. search by popluarity rank 4. find biggest word \n");
		printf("5.list the most popluar words by alphabetical order 6.display n elements by order 7. to quit the app\n");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
			/// display function
			display();
			break;
		case 2:
			////search function 
			search();
			break;
		case 3:
			///search by popluairty
			search_rank();
			break;
		case 4:
			/// find the biggest element
			find_big();
			break;
		case 5:
			///display n elemensts fucntion 
			break;
		case 6:
			running = false;
			break;
		default:
			printf("invalid choice \n");
		}

	}



}
void display() {
	int i = 0, choice;
	bool running = true;
	printf("%d. %s \n", i + 1, words_list[i]);
	while (running == true) {

		printf("1. next 2.previous 3 . menu \n");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
			i++;
			printf("%d. %s\n", i + 1, words_list[i]);
			break;
		case 2:
			if (i < 1) {
				printf("%d. %s\n", i + 1, words_list[i]);
			}
			else {
				i--;
				printf("%d. %s\n", i + 1, words_list[i]);

			}
			break;
		case 3:
			running = false;
			break;
		default:
			printf("invalid choice \n");
		}


	}
}
void search_word() {
	char search[20];
	printf("enter the word to search \n");
	scanf("%19s", search);
	for (int i = 0; i < 4000; i++) {

	}

}

/// biggest word finder 
void find_big() {
	char buffer[20];
	int i = 0, j = 0, big = 0;
	for (i; i < 4000; i++) {
		for (j; j < 100; j++) {
			if (words_list[i][j] == '\0') {
				if (big < j) {
					big = j;
					int k;
					for (k = 0; words_list[i][k] != '\0' && k < 19; k++) {
						buffer[k] = words_list[i][k];
					}
					buffer[k] = '\0';

				}
				break;

			}
		}
		j = 0;
	}
	printf("biggest word is %s it has %d letters", buffer, big);

}void search() {

	char buffer[20];
	int i = 0;
	bool found = false;
	printf("enter the word you want to search \n");
	scanf(" %s", buffer);
	for (i; i < 4000; i++) {
		int j = 0;
		while (buffer[j] == words_list[i][j]) {
			if (buffer[j] == '\0') {
				printf("word found %s is %d . most popluar \n ", words_list[i], i +1);
				found = true;
			}
			j++;
		}


		
		
			}
	if (found == false) {
		printf("word doesnt exist in data \n");
	}

		

}
void search_rank() {
	int i = 0;
	printf("enter the rank of word ");
	scanf(" %d", &i);
	printf("%d most popluar word is %s \n", i , words_list[i - 1]);

}
	
