/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: Sorting using ditrrent types of sort algorithmes
*/
#include <stdio.h>
#include <time.h> //calculate time
#include <stdlib.h> // for random number

//fuction to change order between two in in array
void swap(int* arr, int x, int y) {
	int temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}


//conduct bubble sort
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
    	for (int j = 0; j < n - 1; j++) {
        	if (arr[j] > arr[j + 1]) {
            	swap(arr, j, j + 1);
        	}
    	}
	}
}

//conduct insertion sort
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; ++i) {
    	int key = arr[i];
    	int j = i - 1;

    	while (j >= 0 && arr[j] > key) {
        	arr[j + 1] = arr[j];
        	j = j - 1;
    	}
    	arr[j + 1] = key;
	}
}


//conduct linear search with random number
void linearSearch (int arr[], int n) {
	int target = arr[rand() % n];
	int found = -1;

	for (int i = 0; i < n; i++) {
    	if (arr[i] == target) {
        	found = i;
        	break;
    	}
	}
}

//conduct selection sort
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
    	int min_idx = i;

    	for (int j = i + 1; j < n; j++) {
        	if (arr[j] < arr[min_idx]) {
            	min_idx = j;
        	}
    	}

    	int temp = arr[i];
    	arr[i] = arr[min_idx];
    	arr[min_idx] = temp;
	}
}

//conduct binary search with random number
void binarySearch(int arr[], int n) {
	int target = arr[rand() % n];
	int left = 0, right = n - 1;
	int found = -1;

	insertionSort(arr, n);

	while (left <= right) {
    	int mid = (left + right) / 2;
    	if (arr[mid] == target) {
        	found = mid;
        	break;
    	} else if (arr[mid] < target) {
        	left = mid + 1;
    	} else {
        	right = mid - 1;
    	}
	}
}




//random number generator
int randGen(){
	// int sizeCount = sizeof(randomInput) / sizeof(randomInput[0]);//size.length()
	int getSome = rand();
	return rand();
}

