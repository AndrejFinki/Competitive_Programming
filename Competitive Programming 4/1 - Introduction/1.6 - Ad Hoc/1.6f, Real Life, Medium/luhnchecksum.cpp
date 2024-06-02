#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        string S; cin >> S;
        reverse( S.begin(), S.end() );

        int SUM = 0;
        for( int i = 0 ; i < S.length() ; i++ ){
            int digit = S[i] - '0';
            if( i & 1 ) SUM += ( digit*2 >= 10 ? ((digit*2)%10)+((digit*2)/10) : digit*2 );
            else        SUM += digit;
        }

        cout << ( SUM % 10 ? "FAIL" : "PASS" ) << endl;

    }
}
