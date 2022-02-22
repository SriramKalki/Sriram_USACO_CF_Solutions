#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a=0;
    int b=0;
    int c=0;
    int sum=0;
    int answer=0;
    for(int i=0; i<n; i++){
        cin>> a;
        cin>> b;
        cin>> c;
        sum = a+b+c;
        if(sum >=2){
            answer++;

        }


    }
    cout<< answer;



}