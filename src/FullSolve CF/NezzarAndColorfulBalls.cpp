#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    int curr(0);
    int currentColor(0), maxColor(0);
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        while(curr < n-1){
            while(a[curr] == a[curr+1] && curr < n-1){
                currentColor++;
                curr++;
            }
            maxColor = max(currentColor, maxColor);
            currentColor =0;
            curr++;

        }
        cout << maxColor +1 << endl;
        curr =0;
        maxColor =0;

    }

}