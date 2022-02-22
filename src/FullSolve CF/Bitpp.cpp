#include<iostream>
#include<string>
using namespace std;
int main() {
    int x=0;
    int N;
    cin >> N;
    string s;
    for(int i=0; i<N; i++){
        cin >>s;
        if(s == "++X" || s == "X++"){
            x++;

        }else{
            x--;
        }



    }
    cout << x;




}