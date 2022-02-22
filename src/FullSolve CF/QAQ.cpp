#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int answer=0;
    if(s.length() <3){
        cout << 0;
        return 0;
    }
    for(int a=0; a<=s.length()-3; a++){
        for(int b=a+1; b<=s.length()-2; b++){
            for(int c=b+1; c<=s.length()-1; c++){
                if(s[a] == 'Q' && s[b] == 'A' && s[c] == 'Q'){
                    answer++;
                }
            }
        }
    }
    cout << answer;


}