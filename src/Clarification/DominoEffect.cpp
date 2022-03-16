#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int answer =0;
    for(int i=0; i<n; i++){
        //first check the dominos between a left force and right force
        if(s[i] == 'L'){

            for(int j=i; j>=0; j--){
                if(s[j] == 'R'){

                    if((j-i) % 2 == 0){
                        answer++;
                        i=j;
                    }
                    break;
                }
            }
        }else if(s[i] == 'R'){
            for(int j=i; j<n; j++){
                if(s[j] == 'L'){
                    if((j-i) % 2 == 0){
                        answer++;
                        i=j;
                    }
                    break;
                }
            }

        }
    }
    string p;
    for(int i=0; i<n; i++){
        p[i] = '.';
    }
    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            for(int j=i; j>=0; j--){
                if(s[j] == 'R'){
                    break;
                }else{
                    p[j] = 'L';
                }

            }


        }else if(s[i] == 'R'){
            for(int j=i; j<n; j++){
                if(s[j] == 'L'){
                    break;
                }
                p[j] = 'R';
                i=j;
            }

        }
    }
    for(int i=0; i<n; i++){

        if(p[i] == '.'){
            answer++;
        }
    }
    cout << answer;


}