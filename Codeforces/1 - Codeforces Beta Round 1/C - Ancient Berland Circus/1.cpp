#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-6)

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
void perpendicular_bisector( const Point &, const Point &, LD &, Point & );
void find_inner_circle( const Point &, const Point &, const Point &, Point &, LD & );
LD angle( const Point &, const Point & );
bool is_multiple( const LD &, const LD & );
LD polygon_area( const int &, const LD & );

vector <Point> points;

int main()
{
	get_input();

	Point circumcenter;
	LD circumradius;
	find_inner_circle( points[0], points[1], points[2], circumcenter, circumradius );

	cout << circumcenter.x << ' ' << circumcenter.y << endl;
	cout << circumradius << endl;

	/* TODO: 
	 * Now that we have the circumcenter and circumradius:
	 * 1 - Transpose all points so that the circumcenter is at (0, 0)
	 * 2 - Find the angle between points {1, 2}, {1, 3} as a1 and a2
	 * 3 - Find the first n, such that, m = 360 / n and both a1 and a2 are a multiple of m
	 */

	for( int i = 0 ; i < 3 ; i++ ) {
		points[i].x -= circumcenter.x;
		points[i].y -= circumcenter.y;
	}

	vector <LD> angles;
	for( int i = 0 ; i < 3 ; i++ )
		for( int j = i+1 ; j < 3 ; j++ )
			angles.push_back( angle( points[i], points[j] ) );


	for( int n = 3 ; n <= 100 ; n++ ) {
		
		bool valid = true;

		for( const LD &ang : angles ) {

			LD k = ang * n / 360.0;
			if( fabs( nearbyint( k ) - k ) < ERR ) continue;
			valid = false;
			break;

		}

		if( !valid ) continue;

		cout << polygon_area( n, circumradius ) << endl;
		return 0;

	}

	assert( false );

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
	assert( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y ) >= 0 );
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

void perpendicular_bisector(
	const Point &p1,
	const Point &p2,
	LD &slope,
	Point &mp
) {
	mp = midpoint( p1, p2 );
	if( p1.y == p2.y ) {
		slope = INFINITY;
	} else if( p1.x == p2.x ) {
		slope = 0;
	} else {
		assert( p2.x - p1.x );
		slope = ( p2.y - p1.y ) / ( p2.x - p1.x );
		assert( slope );
		slope = -1 / slope;
	}
}

void find_inner_circle(
	const Point &p1,
	const Point &p2,
	const Point &p3,
	Point &center,
	LD &radius
) {
	LD slope1, slope2;
	Point midpoint1, midpoint2;

	perpendicular_bisector( p1, p2, slope1, midpoint1 );
	perpendicular_bisector( p2, p3, slope2, midpoint2 );

	if( isinf( slope1 ) && isinf( slope2 ) ) {
		center.x = midpoint1.x;
		center.y = ( midpoint1.y + midpoint2.y ) / 2;
	} else if( !isinf( slope1 ) && isinf( slope2 ) ) {
		center.x = midpoint2.x;
		center.y = slope1 * ( center.x - midpoint1.x ) + midpoint1.y;
	} else if( isinf( slope1 ) && !isinf( slope2 ) ) {
		center.x = midpoint1.x;
		center.y = slope2 * ( center.x - midpoint2.x ) + midpoint2.y;
	} else {
		assert( slope1 - slope2 );
		center.x = ( midpoint2.y - midpoint1.y + slope1 * midpoint1.x - slope2 * midpoint2.x ) / ( slope1 - slope2 );
		center.y = slope1 * ( center.x - midpoint1.x ) + midpoint1.y;
	}

	radius = distance( center, p1 );
}

LD angle(
	const Point &p1,
	const Point &p2
) {
	LD ang = atan2( p1.y - p2.y, p1.x - p2.x );
	// while( ang < 0 ) ang += 360.0;
	// if( ang >= 360.0 ) ang -= 360.0;
	return ang;
}

bool is_multiple(
	const LD &v1,
	const LD &v2
) {
	int v = v1 / v2;
	return fabsf64x( v * v2 - v1 ) < ERR;
}

LD polygon_area(
	const int &n,
	const LD &circumradius
) {
	return n * circumradius * circumradius * sinf64x( 2 * M_PI / n ) / 2;
}
