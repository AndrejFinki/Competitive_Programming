#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

string functionType();
void inputDomain( string, vector <string>& );
void inputMappings();

const int maxN = 50;
int N;
vector <string> domain, codomain;
pair <string, string> mapping[maxN];
map <string, int> dMap, cdMap;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string domainS, codomainS;
    while( getline( cin, domainS ) && getline( cin, codomainS ) ){

        dMap.clear(); cdMap.clear();
        domain.clear(); codomain.clear();

        inputDomain( domainS, domain );
        inputDomain( codomainS, codomain );

        inputMappings();

        cout << functionType() << endl;

    }

}

string functionType(){

    function <void()> countAppearances = []() -> void {
        for( int i = 0 ; i < N ; i++ ){
            string p = mapping[i].first, q = mapping[i].second;
            dMap[p]++; cdMap[q]++;
        }
    };

    function <bool()> isFunction = []() -> bool {
        for( string s : domain ){
            if( dMap[s] > 1 ) return false;
        } return true;
    };

    function <bool()> isInjective = []() -> bool {
        for( string s : codomain ){
            if( cdMap[s] > 1 ) return false;
        } return true;
    };

    function <bool()> isSurjective = []() -> bool {
        for( string s : codomain ){
            if( !cdMap[s] ) return false;
        } return true;
    };

    countAppearances();

    bool function = isFunction();

    if( !function ) return "not a function";

    bool injective = isInjective();
    bool surjective = isSurjective();

    if( !injective && !surjective ) return "neither injective nor surjective";
    if( injective && surjective ) return "bijective";
    return ( injective ? "injective" : "surjective" );

}

void inputDomain( string S, vector <string> &V ){

    stringstream SS(S);
    SS >> S;
    while( SS >> S ) V.push_back(S);

}

void inputMappings(){

    cin >> N;
    for( int i = 0 ; i < N ; i++ ){
        string p, q, arrow;
        cin >> p >> arrow >> q;
        mapping[i] = {p,q};
    } cin.ignore();

}