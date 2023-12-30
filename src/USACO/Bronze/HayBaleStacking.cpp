#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;

    int diff[n+1];

    for( int i=0; i< n+1; i++){
        diff[i] = 0;
    }

    for(int i=0; i<k; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        diff[a]++;
        diff[b+1]--;

    }

    int total[n];
    int val =0;
    for(int i=0; i<n; i++){
        total[i] = 0;
        val += diff[i];
        total[i] += val;
    }

    sort(total, total + n);

    cout << total[(n-1)/2];


}