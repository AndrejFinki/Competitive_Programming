#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

int sx, sy;
int tx, ty;
string chess_s, chess_t;

void chess_to_grid( const string &, int &, int & );
int sign( const int & );

int main()
{
	ios::sync_with_stdio( false );
	cin >> chess_s >> chess_t;

	chess_to_grid( chess_s, sx, sy );
	chess_to_grid( chess_t, tx, ty );

	string moves = "";
	int turns = 0;

	while( sx != tx || sy != ty ) { turns++;
		if( sy != ty ) {
			moves += ( sy < ty ? 'R' : 'L' );
			sy += sign( ty - sy );
		}
		if( sx != tx ) {
			moves += ( sx < tx ? 'D' : 'U' );
			sx += sign( tx - sx );
		}
		moves += '\n';
	}

	cout << turns << endl << moves;
}

int sign (
	const int &v
) {
	return ( v ? ( v > 0 ? 1 : -1 ) : 0 );
}

void chess_to_grid (
	const string &chess,
	int &x,
	int &y
) {
	y = chess[0] - 'a';
	x = 8 - ( chess[1] - '0' );
}
