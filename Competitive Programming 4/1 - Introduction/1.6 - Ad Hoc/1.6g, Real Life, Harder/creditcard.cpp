#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const LD ERR = 1e-9;

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        LD R, B, M; cin >> R >> B >> M;

        int DAYS = 0;
        while( DAYS <= 1200 && B > 0 ){ DAYS++;
            B += B * R / 100.0;
            B = floor(B*100+0.5+ERR)/100;
            B -= M;
        }

        cout << ( DAYS > 1200 ? "impossible" : to_string(DAYS) ) << endl;

    }

}
