
#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
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

        std::sort(all(a));
        std::sort(all(b));


        cout << (a == b) << endl;
    }

    return 0;
}

