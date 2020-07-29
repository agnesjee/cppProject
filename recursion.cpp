#include <iostream>
using namespace std;

//n!=n*(n-1)!
int iFact(int n){
    int fac= 1;
    for (int k = 1; k <= n;k++){
        fac = k*fac;
    }
    return fac;

    /*Suppose n = 4
    for (int k = 1; k <= 4; k++) --> k = 1
        fac = 1*1;               --> fac = 1
    for (int k = 1; k <= 4; k++) --> k = 2
        fac = 2*1;               --> fac = 2
    for (int k = 1; k <= 4; k++) --> k = 3
        fac = 3*2;               --> fac = 6
    for (int k = 1; k <= 4; k++) --> k = 4
        fac = 4*6;               --> fac = 24
    return 24
    */

}

int rFact(int n){
    if (n <= 1)
        return 1; 
    else
        return n * rFact(n-1);
}

//F(n) = F(n-1) + F(n-2)
int iFibo(int n){
    if (n <= 1)
        return n;
    
    int a = 0; // for (n-2)
    int b = 1; // for (n-1)
    for (int k = 2; k <= n; k++){
        int c = b + a;
        a = b; // previous become prev prev --> new(n-2) is current (n-1)
        b = c; // new(n-1) is current n
    }
    return b; // also means return c (b = c)
}

int rFibo(int n){
    if (n <= 1)
        return n;
    else
        return rFibo(n-1) + rFibo(n-2);
}

int main(){
    int num;
    cout << "Enter a positive integer number: ";
    cin >> num;
    cout << "Iterative factorial = " << iFact(num) << endl;
    cout << "Recursive factorial = " << rFact(num) << endl;
    cout << "Iterative fibonacci = " << iFibo(num) << endl;
    cout << "Recursive fibonacci = " << rFibo(num) << endl;

    return 0;
}
