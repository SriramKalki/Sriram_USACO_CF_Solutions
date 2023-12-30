#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#include <set>

#define ll long long
using namespace std;

int N;
typedef long long LL;
typedef pair<LL,LL> pll; 
// .first=arrival, .second.first=seniority, .second.second=duration
vector<pair<int, pll>> cows;
 
// .first=priority, .second=cow index
set<pll> waiting;  
 


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll solve(){

    ll ans = 0;
    ll curr_time = 0;
    int next_cow = 1;
    sort(cows.begin(), cows.end());
    curr_time = cows[0].first + cows[0].second.second;

    while(next_cow < N || waiting.size() > 0){
        while(next_cow < N && cows[next_cow].first <= curr_time){
            waiting.insert(make_pair(cows[next_cow].second.first,next_cow));
            next_cow++;
        }
        if(waiting.size() == 0 && next_cow < N){
            curr_time = cows[next_cow].first + cows[next_cow].second.second;
            next_cow++;
        }else if(waiting.size() > 0){
            set<pll>::iterator most_senior = waiting.begin();
            ans = max(ans, curr_time - cows[most_senior->second].first);
            curr_time += cows[most_senior->second].second.second;
            waiting.erase(most_senior);
        }
    }
    return ans;
}

int main(){
    setIO("convention2");
    cin >> N;
    for(int i=0; i <N; i++){
        ll a,t; 
        cin >> a >> t;
        cows.push_back(make_pair(a,make_pair(i,t)));
        
    }

    cout << solve();

}