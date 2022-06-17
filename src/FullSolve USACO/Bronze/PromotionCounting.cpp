/*
 * Solution by Sriram Kalki (888plexiglass#3971) 6/14/2022
 * All test cases, max time 11ms, only 13 lines of code in the main function!
 *
 * Walkthrough:
 * We first find the amount of new participants needed, by using the eq. on line 27 (adding the difference between
 * after[i] and before[i]). Then, we initially add diff to before[0] (now that they're all registered).
 *
 * Now in a for loop, we take the difference between before[i] and after[i], which is going to be our answer to
 * how many people go from division i to division i+1, and then we add this amount to before[i+1] as they all ICP'ed
 * to the next division. We do this two more times to get two more answers, and we are done.
 *
 */


#include <bits/stdc++.h>

using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}



int main(){
    setIO("promote");
    int before[4], after[4], answer[3];
    for(int i=0; i<4; i++){
        cin >> before[i] >> after[i];
    }
    int diff = (after[3] - before[3]) + (after[2] - before[2]) + (after[1] - before[1]) + (after[0] - before[0]);
    before[0] += diff;
    for(int i=0; i<3; i++){
        answer[i] = before[i] - after[i];
        before[i+1] += answer[i];
        before[i] = after[i];
    }
    cout << answer[0] << endl << answer[1] << endl << answer[2] << endl;
}