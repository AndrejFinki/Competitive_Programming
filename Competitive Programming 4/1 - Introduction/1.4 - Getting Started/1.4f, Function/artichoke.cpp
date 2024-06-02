#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

LL p, a, b, c, d, n;

LD price( LL );

int main()
{
    ios::sync_with_stdio( false );

    cin >> p >> a >> b >> c >> d >> n;

    LD maxPrice = price( 1 );
    LD maxDecline = 0;
    for( int i = 2 ; i <= n ; i++ )
    {
        LD currentPrice = price( i );
        maxDecline = max( maxDecline, maxPrice - currentPrice );
        maxPrice = max( maxPrice, currentPrice );
    }

    cout << fixed << setprecision(6) << maxDecline << endl;
}

LD price(
    LL k
) {
    return p * ( sin( a * k + b ) + cos( c * k + d ) + 2 );
}
