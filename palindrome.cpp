#include <iostream>
using namespace std;

#define MAX 10

// define structure of a static stack
struct Stack {
	char data[MAX];
	int top;
};

// check if stack is empty
bool isEmpty(int tmpTop) {
	return (tmpTop < 0);
}

// check if stack is full
bool isFull(int tmpTop) {
	return (tmpTop == (MAX-1));
}

// display all elements in the stack
void displayStack(Stack tmpStack) {
	if (isEmpty(tmpStack.top))
		cout << "Stack is empty!\n";
	else {
		for (int k = 0; k <= tmpStack.top; k++)
			cout << tmpStack.data[k] << " ";
		cout << "TOP\n";
	}
}

// add a new element to the top of the stack
void push(Stack *ptrStack, char n) {
	if (isFull(ptrStack->top))
		cout << "Stack is full! Push aborted\n";
	else {
		ptrStack->top++;
		ptrStack->data[ptrStack->top] = n;
	}
}

// remove an element from the top of the stack
char pop(Stack *ptrStack) {

	char data = '@';
	if (isEmpty(ptrStack->top))
		cout << "Stack is empty! Pop aborted\n";
	else {
		data = ptrStack->data[ptrStack->top];
		ptrStack->top--;
	}
	return data;
}

// return total elements counted in the stack
int displaySize(Stack tmpStack) {
	return (tmpStack.top + 1);
}

bool isPalindrome(Stack *ptrStack, char tmpWord[]){
    bool pal = true;
    int k = 0;

    // Using array
    while (tmpWord[k] != 0){
        if (pop(ptrStack) != tmpWord[k])
            pal = false;
        k++;
    }
    
     /* Using pointers
    for (char *cur = tmpWord, *cur != NULL; cur++){
        if (*cur != pop(ptrStack)){
            pal = false;
        }
    }
    */
    return pal;
}

int main() {
	Stack aStack;
	aStack.top = -1;
    char word[MAX]; //create char like a string

    cout << "Enter a word >> ";//minah
    cin >> word;

    int k = 0;
    while (word[k] != 0){    //use NULL when you are testing for NULL pointer and 0 otherwise
        push(&aStack, word[k]);
        k++;
    }

	displayStack(aStack); // m i n a h TOP

    if (isPalindrome(&aStack, word)){
        cout << word << " is a Palindrome.\n";
    }
    else
    {
        cout << word << " is not a Palindrome.\n";
    }
    

    return 0;
}
