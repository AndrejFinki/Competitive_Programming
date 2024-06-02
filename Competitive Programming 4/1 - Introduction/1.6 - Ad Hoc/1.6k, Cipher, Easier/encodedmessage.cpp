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
        int L = sqrt(S.length());

        for( int i = L-1 ; i >= 0 ; i-- ){
            for( int j = i ; j < S.length() ; j += L ) cout << S[j];
        }

        cout << endl;

    }
}
