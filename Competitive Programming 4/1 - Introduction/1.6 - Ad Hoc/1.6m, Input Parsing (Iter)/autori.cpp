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
    string rv = "";
    for( char c : S ) if( isupper(c) ) rv += c;
    cout << rv << endl;

}
