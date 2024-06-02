#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF ((1LL<<61)+(1LL<<30)-1)
#define LD long double
#define endl '\n'
#define print(x) "[ " << #x << ": " << x << " ]" << flush
#define printW(x,y) "[ " << #x << ": " << setw(y) << x << " ]" << flush
#define printE(a,x) "[ " << #a << "[" << x << "]: " << a[x] << " ]" << flush
#define printV(v)   cout << "[ " << #v << ": "; for(auto _i : v) cout << _i << ' '; cout << "]" << flush << endl
#define printA(a,n) cout << "[ " << #a << ": "; for(int i=0;i<n;i++) cout << a[i] << ' '; cout << "]" << flush << endl
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
const LD ERR = 1e-9; const int MOD = 1e9 + 7; bool areEqual( LD _n1, LD _n2 ){ return fabs( _n1 - _n2 ) < ERR; } bool smallerEqual( LD _n1, LD _n2 ){ return _n1 < _n2 || areEqual( _n1, _n2 ); }
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; }
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

struct CALENDAR{ // Months start from 1 and go to 12
    const int DAYS[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    string MONTH_NAMES[13] = { "None", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    map <string, int> MONTH_TO_IDX = { { "January", 1 }, { "February", 2 }, { "March", 3 }, { "April", 4 }, { "May", 5 }, { "June", 6 }, { "July", 7 }, { "August", 8 }, { "September", 9 }, { "October", 10 }, { "November", 11 }, { "December", 12 } };
    bool isLeap( int Y ){ return !(Y%400) || (!(Y%4)&&(Y%100)); }
    int daysInMonth( int M, int Y ){ return DAYS[isLeap(Y)][M]; }
};

struct DATE : CALENDAR{
    int D, M, Y;
    DATE(){ D = M = Y = -1; }
    DATE( int d, int m, int y ) : D(d), M(m), Y(y) {}
    void advanceDay(){ int dim = daysInMonth(M,Y); D++; if( D > dim ){ D = 1; M++; if( M == 13 ){ M = 1; Y++; } } }
    void advanceDay( int DAYS_TO_ADVANCE ){ while( DAYS_TO_ADVANCE-- >= 0 ) advanceDay(); }
    void retractDay(){ D--; if( !D ){ M--; if( !M ){ Y--; M = 12; } D = daysInMonth(M,Y); } }
    void retractDay( int DAYS_TO_RETRACT ){ while( DAYS_TO_RETRACT-- >= 0 ) retractDay(); }
    const bool operator == ( const DATE &o ) const{ return D == o.D && M == o.M && Y == o.Y; }
};

/* CALENDAR LIBRARY */

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int t; cin >> t;
    while( t-- ){

        int D, N; cin >> D >> N;

        int CURRENT_DAY = 7, RES = 0;
        for( int i = 0 ; i < N ; i++ ){
            int M; cin >> M;
            for( int j = 1 ; j <= M ; j++ ){
                RES += ( j == 13 && CURRENT_DAY == 5 );
                ( ++CURRENT_DAY == 8 ? CURRENT_DAY = 1 : true );
            }
        }

        cout << RES << endl;

    }

}
