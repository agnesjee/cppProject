#include <iostream>
#include <time.h>
using namespace std;

#define MAXL 60000 //Change the maxl from 10000 to 60000 to find the diagrams

int aList[MAXL];
int bList[MAXL];

void displayList(int data[], int size) {
	for (int k = 0; k < size; k++)
		cout << data[k] << " ";
	cout << endl;
}

void bubbleSort(int data[], int size){
	int i, j; // for looping twice
	int temp;

	for (i=0; i< size; i++) {
		for (j=0; j< size-i-1; j++) {
			if (data[j] > data[j+1]) { // need to swap
				//cout << "Swapping " <<  data[j+1] << " & " << data[j] << endl;
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
		//displayList(data, size);
	}
}

void selectionSort(int data[], int size){
	int temp; // for swap
	int max_index; // index of max value
	int rightmost, current;
	
	for (rightmost=size-1; rightmost>0; rightmost--){
		//find the largest item in the unsorted portion
		//rightmost is the end point of the unsorted part of array
		max_index = 0; //points the largest element
		for (current=1; current<=rightmost; current++)
			if (data[current] > data[max_index])
				max_index = current;
		//swap the largest item with last item if necessary
		if (data[max_index] > data[rightmost]){
			//cout << "Swapping " <<  data[rightmost] << " & " << data[max_index] << endl;
			temp = data[max_index]; // swap
			data[max_index] = data[rightmost];
			data[rightmost] = temp;
		}
		//displayList(data, size);
	}
}


int main() {
    clock_t timeBefore, timeAfter;
    double timeTaken;

    srand(time(NULL));
    for (int k = 0; k< MAXL; k++){
        aList[k] = rand() % 100;
        bList[k] = aList[k];
    }
	
	//displayList(aList, MAXL);
    timeBefore = clock();
	selectionSort(aList, MAXL);
    timeAfter = clock();
    timeTaken = (timeAfter - timeBefore)/1000.0;
    //cout << "Bubble Sort N = " << MAXL << " T = " << timeTaken << "s\n";
    cout << "Selection Sort N = " << MAXL << " T = " << timeTaken << "s\n";
	
	return 0;
}
