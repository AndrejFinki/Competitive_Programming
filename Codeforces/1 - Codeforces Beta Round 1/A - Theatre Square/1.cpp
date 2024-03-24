#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)

int main()
{
	LL n, m, a;
	cin >> n >> m >> a;

	cout << ( n/a + bool( n % a ) ) * ( m/a + bool( m % a ) ) << endl;
}
