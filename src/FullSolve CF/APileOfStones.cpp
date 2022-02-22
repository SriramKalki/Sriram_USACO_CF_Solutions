#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    string s;
    cin >> s;

    int start =0;
    int current =0;
    for(int i=0; i<n; i++){
        if(s[i] == '-'){
            if(current != 0){
                current--;
            }
        }else{
            current++;
        }

    }
    cout << current;


}