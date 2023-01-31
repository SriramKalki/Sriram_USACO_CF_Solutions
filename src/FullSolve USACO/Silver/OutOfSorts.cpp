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

struct Val{
    int index,value;
};
int main(){
    setIO("sort");
    int n; cin >> n;
    Val array[n];
    for(int i=0; i<n; i++){
        int x; cin >> x;
        array[i] = {i,x};
    }
    sort(array,array+n,[](Val a, Val b){
        return a.value < b.value || (a.value == b.value && a.index < b.index);
    });

    int answer(0);

    for(int i=0; i<n; i++){
        answer = max(answer,(array[i].index - i));
    }
    cout << answer+1;
}