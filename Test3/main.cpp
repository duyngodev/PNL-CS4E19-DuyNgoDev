#include <iostream>
#include <string>
using namespace std;

bool validString(string input){
    for (char c : input){
        if(c <'a' || c > 'z') return false;
    }
    return true;
}

string encodedString(string input){
    string encoded = "";
    for (int i = 0; i< input.length(); i++){
    char temp = input[i];
    int cnt = 1;
        while( i + 1 <input.length() && input[i+1] == temp ){
           cnt++;
           i++;
        }
    encoded += temp + to_string(cnt);
    }
    return encoded;
}

int main()
{
    string input;
    cin>>input;
    while(!validString(input)){
        cout<<"Please enter string [a-z] only!"<<'\n';
        cin>>input;
    }
    string result = encodedString(input);
    cout<<endl<<result;
    return 0;
}
