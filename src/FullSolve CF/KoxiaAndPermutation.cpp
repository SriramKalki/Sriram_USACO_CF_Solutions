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
        int n,k; cin >> n >> k;
        vector<int> a(n,-1);
        int high = n;
        int low = 1;

        for(int j=0; j<n; j++){
            if ( (j+1) % (k) == 0){
                a[j] = low;
                low++;
            }else{
                a[j] = high;
                high--;
            }
            cout << a[j] << " ";
        }
        cout << endl;

    }
}