#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[m];
    int b[m];
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i];
    }
    int ans(0),load(0),maximum(0);





    while(load <= n){

        //first find container with max matches
        for(int i=1; i<m; i++){

            if(b[i] >= b[maximum]){
                maximum = i;
            }
        }
        if(b[maximum] ==0){
            cout << ans;
            return 0;
        }
        //we take the smallest of the cap or the quantity of this container
        ans += min(n-load,a[maximum]) * b[maximum];
        //update how much we're carrying
        load += min(n-load,a[maximum]);
        if(load ==n){
            cout << ans;
            return 0;
        }
        b[maximum] =0;
        //to prevent us from using this container again
        maximum =0;

    }

}