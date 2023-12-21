#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i < t; i++){
        int n;
        cin >> n;
        string s;
        cin >> s;
        string a = "";

        char store;
        bool adding = false;
        for(int j=0; j < s.length(); j++){
            if(j == 0){
                store = s[0];
                adding = true;
                a += s[0];
            }else {
                if(!adding){
                    adding = true;
                    store = s[j];
                    a+= s[j];
                }else if (s[j] == store){
                    adding = false;
                }

            }
        }
        cout << a << endl;
    }
}