#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x, y; cin >> x >> y;

    if( y == 1 ) cout << ( x == 0 ? "ALL GOOD" : "IMPOSSIBLE" ) << endl;
    else         cout << fixed << setprecision(6) << -x / (LD)( y-1 ) << endl;

}
