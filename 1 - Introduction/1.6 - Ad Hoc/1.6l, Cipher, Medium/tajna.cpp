#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

int main()
{
    ios::sync_with_stdio( false );

    string S; cin >> S;
    int LEN = S.length();
    int N = 1;
    for( int i = 1 ; i <= sqrt(LEN) ; i++ ){
        if( LEN % i ) continue;
        N = i;
    }

    string rv = "";
    for( int i = 0 ; i < N ; i++ ){
        for( int j = i ; j < LEN ; j += N ){
            rv += S[j];
        }
    }

    cout << rv << endl;
}
