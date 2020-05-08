
#include <bits/stdc++.h>

#define rep(var, bound)   for(int var = 0; var < (bound); ++var)
#define all(a)      (a).begin(),(a).end()
#define allStar(a)      (a)->begin(),(a)->end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    //content
    // input:
    // n m
    // m lines with 2 dependencies
    // output:
    // 1 line with all the subjects ordered in one possible order

    // ideas:
    // build dependency graph,
    // repeatedly take topics that have 0 deps until all are taken
    //  decrement each topic

    uint n,m,dependent,dependency;
    n = readNumber();
    m = readNumber();
    auto dependents = new vector<unordered_set<uint>>();
    auto numberOfDependencies = new vector<uint>();
    numberOfDependencies->resize(n + 1); // 0 is ignored
    dependents->resize(n + 1); // 0 is ignored

    auto stack = new vector<uint>();

    for(int i = 0; i < m; i++) {
        dependency = readNumber();
        dependent = readNumber();

        dependents->at(dependency).insert(dependent);
        numberOfDependencies->at(dependent)++;
    }

    for(uint i = 1; i <= n; i++) {
        if(numberOfDependencies->at(i) == 0) {
            stack->push_back(i);
        }
    }

    do {
        uint elem = stack->at(stack->size()-1);
        stack->pop_back();
        cout << elem << " ";

        for_each(all(dependents->at(elem)),[=](uint a){
            numberOfDependencies->at(a)--;
            if(numberOfDependencies->at(a) == 0) {
                stack->push_back(a);
            }
        });
    }while(!stack->empty());


    return 0;
}

