#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct Coord{
    int r,c;
};

Coord p = {0,0};
Coord q = {0,0};

char arr[20][20];
bool vis[20][20];
vector<pair<char,int>> color(2);



void flood(Coord curr, char prevColor){
    if(curr.r < p.r || curr.r > q.r || curr.c < p.c || curr.c > q.c) return; //out of bounds
    if(vis[curr.r][curr.c]) return; //already visited
    if(arr[curr.r][curr.c] != prevColor) return; //wrong color

    vis[curr.r][curr.c] = true;

    Coord a = {curr.r+1,curr.c+0};
    Coord b = {curr.r-1,curr.c+0};
    Coord c = {curr.r+0,curr.c+1};
    Coord d = {curr.r+0,curr.c-1};

    flood(a,arr[curr.r][curr.c]);
    flood(b,arr[curr.r][curr.c]);
    flood(c,arr[curr.r][curr.c]);
    flood(d,arr[curr.r][curr.c]);


}

int main(){
    setIO("where");
    int n;
    cin >> n;
    if(n == 1){cout << 0; return 0;}
    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
            vis[i][j] = false;
        }
    }

    int answer(0);
    
    for(int a=0; a<n; a++){
        //start.x 
        for(int b=0; b<n; b++){
            //start.y
            for(int c=a; c<n; c++){
                //end.x
                for(int d=b; b<n; d++){
                    //end.y 
                    p = {a,b};
                    q = {c,d};

                    for(int i = p.c; i <= q.c; i++){
                        for(int j = p.r; j <= q.r; j++){
                            if(vis[i][j]) continue; //already visited

                            //reset color
                            color[0].first = '.'; color[0].second = 0;
                            color[1].first = '.'; color[1].second = 0;

                            //reset visits
                            for(int i2=0; i2<n; i2++){
                                for(int j2 =0; j2<n; j2++){
                                    vis[i2][j2] = false;
                                }
                            }

                            //adds a new color, checks for max 2 colors
                            if(arr[i][j] != color[0].first || arr[i][j] != color[1].first){
                                if(color[0].first == '.'){
                                    color[0].first = arr[i][j];
                                }else if(color[1].first == '.'){
                                    color[1].first = arr[i][j];
                                }else{
                                    continue;
                                }
                            }

                            if(arr[i][j] == color[0].first){
                                color[0].second++;
                            }else{
                                color[1].second++;
                            }
                            flood(p,arr[i][j]);

                            if((color[0].second == 1 && color[1].second > 1)
                            || color[0].second > 1 && color[1].second == 1){
                                answer++;
                            }

                        }
                    }

                    
                }
            }
        }
    }


    cout << answer;



}