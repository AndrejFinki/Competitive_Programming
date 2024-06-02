#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 8;
char G[N][N];
pair <int, int> DIR[] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool reachesDiamond( string );

int main()
{
    ios::sync_with_stdio( false );

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) cin >> G[i][j];
    G[N-1][0] = '.';

    string CODE; cin >> CODE;

    cout << ( reachesDiamond( CODE ) ? "Diamond!" : "Bug!" ) << endl;
}

bool reachesDiamond( string CODE ){

    function <bool(int,int)> isValid = [](int x, int y) -> bool {
        return x >= 0 && x < N && y >= 0 && y < N;
    };

    int Tx = N-1, Ty = 0, Td = 0;
    for( char c : CODE ){

        if( c == 'F' ){
            Tx += DIR[Td].first;
            Ty += DIR[Td].second;
            if( !isValid(Tx,Ty) || G[Tx][Ty] == 'C' || G[Tx][Ty] == 'I' ) return false;
        }else if( c == 'R' ){
            Td = (Td+1) % 4;
        }else if( c == 'L' ){
            Td = (Td-1+4) % 4;
        }else{
            int ICx = Tx + DIR[Td].first, ICy = Ty + DIR[Td].second;
            if( !isValid(ICx,ICy) || G[ICx][ICy] != 'I' ) return false;
            G[ICx][ICy] = '.';
        }

    }

    return G[Tx][Ty] == 'D';

}
