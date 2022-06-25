#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("diamond");
    int n,k;
    cin >> n >> k;

    int array[n];

    for(int i=0; i<n; i++){
        cin >> array[i];
    }

    sort(array,array +n);
    int left(0), right(0);
    int answer(0);
    while(right <n){
        int curr = 0;

        if(array[right] - array[left] <= k){
            curr = right - left +1;
            right++;
        }else left++;

        answer = max(curr,answer);
    }

    cout << answer;
}