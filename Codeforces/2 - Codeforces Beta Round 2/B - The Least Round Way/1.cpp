#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

const int maxN = 1005;
int N;
int M[maxN][maxN];
int dp_2[maxN][maxN] = {};
int dp_5[maxN][maxN] = {};
bool has_zero = false;

int divs( int, const int & );
int dpf_2( int, int );
int dpf_5( int, int );
string path_2();
string path_5();
string path_0();

int main()
{
	ios::sync_with_stdio( false );
	memset( dp_2, -1, sizeof dp_2 );
	memset( dp_5, -1, sizeof dp_5 );
	
	cin >> N;
	for( int i = 0 ; i < N ; i++ )
		for( int j = 0 ; j < N ; j++ ) {
			cin >> M[i][j];

			if( !M[i][j] )
				has_zero = true;
	}

	int pow_of_2 = dpf_2( N-1, N-1 );
	int pow_of_5 = dpf_5( N-1, N-1 );
	int res = min( pow_of_2, pow_of_5 );
	if( has_zero ) res = min( res, 1 );
	
	cout << res << endl;

	if( pow_of_2 == res )
		cout << path_2() << endl;
	else if( pow_of_5 == res )
		cout << path_5() << endl;
	else
		cout << path_0() << endl;
}

int divs( int v, const int &div ) {
	int rv = 0;
	while( v >= 1 && !( v % div ) ) {
		rv++;
		v /= div;
	}
	return rv;
}

int dpf_2( int i, int j ) {
	if( dp_2[i][j] != -1 )
		return dp_2[i][j];
	if( i == 0 && j == 0 )
		return dp_2[i][j] = divs( M[i][j], 2 );
	if( i == 0 )
		return dp_2[i][j] = divs( M[i][j], 2 ) + dpf_2( i, j-1 );
	if( j == 0 )
		return dp_2[i][j] = divs( M[i][j], 2 ) + dpf_2( i-1, j );

	return dp_2[i][j] = divs( M[i][j], 2 ) + min( dpf_2( i-1, j ), dpf_2( i, j-1 ) );
}

int dpf_5( int i, int j ) {
	if( dp_5[i][j] != -1 )
		return dp_5[i][j];
	if( i == 0 && j == 0 )
		return dp_5[i][j] = divs( M[i][j], 5 );
	if( i == 0 )
		return dp_5[i][j] = divs( M[i][j], 5 ) + dpf_5( i, j-1 );
	if( j == 0 )
		return dp_5[i][j] = divs( M[i][j], 5 ) + dpf_5( i-1, j );

	return dp_5[i][j] = divs( M[i][j], 5 ) + min( dpf_5( i-1, j ), dpf_5( i, j-1 ) );
}

string path_2() {
	string rv = "";
	int i = N-1, j = N-1;
	while( i || j ) {
		if( i == 0 ) {
			rv += "R";
			j--;
		} else if( j == 0 ) {
			rv += "D";
			i--;
		} else {
			if( dp_2[i-1][j] < dp_2[i][j-1] ) {
				rv += "D";
				i--;
			} else {
				rv += "R";
				j--;
			}
		}
	}
	reverse( rv.begin(), rv.end() );
	return rv;
}

string path_5() {
	string rv = "";
	int i = N-1, j = N-1;
	while( i || j ) {
		if( i == 0 ) {
			rv += "R";
			j--;
		} else if( j == 0 ) {
			rv += "D";
			i--;
		} else {
			if( dp_5[i-1][j] < dp_5[i][j-1] ) {
				rv += "D";
				i--;
			} else {
				rv += "R";
				j--;
			}
		}
	}
	reverse( rv.begin(), rv.end() );
	return rv;
}

string path_0() {
	int zi, zj;
	for( int i = 0 ; i < N ; i++ )
		for( int j = 0 ; j < N ; j++ )
			if( M[i][j] == 0 ) {
				zi = i;
				zj = j;
	}

	string rv = "";
	for( int i = 0 ; i < zi ; i++ )
		rv += "D";
	for( int j = 0 ; j < zj ; j++ )
		rv += "R";
	for( int i = 0 ; i < N - zi - 1 ; i++ )
		rv += "D";
	for( int j = 0 ; j < N - zj - 1 ; j++ )
		rv += "R";
	return rv;
}
