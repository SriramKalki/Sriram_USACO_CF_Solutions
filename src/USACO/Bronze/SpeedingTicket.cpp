#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("speeding");
    int n,m;
    cin >> n >> m;
    int officialSpeed[n],officialSegment[n],bessieSpeed[m],bessieSegment[m];
    officialSegment[0]=0;
    bessieSegment[0]=0;
    int current, sum(0);
    for(int i=0; i<n; i++){
        cin >> current;
        sum += current;
        officialSegment[i] = sum;
        cin >> officialSpeed[i];

    }
    sum = 0;
    for(int i=0; i<m; i++){
        cin >> current;
        sum += current;
        bessieSegment[i] = sum;
        cin >> bessieSpeed[i];
    }
    int x(0),y(0),curr(0),maximum(0);
    for(int i=0; i<100;i++){
        if(i >= officialSegment[x]){
            x++;
        }
        if(i >= bessieSegment[y]){
            y++;
        }
        curr = bessieSpeed[y]-officialSpeed[x];
        maximum = max(maximum,curr);

    }
    cout << maximum << endl;


}