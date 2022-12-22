#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int n;
        cin >> n;
        int array[n];
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            x--;
            array[j] = x;
        }

        vector<int> used(n);
        vector<int> ans(n);
        for (int j = 0; j < n; ++j) {
            if (!used[j]) {
                vector<int> cur;
                while (!used[j]) {
                    cur.push_back(j);
                    used[j] = true;
                    j = array[j];
                }
                for (auto el : cur) ans[el] = cur.size();
            }
        }

        for (int j = 0; j < n; ++j) cout << ans[j] << " ";
        cout << endl;


    }
}