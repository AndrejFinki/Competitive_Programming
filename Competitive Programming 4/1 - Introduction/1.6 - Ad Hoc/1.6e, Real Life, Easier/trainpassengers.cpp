#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

LL C, N;

int main()
{
    ios::sync_with_stdio( false );

    cin >> C >> N;

    LL currentCap = 0; bool isConsistent = true;
    for( int i = 0 ; i < N ; i++ ){

        int L, E, S; cin >> L >> E >> S;

        if( L > currentCap ) { isConsistent = false; break; }
        currentCap -= L;
        if( currentCap + E > C ){ isConsistent = false; break; }
        currentCap += E;
        if( currentCap != C && S ){ isConsistent = false; break; }

    }

    cout << ( isConsistent && !currentCap ? "possible" : "impossible" ) << endl;
}
