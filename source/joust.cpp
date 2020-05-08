
#include <bits/stdc++.h>

#define rep(var, bound)   for(int var = 0; var < (bound); ++var)
#define all(a)      (a).begin(),(a).end()
#define allStar(a)      (a)->begin(),(a)->end()
//#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int readNumber() {
    int result=0;
    char c = (char) getchar();
    int isNegative = 1;
    while(!(c >= '0' && c <= '9')) {
        if(c == '-') {
            isNegative = -1;
        } else {
            isNegative = 1;
        }
        c = (char) getchar();
    }
    while (c >= '0' && c <= '9') {
        result = 10 * result + (c-'0');
        c = (char) getchar();
    }
    return result * isNegative;
}

int askPrince(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int answer = readNumber();
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content

    int nrknights = readNumber();

    int answer = askPrince(1,2);
    vector<int> ranking;
    if(answer==0){
        ranking = vector<int>({2,1});
    } else {
        ranking = vector<int>({1,2});
    }

    for(int i = 3; i <= nrknights; i++) {
        answer = askPrince(ranking.back(), i);
        switch (answer) {
            case -1 :
            default:
                cerr << "the Prince is angry";
                return 0;
            case 1 :
                ranking.push_back(i);
                continue;
            case 0 :
                answer = askPrince(ranking.front(), i);
        }
        switch (answer) {
            case -1 :
            default:
                cerr << "the Prince is angry";
                return 0;
            case 0 :
                ranking.insert(ranking.begin(),i);
                continue;
            case 1 : break;
        }
        int beginIndex = 0;
        int endIndex = ranking.size() - 1;

        while (endIndex - beginIndex > 1){
            int middleIndex = (beginIndex + endIndex)/2;
            answer = askPrince(ranking[middleIndex], i);
            switch (answer) {
                case -1 :
                default:
                    cerr << "the Prince is angry";
                    return 0;

                case 1 :
                    beginIndex = middleIndex;
                    break;

                case 0 :
                    endIndex = middleIndex;
                    break;
            }
        }
        ranking.insert(ranking.begin() + endIndex, i);
    }

    stringstream ss;
    ss << "!";
    for(auto knight : ranking) {
        ss << " " << knight;
    }
    cout << ss.str() << endl;

    return 0;
}

