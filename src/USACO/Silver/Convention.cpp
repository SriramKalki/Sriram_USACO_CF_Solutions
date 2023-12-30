#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n,m,c; //n is amt of cows, m is amt of buses, c is capacity

bool check(vector<int> cow, int wait){
    int currStart(0);
    int currEnd(0);
    int busFilled(1);

    for(int i=1; i<n; i++){
        if(currEnd - currStart + 1 < c && cow[i] - cow[currStart] <= wait){
            //curr bus has space, doesn't affect wait times
            currEnd++;
        }else{
            //need to start a new bus
            if(busFilled < m) {
                currStart = i;
                currEnd = i;
                busFilled++;
            }else{
                return false;
            }
        }
    }
    return true;
}
int main(){
    setIO("convention");

    cin >> n >> m >> c;
    vector<int> cow(n);
    for(int i=0; i<n; i++){
        cin >> cow[i];
    }
    sort(begin(cow),end(cow));

    int min = 1;
    int max = cow[n-1];
    while(min != max) {
        int mid = (min+max)/2;
        if(check(cow,mid)) {
            max = mid;
        }
        else {
            min = mid+1;
        }
    }
    cout << min;
}