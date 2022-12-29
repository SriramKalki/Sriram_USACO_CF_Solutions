#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>


#define ll long long

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

ll int n,m;
bool check(vector<pair<ll int,ll int>>& grass,ll int d){

    ll int currCow(-1),currGrass(-1),remnCow(-1);

    currCow = grass[0].first;
    currGrass = 0;
    remnCow = n-1;

    while(remnCow > 0){
        if(currCow + d <= grass[currGrass].second){
            //place cow here
            currCow += d;
        }else{
            //we need to find a new grass patch
            //if currCow + d is inside a new patch, use that location
            //we know we searched too far if grass[currGrass].first > currCow + d
            //else if currCow + d is outside a patch, find the starting point of the nearest grass patch and use that

            while(currCow + d >= grass[currGrass].first){
                if(currCow + d <= grass[currGrass].second){
                    currCow += d;
                    break;
                }else{
                    currGrass++;
                }

                if(currGrass == m){
                    return false;
                }else if(currCow + d < grass[currGrass].first){
                    currCow = grass[currGrass].first;
                    break;
                }

            }

        }
        remnCow--;


    }
    return true;
}

int main(){
    setIO("socdist");

    cin >> n >> m;
    vector<pair<ll int,ll int>> grass(m);
    for(int i=0; i<m; i++){
        cin >> grass[i].first >> grass[i].second;
    }
    sort(grass.begin(),grass.end());
    ll int low = 1,high = 1e13;
    ll int answer(-1);
    while(low <= high){
        int mid = (low + high)/2;
        if(check(grass,mid)){
            answer = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    cout << answer;


}