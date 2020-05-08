
#include <bits/stdc++.h>

#define rep(var, bound)   for(int var = 0; var < (bound); ++var)
#define all(a)      (a).begin(),(a).end()
#define allStar(a)      (a)->begin(),(a)->end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;
using Street = pair<int,int>; // end, Distance
using Streets = vector<Street>;

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

bool smallerThanNeeded(int nrReachedCities, int nrCities) {
    return nrReachedCities < nrCities && nrReachedCities < (3*nrCities + 3)/4;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    // input
    int testCases;
    //cin >> testCases;
    testCases = readNumber();

    rep(testCase,testCases) {
        //input each testCase
        int nrCities, nrStreets, maxDist=INT32_MAX, nrReachedCities=0;
        //cin >> nrCities >> nrStreets;
        nrCities = readNumber();
        nrStreets = readNumber();

        auto streets = vector<Streets>();// for each city: streets with: end, Distance
        streets.resize(nrCities);
        auto reachableStreets = map<int, vector<int>>(); // distance -> endPoints

        rep(streeti, nrStreets) {
            int start,end,distance;
            //cin >> start >> end >> distance;
            start = readNumber();
            end = readNumber();
            distance = readNumber();

            streets[start].emplace_back(make_pair(end, distance));
            streets[end].emplace_back(make_pair(start, distance));
            if(start == 0) {
                maxDist = min(distance, maxDist);
            }
        }

        auto distances = set<int>();
        for(auto street : streets[0]) {
            reachableStreets[street.second].emplace_back(street.first);
            distances.insert(street.second);
        }
        // state here:
        // all streets read in
        // all reachableStreets on startCity stored
        // minDist found

        auto visited = vector<bool>();
        visited.resize(nrCities,false);
        visited[0] = true;
        nrCities--;
        while(smallerThanNeeded(nrReachedCities, nrCities)) {//check math
            maxDist = *(distances.begin());
            distances.erase(maxDist);
            auto usableStreets = reachableStreets.at(maxDist);
            while (!usableStreets.empty()) {
                int currentEnd = usableStreets.at(usableStreets.size() - 1);
                usableStreets.pop_back();

                if(!visited[currentEnd]){
                    visited[currentEnd] = true;
                    nrReachedCities++;
                    if(!smallerThanNeeded(nrReachedCities, nrCities)) {
                        break;
                    }
                    for(auto street : streets[currentEnd]){
                        if(!visited[street.first]){
                            if(street.second <= maxDist) {
                                usableStreets.insert(usableStreets.begin(), street.first);
                            } else {
                                reachableStreets[street.second].emplace_back(street.first);
                                distances.insert(street.second);
                            }
                        }
                    }
                }
            }
            if(!smallerThanNeeded(nrReachedCities, nrCities)) {
                break;
            }
            reachableStreets.erase(maxDist);
        }
        cout << maxDist << endl;
    }
    return 0;
}

