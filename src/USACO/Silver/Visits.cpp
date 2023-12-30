#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;

// cow i wants to visit cow a[i] and gets v[i] points
vector<int> a, v;
// reversed_graph[i] stores the cows that want to go to farm i
vector<vector<int>> reversed_graph;
// marks cows as visited once we have processed them
vector<bool> visited;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void mark(int y){
    if (visited[y]) return;
    visited[y] = true;
    for(int c : reversed_graph[y]) mark(c);
}
int cycle(int i){
    int y = a[i];
    int z = a[y];
    while(y != z){
        y = a[y];
        z = a[a[z]];
    }
    //now y = z
    int min_v = v[y];
    y = a[y];
    while(y != z){
        min_v = min(min_v,v[y]);
        y = a[y];
    }
    mark(y);
    return min_v;
}

int main(){
    int n;
    cin >> n;
    v.resize(n);
	a.resize(n);
	visited.resize(n);
	reversed_graph.resize(n);
    long long answer = 0;
    for(int i=0; i<n; i++){
        cin >> a[i] >> v[i];
        a[i]--;
        answer += v[i];
        reversed_graph[a[i]].push_back(i);
    }

    for(int i=0; i <n;i++){
        if(!visited[i]) answer -= cycle(i);
    }
    cout << answer;
}