//conduct sorting and calculate time
void evaulation(){
	int size[] = {10, 50, 100, 500, 1000, 5000, 10000, 25000, 50000};
	int sizeCount = sizeof(size) / sizeof(size[0]);//size.length()
	float timeCheck[sizeCount];
	int randT[10];
	int randFF[50];
	int randH[100];
	int randFH[500];
	int randTh[1000];
	int randFT[5000];
	int randTT[10000];
	int randTFT[25000];
	int randFtT[50000];
	
	int randT_temp[10];
	int randFF_temp[50];
	int randH_temp[100];
	int randFH_temp[500];
	int randTh_temp[1000];
	int randFT_temp[5000];
	int randTT_temp[10000];
	int randTFT_temp[25000];
	int randFtT_temp[50000];
    
	for(int i = 0 ; i < 10; i ++){
    	randT[i] = randGen();
    	randT_temp[i] = randT[i];
	}
	for(int i = 0 ; i < 50; i ++){
    	randFF[i] = randGen();
    	randFF_temp[i] = randFF[i];
	}
	for(int i = 0 ; i < 100; i ++){
    	randH[i] = randGen();
    	randH_temp[i] = randH[i];
	}
	for(int i = 0 ; i < 500; i ++){
    	randFH[i] = randGen();
    	randFH_temp[i] = randFH[i];
	}
	for(int i = 0 ; i < 1000; i ++){
    	randTh[i] = randGen();
    	randFH_temp[i] = randFH[i];
	}
	for(int i = 0 ; i < 5000; i ++){
    	randFT[i] = randGen();
    	randFT_temp[i] = randFT[i];
	}
	for(int i = 0 ; i < 10000; i ++){
    	randTT[i] = randGen();
    	randTT_temp[i] = randTT[i];
	}
	for(int i = 0 ; i < 25000; i ++){
    	randTFT[i] = randGen();
    	randTFT_temp[i] = randTFT[i];
	}
	for(int i = 0 ; i < 50000; i ++){
    	randFtT[i] = randGen();
    	randFtT_temp[i] = randFtT[i];
	}
    
	double duration_bubble[9];
	double duration_selection[9];
	double duration_insertion[9];
        double duration_linear[9];
        double duration_binary[9];

	clock_t start, finish;
        
	// Bubble Sort
	start = clock();
	bubbleSort(randT, 10);
	finish = clock();
	duration_bubble[0] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randFF, 50);
	finish = clock();
	duration_bubble[1] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randH, 100);
	finish = clock();
	duration_bubble[2] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randFH, 500);
	finish = clock();
	duration_bubble[3] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randTh, 1000);
	finish = clock();
	duration_bubble[4] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randFT, 5000);
	finish = clock();
	duration_bubble[5] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randTT, 10000);
	finish = clock();
	duration_bubble[6] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randTFT, 25000);
	finish = clock();
	duration_bubble[7] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	bubbleSort(randFtT, 50000);
	finish = clock();
	duration_bubble[8] = (double)(finish - start) / CLOCKS_PER_SEC;
    
    for(int i = 0 ; i < 10; i ++){
    	randT[i] = randT_temp[i];
	}
	for(int i = 0 ; i < 50; i ++){
    	randFF[i] = randFF_temp[i];
	}
	for(int i = 0 ; i < 100; i ++){
    	randH[i] = randH_temp[i];
	}
	for(int i = 0 ; i < 500; i ++){
    	randFH[i] = randFH_temp[i];
	}
	for(int i = 0 ; i < 1000; i ++){
    	randTh[i] = randTh_temp[i];
	}
	for(int i = 0 ; i < 5000; i ++){
    	randFT[i] = randFT_temp[i];
	}
	for(int i = 0 ; i < 10000; i ++){
    	randTT[i] = randTT_temp[i];
	}
	for(int i = 0 ; i < 25000; i ++){
    	randTFT[i] = randTFT_temp[i];
	}
	for(int i = 0 ; i < 50000; i ++){
    	randFtT[i] = randFtT_temp[i];
	}
        
	// Selection Sort
	start = clock();
	selectionSort(randT, 10);
	finish = clock();
	duration_selection[0] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randFF, 50);
	finish = clock();
	duration_selection[1] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randH, 100);
	finish = clock();
	duration_selection[2] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randFH, 500);
	finish = clock();
	duration_selection[3] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randTh, 1000);
	finish = clock();
	duration_selection[4] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randFT, 5000);
	finish = clock();
	duration_selection[5] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randTT, 10000);
	finish = clock();
	duration_selection[6] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randTFT, 25000);
	finish = clock();
	duration_selection[7] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	selectionSort(randFtT, 50000);
	finish = clock();
	duration_selection[8] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	// Insertion Sort
	start = clock();
	insertionSort(randT, 10);
	finish = clock();
	duration_insertion[0] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randFF, 50);
	finish = clock();
	duration_insertion[1] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randH, 100);
	finish = clock();
	duration_insertion[2] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randFH, 500);
	finish = clock();
	duration_insertion[3] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randTh, 1000);
	finish = clock();
	duration_insertion[4] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randFT, 5000);
	finish = clock();
	duration_insertion[5] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randTT, 10000);
	finish = clock();
	duration_insertion[6] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randTFT, 25000);
	finish = clock();
	duration_insertion[7] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	start = clock();
	insertionSort(randFtT, 50000);
	finish = clock();
	duration_insertion[8] = (double)(finish - start) / CLOCKS_PER_SEC;
    
	// Linear Search
	start = clock();
	linearSearch(randT, 10);
	finish = clock();
	duration_linear[0] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randFF, 50);
	finish = clock();
	duration_linear[1] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randH, 100);
	finish = clock();
	duration_linear[2] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randFH, 500);
	finish = clock();
	duration_linear[3] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randTh, 1000);
	finish = clock();
	duration_linear[4] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randFT, 5000);
	finish = clock();
	duration_linear[5] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randTT, 10000);
	finish = clock();
	duration_linear[6] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randTFT, 25000);
	finish = clock();
	duration_linear[7] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	linearSearch(randFtT, 50000);
	finish = clock();
	duration_linear[8] = (double)(finish - start) / CLOCKS_PER_SEC;

	// Binary Search
	start = clock();
	binarySearch(randT, 10);
	finish = clock();
	duration_binary[0] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randFF, 50);
	finish = clock();
	duration_binary[1] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randH, 100);
	finish = clock();
	duration_binary[2] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randFH, 500);
	finish = clock();
	duration_binary[3] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randTh, 1000);
	finish = clock();
	duration_binary[4] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randFT, 5000);
	finish = clock();
	duration_binary[5] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randTT, 10000);
	finish = clock();
	duration_binary[6] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randTFT, 25000);
	finish = clock();
	duration_binary[7] = (double)(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	binarySearch(randFtT, 50000);
	finish = clock();
	duration_binary[8] = (double)(finish - start) / CLOCKS_PER_SEC;


    
	// Save results to results.csv
	FILE *fp = fopen("results.csv", "w");  // Overwrites or creates a new file
	if (fp == NULL) {
    	printf("failed to open results.csv for writing.\n");
    	return;
	}

	fprintf(fp, "Size,BubbleSort,SelectionSort,InsertionSort,LinearSearch,BinarySearch\n");
		for (int i = 0; i < sizeCount; i++) {
			fprintf(fp, "%d,%.6f,%.6f,%.6f,%.6f,%.6f\n",
		    	size[i],
		    	duration_bubble[i],
		    	duration_selection[i],
		    	duration_insertion[i],
		    	duration_linear[i],
		    	duration_binary[i]);
		}
	fclose(fp);
	printf("Results saved to results.csv successfully.\n");
}


int main() {
	evaulation();
	return 0;
}
