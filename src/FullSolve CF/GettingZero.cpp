#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

#define ll long long
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int q;
        cin >> q;

        int minOperations(32);
        for(int a = 0 ; a <= 15; a++){
            for(int m=0; m <= 15; m++){
                if(((q + a) * (int) pow(2,m)) % 32768 == 0){
                    minOperations = min(minOperations,a + m);
                }
            }
        }
        cout << minOperations << " ";

    }
}