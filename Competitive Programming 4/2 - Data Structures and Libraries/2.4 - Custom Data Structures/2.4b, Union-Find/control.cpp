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
const int maxM = 500005;
int N, M;
UnionFindDisjointSet UFDS;
bitset <maxM> seen_ing;
int ingredients[maxM];

int main()
{
	ios::sync_with_stdio( false );
	
	int recipes_made = 0, ing, new_set, unique_ing_seen;
	bool is_valid_recipe;
	cin >> N;
	for( int i = 0 ; i < N ; i++ ) {
		cin >> M;
		seen_ing.reset();
		int size_sum = unique_ing_seen = 0;
		for( int j = 0 ; j < M ; j++ ) {
			cin >> ing;
			ing = UFDS.find_set( ing );
			if( seen_ing.test( ing ) ) continue;
			size_sum += UFDS.elements[ing];
			seen_ing.set( ing );
			ingredients[unique_ing_seen++] = ing;
		}
		if( size_sum != M ) continue;
		new_set = ing;
		recipes_made++;
		for( int i = 0 ; i < unique_ing_seen ; i++ )
			UFDS.merge_set( new_set, ingredients[i] );
	}

	cout << recipes_made << endl;
}
