#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int s[n],t[n],b[n];
    vector<pair<int,int>> st;
    vector<pair<int, int>> sb;


    for(int i=0; i<n; i++){
        cin >> s[i] >> t[i] >> b[i];

        st.push_back(make_pair(s[i],t[i]));

        sb.push_back(make_pair(s[i],b[i]));
    }

    sort(st.begin(),st.end());
    sort(sb.begin(),sb.end());

    int buckets =0;






}