#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int q;
    cin >> q;
    int l,r,d;
    int a=1;
    int lowerBound;
    int upperBound;
    for(int i=0; i<q; i++){
        cin>>l>>r>>d;
        lowerBound = floor((double) l/d);
        upperBound = ceil((double) r/d);
        if(d >= l){
            if(r % d ==0){
                cout << (upperBound +1)*d << endl;
            }else{
                cout << upperBound * d << endl;
            }

        }else{
            cout << d << endl;


        }




    }

}