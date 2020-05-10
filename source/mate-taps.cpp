
#include <bits/stdc++.h>

#define rep(var, bound)   for(int var = 0; var < (bound); ++var)
#define all(a)      (a).begin(),(a).end()
#define allStar(a)      (a)->begin(),(a)->end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

//merlinstuff
int readNumber() {
    int result=0;
    char c = (char) getchar();
    while(!(c >= '0' && c <= '9')) {
        c = (char) getchar();
    }
    while (c >= '0' && c <= '9') {
        result = 10 * result + (c-'0');
        c = (char) getchar();
    }
    return result;
}

// rep, rank
pair<int,int> find(int x, vector<pair<int,int>>& representants){
    auto father = representants[x];
    if(father.first == x){
        return father;
    }
    father = find(father.first, representants);
    representants[x].first = father.first;
    return representants[x];
}

// returns whether union was necessary
bool unite(int x, int y, vector<pair<int,int>>& representants) {
    auto repx = find(x, representants);
    auto repy = find(y, representants);
    if(repx.first == repy.first) {
        return false;
    }

    int newRank = (repx.second == repy.second ? repx.second+1 : max(repx.second,repy.second));

    if(repx.second < repy.second){
        // set x to {repy, yrank}
        pair<int, int> newPair = {repy.first, newRank};
        representants[repx.first] = newPair;
    } else {
        pair<int, int> newPair = {repx.first, newRank};
        representants[repy.first] = newPair;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    int nrRooms = readNumber();
    int nrConnections = readNumber();
    ll costOfTank = readNumber();
    auto pipes = vector<tuple<int,int,int>>(); // distance, start, end

    int start, end, costOfPipe;
    rep(i, nrConnections) {
        start = readNumber(), end = readNumber(), costOfPipe = readNumber();
        if (costOfPipe < costOfTank) {
            pipes.emplace_back(costOfPipe,start,end);
        }
    }
    // better sort could be faster
    sort(all(pipes));
    // plan MST with kruskarl
    // 1 tank per CC
    ll nrCCs = nrRooms;
    // makeSet
    auto representants = vector<pair<int,int>>(); // representant, rank (depth of tree)
    representants.resize(nrRooms);
    rep(i, nrRooms) {
        representants[i] = make_pair(i,0);
    }
    ll totalCosts = 0;
    for(auto pipe : pipes) {
        tie(costOfPipe,start,end) = pipe;
        bool hadToUnite = unite(start,end,representants);
        if(hadToUnite) {
            totalCosts += costOfPipe;
            nrCCs--;
            if(nrCCs == 1){
                break;
            }
        }
    }
    totalCosts += nrCCs * costOfTank;
    cout << totalCosts;

    return 0;
}

