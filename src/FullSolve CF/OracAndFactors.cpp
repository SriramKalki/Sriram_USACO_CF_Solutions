#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    int k;
    int answer=0;

    for(int i=0; i<t; i++){
        cin >> n >> k;
        answer =n;

        if(answer % 2 == 1){
            for(int i=2; i<=answer; i++){
                if(answer % i ==0){
                    cout << answer +i+2*(k-1) << endl;
                    break;
                }
            }

        }else{
            cout << answer + 2*k << endl;
        }



    }


}