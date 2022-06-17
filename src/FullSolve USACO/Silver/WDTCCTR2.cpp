#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("maxcross");
    int n,b,k;
    cin >> n >> k >> b;
    int array[n];
    int psum[n+1];
    for(int i=0; i<n; i++){
        array[i] = 1;
    }
    for(int i=0; i<b; i++){
        int x;
        cin >> x;
        x--;
        array[x] = 0;
    }
    psum[0] = 0;
    for(int i=1; i<n+1; i++){
        psum[i] = psum[i-1] + array[i-1]; //psum[i] sum of first i elements
    }

    //sums of array[n] to array[n+k-1] => psum of psum[n+k] - psum[n];

    int answer = 1000000000;
    for(int i=0; i <= n-k; i++){
        answer = min(answer, k - (psum[i+k] - psum[i]));
    }
    cout << answer;
}