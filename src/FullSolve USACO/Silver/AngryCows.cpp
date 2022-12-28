#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n,k;

bool check(vector<pair<int,bool>> arr, int r){

    int remaining = k;
    int currIndex = 0;
    while(remaining > 0){
        while(arr[currIndex].second && currIndex < arr.size()){
            currIndex++;
        }
        if(currIndex == arr.size()) break;
        int coutTarget = arr[currIndex].first + r;


        int i = currIndex;
        while(i < arr.size() && arr[i].first <= arr[currIndex].first + 2 *r){

            arr[i].second = true;
            i++;
        }

        remaining--;
    }
    for(auto u : arr){
        if(!u.second) {
            return false;
        }
    }
    return true;
}
int main(){
    setIO("angry");

    cin >> n >> k;
    vector<pair<int,bool>> arr(n);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr[i].first = x;
        arr[i].second = false;
    }
    sort(begin(arr),end(arr));

    int low = 0; int high = 50001;
    int answer(-1);

    while(low < high){
        for(auto u : arr){
            u.second = false;
        }
        int mid = (low + high)/2;
        if(check(arr,mid)){
            answer = mid;
            high = mid;
        }else{
            low = mid +1;
        }
    }
    cout << low;

}