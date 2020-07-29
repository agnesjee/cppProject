#include <iostream>
using namespace std;

#define MAXL 10
int aList[MAXL];
int bList[MAXL];
int size;

void displayList(int data[], int size){
    for (int k = 0; k < size; k++){
        cout << data[k] << " ";
    }
    cout << endl;
}

void bubbleSort(int data[], int size){
int i, j; // for looping twice
int temp;

for (i=0; i< size; i++){//the big round
    for (j=0; j< size-i-1; j++){ //go through first until second last element (one by one to compare)
        if (data[j] > data[j+1]){  // need to swap
            cout << "Swapping " << data[j] << " & " << data[j+1] << endl;
            temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
        }
    }
    displayList(data, size);
}

}

void selectionSort(int data[], int size){
int temp; // for swap
int max_index; // index of max value
int rightmost, current;

for (rightmost = size-1; rightmost > 0; rightmost--){
//find the largest item in the unsorted portion
//rightmost is the end point of the unsorted part of array

    max_index = 0; //points the largest element

    for (current = 1; current <= rightmost; current++){
        if (data[current] > data[max_index]){
            max_index = current;
        }
    }
  //swap the largest item with last item if necessary
    if (data[max_index] > data[rightmost]){
        cout << "Swapping " << data[max_index] << " & " << data[rightmost] << endl;
        temp = data[max_index]; // swap
        data[max_index] = data[rightmost];
        data[rightmost] = temp;
    }
    displayList(data, size);
}
}

int main(){
    aList[0] = 8;
    aList[1] = 6;
    aList[2] = 7;
    aList[3] = 5;
    aList[4] = 1;
    size = 5;
    copy(aList, aList+size, bList); //array copy function
    cout << "----------------\n";
    cout << "List before Bubble Sort -> ";
    displayList(aList, size);
    cout << "----------------\n";
    bubbleSort(aList, size);
    cout << "List after Bubble Sort ^^ \n";
    cout << "----------------\n";
    cout << "List before Selection Sort -> ";
    displayList(bList, size);
    cout << "----------------\n";
    selectionSort(bList, size);
    cout << "List after Selection Sort ^^ \n";
    
    return 0;
}
