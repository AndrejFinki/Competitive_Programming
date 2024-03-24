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
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

struct pos{ int x, y; 
    pos(){} 
    pos( int _x, int _y ) : x(_x), y(_y) {} 
} const dir[] = { {2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2} };

bool isValid();

const int N = 5;
char G[N][N];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) cin >> G[i][j];

    cout << ( isValid() ? "valid" : "invalid" ) << endl;

}



bool isValid(){

    function <bool(int,int)> isValid = [](int x, int y) -> bool{
        return 0 <= x && x < N && 0 <= y && y < N;
    };

    function <bool(int,int)> isValidKnight = [isValid](int x, int y) -> bool{
        for( pos d : dir ){
            int _x = x + d.x, _y = y + d.y;
            if( !isValid(_x,_y) ) continue;
            if( G[_x][_y] == 'k' ) return false;
        } return true;
    };

    int count = 0;
    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
        if( G[i][j] != 'k' ) continue;
        count++;
        if( !isValidKnight(i,j) ) return false;
    } return count == 9;

}
