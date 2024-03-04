#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 8;
bool fromStart[N][N], fromEnd[N][N];
pair <int,int> DIAG[] = { {-1,-1}, {-1,1}, {1,-1}, {1,1} };

pair <int,int> inputPos();
void rookMove( pair<int,int>, bool[][N] );
pair <int,int> findCommon();

int main()
{
    ios::sync_with_stdio( false );

    int t; cin >> t;
    while( t-- ){

        memset( fromStart, 0, sizeof fromStart );
        memset( fromEnd, 0, sizeof fromEnd );

        pair <int,int> start = inputPos();
        pair <int,int> endp = inputPos();

        rookMove( start, fromStart );
        rookMove( endp, fromEnd );

        if( start == endp ) cout << 0 << ' ' << char(start.first + 'A') << ' ' << start.second+1 << endl;
        else if( fromStart[endp.first][endp.second] ){
            cout << 1 << ' ' << char(start.first + 'A') << ' ' << start.second+1 << ' ' << char(endp.first + 'A') << ' ' << endp.second+1 << endl;
        }else{
            pair <int,int> middle = findCommon();
            if( middle.first == -1 ) cout << "Impossible" << endl;
            else{
                cout << 2 << ' ' << char(start.first + 'A') << ' ' << start.second+1 << ' ' << char(middle.first + 'A') << ' ' << middle.second+1 << ' ' << char(endp.first + 'A') << ' ' << endp.second+1 << endl;
            }
        }

    }
}

pair <int, int> findCommon(){
    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
        if( fromStart[i][j] && fromEnd[i][j] ) return {i,j};
    }
    return {-1,-1};
}

void rookMove( pair <int, int> p, bool vis[][N] ){

    for( pair <int, int> d : DIAG ){
        int x = p.first, y = p.second;
        while( x >= 0 && x < N && y >= 0 && y < N ){
            vis[x][y] = true;
            x += d.first; y += d.second;
        }
    }

}

pair <int,int> inputPos(){
    char x; int y;
    cin >> x >> y;
    return { x - 'A', y - 1 };
}
