#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
char words_list[5000][100];
bool sorted = false;
char sorted_list[5000][100];
void display();
void find_big();
void search();
void search_rank();

void sort();
void display_sorted();
void display_n();
void display_random();

void load_data(FILE* fp, int data_size );
void load_data2(FILE* fp, int data_size);
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
	rewind(fp);
	load_data2(fp, 4000);
	

	menu();

	return 0;
}

void load_data(FILE* fp, int data_size ) {
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
		printf("5.list the most popluar words by alphabetical order 6.display n elements by order 7. to display a random word\n");
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
			///sort the list by alphabetical order
			display_sorted();
			break;
		case 6:
			// display n elements by order
			display_n();
			break;
		case 7:
			// display a random word
			display_random();
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
	printf("biggest word is %s it has %d letters\n", buffer, big);

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
void sort() {
	int min = 0;
	char buffer[20];
	for (int i = 0; i < 4000; i++) {
		min = i;
		for (int j = i + 1; j < 4000; j++) {
			for (int k = 0; k < 20; k++) {
				int diff = sorted_list[j][k] - sorted_list[min][k];
				if (diff < 0) {
					min = j;
					break;
				}
				else if (diff > 0) {
					break;

				}
			}
		}
		for (int o = 0; o < 20; o++) {
			buffer[o] = sorted_list[i][o];
			sorted_list[i][o] = sorted_list[min][o];
			sorted_list[min][o] = buffer[o];
		}


	}
	printf("words sorted by alphabetical order \n");
	sorted = true;

}
void display_sorted() {
	if (sorted == false) {
		sort();
	}
	
	int i = 0, choice;
	bool running = true;
	printf("%d. %s \n", i + 1, sorted_list[i]);
	while (running == true) {

		printf("1. next 2.previous 3 . menu \n");
		scanf(" %d", &choice);
		switch (choice)
		{
		case 1:
			i++;
			printf("%d. %s\n", i + 1, sorted_list[i]);
			break;
		case 2:
			if (i < 1) {
				printf("%d. %s\n", i + 1, sorted_list[i]);
			}
			else {
				i--;
				printf("%d. %s\n", i + 1, sorted_list[i]);

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
void load_data2(FILE* fp, int data_size) {
	for (int i = 0; i < data_size; i++) {
		fscanf(fp, "%s", sorted_list[i]);


	}
}
void display_n() {
	int n;
	printf("enter the number of elements you want to display \n");
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		printf("%d. %s \n", i + 1, words_list[i]);
	}
}
void display_random() {
	srand(time(NULL));
	int random_index = rand() % 4000;
	printf("random word is %s  ranked %d\n", words_list[random_index], random_index + 1);
}
