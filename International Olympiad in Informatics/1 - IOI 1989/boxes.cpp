#include <bits/stdc++.h>
using namespace std;

#define	  LL	long long
#define	  LD	long double
#define	 INF	(1<<30)
#define	 ERR	(1e-9)
#define	endl	'\n'

struct state_t {
	string state;
	int moves;

	state_t() = default;
	state_t(
		const string & state,
		const int & moves
	) : state( state ), moves( moves ) {}
};

int N;

void solve();
state_t search( state_t );

int main()
{
	ios::sync_with_stdio( false );
	cin.tie(  NULL );
	cout.tie( NULL );

	cin >> N;

	while( true )
		solve();
}

void solve()
{
	char boxes[2*N];
	for( int i = 0 ; i < 2*N ; i++ )
		if( !( cin >> boxes[i] ) )
			exit(0);

	for( int i = 0 ; i < 2*N ; i++ )
		if( boxes[i] == 'X' && boxes[i+1] != 'X' )
			return;
		else if( boxes[i] == 'X' && boxes[i+1] == 'X' )
			break;

	string start_state = "";
	for( int i = 0 ; i < 2*N ; i++ )
		start_state += boxes[i];

	state_t end_state =	search( { start_state, 0 } );

	cout << "Input state: " << start_state << endl;
	if( end_state.moves == -1 )
		cout << "No path exists." << endl;
	else {
		cout << "Min moves: " << end_state.moves << endl;
		cout << "Final state: " << end_state.state << endl;
	}
	cout << endl;
}

state_t search(
	state_t state
) {
	function <bool(const string &)> is_ending_state = []( const string &s ) -> bool {
		bool seen_B = false;
		for( int i = 0 ; i < s.length() ; i++ ) {
			if( s[i] == 'B' )
				seen_B = true;
			else if( seen_B && s[i] == 'A' )
				return false;
		}
		return true;
	};

	function <void(const string &, int i, int j, string &)> exchange = []( const string &s, int i, int j, string &res ) -> void {
		if( i+1 >= 2*N || j+1 >= 2*N )
			return;
		if( s[i] == 'X' || s[i+1] == 'X' )
			return;
		if( s[j] != 'X' || s[j+1] != 'X' )
			return;
		if( i == j || i == j+1 || i+1 == j || i+1 == j+1 )
			return;
		res = s;
		swap( res[i], res[j] );
		swap( res[i+1], res[j+1] );
	};

	function <vector<state_t>(const state_t &)> get_all_moves = [exchange]( const state_t &s ) -> vector <state_t> {
		vector <state_t> v;
		int blank_idx = -1;
		for( int i = 0 ; i < s.state.length() ; i++ )
			if( s.state[i] == 'X' ) {
				blank_idx = i;
				break;
		}
		assert( blank_idx != -1 );
		for( int i = 0 ; i < s.state.length() ; i++ ) {
			string new_state_string = "";
			exchange( s.state, i, blank_idx, new_state_string );
			if( new_state_string == "" )
				continue;
			v.push_back( { new_state_string, s.moves + 1 } );
		}
		return v;
	};

	set <string> visited;
	queue <state_t> q;
	q.push( state );

	while( !q.empty() ) {
		state = q.front();
		q.pop();

		if( visited.count( state.state ) )
			continue;

		visited.insert( state.state );

		if( is_ending_state( state.state ) )
			return state;

		for( state_t next_move : get_all_moves( state ) ) {
			if( !visited.count( next_move.state ) )
				q.push( next_move );
		}
	}

	return { "", -1 };
}
