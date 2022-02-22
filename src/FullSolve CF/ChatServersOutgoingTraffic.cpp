#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int currentPeople =0;
    int outgoing =0;
    while (getline(cin, s)){


        if(s[0] == '+'){
            currentPeople++;

        }else if(s[0] == '-'){
            currentPeople--;

        }else{
            for(int i=0; i<s.length(); i++){
                if(s[i] == ':'){
                    outgoing += (s.length()-1 - i)*currentPeople;

                    break;
                }
            }

        }



    }
    cout << outgoing;
}
