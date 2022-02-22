#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;

    int total =0;
    bool danger = false;
    //first element is s[0] last element is s[length-1]
    if(s.length() >= 7) {
        for (int i = 0; i < s.length() - 6; i++) {
            for (int j = i; j <= i + 6; j++) {
                if(s[j] == '1'){
                    total++;
                }

            }
            if (total == 0 || total == 7) {
                danger =true;
                break;
            }
            total=0;
        }

    }
    if(danger){

        cout << "YES";
    }else{
        cout << "NO";
    }

}