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
    setIO("hoofball");
    int n;
    
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    int targets[n];
    int pass_to[n];
    for(int i=0; i<n; i++) pass_to[i] = 0;
    for(int i=0; i<n; i++){
        int target = 0;
        int dist = 1001;
        for(int j=0; j<n;j++){
            if(i == j) continue;
            if(abs(a[j]-a[i]) < dist){
                dist = abs(a[j]-a[i]);
                target = j;
            }else if(abs(a[j] - a[i]) == dist){
                //leftmost
                if(a[j] < a[target]) target = j;
            }

        }
        targets[i] = target;
        pass_to[target]++;

    }

    int answer = 0;
    for(int i=0; i<n; i++){
        if(pass_to[i] == 0) answer++;
        if(targets[targets[i]] == i && i < targets[i] && pass_to[i] == 1 && pass_to[targets[i]] == 1) answer++;
    }
    cout << answer;
}