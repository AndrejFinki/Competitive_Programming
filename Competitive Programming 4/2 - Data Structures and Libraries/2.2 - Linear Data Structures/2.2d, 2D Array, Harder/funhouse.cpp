#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF (((1LL<<61)+(1LL<<30)-1)/2)
#define LD long double
#define endl '\n'
#define print(x) "[ " << #x << ": " << x << " ]" << flush
#define printW(x,y) "[ " << #x << ": " << setw(y) << x << " ]" << flush
#define printE(a,x) "[ " << #a << "[" << x << "]: " << a[x] << " ]" << flush
#define printV(v)   if(1){cout << "[ " << #v << ": "; for(auto _i : v) cout << _i << ' '; cout << "]" << flush << endl;}
#define printA(a,n) if(1){cout << "[ " << #a << ": "; for(int i=0;i<n;i++) cout << a[i] << ' '; cout << "]" << flush << endl;}
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
const LD ERR = 1e-7; const int MOD = 1e9 + 7; bool areEqual( LD _n1, LD _n2 ){ return fabs( _n1 - _n2 ) < ERR; } bool smallerEqual( LD _n1, LD _n2 ){ return _n1 < _n2 || areEqual( _n1, _n2 ); }
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; }
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} } const dir[] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
enum DIRECTION{ UP, DOWN, LEFT, RIGHT };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

pos findExit();
void printGrid();

const int maxN = 25;
int N, M;
char G[maxN][maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC = 0;
    while( cin >> M >> N && N ){ TC++;

        for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < M ; j++ ) cin >> G[i][j];

        pos E = findExit();
        G[E.x][E.y] = '&';

        cout << "HOUSE " << TC << endl;
        printGrid();

    }

}



pos findExit(){

    function <pos()> findStart = []() -> pos{
        for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < M ; j++ ) if( G[i][j] == '*' ) return {i,j}; return {-1,-1};
    };

    function <int(pos)> findDirFromStart = [](pos S) -> int{
        if( S.x == 0 ) return 1;
        if( S.y == 0 ) return 3;
        if( S.x == N-1 ) return 0;
        return 2;
    };

    function <int(int,char)> changeMovement = []( int d, char c ) -> int{
        if( c == '/' ){
            if( d == UP ) return RIGHT;
            if( d == DOWN ) return LEFT;
            if( d == LEFT ) return DOWN;
            if( d == RIGHT ) return UP;
        }
        if( c == '\\' ){
            if( d == UP ) return LEFT;
            if( d == DOWN ) return RIGHT;
            if( d == LEFT ) return UP;
            if( d == RIGHT ) return DOWN;
        }
        return 0;
    };

    pos S = findStart();
    int d = findDirFromStart(S);

    while( G[S.x][S.y] != 'x' ){
        S.x += dir[d].x; S.y += dir[d].y;
        if( G[S.x][S.y] == '/' || G[S.x][S.y] == '\\' ) d = changeMovement(d, G[S.x][S.y]);
    }

    return S;

}

void printGrid(){

    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < M ; j++ ){
            cout << G[i][j];
        } cout << endl;
    }

}
