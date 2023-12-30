#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#define ll long long
using namespace std;


void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int n;
char s[20][20];
bool been_there[20][20];

struct Rectangle {
    int x0,y0,x1,y1;
};

vector<Rectangle> PCL; 

void visit(int i, int j, int c, int x0, int y0, int x1, int y1){
    been_there[i][j] = true;
    if(i > x0 && s[i-1][j] - 'A' == c && !been_there[i-1][j]){
        visit(i-1,j,c,x0,y0,x1,y1);
    }
    if(j > y0 && s[i][j-1] - 'A' == c && !been_there[i][j-1]){
        visit(i,j-1,c,x0,y0,x1,y1);
    }
    if(i < x1 && s[i+1][j] - 'A' == c && !been_there[i+1][j]){
        visit(i+1,j,c,x0,y0,x1,y1);
    }
    if(j < y1 && s[i][j+1] - 'A' == c && !been_there[i][j+1]){
        visit(i,j+1,c,x0,y0,x1,y1);
    }
}

bool isPCL(int x0, int y0, int x1, int y1){
    int num_colors = 0;
    int color_count[26] = {0};
    for (int i = x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            been_there[i][j] = false;
        }
    }

    for (int i = x0; i<=x1; i++){
        for(int j=y0; j<=y1; j++){
            if(!been_there[i][j]){
                int c = s[i][j] - 'A';
                if(color_count[c] == 0) num_colors++;
                color_count[c]++;
                visit(i,j,c,x0,y0,x1,y1);
            }
        }
    }
    if(num_colors != 2) return false;
    bool one = false; bool many = false;

    for(int i=0; i<26; i++){
        if(color_count[i] == 1) one = true;
        if(color_count[i] > 1) many = true;
    }
    
    return one && many;

}
bool subset(int x, int y){
    //if x is a subgrid of y
    return PCL[x].x0 >= PCL[y].x0
    && PCL[x].x1 <= PCL[y].x1
    && PCL[x].y0 >= PCL[y].y0
    && PCL[x].y1 <= PCL[y].y1;
}
bool isMaximal(int x){
    for(int i=0; i<PCL.size(); i++){
        if(x != i && subset(x,i)) return false;
    }
    return true;
}

int main(){
    setIO("where");
    cin >> n;
    for(int i=0; i <n; i++){
        string a;
        cin >> a;
        for(int j = 0; j < n; j++){
            s[i][j] = a[j];
        }
    }

    
    for(int x0 = 0; x0 <n; x0++){
        for(int y0 = 0; y0 <n; y0++){
            for(int x1 = x0; x1 <n; x1++){
                for(int y1 = y0; y1 <n; y1++){
                    if(isPCL(x0,y0,x1,y1)){
                        Rectangle r = {x0,y0,x1,y1};
                        PCL.push_back(r);
                    }
                }    
            }
        }    
    }

    int answer = 0;
    for(int i=0; i< PCL.size(); i++){
        if(isMaximal(i)) answer++;
    }
    cout << answer;


}