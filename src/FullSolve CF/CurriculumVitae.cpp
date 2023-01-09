#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int n;
    cin >> n;
    int zeros[n];
    int array[n];
    for(int i=0; i<n; i++){
        cin >> array[i];
        int x = array[i];
        if(i == 0){
            zeros[0] = (x == 0) ? 1 : 0;
        }else{
            zeros[i] = zeros[i-1] + ((x==0)?1:0);
        }
    }

    int maxTotal(-1);
    for(int i=0; i<n; i++){
        int currTotal = zeros[i];
        if(array[i] == 0 || i == 0){
            for(int j = i; j<n; j++){
                if(array[j] == 1) currTotal++;
            }
        }
        maxTotal=max(maxTotal,currTotal);
    }
    cout << maxTotal;




}