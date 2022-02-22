#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int sum =0;
    int lb,ub;
    for  (int i=0; i<t; i++){
        cin >> lb >> ub;

        if(lb % 2 == 0){
            if(ub % 2 ==0){
                cout << ((ub-lb)/2)*(-1) + ub << endl;

            }else{
                cout << ((ub-lb+1)/2)*(-1) << endl;
            }

        }else{
            if(ub % 2 ==0){
                cout << ((ub-lb+1)/2) << endl;

            }else{
                cout << ((ub-lb)/2)-ub << endl;
            }


        }




    }



}