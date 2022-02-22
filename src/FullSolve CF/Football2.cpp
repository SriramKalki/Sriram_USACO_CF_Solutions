#include <iostream>

using namespace std;

int main(){
    int n;
    string team;
    string team2;
    cin >> n;
    int teamP(0),team2P(0);
    string curr;
    for(int i=0; i<n; i++){
        cin >> curr;
        if(i == 0 || curr == team){
            team = curr;
            teamP++;
        }else if(curr != team){
            team2 = curr;
            team2P++;
        }


    }

    if(teamP > team2P){
        cout << team;
    }else{
        cout << team2;
    }



}