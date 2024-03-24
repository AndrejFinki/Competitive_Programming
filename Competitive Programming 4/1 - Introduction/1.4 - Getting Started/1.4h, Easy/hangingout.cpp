#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    int L, N, k, RES = 0, CAP = 0; cin >> L >> N;
    string S;

    for( int i = 0 ; i < N ; i++ )
    {    
        cin >> S >> k;
        if( S == "enter" ) ( CAP + k > L ? RES++ : CAP += k );
        else CAP -= k;
    }

    cout << RES << endl;
}
