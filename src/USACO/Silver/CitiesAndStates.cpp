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
    setIO("citystate");
    int n;
    cin >> n;
    map<string,string> m;
    for(int i=0; i<n; i++){
        string city,state;
        cin >> city >> state;
        m[state] = city;

    }
    int answer(0);
    for(const auto& x : m){
        string curr = x.second.substr(0,2);

        if(m.count(curr) !=0) {
            if(m[curr].substr(0,2) == x.first) answer++;
        }


    }
    cout << answer;
}