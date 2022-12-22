#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("moobuzz");
    long long int n;
    cin >> n;

    //Every 15 numbers, there are 8 numbers said, and 7 moos
    //1 mod 15, 2 mod 15, 4 mod 15, 7 mod 15, 8 mod 15, 11 mod 15, 13 mod 15, 14 mod 15
    //16 mod 15,...

    int residue[] = {14,1,2,4,7,8,11,13};
    int answer = 15 * floor((n-1)/8.0) + residue[n%8];
    cout << answer;
}