#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const LD ERR = 1e-7;
const int maxN = 105;
char G[maxN][maxN];

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        memset( G, 0, sizeof G );

        string MSG; cin >> MSG;

        int LEN = MSG.length();
        int M = pow(ceil(sqrt(LEN)),2) + ERR;
        int K = sqrt(M);

        for( int j = K-1 ; j >= 0 ; j-- ) for( int i = 0 ; i < K ; i++ ){
            int idx = K*(K-j-1) + i;
            if( idx == LEN ) break;
            G[i][j] = MSG[idx];
        }

        string rv = "";
        for( int i = 0 ; i < K ; i++ ) for( int j = 0 ; j < K ; j++ ) if( G[i][j] ) rv += G[i][j];

        cout << rv << endl;

    }
}
