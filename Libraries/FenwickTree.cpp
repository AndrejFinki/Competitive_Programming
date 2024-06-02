#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

class FenwickTree {
public:
	FenwickTree() = default;
	FenwickTree( const int *, const int );

	static constexpr int FENWICK_MAX_ELEMENTS = 100005;
	int ft[ FENWICK_MAX_ELEMENTS ] = {};
};

FenwickTree::FenwickTree( const int *f, const int f_size ) {
	for( int i = 1 ; i <= f_size ; i++ ) {
		ft[i] += f[i];
		
	}
}

int main()
{
	ios::sync_with_stdio( false );
	cin.tie( NULL );
	cout.tie( NULL );
	
}
