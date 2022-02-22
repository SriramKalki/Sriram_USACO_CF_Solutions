#include <iostream>

using namespace std;


int main(){
    string alphabet;
    cin >> alphabet;
    string word;
    cin >> word;

    bool found = false;
    int answer =0;
    int i=0;
    while(!found){
        answer++;
        for(int a=0; a<26; a++){
            if(alphabet[a] == word[i]){
                if(i == word.length() -1){
                    found = true;
                    break;
                }else{
                    i++;
                }
            }
        }


    }

    cout << answer;
}