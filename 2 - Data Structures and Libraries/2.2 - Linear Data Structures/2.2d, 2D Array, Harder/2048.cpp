
 Download 1.cpp
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
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

void makeMovement();
void printGrid();

const int N = 4;
int G[N][N];
int DIR;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) cin >> G[i][j];
    cin >> DIR;

    makeMovement();

    printGrid();

}



void makeMovement(){

    function <bool(int,int)> isValid = [](int x, int y) -> bool{
        return 0 <= x && x < N && 0 <= y && y < N;
    };

    function <void()> moveLeft = [isValid]() -> void{
        
        for( int rep = 0 ; rep < N ; rep++ ) for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
            if( isValid( i, j-1 ) && G[i][j-1] == 0 ) swap( G[i][j-1], G[i][j] );
        }

        for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
            if( isValid( i, j-1 ) && G[i][j-1] == G[i][j] ){
                G[i][j-1] *= 2;
                G[i][j] = 0;
            }
        }

        for( int rep = 0 ; rep < N ; rep++ ) for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
            if( isValid( i, j-1 ) && G[i][j-1] == 0 ) swap( G[i][j-1], G[i][j] );
        }

    };

    function <void()> moveUp = [isValid]() -> void{
        
        for( int rep = 0 ; rep < N ; rep++ ) for( int j = 0 ; j < N ; j++ ) for( int i = 0 ; i < N ; i++ ){
            if( isValid( i-1, j ) && G[i-1][j] == 0 ) swap( G[i-1][j], G[i][j] );
        }

        for( int j = 0 ; j < N ; j++ ) for( int i = 0 ; i < N ; i++ ){
            if( isValid( i-1, j ) && G[i-1][j] == G[i][j] ){
                G[i-1][j] *= 2;
                G[i][j] = 0;
            }
        }

        for( int rep = 0 ; rep < N ; rep++ ) for( int j = 0 ; j < N ; j++ ) for( int i = 0 ; i < N ; i++ ){
            if( isValid( i-1, j ) && G[i-1][j] == 0 ) swap( G[i-1][j], G[i][j] );
        }

    };

    function <void()> moveRight = [isValid]() -> void{
        
        for( int rep = 0 ; rep < N ; rep++ ) for( int i = 0 ; i < N ; i++ ) for( int j = N-1 ; j >= 0 ; j-- ){
            if( isValid( i, j+1 ) && G[i][j+1] == 0 ) swap( G[i][j+1], G[i][j] );
        }

        for( int i = 0 ; i < N ; i++ ) for( int j = N-1 ; j >= 0 ; j-- ){
            if( isValid( i, j+1 ) && G[i][j+1] == G[i][j] ){
                G[i][j+1] *= 2;
                G[i][j] = 0;
            }
        }

        for( int rep = 0 ; rep < N ; rep++ ) for( int i = 0 ; i < N ; i++ ) for( int j = N-1 ; j >= 0 ; j-- ){
            if( isValid( i, j+1 ) && G[i][j+1] == 0 ) swap( G[i][j+1], G[i][j] );
        }

    };

    function <void()> moveDown = [isValid]() -> void{
        
        for( int rep = 0 ; rep < N ; rep++ ) for( int j = 0 ; j < N ; j++ ) for( int i = N-1 ; i >= 0 ; i-- ){
            if( isValid( i+1, j ) && G[i+1][j] == 0 ) swap( G[i+1][j], G[i][j] );
        }

        for( int j = 0 ; j < N ; j++ ) for( int i = N-1 ; i >= 0 ; i-- ){
            if( isValid( i+1, j ) && G[i+1][j] == G[i][j] ){
                G[i+1][j] *= 2;
                G[i][j] = 0;
            }
        }

        for( int rep = 0 ; rep < N ; rep++ ) for( int j = 0 ; j < N ; j++ ) for( int i = N-1 ; i >= 0 ; i-- ){
            if( isValid( i+1, j ) && G[i+1][j] == 0 ) swap( G[i+1][j], G[i][j] );
        }

    };

    // 0 Left, 1 Up, 2 Right, 3 Down
    if( DIR == 0 ) moveLeft();
    if( DIR == 1 ) moveUp();
    if( DIR == 2 ) moveRight();
    if( DIR == 3 ) moveDown();

}

void printGrid(){

    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < N ; j++ ) cout << G[i][j] << ' ';
        cout << endl;
    }

}
