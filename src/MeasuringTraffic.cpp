#include <iostream>

using namespace std;
/*
     * General Approach: Since there is going to be one 'none' measurement, we start at that and go backwards
     * to find the best range at mile 0.
     *
     * Going backwards:
     * If there is a "off" ramp:
     * -Assuming the current range is [a,b], and the off ramp reports [c,d], then
     * the measurement before the off ramp will be
     * [a+c,b+d]
     *
     * If there is a "on" ramp:
     * -Assuming the current range is [a,b], and the on ramp reports [c,d], then
     * the measurement before the on ramp will be
     * [a-d,b-c]
     *
     * If there is a "none" ramp:
     * -Assuming the current range is [a,b], and the none ramp reports [c,d], then
     * the measurement before the none ramp will be
     * [max(a,c),min(b,d)]
     */

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}





int main(){

    //Types of ramps: 1 means on, 2 means none, 3 means off
    setIO("traffic");
    int n;
    cin >> n;
    int type[n];
    int minimum[n],maximum[n];
    int latestNone=0;
    for(int i=0; i<n; i++){
        string curr;
        cin >> curr;
        if(curr == "on"){
            type[i] = 1;
        }else if(curr == "none"){
            type[i] = 2;
            latestNone = i;
        }else{
            type[i] = 3;
        }
        cin >> minimum[i] >> maximum[i];

    }
    int firstMin,firstMax;
    firstMin = minimum[latestNone];
    firstMax = maximum[latestNone];
    for(int i=latestNone; i>=0; i--){
        if(type[i] == 1){
            firstMin -= maximum[i];
            firstMax -= minimum[i];
        }else if(type[i] == 2){
            firstMin = max(firstMin,minimum[i]);
            firstMax = min(firstMax,maximum[i]);
        }else{
            firstMin += minimum[i];
            firstMax += maximum[i];
        }
    }
    //now we have the first range, we just do the same process again but now we're flipping what
    //happens when a ramp is on and when a ramp is off
    int finalMin(firstMin),finalMax(firstMax);

    for(int i=0; i<n; i++){
        if(type[i] == 1){
            //on ramp
            finalMin += minimum[i];
            finalMax += maximum[i];
        }else if(type[i] == 2){
            //none ramp is the same as before
            finalMin = max(finalMin,minimum[i]);
            finalMax = min(finalMax,maximum[i]);
        }else{
            finalMin -= maximum[i];
            finalMax -= minimum[i];
        }
    }

    if(firstMin < 0){
        firstMin = 0;
    }
    if(firstMax <0){
        firstMax =0;
    }
    if(finalMin <0){
        finalMin =0;
    }
    if(finalMax <0){
        finalMax =0;
    }

    cout << firstMin << " " << firstMax << endl << finalMin << " " << finalMax;

}

