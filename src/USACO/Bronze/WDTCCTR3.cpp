#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("cowqueue");
    int n;
    cin >> n;
    int a[n],b[n];
    vector<pair <int , int>> pair;
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
        pair.push_back(make_pair(a[i],b[i]));

    }

    sort(pair.begin(),pair.end());
    int time =0;

    for(int i=0; i<n;i++){
        if(pair[i].first >= time){
            time = pair[i].first + pair[i].second;
        }else{
            time += pair[i].second;
        }


    }

    cout << time;


}