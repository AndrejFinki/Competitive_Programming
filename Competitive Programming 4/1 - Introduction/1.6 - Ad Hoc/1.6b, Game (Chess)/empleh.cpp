#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int N = 8;
char board[N][N];

void place( string, function<int(int)> );
void printBoard();

int main()
{
    ios::sync_with_stdio( false );

    for( int i = 0 ; i < N ; i++ ) for( int j = 0 ; j < N ; j++ ) board[i][j] = '~';

    string line;
    getline( cin, line );
    place( line, ::toupper );
    getline( cin, line );
    place( line, ::tolower );

    printBoard();

}

void printBoard(){

    for( int i = 0 ; i < N ; i++ ){

        cout << "+---+---+---+---+---+---+---+---+" << endl;

        for( int j = 0 ; j < N ; j++ ){
            char fillChar = ( ( i & 1 ) == ( j & 1 ) ? '.' : ':' );
            cout << '|' << fillChar << ( board[i][j] == '~' ? fillChar : board[i][j] ) << fillChar;
        } cout << '|' << endl;

    }

    cout << "+---+---+---+---+---+---+---+---+" << endl;

}

void place( string S, function <int(int)> correctCase ){

    for( char &c : S ) if( c == ',' ) c = ' ';

    stringstream SS(S);
    SS >> S;

    while( SS >> S ){
        if( S.length() == 2 ) S = "P" + S;
        S[0] = correctCase(S[0]);
        int x = 7 - (S[2] - '1'), y = S[1] - 'a';
        board[x][y] = S[0];
    }

}
