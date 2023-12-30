#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("circlecross");
    string s;
    cin >> s;

    vector<pair <int,int>> e(26);
    int alphabet[26];
    for(int i=0; i<26; i++){
        alphabet[i]=0;
    }
    for(int i=0; i< s.length(); i++){
        alphabet[int(s[i])-65]++;
        if(alphabet[int(s[i])-65] == 1){
            e[int(s[i])-65].first = i;
        }else{
            e[int(s[i])-65].second = i;
        }

    }
    int answer =0;
    for(int i=0; i<25; i++){
        for(int j = i+1; j<26; j++){
            int check =0;
            if(e[i].first > e[i].second){
                if((e[j].first > e[i].second && e[j].first < e[i].first) && !(e[j].second > e[i].second && e[j].second < e[i].first)){
                    answer++;
                }else if(!(e[j].first > e[i].second && e[j].first < e[i].first) && (e[j].second > e[i].second && e[j].second < e[i].first)){
                    answer++;
                }

            }else{
                if((e[j].first > e[i].first && e[j].first < e[i].second) && !(e[j].second > e[i].first && e[j].second < e[i].second)){
                    answer++;
                }else if(!(e[j].first > e[i].first && e[j].first < e[i].second) && (e[j].second > e[i].first && e[j].second < e[i].second)){
                    answer++;
                }
            }

        }
    }

    cout << answer;

}