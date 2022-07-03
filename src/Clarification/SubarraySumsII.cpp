#include <iostream>

using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int array[n], psum[n+1]; psum[0]=0;
    for(int i=0; i<n; i++){
        cin >> array[i];
        psum[i+1] = psum[i] + array[i];
    }
    int answer = 0;
    for(int i=0; i< n; i++){
        for(int j=i+1; j< n+1; j++){
            if(psum[j]-psum[i] == x){
                answer++;
            }
        }
    }
    cout << answer;


}