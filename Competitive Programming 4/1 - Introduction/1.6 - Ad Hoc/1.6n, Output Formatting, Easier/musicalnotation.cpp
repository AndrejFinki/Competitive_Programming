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

void printSheet(string);
int findPos( char );

const string defaultSheet = " - - - - -   -";
int N;
string OUT[14] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    printSheet("GFEDCBAgfedcba");
    printSheet("::::::::::::::");
    printSheet("              ");

    cin >> N;
    string note;
    for( int i = 0 ; i < N ; i++ ){

        if( i ) printSheet(defaultSheet);

        cin >> note;

        int duration = ( note.length() == 1 ? 1 : stoi(note.substr(1,INF)) );
        int tone = findPos(note[0]);

        string currentSheet = defaultSheet;
        currentSheet[tone] = '*';
        while( duration-- ) printSheet(currentSheet);

    }

    for( int i = 0 ; i < 14 ; i++ ){
        cout << OUT[i] << endl;
    }

}

void printSheet( string S ){
    for( int i = 0 ; i < 14 ; i++ ){
        OUT[i] += S[i];
    }
}

int findPos( char c ){

    string scale = "GFEDCBAgfedcba";
    for( int i = 0 ; i < scale.length() ; i++ ) if( c == scale[i] ) return i;

}
