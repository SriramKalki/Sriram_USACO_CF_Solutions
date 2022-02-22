#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
    int t,x(100),current,length;
    int answer(0);
    int occurence[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    //occurence[0] is how many times -100 appears, occurence[200] is how many times 100 appears;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> length;
        for(int j=0; j<length;j++){
            cin >> current;
            occurence[current+x]++;
        }
        for(int j= -100; j <0; j++){
            if((occurence[j+x] ==0 && occurence[x-j]>0)){
                occurence[x-j]--;
                occurence[j+x]++;
            }else if((occurence[j+x] >0 && occurence[x-j]==0)){
                occurence[x-j]++;
                occurence[j+x]--;
            }
        }

        for(int j=0; j< 201; j++){
            if(occurence[j] >0){
                answer++;
            }
            occurence[j] =0;
        }
        cout << answer << endl;
        answer =0;
    }

}