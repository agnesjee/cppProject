#include <iostream>
#include <time.h>
using namespace std;

#define MAXL 100

int lList[MAXL];
int lStep = 0;
int schVal = 0; //search value
int schPos = 0; //search position
int bStep = 0;
int bList[MAXL];

void displayList(int list[]){
    for(int k = 0; k < MAXL; k++){
        cout << list[k] << " ";
    }
    cout << endl;
}

int linearSearch(int list[], int key){ //use int, because it will return the position; key is search value
    int index = -1; //position, if return the last number(100) meaning that the searching is unsuccessful (number that we search doesn't exist)

    for(int k = 0; k < MAXL; k++){
        lStep++;
        if(list[k] == key){
            index = k;
            break;
        }
    }
    return index;
}

int binarySearch(int list[], int first, int last, int key){
    int index = -1;

    if (first > last) // invalid list
        index = -1;
    else {
        int mid = (first + last)/2;
        bStep++;
        if (key == list[mid]) // very small list
            index = mid;
        else{
            if (key < list[mid])
                index = binarySearch(list, first, mid-1, key);
            else
                index = binarySearch(list, mid+1, last, key);
        }
    }
    return index;
}

void bubbleSort(int data[], int size){
int i, j; // for looping twice
int temp;

for (i=0; i< size; i++){//the big round
    for (j=0; j< size-i-1; j++){ //go through first until second last element (one by one to compare)
        if (data[j] > data[j+1]){  // need to swap
            //cout << "Swapping " << data[j] << " & " << data[j+1] << endl;
            temp = data[j];
            data[j] = data[j+1];
            data[j+1] = temp;
        }
    }
    //displayList(data, size);
}

}


int main(){
    srand(time(NULL));

    for (int k = 0; k<MAXL; k++){
        lList[k] = rand() % 1000;
        bList[k] = lList[k];
    }

    displayList(lList);
    cout << "Enter searched value > ";
    cin >> schVal;
    schPos = linearSearch(lList, schVal);
    cout << "LINEAR SEARCH FOR " << schVal << " FOUND AT POS " << schPos << endl;
    cout << "STEPS TAKEN = " << lStep << endl;
    bubbleSort(bList, MAXL);
    displayList(bList);
    schPos = binarySearch(bList, 0, MAXL, schVal);
    cout << "BINARY SEARCH FOR " << schVal << " FOUND AT POS " << schPos << endl;
    cout << "STEPS TAKEN = " << bStep << endl;


    return 0;
}
