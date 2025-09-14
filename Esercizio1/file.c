#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int l, int* arr) {
	for (int i = 0; i < l; i++) {
		printf("%d ", arr[i]);
	}
}

void swap(int l, int* arr, int pos1, int pos2) {
	int temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}

void invetrArr(int l, int* arr) {
	for (int i = 0; i < l / 2; i++) {
		int temp = arr[i];
		arr[i] = arr[l - i - 1];
		arr[l - i - 1] = temp;
	}
	
	printArr(l, arr);
}

void sumAvarage(int l, int* arr) {
	int sum = 0;

	for (int i = 0; i < l; i++) {
		sum += arr[i];
	}
	
	printf("sum: %d", sum);
	printf("avarage: %d", (sum / l));
}

void printEven(int l, int* arr) {
	for (int i = 0; i < l; i++) {
		if (arr[i] % 2 == 0) {
			printf("%d ", arr[i]);
		}
	}
}

void printOdd(int l, int* arr) {
	for (int i = 0; i < l; i++) {
		if (arr[i] % 2 != 0) {
			printf("%d ", arr[i]);
		}
	}
}

// Return i if found, -1 otherwise
int searchNumber(int l, int* arr, int n) {
	for (int i = 0; i < l; i++) {
		if (arr[i] == n) {
			return i;
		}
	}
	
	return -1;
}

// Put 0 in place of the number
void deleteNumber (int l, int* arr, int n) {
	for (int i = 0; i < l; i++) {
		if (arr[i] == n) {
			arr[i] = 0;
		}
	}
}

void swapNumbers(int l, int* arr) {
	for (int i = 0; i < l; i += 2) {
		if (i + 1 >= l) {
			break;
		}

		swap(l, arr, i, i + 1);
	}
}

void bubbleSort(int l, int* arr) {
	for (int i = l; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(l, arr, j, j + 1);
			}
		}
	}
}

void printMenu(int l, char menu[][100]) {
	for (int i = 0; i < l; i ++) {
		printf("%s\n", menu[i]);
	}
}

int main(int argc, char* argv[]) 
{
  char menu[][100] = {
		"1. Print array",
		"2. Invert array",
		"3. Sum and avarage",
		"4. Print even numbers",
		"5. Print odd numbers",
		"6. Search number",
		"7. Delete number",
		"8. Swap each two elements",
		"9. Sort array",
		"10. Exit"
	};
	int lMenu = sizeof(menu) / sizeof(menu[0]); 

	// Generate a random array
	int sizeArr = 10;
	int* arr = (int *)malloc(sizeArr * sizeof(int));

	srand(time(0));

	for (int i = 0; i < sizeArr; i++) {
    arr[i] = rand() % 100; // Generates numbers between 0 and 99
  }

	int _continue = 1;

	while (_continue) {
		printf("\n\n");
		int choice;
		printMenu(lMenu, menu);
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printArr(sizeArr, arr);
				break;
			case 2:
				invetrArr(sizeArr, arr);
				break;
			case 3:
				sumAvarage(sizeArr, arr);
				break;
			case 4:
				printEven(sizeArr, arr);
				break;
			case 5:
				printOdd(sizeArr, arr);
				break;
			case 6: {
				int n;
				printf("Enter number to search: ");
				scanf("%d", &n);
				int found = searchNumber(sizeArr, arr, n);
				if (found >= 0) {
					printf("Number found in position: %d\n", found);
				} else {
					printf("Number not found\n");
				}
				break;
			}
			case 7: {
				int n;
				printf("Enter number to delete: ");
				scanf("%d", &n);
				deleteNumber(sizeArr, arr, n);
				break;
			}
			case 8:
				swapNumbers(sizeArr, arr);
				break;
			case 9:
				bubbleSort(sizeArr, arr);
				break;
			case 10:
				_continue = 0;
				break;
			default:
				printf("Invalid choice\n");
		}
	}

	printf("\n");
	free(arr);
	return 0;
}