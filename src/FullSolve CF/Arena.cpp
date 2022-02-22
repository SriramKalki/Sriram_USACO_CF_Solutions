#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;
        vector<int> a(n);

        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int p(0),consec(1);
        while(a[p] == a[p+1] && p <= n-2){
            p++;
            consec++;
        }
        cout << n-consec << endl;
    }



}