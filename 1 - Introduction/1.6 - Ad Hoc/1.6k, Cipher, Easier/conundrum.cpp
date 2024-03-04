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

    int res = 0;
    for( int i = 0 ; i < S.length() ; i++ ){

        if( (i%3==0) ) res += S[i] != 'P';
        if( (i%3==1) ) res += S[i] != 'E';
        if( (i%3==2) ) res += S[i] != 'R';


    }
    
    cout << res << endl;
}
