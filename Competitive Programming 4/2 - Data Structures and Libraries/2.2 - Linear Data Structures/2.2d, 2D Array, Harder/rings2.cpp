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
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} } const dir[] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; enum DIRECTION{ UP, RIGHT, DOWN, LEFT };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

void fillRing(int);
void printTree();

const int maxN = 105;
int N, M;
int G[maxN][maxN] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cout << setfill('.');
    cin >> N >> M;
    for( int i = 1 ; i <= N ; i++ ) for( int j = 1 ; j <= M ; j++ ){
        char c; cin >> c;
        if( c != 'T' ) continue;
        G[i][j] = -1;
    }

    for( int i = 0 ; i < maxN ; i++ ) fillRing(i);

    printTree();

}



void fillRing( int r ){

    for( int i = 1 ; i <= N ; i++ ) for( int j = 1 ; j <= M ; j++ ){
        if( G[i][j] != -1 ) continue;
        for( pos d : dir ){
            if( G[i+d.x][j+d.y] == r ) G[i][j] = r+1;
        }
    }

}

void printTree(){
    
    int maxNum = 1;
    for( int i = 1 ; i <= N ; i++ ) for( int j = 1 ; j <= M ; j++ ) maxNum = max( maxNum, G[i][j] );
    maxNum = log10(maxNum)+2;

    for( int i = 1 ; i <= N ; i++ ) {
        for( int j = 1 ; j <= M ; j++ ){
            if( !G[i][j] ) for( int k = 0 ; k < maxNum ; k++ ) cout << '.';
            else cout << setw(maxNum) << G[i][j];
        } cout << endl;
    }

}
