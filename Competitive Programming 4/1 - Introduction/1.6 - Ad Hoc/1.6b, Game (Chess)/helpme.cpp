#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 8;
char board[N][N];
vector <string> white, black;

void inputBoard(), findWhite(), findBlack();

int main()
{
    ios::sync_with_stdio( false );

    inputBoard();

    findWhite();
    findBlack();

    cout << "White:"; bool first = true;
    for( string w : white ){
        if( !first ) cout << ','; else { cout << ' '; first = false; }
        if( w[0] == 'P' ) w = w.substr(1,INF);
        cout << w;
    } cout << endl; first = true;
    cout << "Black:";
    for( string b : black ){
        if( !first ) cout << ','; else { cout << ' '; first = false; }
        if( b[0] == 'P' ) b = b.substr(1,INF);
        cout << b;
    } cout << endl;
}

void findWhite(){

    for( char c : { 'K', 'Q', 'R', 'B', 'N', 'P' } ){
        for( int i = N-1 ; i >= 0 ; i-- ) for( int j = 0 ; j < N ; j++ ){
            if( board[i][j] != c ) continue;
            string temp = "";
            temp += c;
            temp += char( j + 'a' );
            temp += to_string( 8 - i );
            white.push_back( temp );        
        }
    } 

}

void findBlack(){

    for( char c : { 'k', 'q', 'r', 'b', 'n', 'p' } ){
        for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ){
            if( board[i][j] != c ) continue;
            string temp = "";
            temp += toupper(c);
            temp += char( j + 'a' );
            temp += to_string( 8 - i );
            black.push_back( temp );
        }
    }

}

void inputBoard(){

    string line;
    for( int i = 0 ; i < N ; i++ ){

        getline( cin, line ); getline( cin, line );

        for( int j = 0, jidx = 2 ; j < N ; j++, jidx += 4 ){
            board[i][j] = line[jidx];
            if( board[i][j] == ':' || board[i][j] == '.' ) board[i][j] = '~';
        }

    }

}
