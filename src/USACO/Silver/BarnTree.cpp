#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

struct Order{
    int source,destination,give;
};
vector<int> amtBales;
vector<vector<int>> adj(200000);
vector<bool> find_visited(200000,false);

int threshold(0);
int currTotal(0);
int currSearched(0);
bool done(false);

int need(0);
int answer(0);
vector<Order> orders;

//account for indexing!!!

bool cmp(const pair<int,int> &a,
         const pair<int,int> &b)
{
    return (a.second > b.second);
}

bool finished(int node, int currExtra, vector<bool>& equal){

    equal[node] = (currExtra == 0);

    bool isDone = true;
    for(int i=0; i<equal.size(); i++){
        equal[i] = (amtBales[i] - threshold == 0);
        if(!equal[i]){isDone = false;}
    }
    done = isDone;
    return done;
}
void find_need(int node, int start){
    //count currNode
    currTotal += amtBales[node];
    currSearched++;
    find_visited[node] = true;
    for(auto c : adj[node]){

        if(find_visited[c] || c==start) continue;
        find_need(c,node);
    }
}

void dfs(int prevNode, int node,vector<bool>& equal){

    int currExtra = amtBales[node] - threshold;

    if(finished(node,currExtra,equal)) return;

    //order nodes in priority (most excess bales  ---- least excess/demand bales)
    vector<pair<int,int>> priority;
    for(auto c : adj[node]){

        //reset global
        need = 0;
        currTotal = 0;
        currSearched = 0;
        find_need(c,node);
        priority.push_back({c,currTotal -currSearched*threshold});
    }
    fill(begin(find_visited),end(find_visited), false);
    sort(begin(priority),end(priority),cmp);

    for(int i=0; i<priority.size(); i++){

        if(finished(node,currExtra,equal)) return;
        if(priority[i].second > 0){
            //if excess

            //go dfs here
            dfs(node,priority[i].first,equal);
        }else if(priority[i].second < 0){
            if(currExtra > 0){
                //if not excess
                int give = max(abs(priority[i].second),currExtra);
                amtBales[node] -= give;
                amtBales[priority[i].first] += give;
                int source = node+1;
                int destination = priority[i].first+1; //CHANGE

                if(give != 0) {
                    orders.push_back({source,destination,give});
                    answer++;
                }
            }
            dfs(node,priority[i].first,equal);
        }
    }

}


int main(){
    int n;
    cin >> n;
    int sum(0);
    int maxBales(-1);
    int locationMax(-1);
    vector<bool> equal(n,false);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        sum += x;
        amtBales.push_back(x);
        if(amtBales[i] >= maxBales) {
            maxBales = max(maxBales, amtBales[i]);
            locationMax = i;
        }
    }
    threshold = sum/n;

    for(int i=0; i<n-1; i++){
        int a,b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(locationMax,locationMax,equal);

    cout << answer << endl;
    for(auto c : orders){

        cout << c.source << " " << c.destination << " " << c.give << endl;
    }

}