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

ll int solve(ll int a, ll int b){

    if(a == b){
        return 0;
    }else if(a > b){
        if(a % 2 == 0){
            return 1 + solve(a/2,b);
        }else{
            return 2 + solve((a+1)/2,b);
        }
    }else{
        return min(b-a,1 + (bool) (b % 2) + solve(a,b/2));
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
		ll int a, b;
		cin >> a >> b;
		cout << solve(a, b) << endl;
	}
}