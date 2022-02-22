#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;

    int array[26];
    string s;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<t; i++){
        for(int j=0; j<26; j++){
            array[j]=0;
        }
        cin >> s;
        for(int j=0; j< s.length(); j++ ){
            array[int(s[j])-97]++;

        }
        for(int j=0; j<26; j++){
            if(array[j] == 1){
                cout << letters[j];
            }else if(array[j] == 2){
                cout << letters[j] << letters[j];
            }

        }
        cout << endl;

    }



}