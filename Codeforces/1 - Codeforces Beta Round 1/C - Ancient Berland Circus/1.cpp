#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)

class Point {

public:
	Point() = default;
	Point(
		const LD &_x,
		const LD &_y
	) : x(_x), y(_y) {}

	LD x;
	LD y;

};

void get_input();
LD distance( const Point &, const Point & );
Point midpoint( const Point &, const Point & );


vector <Point> points;

int main()
{
	get_input();


}

void get_input()
{
	LD x, y;
	while( cin >> x >> y ) {
		points.push_back( Point( x, y ) );
	}
}

LD distance (
	const Point &p1,
	const Point &p2
) {
	return sqrt( 
		( p1.x - p2.x ) * ( p1.x - p2.x ) +
		( p1.y - p2.y ) * ( p1.y - p2.y )
	);
}

Point midpoint (
	const Point &p1,
	const Point &p2
) {
	return Point (
		( p1.x + p2.x ) / 2,
		( p1.y + p2.y ) / 2
	);
}
