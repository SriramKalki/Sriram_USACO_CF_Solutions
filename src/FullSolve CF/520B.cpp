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
    int n,m;
    cin >> n >> m;

    int answer = 0;
    //divide by 2 or add 1
    while(n != m){
        if(m > n && m % 2 == 0){
            answer++;
            m /= 2;
        }else{
            answer++;
            m++;
        }
    }
    cout << answer;
}