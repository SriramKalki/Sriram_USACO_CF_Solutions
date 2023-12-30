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


int bsearch(vector<int>& haybales, int goal){
    if(haybales[0] > goal) {
        return 0;
    }

    int min = 0;
    int max = haybales.size()-1;

    while(min != max) {
        int mid = (min+max+1)/2;
        if(haybales[mid] <= goal) {
            min = mid;
        }
        else {
            max = mid-1;
        }
    }
    return min + 1;
}
int main(){

    setIO("haybales");

    int n,q;
    cin >> n >> q;

    vector<int> haybales(n);

    for(int i=0; i<n; i++){
        cin >> haybales[i];
    }

    sort(begin(haybales),end(haybales));

    for(int i=0; i<q; i++){
        int a,b; cin >> a >> b;

        cout << bsearch(haybales,b) - bsearch(haybales,a-1) << endl;

    }

}