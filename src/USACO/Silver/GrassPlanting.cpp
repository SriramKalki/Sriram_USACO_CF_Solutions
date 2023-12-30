#include <vector>
#include <string>
#include <iostream>
#include <numeric>
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
    setIO("planting");
    int n;
    cin >> n;
    int a[n];

    for(int i=0; i<n; i++){
        a[i] = 0;
    }

    for(int i=0; i<n-1; i++){
        int x,y;
        cin >> x >> y;
        a[x]++; a[y]++;
    }

    sort(a,a+n);
    cout << a[n-1] +1 << endl;
}