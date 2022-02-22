#include <iostream>
#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll g(0),h(0);
    //iterate between the size of the photo
        //iterate for the possible starting cows
            //check each cow in the photo
ll ans(0);
            //n will be the amount of cows (no index)
    for(ll i=0; i< n-2; i++){
        for(ll j=i; j<n; j++ ){
            if(s[j] =='H'){
                h++;
            }else{
                g++;
            }

            if(g + h >= 3 && (g==1 || h==1)){
                ans++;
            }
        }
        g=0;
        h=0;


    }
    cout << ans;



}