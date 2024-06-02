#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int n; cin >> n;
    for( int tc = 1 ; tc <= n ; tc++ )
    {
        int x;
        cin >> x;
        cout << x << ' ' << ( abs(x) % 2 ? "is odd" : "is even" ) << endl;
    }
}