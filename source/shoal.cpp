
#include <bits/stdc++.h>

#define rep(var, bound)   for(int var = 0; var < (bound); ++var)
#define all(a)      (a).begin(),(a).end()
#define allStar(a)      (a)->begin(),(a)->end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    // puddles moats
    // moat1, moat2

    int puddles,moats,start,end;
    cin >> puddles >> moats;

    if(moats < puddles-1) {
        cout << "NO";
    }

    auto adjList = new Graph();
    adjList->resize(puddles);

    rep(i, moats) {
        cin >> start >> end;
        adjList->at(start).push_back(end);
        adjList->at(end).push_back(start);
    }
    auto queue = new vector<int>();
    auto visited = new vector<bool>();
    visited->resize(puddles,false);
    queue->insert(queue->begin(),0);
    do{
        int elem = queue->at(queue->size()-1);
        visited->at(elem) = true;
        queue->pop_back();
        for(auto neighbour : adjList->at(elem)) {
            if(!visited->at(neighbour)){
                queue->push_back(neighbour);
            }
        }
    }while(!queue->empty());

    if(count(allStar(visited),false) == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

