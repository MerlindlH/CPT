
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
    int nrBrooms, ringpos, broomlength;
    cin >> nrBrooms;
    if(nrBrooms <= 2) {
        cout << nrBrooms;
        return 0;
    }
    auto brooms = vector<pair<int, int>>();
    brooms.resize(nrBrooms);
    rep(i, nrBrooms){
        cin >> broomlength >> ringpos;
        brooms[i] = make_pair(ringpos, broomlength);
    }

    std::sort(all(brooms));
    int currentEnd = brooms[0].first;
    int newBestEnd = INT_MAX;
    int nrPossibleBrooms = 1;
    for(int i = 1; i < nrBrooms; i++) {
        auto broom = brooms[i];
        ringpos = broom.first;
        broomlength = broom.second;
        if (ringpos < newBestEnd) {
            newBestEnd = min(newBestEnd, max(currentEnd + broomlength, ringpos));
        } else {
            currentEnd = newBestEnd;
            nrPossibleBrooms++;
            newBestEnd = max(currentEnd + broomlength, ringpos);
        }
    }
    if(newBestEnd >= currentEnd) {
        nrPossibleBrooms++;
    }
    cout << nrPossibleBrooms;
    return 0;
}

