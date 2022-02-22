#include <iostream>

using namespace std;


int main(){
    int t;
    cin >> t;

    for(int i=0 ; i<t; i++){
        int n;
        int changes =0;

        cin >> n;
        int answer =n;
        bool found = false;
        bool divisible = false;
        if(n <100){
            if(n % 7 == 0){
                cout << n << endl;
                divisible = true;
            }
            answer +=  7 - (n % 7);
            if(!divisible){

                if(answer/10 != n/10){
                    //we have to change the 10s digit
                    answer =n;
                    while(n < 100 && !found){
                        answer += 10;
                        if(answer % 7 == 0){
                            found = true;
                            cout << answer << endl;

                        }
                    }
                }else{
                    cout << answer << endl;

                }
            }

        }else{
            if(n % 7 == 0){
                cout << n << endl;
                divisible = true;
            }
            answer +=  7 - (n % 7);
            if(!divisible){

                if(answer/10 != n/10){
                    //we have to change the 10s digit
                    answer =n;
                    while(n < 100 && !found){
                        answer += 10;
                        if(answer % 7 == 0){
                            found = true;
                            cout << answer << endl;
                        }
                    }
                }else{
                    cout << answer << endl;
                    found = true;
                }

            }
            if(!found){
                //100s digit now
                answer =n;
                while(answer < 1000 && !found){
                    answer+= 100;
                    if(answer % 7 == 0){
                        cout << answer << endl;
                        found = true;
                    }

                }


            }

        }

    }



}