#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int curr[n],goal[n],array[n];
    //Abstract: Find the largest consecutive set of numbers in curr[n] such
    //that its in ascending order in goal[n]
    //CURR: x = position y = ID
    //ARRAY: x = ID y = position
    //GOAL: x = position y = ID

    for(int i=0; i<n; i++){
        cin >> curr[i];

    }
    for(int i=0; i<n; i++){
        cin >> goal[i];
        array[goal[i]]=i;
    }

    int currLength = 1;
    int maxLength=0;
    int x =0;
    while(x <= n-2){
        if(array[curr[x+1]] > array[curr[x]]){
            currLength++;
            x++;
        }else{

            maxLength = max(currLength,maxLength);
            currLength=1;
            x++;
        }

    }
    maxLength = max(currLength,maxLength);
    cout << n - maxLength;
}