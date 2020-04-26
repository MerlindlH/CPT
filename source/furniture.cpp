
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
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


    // test word a == word b with reordering
    int numberOfPairs;
    cin >> numberOfPairs;

    for(int i = 0; i < numberOfPairs; i-=-1) {
        string a, b;
        cin >> a;
        cin >> b;
        if(a.length() != b.length()){
            cout << false << endl;
            continue;
        }
        auto counts = new vector<int>();
        counts->resize(26);

        for(uint j=0; j < a.length(); j+=+1) {
            counts->at(a[j]-'a')++;
            counts->at(b[j]-'a')--;
        }

        cout << (count(allStar(counts), 0) == 26) << endl;
    }

    return 0;
}

