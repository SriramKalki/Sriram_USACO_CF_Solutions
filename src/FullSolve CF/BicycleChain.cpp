#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;

    int m;

    cin >> n;
    int front[n];
    for(int i=0;i<n;i++){
        cin >> front[i];

    }
    cin >> m;
    int back[m];
    for(int i=0; i<m; i++){
        cin >> back[i];
    }
    int integer[n*m];
    int x =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(back[j] % front[i] == 0){
                integer[x] = back[j]/front[i];
                x++;
            }


        }
    }
    sort(integer, integer+x,greater<>());
    int max = integer[0];
    x=0; //reuse a variable why not
    int ans=1;
    while(integer[x] == integer[x+1]){
        ans++;
        x++;

    }
    cout << ans;
    //bruh2
}