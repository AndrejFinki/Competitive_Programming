#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

struct boat_t {
	int t;
	int p;
	int i;
	LD value;

	boat_t() = default;
	boat_t( int t, int p, int i ) : t(t), p(p), i(i) {
		value = (LD)(p) / t;
	}

	bool operator < ( const boat_t &o ) const {
		if( value != o.value )
			return value > o.value;
		if( t != o.t )
			return t > o.t;
		return i < o.i;
	}
};

pair <int, string> greedy_strategy();
pair <int, string> complete_fill();

int N, V;
vector <boat_t> boats;

int main()
{
	ios::sync_with_stdio( false );
	
	cin >> N >> V;

	for( int i = 0 ; i < N ; i++ ) {
		int t, p;
		cin >> t >> p;
		boats.push_back( boat_t( t, p, i+1 ) );
	}

	sort( boats.begin(), boats.end() );

	pair <int, string> res[] = { greedy_strategy(), complete_fill() };

	if( res[0].first >= res[1].first )
		cout << res[0].first << endl << res[0].second << endl;
	else
		cout << res[1].first << endl << res[1].second << endl;
}

/* Standard greedy strategy */
pair <int, string> greedy_strategy()
{
	int value = 0;
	int cap = V;
	string boats_taken = "";

	for( int i = 0 ; i < N && cap ; i++ ) {
		if( cap < boats[i].t )
			continue;
		cap -= boats[i].t;
		value += boats[i].p;
		boats_taken += to_string( boats[i].i ) + " ";
	}

	return make_pair( value, boats_taken );
}

/* If an unused space is left in the boat at the end, take out the last small boat and replace it with the next big boat */
pair <int, string> complete_fill()
{
	int value = 0;
	int cap = V;
	vector <int> boats_taken;
	int last_small_boat_taken = -1;

	for( int i = 0 ; i < N && cap ; i++ ) {
		if( cap == 1 ) {
			if( last_small_boat_taken == -1 )
				return make_pair( -1, "" ); /* We haven't taken a small boat to replace, greedy strategy will be better */
			value -= boats[ last_small_boat_taken ].p;
			while( i < N && boats[i].t == 1 )
				i++;
			if( i == N )
				return make_pair( -1, "" ); /* We didn't find a big boat to place instead of a small one, greedy strategy will be better */
			/* We did find a big boat to place here, might be better than greedy */
			for( int i = boats_taken.size() - 1 ; i >= 0 ; i-- ) {
				if( boats_taken[i] != boats[ last_small_boat_taken ].i )
					continue;
				boats_taken.erase( boats_taken.begin() + i );
				break;
			}
			cap = 2;
		}
		cap -= boats[i].t;
		value += boats[i].p;
		boats_taken.push_back( boats[i].i );
		if( boats[i].t == 1 )
			last_small_boat_taken = i;
	}

	string boats_taken_str = "";
	for( const int &i : boats_taken )
		boats_taken_str += to_string(i) + " ";

	return make_pair( value, boats_taken_str );
}
