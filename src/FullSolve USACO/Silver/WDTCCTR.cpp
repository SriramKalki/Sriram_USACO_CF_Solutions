#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Intersect{
    int s,e;
};

bool cmp(const Intersect& x, const Intersect& y) {
    return x.e < y.e;
}

int main(){
    setIO("helpcross");
    int c,n;
    cin >> c >> n;

    vector<int> chicks(c);
    for(int i=0; i<c; i++){
        cin >> chicks[i];
    }

    vector<Intersect> times(n);
    for(int i=0; i<n; i++){
        cin >> times[i].s >> times[i].e;
    }

    sort(begin(chicks),end(chicks));
    sort(begin(times),end(times),cmp);

    bool visited[n];
    fill(visited, visited + n, false);

    int ans = 0;

    for(auto chicken : chicks){
        for(int i=0; i<n; i++){
            if(!visited[i] && times[i].s <= chicken && chicken <= times[i].e){
                ans++;
                visited[i] = true;
                break;
            }
        }
    }

    cout << ans;

}