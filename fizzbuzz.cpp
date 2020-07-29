#include <iostream>
using namespace std;

int main(){
    for (int i=1; i<=50; i++){
      if(i%3==0)
      cout << "FIZZ\n";

      else if(i%5==0)
      cout << "BUZZ\n";

      else
      cout << i <<"\n";

      
    }
    return 0;
}
