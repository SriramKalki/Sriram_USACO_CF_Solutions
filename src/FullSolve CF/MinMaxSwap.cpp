#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int t;
    cin >> t;
    int c,d;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for(int j=0; j<n; j++){
            cin >> a[j];

        }
        for(int j=0; j<n; j++){
            cin >> b[j];
            if(a[j] >= b[j]){
                c=a[j];
                d=b[j];
                a[j]=d;
                b[j]=c;
                //swap
            }

        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll answer = a[n-1] * b[n-1];

        cout << answer << endl;



    }


}