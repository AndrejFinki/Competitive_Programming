#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxN = 35;
int N, M, SHOTS;
bool G[2][maxN][maxN];
int shipsLeft[2];

void inputGrid(int);
bool makeShot( int, int, int );

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        memset( shipsLeft, 0, sizeof shipsLeft );
        memset( G, 0, sizeof G );

        cin >> M >> N >> SHOTS;

        for( int i : { 0, 1 } ) inputGrid(i);

        int x, y;
        while( SHOTS > 0 && shipsLeft[0] > 0 && shipsLeft[1] > 0 ){

            do{
                cin >> y >> x; x = N - 1 - x; SHOTS--;
            }while( makeShot( x, y, 0 ) );

            do{
                cin >> y >> x; x = N - 1 - x; SHOTS--;
            }while( makeShot( x, y, 1 ) );

        }

        while( SHOTS-- > 0 ){ cin >> x >> y; }

        if( (shipsLeft[0] > 0) == (shipsLeft[1] > 0) ) cout << "draw" << endl;
        else cout << "player " << ( shipsLeft[0] ? "one" : "two" ) << " wins" << endl;

    }
}

bool makeShot( int x, int y, int idx ){

    if( !G[1-idx][x][y] ) return false;

    G[1-idx][x][y] = false;
    shipsLeft[1-idx]--;
    return shipsLeft[1-idx] > 0;

}

void inputGrid( int idx ){

    char c;
    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < M ; j++ ){
            cin >> c;
            G[idx][i][j] = bool( c == '#' );
            shipsLeft[idx] += bool( c == '#' );
        }
    }

}