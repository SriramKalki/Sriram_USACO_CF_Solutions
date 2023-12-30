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

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("balancing");
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    
    for(int i=0; i<n; i++){
        int x,y; cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    int answer = 1001;
    sort(v.begin(),v.end());
    
    for(int i=0; i<n; i++){
        int horizontal = v[i].second + 1;
        vector<pair<int,int>> above;
        vector<pair<int,int>> below;
        for(int j=0; j <n; j++){
            if(v[j].second > horizontal){
                above.push_back(v[j]);
            }else{
                below.push_back(v[j]);
            }
        }

        int abv_index =0,bel_index =0;
        int abvSize = above.size();
        int belSize = below.size();
        while(abv_index < above.size() || bel_index < below.size()){
            int xBorder = 1000001;
			if(bel_index < below.size()) {
				xBorder = min(xBorder, below[bel_index].first);
			}
			if(abv_index < above.size()) {
				xBorder = min(xBorder, above[abv_index].first);
			}

            while(bel_index < below.size() && below[bel_index].first == xBorder){
                bel_index++;
            }

            while(abv_index < above.size() && above[abv_index].first == xBorder){
                abv_index++;
            }
            answer = min(answer, max( max(bel_index,belSize-bel_index), max(abv_index,abvSize-abv_index) ));
        }

    }
    cout << answer;
}