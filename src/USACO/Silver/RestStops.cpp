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
    setIO("reststops");
    ll int L,N,F,B;
    cin >> L >> N >> F >> B;
    ll int x[N],c[N];
    bool isMax[N];
    for(int i=0; i< N; i++){
        cin >> x[i] >> c[i];
    }

    int max = 0;
    for(int i=N-1; i>=0; i--){
        if(c[i] > max){
            isMax[i] = true;
            max = c[i];
        }
    }
    ll int answer = 0;
    ll int lastStop = 0;
    for(int i=0; i < N; i++){
        if(isMax[i] == 0) continue;
        answer += c[i] * (F-B) * (x[i] - lastStop);
        lastStop = x[i];
    }
    cout << answer;

}