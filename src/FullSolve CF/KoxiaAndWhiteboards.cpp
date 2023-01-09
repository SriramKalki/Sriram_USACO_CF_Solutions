#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long

using namespace std;


int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        ll int sum(0);
        int n,m;
        cin >> n >> m;
        priority_queue<int,vector<int>,greater<int>> a;
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            sum += x;
            a.push(x);
        }
        for(int j=0; j<m; j++){
            int x;
            cin >> x;
            sum += (x - a.top());
            a.pop();
            a.push(x);

        }
        cout << sum << endl;
    }
}