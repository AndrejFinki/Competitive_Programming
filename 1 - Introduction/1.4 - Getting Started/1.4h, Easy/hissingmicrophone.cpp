#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    string S; cin >> S;

    bool hasHiss = false;
    for( int i = 1 ; i < S.length() ; i++ )
    {
        if( S[i-1] == 's' && S[i] == 's' ){ hasHiss = true; break; }
    }

    cout << ( hasHiss ? "hiss" : "no hiss" ) << endl;
}
