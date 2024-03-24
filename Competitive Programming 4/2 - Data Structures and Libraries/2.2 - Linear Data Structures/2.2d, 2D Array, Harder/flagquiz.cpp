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

void process(int, string);
void printGrid();
void generateList();

const int maxN = 105;
int N, M;
string G[maxN][maxN];
int minScore = INF;
vector <int> minScoreList;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string question; getline( cin, question );

    cin >> N; cin.ignore();
    for( int i = 0 ; i < N ; i++ ){
        getline( cin, question );
        process(i,question);
    }

    generateList();

    for( int i : minScoreList ){
        for( int j = 0 ; j < M ; j++ ){
            if( j ) cout << ", ";
            cout << G[i][j];
        } cout << endl;
    }

    if( DEBUG ) printGrid();

}



void process( int idx, string line ){

    M = 0;
    string S = "";
    for( int i = 0 ; i < line.length() ; i++ ){
        if( line[i] == ',' ){
            i++;
            G[idx][M++] = S;
            S = "";
            continue;
        } S += line[i];
    } G[idx][M++] = S;

}

void printGrid(){

    cout << print(N) << print(M) << endl;
    for( int i = 0 ; i < N ; i++ ){
        for( int j = 0 ; j < M ; j++ ){
            cout << printW(G[i][j],12) << ' ';
        } cout << endl;
    } cout << endl;

}

void generateList(){

    for( int k = 0 ; k < N ; k++ ){

        int currentScore = 0;

        for( int i = 0 ; i < N ; i++ ){ 
            int diff = 0;
            for( int j = 0 ; j < M ; j++ ) diff += ( G[k][j] != G[i][j] );
            currentScore = max( currentScore, diff );
        }

        if( currentScore > minScore ) continue;
        if( currentScore < minScore ){ minScore = currentScore; minScoreList.clear(); }
        minScoreList.push_back(k); 

    }

    if( DEBUG ) printV(minScoreList);

}
