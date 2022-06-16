#include <iostream>

using namespace std;

#define ll long long

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("div7");
    ll n;
    cin >> n;
    ll array[n],prefix[n+1];
    int lastFound[7];
    prefix[0] =0;
    for(int i=0; i<n; i++){
        cin >> array[i];
        prefix[i+1] = (prefix[i] + array[i]) % 7;

    }
    for(int i=0; i<7; i++){
        lastFound[i]=-1;
    }
    int answer =0;
    for(int i =0; i<n+1; i++){
        if(lastFound[prefix[i]] == -1){
            lastFound[prefix[i]] = i;
        }else{
            answer = max(i - lastFound[prefix[i]],answer);
        }
    }
    cout << answer;


}