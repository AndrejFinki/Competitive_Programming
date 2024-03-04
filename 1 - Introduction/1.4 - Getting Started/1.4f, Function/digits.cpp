#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int F( string );

int main()
{
    ios::sync_with_stdio( false );

    string S;
    while( cin >> S && S != "END" ){
        cout << F(S) << endl;
    }
}

int F(
    string S
) {
    if( S == "1" ) return 1;
    return F( to_string( ( int )S.length() ) ) + 1;
}
