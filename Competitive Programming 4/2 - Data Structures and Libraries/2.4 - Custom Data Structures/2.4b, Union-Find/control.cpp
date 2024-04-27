#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

/* UnionFindDisjointSet Class Begin */

class UnionFindDisjointSet {

public:
	UnionFindDisjointSet();

	void reset_set();
	void merge_set( int, int );
	bool are_same_set( int, int );
	int find_set( int );

	static constexpr int MAX_SET_ELEMENT = 500005;
	int dset[MAX_SET_ELEMENT];
	int elements[MAX_SET_ELEMENT];

};

UnionFindDisjointSet::UnionFindDisjointSet() {
	reset_set();
}
void UnionFindDisjointSet::reset_set() {
	for( int i = 0 ; i < MAX_SET_ELEMENT ; i++ ) {
		dset[i] = i;
		elements[i] = 1;
	}
}
void UnionFindDisjointSet::merge_set( int p, int q ) {
	if( are_same_set( p, q ) )
		return;
	p = find_set( p );
	q = find_set( q );
	dset[q] = p;
	elements[p] += elements[q];
}
bool UnionFindDisjointSet::are_same_set( int p, int q ) {
	return find_set( p ) == find_set( q );
}
int UnionFindDisjointSet::find_set( int p ) {
	if( dset[p] == p )
		return p;
	return dset[p] = find_set( dset[p] );
}

/* UnionFindDisjointSet Class End */

const int maxN = 200005;
int N, M;
UnionFindDisjointSet UFDS;
unordered_map <int, int> ingredients;

int main()
{
	ios::sync_with_stdio( false );
	
	int recipes_made = 0, ing, new_set;
	bool is_valid_recipe;
	cin >> N;
	for( int i = 0 ; i < N ; i++ ) {
		cin >> M;
		ingredients.clear();
		for( int j = 0 ; j < M ; j++ ) {
			cin >> ing;
			ingredients[ UFDS.find_set( ing ) ] += 1;
		}
		is_valid_recipe = true;
		for( const pair <int, int> &p : ingredients ) {
			if( p.second == UFDS.elements[ p.first ] ) continue;
			is_valid_recipe = false;
			break;
		}
		if( !is_valid_recipe ) continue;
		new_set = UFDS.find_set( ing );
		for( const pair <int, int> &p : ingredients ) {
			UFDS.merge_set( p.first, new_set );
			ingredients[p.first] = 0;
		}
		recipes_made++;
	}

	cout << recipes_made << endl;
}
