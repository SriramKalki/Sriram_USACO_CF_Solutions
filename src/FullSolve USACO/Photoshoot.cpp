#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("photo");
    int n;
    cin >>n;
    int array[n-1];
    int answer[n];
    bool flag(false);
    for(int i=0; i<n-1; i++){
        cin >> array[i];
    }
    for(int i=1; i<array[0]; i++){
        answer[0] = i;
        flag = false;
        for(int j = 1; j<n; j++){
            answer[j] = array[j-1] - answer[j-1];
            if(answer[j] <=0){
                flag = true;
                break;
            }
            for(int k=0; k<j; k++){
                if(answer[j] == answer[k]){
                    flag= true;
                    break;
                }
            }

            if(flag){
                break;
            }
        }
        if(!flag){
            break;
        }

    }
    for(int i=0; i<n; i++){
        if(i == n-1){
            cout << answer[i];
        }else{

            cout << answer[i] << " ";

        }

    }


}