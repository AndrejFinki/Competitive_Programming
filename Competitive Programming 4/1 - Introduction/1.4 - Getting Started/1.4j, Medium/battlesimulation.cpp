#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

string S; 

bool isCombo( int );
char counter( char );

int main()
{
    ios::sync_with_stdio( false );

    cin >> S;

    for( int i = 0 ; i < S.length() ; i++ ){
        if( isCombo(i) ) cout << 'C', i += 2;
        else             cout << counter(S[i]);
    } cout << endl;
}

bool isCombo( int i ){
    if( i + 2 >= S.length() ) return false;
    return S[i] != S[i+1] && S[i] != S[i+2] && S[i+1] != S[i+2];
}

char counter( char c ){
    if( c == 'R' ) return 'S';
    if( c == 'B' ) return 'K';
    if( c == 'L' ) return 'H';
    return '~';
}