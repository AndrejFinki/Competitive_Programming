#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

struct round_t { public:
	string player;
	int score;
};

const int max_n = 1005;
int N;
unordered_map <string, int> current_score;
round_t rounds[max_n];

int main()
{
	ios::sync_with_stdio( false );
	cin >> N;

	for( int i = 0 ; i < N ; i++ )
		cin >> rounds[i].player >> rounds[i].score;

	for( int i = 0 ; i < N ; i++ ) {
		current_score[ rounds[i].player ] += rounds[i].score;
	}

	int max_score = 0;
	unordered_set <string> winners;
	for( const pair <string, int> &p : current_score ) {
		if( p.second < max_score ) continue;
		if( p.second > max_score ) winners.clear();
		max_score = p.second;
		winners.insert( p.first );
	}

	current_score.clear();

	for( int i = 0 ; i < N ; i++ ) {
		if( !winners.count( rounds[i].player ) ) continue;
		current_score[ rounds[i].player ] += rounds[i].score;
		if( current_score[ rounds[i].player ] < max_score ) continue;
		cout << rounds[i].player << endl;
		break;
	}
}