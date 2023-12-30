#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Buyers{
    int a,b;
};
bool cmp(const Buyers& x, const Buyers& y) { return x.b > y.b; }
int main(){

    setIO("rental");
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> perCow;
    for(int i=0; i<n; i++){int x; cin >> x; perCow.push_back(x);}
    sort(begin(perCow), end(perCow), greater<int>());

    vector<Buyers> buyer;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        buyer.push_back({a,b});
    }
    sort(begin(buyer),end(buyer),cmp);

    vector<int> rental;
    for(int i=0; i<r; i++){int x; cin >> x; rental.push_back(x);}
    sort(begin(rental), end(rental), greater<int>());

    long long int maxProfit[n+1]; maxProfit[0] = 0;
    int shopIndex(0);

    for(int i=0; i<n; i++){
        maxProfit[i+1] = maxProfit[i];


        while(shopIndex < m && perCow[i] > 0){
            int quantity = min(perCow[i],buyer[shopIndex].a);
            maxProfit[i+1] += quantity * buyer[shopIndex].b;
            perCow[i] -= quantity;
            buyer[shopIndex].a -= quantity;

            if(buyer[shopIndex].a == 0){shopIndex++;}

        }
    }

    long long int rent[n+1]; rent[0] = 0;
    long long int psum[r+1]; psum[0] = 0;
    for(int i=0; i<r; i++){
        psum[i+1] = psum[i] + rental[i];
    }

    long long int maximum(0);
    for(int i=0; i<=n; i++){
        rent[i] = psum[min(r,i)];
        maxProfit[n-i] += rent[i];
        maximum = max(maximum,maxProfit[n-i]);
    }
    cout << maximum;





}