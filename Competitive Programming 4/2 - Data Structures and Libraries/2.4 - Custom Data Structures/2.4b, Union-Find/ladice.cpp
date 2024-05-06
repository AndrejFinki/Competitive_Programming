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

	static constexpr int MAX_SET_ELEMENT = 300005;
	int dset[MAX_SET_ELEMENT];
	int dset_size[MAX_SET_ELEMENT];

};

UnionFindDisjointSet::UnionFindDisjointSet() {
	reset_set();
}
void UnionFindDisjointSet::reset_set() {
	for( int i = 0 ; i < MAX_SET_ELEMENT ; i++ ) {
		dset[i] = i;
		dset_size[i] = 1;
	}
}
void UnionFindDisjointSet::merge_set( int p, int q ) {
	if( are_same_set( p, q ) )
		return;
	p = find_set( p );
	q = find_set( q );
	dset[q] = p;
	dset_size[p] += dset_size[q];
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

const int maxN = 300005;
int N, L;
UnionFindDisjointSet UFDS;

int main()
{
	ios::sync_with_stdio( false );
	cin >> N >> L;

	int l, r, s_l, s_r;
	bool is_taken = true;
	for( int i = 0 ; i < N ; i++ ) {
		cin >> l >> r;
		s_l = UFDS.find_set( l );
		s_r = UFDS.find_set( r );

		is_taken = false;
		if( UFDS.are_same_set( l, r ) )
			is_taken = bool( UFDS.dset_size[s_l] );
		else
			is_taken = bool( UFDS.dset_size[s_l] || UFDS.dset_size[s_r] );

		if( is_taken ) {
			cout << "LADICA" << endl;
			UFDS.merge_set( l, r );
			UFDS.dset_size[ s_l ]--;
		} else {
			cout << "SMECE" << endl;
		}
	}
}
