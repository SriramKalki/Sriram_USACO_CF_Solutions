#include <string>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main(){
    setIO("bcount");

    int n,q; cin >> n >> q;

    vector<int> h(n+1);
    vector<int> g(n+1);
    vector<int> j(n+1);

    h[0] = 0; g[0] = 0; j[0] = 0;
    for(int i=1; i<n+1; i++){
        int x;
        cin >> x;
        h[i] = h[i-1];
        g[i] = g[i-1];
        j[i] = j[i-1];
        switch(x){
            case 1:
                h[i]++;
                break;
            case 2:
                g[i]++;
                break;
            case 3:
                j[i]++;
                break;
        }

    }

    for(int i=0; i<q; i++){
        int a,b;
        cin >> a >> b;

        cout << h[b]-h[a-1] << " " << g[b]-g[a-1] << " " << j[b]-j[a-1] << endl;

    }


}