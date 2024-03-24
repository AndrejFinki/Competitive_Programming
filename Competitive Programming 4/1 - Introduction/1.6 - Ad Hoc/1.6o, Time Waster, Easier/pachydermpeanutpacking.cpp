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

struct box{
    LD x1, y1, x2, y2;
    string type;
    box(){}
    box( LD _x1, LD _y1, LD _x2, LD _y2 ) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
    bool isInBox( LD x, LD y ){
        return smallerEqual( x1, x ) && smallerEqual( x, x2 ) && smallerEqual( y1, y ) && smallerEqual( y, y2 );
    }
};

int findBox( LD, LD );

const int maxN = 35;
int N, M;
box boxList[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    bool first = true;
    while( cin >> N && N ){

        if( !first ) cout << endl; else first = false; 

        for( int i = 0 ; i < N ; i++ ) cin >> boxList[i].x1 >> boxList[i].y1 >> boxList[i].x2 >> boxList[i].y2 >> boxList[i].type;

        cin >> M;
        while( M-- ){

            LD x, y; string type;
            cin >> x >> y >> type;

            int boxIdx = findBox( x, y );

            if( boxIdx == -1 ) cout << type << ' ' << "floor" << endl;
            else               cout << type << ' ' << ( type == boxList[boxIdx].type ? "correct" : boxList[boxIdx].type ) << endl;

        }

    }

}

int findBox( LD x, LD y ){

    for( int i = 0 ; i < N ; i++ ){
        if( boxList[i].isInBox(x,y) ) return i;
    }

    return -1;

}
