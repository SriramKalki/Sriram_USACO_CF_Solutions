#include <iostream>

using namespace std;

int main(){
    char correct[3][3];
    char guess[3][3];
    int correctAlphabet[26],guessAlphabet[26];
    for(int i=0; i<26; i++){
        correctAlphabet[i] =0;
        guessAlphabet[i] =0;
    }
    string line1,line2,line3;
    cin >> line1 >> line2 >> line3;
    for(int i=0; i<3; i++){
        correct[0][i] = line1[i];
        correctAlphabet[(int) line1[i] -65]++;
    }
    for(int i=0; i<3; i++){
        correct[1][i] = line2[i];
        correctAlphabet[(int) line2[i] -65]++;
    }
    for(int i=0; i<3; i++){
        correct[2][i] = line3[i];
        correctAlphabet[(int) line3[i] -65]++;
    }
    cin >> line1 >> line2 >> line3;
    for(int i=0; i<3; i++){
        guess[0][i] = line1[i];
        guessAlphabet[(int) line1[i] -65]++;
    }
    for(int i=0; i<3; i++){
        guess[1][i] = line2[i];
        guessAlphabet[(int) line2[i] -65]++;
    }
    for(int i=0; i<3; i++){
        guess[2][i] = line3[i];
        guessAlphabet[(int) line3[i] -65]++;
    }
    //---------------------------------
    int green =0;
    int yellow =0;
    //haha gg found the opening thread - totally not a quote from demon slayer

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(correct[i][j] == guess[i][j]){
                green++; //green+_+ yes
                correctAlphabet[(int)correct[i][j] - 65]--;
                guessAlphabet[(int)correct[i][j] - 65]--;


            }
        }

    }
    cout << green << endl;
    for(int i=0; i<26; i++){
        yellow+= min(correctAlphabet[i],guessAlphabet[i]);

    }
    cout << yellow;
}