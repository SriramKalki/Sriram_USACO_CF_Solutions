#include <iostream>

using namespace std;

int main(){
    string s;
    string t;
    bool s_vowel;
    bool t_vowel;
    cin >> s >> t;
    if(s.length() == t.length()){
        for(int i=0; i < t.length(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                s_vowel = true;

            }else{
                s_vowel = false;
            }
            if(t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' || t[i] == 'A' || t[i] == 'E' || t[i] == 'I' || t[i] == 'O' || t[i] == 'U'){
                t_vowel = true;

            }else{
                t_vowel = false;
            }
            if(s_vowel != t_vowel){
                cout << "No";
                return 0;
            }
        }
        cout << "Yes";
        return 0;
    }else{
        cout << "No";

    }


}