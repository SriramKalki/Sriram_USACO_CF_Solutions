#include <vector>
#include <string>
#include <iostream>
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
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int q;
        int latest;
        bool wrap = false;
        cin >> q;
        vector<int> a(q);
        for(int j=0; j < q; j++){
            if(j == 0){
                cin >> a[j];
                cout << 1;
                latest = 0;
                continue;
            }
            int curr;
            cin >> curr;

            if(!wrap){
                if(curr >= a[latest]){
                    a[latest+1] = curr;
                    latest++;
                    cout << 1;
                }else if(curr <= a[0]){
                    a[latest+1] = curr;
                    latest++;
                    cout << 1;
                    wrap = true;
                }
            }else{
                if(curr >= a[latest] && curr <= a[0]){
                    a[latest+1] = curr;
                    latest++;
                    cout << 1;
                }else{
                    cout << 0;
                }
            }

        }
    cout << endl;
    }

}