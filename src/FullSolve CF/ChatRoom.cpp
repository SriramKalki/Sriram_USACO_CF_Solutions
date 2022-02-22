#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int counter=0;
    int previousCounter =-1;
    for(int i=counter; i< s.size(); i++){
        if(s[i] == 'h'){
            counter =i;
            break;
        }

    }
    if(counter == previousCounter){
        cout << "NO";
        return 0;
    }
    previousCounter =counter;
    for(int i=counter+1; i< s.size(); i++){
        if(s[i] == 'e'){
            counter =i;
            break;
        }

    }
    if(counter == previousCounter){
        cout << "NO";
        return 0;
    }
    previousCounter =counter;
    for(int i=counter+1; i< s.size(); i++){
        if(s[i] == 'l'){
            counter =i;
            break;
        }

    }
    if(counter == previousCounter){
        cout << "NO";
        return 0;
    }
    previousCounter =counter;
    for(int i=counter+1; i< s.size(); i++){
        if(s[i] == 'l'){
            counter =i;
            break;
        }

    }
    if(counter == previousCounter){
        cout << "NO";
        return 0;
    }
    previousCounter =counter;
    for(int i=counter+1; i< s.size(); i++){
        if(s[i] == 'o'){
            counter =i;
            break;
        }

    }
    if(counter == previousCounter){
        cout << "NO";
        return 0;
    }
    previousCounter =counter;
    cout << "YES";



}