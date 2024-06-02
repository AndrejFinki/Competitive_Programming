#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

const int maxN = 100005;
int N, M;
int dset[2*maxN];
int elements[2*maxN];
LL sum[2*maxN];

void reset_set();
void merge_set( int, int );
bool are_same_set( int, int );
int find_set( int );
void move_element( int, int );

int main()
{
	ios::sync_with_stdio( false );
	while( cin >> N >> M ) {
		reset_set();
		for( int i = 0 ; i < M ; i++ ) {
			int op, p, q;
			cin >> op >> p;
			if( op != 3 ) cin >> q; 
			switch( op ) {
				case 1:
					merge_set( p, q );
					break;
				
				case 2:
					move_element( p, q );
					break;

				case 3:
					int p_set = find_set(p);
					cout << elements[p_set] << ' ' << sum[p_set] << endl;
					break;
			}
		}
	} 
}

void move_element(
	int p,
	int q
) {
	if( are_same_set( p, q ) )
		return;
	int p_set = find_set(p);
	q = find_set(q);

	dset[p] = q;
	elements[p_set]--;
	elements[q]++;
	sum[p_set] -= p;
	sum[q] += p;
}

int find_set(
	int p
) {
	if( dset[p] == p )
		return p;
	return dset[p] = find_set( dset[p] ); 
}

bool are_same_set(
	int p,
	int q
) {
	return find_set( p ) == find_set( q );
}

void merge_set(
	int p,
	int q
) {
	if( are_same_set( p, q ) )
		return;
	p = find_set( p );
	q = find_set( q );

	dset[q] = p;
	elements[p] += elements[q];
	sum[p] += sum[q];
}

void reset_set()
{
	for( int i = 0 ; i < maxN ; i++ ) {
		dset[i] = maxN + i;
		dset[ dset[i] ] = dset[i];
		elements[ dset[i] ] = 1;
		sum[ dset[i] ] = i;
	}
}
