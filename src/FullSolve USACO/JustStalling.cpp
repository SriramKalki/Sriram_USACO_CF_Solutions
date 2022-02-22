#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int heights[n];
    int limits[n];

    for(int i=0; i<n; i++){
        cin >> heights[i];
    }

    for(int i=0; i<n; i++){
        cin >> limits[i];
    }
    int possible[n];

    for(int i=0; i<n; i++){
        possible[i]=0;
        for(int j=0; j<n; j++){
            if(heights[j] <= limits[i]){
                possible[i]++;
            }
        }

    }

    vector< pair<int,int>> ans;

    for(int i=0; i<n; i++){
        ans.push_back(make_pair(limits[i],possible[i]));

    }
    sort(ans.begin(),ans.end());

    long long answer=1;

    int x=0;
    for(int i=0; i<n; i++){
        answer *= (ans[i].second - x);
        x++;
    }
    cout << answer;

}