#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int choose[n+1],times[n+1];
    for(int i=1; i<n+1;i++){
        cin >> choose[i];
    }
    for(int i=1; i<n+1;i++){
        cin >> times[i];
    }
    int maximumLoc(0),maximum(0),unoccupied(0);
    choose[0] = 0;
    times[0] =0;
    for(int i=1; i<=k;i++){
        for(int j=1; j<n+1;j++){
            if(choose[j] == i && choose[j] >= maximum){
                maximum = max(maximum,times[j]);
                maximumLoc = j;
            }
        }
        if(maximum == 0){
            //this job wasn't taken by anybody
            unoccupied++;
        }else{
            times[maximumLoc] =1000000000;
            maximum =0;
            maximumLoc =0;
        }

    }
    //sort(times,times+n+1);
    int answer(0);
    for(int i=0; i<=n; i++){
        cout << times[i] << endl;
    }
    cout << answer << " " << unoccupied;


}
