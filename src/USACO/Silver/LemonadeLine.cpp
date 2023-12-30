#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lemonade");
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i=0; i<n; i++){
        cin >> list[i];
    }
    sort(begin(list),end(list),greater<int>());

    int answer(0);
    for(int i=0; i<n; i++){
        if(answer <= list[i]){
            answer++;
        }else{
            break;
        }
    }
    cout << answer;

}