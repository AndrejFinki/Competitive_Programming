#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxN = 1005;
int N, K;
string card[maxN];
bool matched[maxN] = {};

void runTurns();
int matchKnown();
int matchUnknown();

int main()
{
    ios::sync_with_stdio( false );

    for( string &c : card ) c = "~";

    cin >> N >> K;
    int res = 0;

    runTurns();

    res += matchKnown();

    res += matchUnknown();

    cout << res << endl;
}

int matchUnknown(){

    int knownUnmatched = 0, unknown = 0;
    for( int i = 1 ; i <= N ; i++ ){
        if( matched[i] ) continue;
        ( card[i] == "~" ? unknown++ : knownUnmatched++ );
    }

    return ( unknown == knownUnmatched ? unknown : bool( knownUnmatched == 0 && unknown == 2 ) );

}

int matchKnown(){

    int rv = 0;
    for( int i = 1 ; i <= N ; i++ ){

        if( matched[i] || card[i] == "~" ) continue;

        for( int j = i+1 ; j <= N ; j++ ){
            if( card[i] != card[j] ) continue;
            rv++;
            matched[i] = matched[j] = true;
            break;
        }

    }

    return rv;

}

void runTurns(){

    for( int i = 0 ; i < K ; i++ ){
        
        int x, y; string sx, sy;
        cin >> x >> y >> sx >> sy;

        card[x] = sx; card[y] = sy;

        if( sx == sy ) matched[x] = matched[y] = true;

    }

}
