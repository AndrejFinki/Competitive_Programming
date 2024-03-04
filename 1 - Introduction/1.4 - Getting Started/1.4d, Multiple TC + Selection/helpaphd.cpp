#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- )
    {
        string S;
        cin >> S;

        if( S == "P=NP" ) {
            cout << "skipped" << endl;
            continue;
        }

        for( char &c : S ) if( c == '+' ) c = ' ';
        stringstream SS( S );

        int x, y;
        SS >> x >> y;

        cout << x + y << endl;
    }
}