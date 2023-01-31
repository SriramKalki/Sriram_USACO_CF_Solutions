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
    int n;
    cin >> n;
    string s[n]; int a[n];

    map<string,int> m1;
    for(int i=0; i<n; i++){
        cin >> s[i] >> a[i];
        m1[s[i]] += a[i];
    }
    int max_score(INT32_MIN);
    for(int i=0; i < n; i++){
        max_score = max(max_score, m1[s[i]]);
    }

    map<string,int> m2;

    for(int i=0; i<n; i++){
        m2[s[i]] += a[i];

        if(m2[s[i]] >= max_score && m1[s[i]] == max_score){
            cout << s[i] << endl;
            break;
        }
    }

}