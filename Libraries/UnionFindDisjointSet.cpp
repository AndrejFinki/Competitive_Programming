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