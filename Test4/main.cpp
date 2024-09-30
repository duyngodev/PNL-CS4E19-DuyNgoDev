#include <iostream>
#include <cmath>
using namespace std;

bool primeNum(int n){
    for (int i = 2 ; i <= sqrt(n); i++ ){
        if(n%i==0) return false;
    }
    if(n<2) return false;
    else return true;
}

bool superPrime(int n){
    while(primeNum(n)) n/=10;
    if(n!=0) return false;
    else return true;
}

int main()
{
    int n;
    cin>>n;

    //output
    cout<<endl;
    for (int i=2; i < n ; i++){
        if(superPrime(i)) cout<<i<<' ';
    }
    return 0;
}
