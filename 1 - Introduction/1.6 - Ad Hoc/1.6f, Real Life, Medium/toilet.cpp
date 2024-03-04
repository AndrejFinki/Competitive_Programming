#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

string S;
int P1(), P2(), P3();

int main()
{
    ios::sync_with_stdio( false );

    cin >> S;

    cout << P1() << endl << P2() << endl << P3() << endl;
}

int P1(){

    char currentState = S[0]; int rv = 0;

    for( int i = 1 ; i < S.length() ; i++ ){
        
        char C = S[i];

        if( C != currentState ) rv++;
        if( C != 'U' ) rv++;
        currentState = 'U';

    }

    return rv;

}

int P2(){

    char currentState = S[0]; int rv = 0;

    for( int i = 1 ; i < S.length() ; i++ ){
        
        char C = S[i];

        if( C != currentState ) rv++;
        if( C != 'D' ) rv++;
        currentState = 'D';

    }

    return rv;

}

int P3(){

    char currentState = S[0]; int rv = 0;

    for( int i = 1 ; i < S.length() ; i++ ){
        
        char C = S[i];

        if( C != currentState ) rv++;
        currentState = C;

    }

    return rv;

}
