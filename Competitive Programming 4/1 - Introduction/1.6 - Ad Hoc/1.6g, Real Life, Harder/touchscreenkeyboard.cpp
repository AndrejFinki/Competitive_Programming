#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

struct pos{
    int x, y;
    pos(){}
    pos( int _x, int _y ) : x(_x), y(_y) {}
};

struct word{
    string w; int dist;
    word(){}
    word( string _w, int _d ) : w(_w), dist(_d) {}
    const bool operator < ( const word &o ) const{
        if( dist != o.dist ) return dist < o.dist;
        return w < o.w;
    }
};

const int N = 3, M = 11;
const string keyboard[] = { "qwertyuiop",
                            "asdfghjkl ",
                            "zxcvbnm   " };
map <char, pos> keyMap;

void init();
int calculateDistance( string, string );

int main()
{
    ios::sync_with_stdio( false );

    init();

    int t; cin >> t;
    while( t-- ){

        string S; int W;
        cin >> S >> W;

        word wordList[W];
        for( int i = 0 ; i < W ; i++ ){ cin >> wordList[i].w; wordList[i].dist = calculateDistance( S, wordList[i].w ); }

        sort( wordList, wordList+W );

        for( word w : wordList ){
            cout << w.w << ' ' << w.dist << endl;
        }

    }
}

int calculateDistance( string p, string q ){

    function <int(char,char)> distance = [](char p, char q) -> int {
        return abs( keyMap[p].x-keyMap[q].x ) + abs( keyMap[p].y - keyMap[q].y );
    };

    int rv = 0;
    for( int i = 0 ; i < p.length() ; i++ ) rv += distance( p[i], q[i] );
    return rv;

}

void init(){

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < M ; j++ ) keyMap[keyboard[i][j]] = {i,j};

}
