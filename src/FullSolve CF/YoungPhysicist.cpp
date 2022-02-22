#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int x=0;
    int y=0;
    int z=0;
    int xcurr=0;
    int ycurr =0;
    int zcurr=0;

    for(int i=0; i<n; i++){
        cin >> xcurr >> ycurr >> zcurr;
        x += xcurr;
        y += ycurr;
        z += zcurr;


    }
    if(x ==0 && y==0 && z==0){
        cout << "YES";
        return 0;
    }else{
        cout << "NO";
        return 0;

    }


}