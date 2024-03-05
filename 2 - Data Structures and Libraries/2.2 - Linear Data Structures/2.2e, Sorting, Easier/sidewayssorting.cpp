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
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; } int sign( int x ){ return x < 0 ? -1 : ( x > 0 ? 1 : 0 ); }
struct pos{ int x, y; pos(){} pos( int _x, int _y ) : x(_x), y(_y) {} const bool operator < ( const pos &o ) const { if( x != o.x ) return x < o.x; return y < o.y; } } const dir[] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; enum DIRECTION{ UP, RIGHT, DOWN, LEFT };
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

void getStringList();
bool ignoreCaseSort( string, string );
void placeIntoGrid();

const int maxN = 20;
int R, C;
char G[maxN][maxN];
string stringList[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool first = true;
    while( cin >> R >> C && R ){

        for( int i = 0 ; i < R ; i++ ) for( int j = 0 ; j < C ; j++ ) cin >> G[i][j];

        getStringList();

        stable_sort( stringList, stringList+C, ignoreCaseSort );

        placeIntoGrid();

        if( !first ) cout << endl; else first = false;
        for( int i = 0 ; i < R ; i++ ){
            for( int j = 0 ; j < C ; j++ ){
                cout << G[i][j];
            } cout << endl;
        }

    }

}



void getStringList(){

    for( int j = 0 ; j < C ; j++ ){
        string &s = stringList[j];
        s = "";
        for( int i = 0 ; i < R ; i++ ) s += G[i][j];
    }

}

bool ignoreCaseSort( string p, string q ){
    transform( p.begin(), p.end(), p.begin(), ::tolower );
    transform( q.begin(), q.end(), q.begin(), ::tolower );
    return p < q;
}

void placeIntoGrid(){

    for( int j = 0 ; j < C ; j++ ){
        for( int i = 0 ; i < R ; i++ ) G[i][j] = stringList[j][i];
    }

}
