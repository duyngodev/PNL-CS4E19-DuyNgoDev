#include <iostream>
#include <cmath>
using namespace std;

int sum(int number){
    int sum = 0;
    for (int i=1; i<= sqrt(number); i++ ){
        if(number % i ==0) {
        sum+=i;
        if(i!= number / i) sum+=(number/i); //exclude i if i == sqrt(number)
        }
    }
    return sum;
}

int main()
{
    //Input T case
    int n;
    cin>>n;
    while(n<1 || n>100){
        cout<<"Enter T in [1-100]"<<'\n';
        cin>>n;
    }
    int arr[n];
    for (int i = 0; i<n; i++){
        cin>>arr[i];
        while(arr[i]<1 || arr[i]>1000000000){
            cout<<"Enter T-case in [1-10^9]"<<'\n';
            cin>>arr[i];
        }
    }

    //Output
    cout<<endl;
    for (int i = 0; i<n; i++){
        cout<<sum(arr[i])<<'\n';
    }

    return 0;
}
