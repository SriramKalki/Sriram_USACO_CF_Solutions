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

struct Cow{
    int length;

};

bool totalTime(vector<Cow>& cow, int k, int maxTime){
    int lastTime = 0;
    priority_queue <int, vector<int>, greater<int> > q;
    for(int i=0; i<cow.size();i++){
        if(q.size() == k){
            lastTime = q.top();
            q.pop();
        }
        if(lastTime + cow[i].length > maxTime){
            return false;
        }
        q.push(lastTime + cow[i].length);
    }
    return true;
}

int main(){
    setIO("cowdance");
    int n,t;
    cin >> n >> t;
    vector<Cow> cow(n);
    for(int i=0; i<n; i++){
        cin >> cow[i].length;

    }

    int min = 1;
    int max = n;
    while(min != max) {
        int mid = (min+max)/2;
        if(totalTime(cow,mid,t)) {
            max = mid;
        }
        else {
            min = mid+1;
        }
    }
    cout << min;
}