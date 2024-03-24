#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)

void init();
bool type_1( const string & );
string solve_1( const string & );
string solve_2( const string & );
int str_to_int( const string & );

const int max_len = 1000005;
string int_to_str[ max_len ];

int main()
{
	init();

	int t; cin >> t;
	while( t-- ) {
		string q;
		cin >> q;

		cout << ( type_1( q ) ? solve_1( q ) : solve_2( q ) ) << endl;
	}
}

bool type_1(
	const string &s
) {
	for( int i = 1  ; i < s.length() ; i++ ) {
		if( s[i] == 'C' && isdigit( s[i-1] ) ) return true;
	}
	return false;
}

string solve_1(
	const string &s
) {
	int i = 0;
	for( ; i < s.length() && s[i] != 'C' ; i++ ) {}
	stringstream ss( s.substr( i+1, INF ) );
	int col;
	ss >> col;
	string col_str = int_to_str[ col ];
	string row = s.substr( 1, i-1 );
	return col_str + row;
}

string solve_2(
	const string &s
) {
	int i = 0;
	for( ; i < s.length() && !isdigit( s[i] ) ; i++ ) {}
	string col_str = s.substr( 0, i );
	int col = str_to_int( col_str );
	string row = s.substr( i, INF );
	return "R" + row + "C" + to_string( col );
}

int str_to_int(
	const string &s
) {
	int m = 1, rv = 0;
	for( int i = s.length()-1 ; i >= 0 ; i-- ) {
		rv += m * ( s[i] - 'A' + 1 );
		m *= 26;
	}
	return rv;
}

void init()
{
	function <void( string & )> increment = []( string &s ) -> void {
		int j = s.length() - 1;
		while( j > -1 && s[j] == 'Z' ) {
			s[j] = 'A';
			j--;
		}
		if( j != -1 )
			s[j] = s[j] + 1;
		else
			s = "A" + s;
	};

	string col_str = "A";
	for( int i = 1 ; i <= 1e6 ; i++ ) {
		int_to_str[i] = col_str;
		increment( col_str );
	}
}
