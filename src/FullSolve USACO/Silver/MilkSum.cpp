#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

#define ll long long
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;
int orig[150000];

ll int query(int a, int b, int size){


    int before = orig[a];
    orig[a] = b;

    for(int i=0; i<size; i++){
        pq.push(orig[i]);
    }

    orig[a] = before;

    ll int sum(0);
    int cnt = 1;
    while(!pq.empty()){

        sum += cnt * pq.top();
        pq.pop();
        cnt++;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;


    for(int i=0; i<n; i++){
        cin >> orig[i];
    }

    int t; cin >> t;


    for(int i=0; i<t; i++){
        int a,b; cin >> a; cin >> b; a--; //zero index. Cow a now produces b units
        cout << query(a,b,n) << endl;
    }
}