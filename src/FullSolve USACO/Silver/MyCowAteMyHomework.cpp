#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


 void setIO(string s) {
     freopen((s + ".in").c_str(), "r", stdin);
     freopen((s + ".out").c_str(), "w", stdout);
 }

int main(){
    setIO("homework");
    int n;
    cin >> n;
    vector<int> problems(n);
    for(int i=0; i<n; i++) cin >> problems[i];

    int currMin = problems[n-1]; //current minimum problem
    int currSum = problems[n-1]; //current sum of problems
    double currScore = problems[n-1]; //current score of test

    double eaten[n-1]; //array of k values
    eaten[0]=0;
    for(int i = n-3; i>=0; i--){
        currMin = min(problems[i+1],currMin);
        currSum += problems[i+1];
        //k+1 is the amt of problems eaten
        currScore = (double) (currSum - currMin)/(n-i-2);
        int amtEaten = i+1;
        eaten[amtEaten] = currScore;

    }

    double maxScore(-1);
    //finding max possible score
    for(int i=0; i<n-1; i++){
        maxScore = max(maxScore,eaten[i]);
    }


    for(int i=1; i<n-1; i++){
        if(eaten[i] == maxScore) cout << i << endl;
    }

}