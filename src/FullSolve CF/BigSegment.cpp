#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int start[n];
    int end[n];
    int minloc =1000000001;
    int maxloc =0;
    for(int i=0; i<n; i++){
        cin >> start[i] >> end[i];
        minloc = min(minloc,start[i]);
        maxloc = max(maxloc, end[i]);
    }
    for(int i=0; i<n; i++){
        if(start[i] == minloc && end[i] == maxloc){
            cout << i+1;
            return 0;
        }
    }
    cout << -1;



}