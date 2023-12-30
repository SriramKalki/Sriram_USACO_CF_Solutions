#include <bits/stdc++.h>
#define ll long long
using namespace std;


long long int MAX = 1e18;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Point{
    ll int x,y;
};
bool cmp(const Point& x, const Point& y){
    if(x.x == y.x){
        return x.y < y.y;
    }
    return x.x < y.x;
}

ll int solve(int n, vector<Point>& v){
    ll int minx(MAX),miny(MAX),maxx(-1),maxy(-1);
    for(int i=0; i<n; i++){
        ll int x = v[i].x; ll int y = v[i].y;

        minx = min(x,minx); miny = min(y,miny); maxx = max(x,maxx); maxy = max(y,maxy);
    }
    ll int orgArea = (maxx-minx) * (maxy-miny);

    sort(begin(v),end(v),cmp);

    ll int array[n+1]; array[0] = 0;

    ll int cminx(MAX),cminy(MAX),cmaxx(-1),cmaxy(-1);
    for(int i=1; i<=n; i++){
//        while(v[i].y == v[i+1].y && i < n){
//            array[i] += MAX; //this sum is invalid as the fences share a boundary
//            i++;
//        }
        ll int x(v[i-1].x),y(v[i-1].y);
        cminx = min(x,cminx); cminy = min(y,cminy); cmaxx = max(x,cmaxx); cmaxy = max(y,cmaxy);
        ll int firstArea = (cmaxx-cminx) * (cmaxy - cminy);
        array[i] = firstArea;
    }
    cminx=MAX;cminy=MAX;cmaxx=-1;cmaxy=-1;
    for(int i=n-1; i>=0; i--){
        //array[n-i]
//        while(v[i].y == v[i-1].y && i > 0){
//            array[i] += MAX; //this sum is invalid as the fences share a boundary
//            i--;
//        }
        ll int x(v[i].x),y(v[i].y);
        cminx = min(x,cminx); cminy = min(y,cminy); cmaxx = max(x,cmaxx); cmaxy = max(y,cmaxy);
        ll int secondArea = (cmaxx-cminx) * (cmaxy - cminy);
        array[i] += secondArea;
    }
    ll int minArea(array[0]);
    for(int i=0; i<n; i++){
        minArea = min(minArea, array[i]);
    }
    return orgArea - minArea;
}
int main(){
    setIO("split");
    int n;
    cin >> n;

    vector<Point> v;
    for(int i=0; i<n; i++){
        ll int x,y;
        cin >> x >> y;
        v.push_back({x,y});

    }
    ll ans = solve(n,v);
    for(auto& p : v){
        swap(p.x,p.y);
    }
    ans = max(ans,solve(n,v));
    cout << ans;
}