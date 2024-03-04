#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int findValue( int, int );

int main()
{
    ios::sync_with_stdio( false );

    int p1, q1, p2, q2;
    while( cin >> p1 >> q1 >> p2 >> q2 && p1 )
    {
        int vA = findValue( p1, q1 );
        int vB = findValue( p2, q2 );

        if( vA == vB ) cout << "Tie." << endl;
        else           cout << "Player " << ( vA > vB ? 1 : 2 ) << " wins." << endl;
    }
}

int findValue(
    int x,
    int y
) {
    if( x > y ) swap( x, y );
    if( x == 1 && y == 2 ) return 1000;
    if( x == y ) return 100 * x;
    return 10 * y + x;
}
