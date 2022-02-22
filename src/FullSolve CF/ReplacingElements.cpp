#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int tc;
    cin >> tc;

    while (tc--) {
        int n,d;
        cin >> n >> d;
        vector<int> v(n);
        for(int& x : v) cin >> x;
        sort(v.begin(),v.end());

        if(v[n-1] <=d){
            cout << "YES" << endl;
        }else if(v[0] + v[1] <=d){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;

        }
    }


}