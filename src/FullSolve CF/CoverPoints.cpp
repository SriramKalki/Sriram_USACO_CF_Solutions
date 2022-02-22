#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n;
    int x;
    int y;
    int maximum=0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        cin >> y;
        maximum = max(x+y, maximum);

    }
    cout << maximum;



}