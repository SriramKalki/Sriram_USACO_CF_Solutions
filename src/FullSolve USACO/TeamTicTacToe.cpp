#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int checkOne(char ch, char a[3][3]){
    if(a[0][0] == ch && a[0][0] == a[0][1] && a[0][0] == a[0][2]){
        return 1;
    }
    if(a[1][0] == ch && a[1][0] == a[1][1] && a[1][0] == a[1][2]){
        return 1;
    }
    if(a[2][0] == ch && a[2][0] == a[2][1] && a[2][0] == a[2][2]){
        return 1;
    }
    //---------
    if(a[0][0] == ch && a[0][0] == a[1][0] && a[0][0] == a[2][0]){
        return 1;
    }
    if(a[0][1] == ch && a[0][1] == a[1][1] && a[0][1] == a[2][1]){
        return 1;
    }
    if(a[0][2] == ch && a[0][2] == a[1][2] && a[0][2] == a[2][2]){
        return 1;
    }
    //--------
    if(a[0][0] == ch && a[1][1] == a[0][0] && a[1][1] == a[2][2]){
        return 1;
    }
    if(a[0][2] == ch && a[1][1] == a[0][2] && a[0][2] == a[2][0]){
        return 1;
    }
    return 0;
}

int checkTwo(char ch1, char ch2, char a[3][3]){
    if((ch1 == a[0][0] || ch2 == a[0][0]) && (ch1 == a[0][1] || ch2 == a[0][1]) && (ch1 == a[0][2] || ch2 == a[0][2])){
        if(!(a[0][0] == ch1 && a[0][1] == ch1 && a[0][2] == ch1) && !(a[0][0] == ch2 && a[0][1] == ch2 && a[0][2] == ch2)) {
            return 1;
        }
    }
    if((ch1 == a[1][0] || ch2 == a[1][0]) && (ch1 == a[1][1] || ch2 == a[1][1]) && (ch1 == a[1][2] || ch2 == a[1][2])){
        if(!(a[1][0] == ch1 && a[1][1] == ch1 && a[1][2] == ch1) && !(a[1][0] == ch2 && a[1][1] == ch2 && a[1][2] == ch2)) {
            return 1;
        }
    }
    if((ch1 == a[2][0] || ch2 == a[2][0]) && (ch1 == a[2][1] || ch2 == a[2][1]) && (ch1 == a[2][2] || ch2 == a[2][2])){
        if(!(a[2][0] == ch1 && a[2][1] == ch1 && a[2][2] == ch1) && !(a[2][0] == ch2 && a[2][1] == ch2 && a[2][2] == ch2)) {
            return 1;
        }
    }

    //--------------------------

    if((ch1 == a[0][0] || ch2 == a[0][0]) && (ch1 == a[1][0] || ch2 == a[1][0]) && (ch1 == a[2][0] || ch2 == a[2][0])){
        if(!(a[0][0] == ch1 && a[1][0] == ch1 && a[2][0] == ch1) && !(a[0][0] == ch2 && a[1][0] == ch2 && a[2][0] == ch2)) {
            return 1;
        }
    }
    if((ch1 == a[0][1] || ch2 == a[0][1]) && (ch1 == a[1][1] || ch2 == a[1][1]) && (ch1 == a[2][1] || ch2 == a[2][1])){
        if(!(a[0][1] == ch1 && a[1][1] == ch1 && a[2][1] == ch1) && !(a[0][1] == ch2 && a[1][1] == ch2 && a[2][1] == ch2)) {
            return 1;
        }
    }
    if((ch1 == a[0][2] || ch2 == a[0][2]) && (ch1 == a[1][2] || ch2 == a[1][2]) && (ch1 == a[2][2] || ch2 == a[2][2])){
        if(!(a[0][2] == ch1 && a[1][2] == ch1 && a[2][2] == ch1) && !(a[0][2] == ch2 && a[1][2] == ch2 && a[2][2] == ch2)) {
            return 1;
        }
    }
    //-------------------------
    if((ch1 == a[0][0] || ch2 == a[0][0]) && (ch1 == a[1][1] || ch2 == a[1][1]) && (ch1 == a[2][2] || ch2 == a[2][2])){
        if(!(a[0][0] == ch1 && a[1][1] == ch1 && a[2][2] == ch1) && !(a[0][0] == ch2 && a[1][1] == ch2 && a[2][2] == ch2)) {
            return 1;
        }
    }
    if((ch1 == a[0][2] || ch2 == a[0][2]) && (ch1 == a[1][1] || ch2 == a[1][1]) && (ch1 == a[2][0] || ch2 == a[2][0])){
        if(!(a[0][2] == ch1 && a[1][1] == ch1 && a[2][0] == ch1) && !(a[0][2] == ch2 && a[1][1] == ch2 && a[2][0] == ch2)) {
            return 1;
        }
    }
    return 0;
}


int main(){
    setIO("tttt");
    char array[3][3];


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> array[i][j];

        }
    }
    //1cow
    int answer1 =0;
    char ch;
    for(int i=0; i<26; i++){
        ch = (char)(i +65);
        if(checkOne(ch,array) == 1){
            answer1++;
        }
    }
    cout << answer1 << endl;
    int answer2 =0;
    char ch1,ch2;
    for(int i=0; i<26; i++){
        for(int j=i; j<26; j++){
            ch1 = (char)(i+65);
            ch2 = (char)(j+65);
            if(checkTwo(ch1,ch2,array) ==1){
                answer2++;
            }
        }
    }
    cout << answer2 << endl;
}