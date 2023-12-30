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

int main(){
    setIO("berries");
    int n,k;
    cin >> n >> k;
    int b[n];
    int maxB = -1;
    for(int i=0; i<n; i++){
        cin >> b[i];
        maxB = max(maxB,b[i]);
    }
    int maxTot = 0;
    int chunks[1001];
    for(int q=1; q <= maxB; q++){
        for(int i=0; i<1001; i++){
            chunks[i] = 0;
        }

        for(int i=0; i<n; i++){
            chunks[q] += b[i]/q;
            chunks[b[i] % q]++;
        }

        if(k/2 > chunks[q]) continue;

        chunks[q] -= k/2;
        int baskets = 0;
        int currStack = q;
        int tot = 0;
        while(currStack > 0 && baskets < k/2){
            if(chunks[currStack] > 0){
                tot += currStack;
                baskets++;
                chunks[currStack]--;
            }else{
                currStack--;
            }
        }

        if(baskets == k/2){
            maxTot = max(tot,maxTot);
        }
    }
    cout << maxTot;

}