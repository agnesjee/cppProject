#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main() {

  srand(time(NULL));

  int computer = std::rand() % 3 + 1;

  int user;

  cout << "====================\n";
  cout << "rock paper scissors!\n";
  cout << "====================\n";

  cout << "1) Rock\n";
  cout << "2) Paper\n";
  cout << "3) Scissors\n";

  cout << "Shoot! Enter the number: ";

  cin >> user;

  if (user == 1)
    cout << "you choose: Rock\n";
  else if (user == 2)
    cout << "you choose: Paper\n";
  else
    cout << "you choose: Scissors\n";

  if (computer == 1)
    cout << "cpu choose: Rock\n";
  else if (computer == 2)
    cout << "cpu choose: Paper\n";
  else
    cout << "cpu choose: Scissors\n";


  if (user == computer) {
    cout << "it's a tie!\n";
  }

  // user rock
  else if (user == 1) {
    if (computer == 2) {
        cout << "you lost! booooo!\n";
    }
    if (computer == 3) {
        cout << "you won! woohoo!\n";
    }
  }

  // user paper
  else if (user == 2) {
    if (computer == 1) {
        cout << "you won! woohoo!\n";
    }
    if (computer == 3) {
        cout << "you lost! booooo!\n";
    }
  }

  // user scissors
  else if (user == 3) {
    if (computer == 1) {
        cout << "you won! woohoo!\n";
    }
    if (computer == 2) {
        cout << "you lost! booooo!\n";
    }
  }

  return 0;
}
