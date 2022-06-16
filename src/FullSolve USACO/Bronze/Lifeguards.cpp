#include <iostream>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lifeguards");
    int n;
    cin >> n;
    int start[n],end[n];
    int times[1000]; //times[0] is 0-1
    for(int i=0; i<1000; i++){
        times[i] = 0;
    }
    for(int i=0; i<n; i++){

        cin >> start[i] >> end[i];
        for(int j= start[i]; j< end[i]; j++){
            times[j]++;
        }
    }
    int answer =0, current=0;
    for(int i=0; i<n; i++){
        current =0;
        for(int j=start[i]; j<end[i]; j++){
            times[j]--;
        }
        for(int j=0; j<999; j++){
            if(times[j] > 0){
                current++;
            }
        }
        answer = max(answer,current);
        for(int j=start[i]; j<end[i]; j++){
            times[j]++;
        }
    }
    cout << answer;





}