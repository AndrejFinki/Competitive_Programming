#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 3;
char G[N][N];

bool isValid();
int countWins( char, char );

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) cin >> G[i][j];

        cout << ( isValid() ? "yes" : "no" ) << endl;

    }
}

bool isValid(){

    int Xc = 0, Oc = 0;
    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){ Xc += bool( G[i][j] == 'X' ); Oc += bool( G[i][j] == 'O' ); }

    if( Oc != Xc && Oc+1 != Xc ) return false;

    int Xw = countWins('X', 'x');
    int Ow = countWins('O', 'o');

    if( Xw > 1 || Ow > 1 || ( Xw >= 1 && Ow >= 1 ) ) return false;

    if( Xw == 1 && Xc != 1+Oc ) return false;
    if( Ow == 1 && Xc != Oc ) return false;

    return true;

}

int countWins( char W, char w ){

    int wins = 0;
    for( int i = 0 ; i < N ; i++ ){
        if( G[i][0] != W ) continue;
        if( G[i][0] == G[i][1] && G[i][0] == G[i][2] ){
            for( int j = 0 ; j < N ; j++ ) G[i][j] = w;
            wins++;
        }
    }

    for( int j = 0 ; j < N ; j++ ){
        if( G[0][j] != W ) continue;
        if( G[0][j] == G[1][j] && G[0][j] == G[2][j] ){
            for( int i = 0 ; i < N ; i++ ) G[i][j] = w;
            wins++;
        }
    }

    if( G[1][1] == W ){
        if( G[0][0] == G[1][1] && G[0][0] == G[2][2] ){
            G[0][0] = G[1][1] = G[2][2] = w;
            wins++;
        }
        if( G[0][2] == G[1][1] && G[1][1] == G[2][0] ){
            G[0][2] = G[1][1] = G[2][0] = w;
            wins++;
        }
    }

    return wins;

}
