#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int MAX_N = 100000;
  
string S;
int N, prefix_sol[MAX_N+1], suffix_sol[MAX_N+1];

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
//Z overlaps A
void build_sol(int *sol){
    stack<char> active_col;
    for(int i=0; i <N; i++){
        sol[i+1] = sol[i];
        while(!active_col.empty() && active_col.top() > S[i]){
            active_col.pop();
            //popping current color because its too dark for the current character
        }
        if(active_col.empty() || active_col.top() < S[i]){
            //the color we need can overlap the active color
            active_col.push(S[i]);
            sol[i+1]++;
        }
    }
}


int main(){
    int Q;
    cin >> N >> Q;
    cin >> S;
    build_sol(prefix_sol);
    reverse(S.begin(),S.end());
    build_sol(suffix_sol);

    for(int i=0; i<Q; i++){
        int x,y;
        cin >> x >> y;
        cout << prefix_sol[x-1] + suffix_sol[N-y] << endl;
    }

}