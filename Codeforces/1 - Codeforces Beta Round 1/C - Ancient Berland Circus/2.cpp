#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)

class Point {
public:
	LD x, y;
	Point();
	Point( const LD &, const LD & );
	bool operator < ( const Point & ) const;
	bool operator == ( const Point & ) const;
};

class Line {
public:
	LD a, b, c;
	Line();
	Line( const Point &, const Point & );
	void normalize();
	bool operator == ( const Line & ) const;
};

class Vector {
public:
	LD x, y;
	Vector();
	Vector( const LD &, const LD & );
};

class Geometry {
public:
	static constexpr LD precision = 1e-9;
	static bool is_zero( const LD & );
	static bool are_equal( const LD &, const LD & );
	static bool less_than( const LD &, const LD & );
	static LD point_distance( const Point &, const Point & );
	static LD deg_to_rad( const LD & );
	static Point rotate_wrt_origin( const Point &, const LD & );
	static void points_to_line( const Point &, const Point &, Line & );
	static bool are_lines_parallel( const Line &, const Line & );
	static bool line_intersection( const Line &, const Line &, Point & );
	static Vector points_to_vector( const Point &, const Point & );
	static Vector scale_vector( const Vector &, const LD & );
	static Point translate_point( const Point &, const Vector & );
	static LD dot_product( const Vector &, const Vector & );
	static LD vector_norm_sq( const Vector & );
	static LD dist_point_to_line( const Point &, const Point &, const Point &, Point & );
	static LD dist_point_to_segment( const Point &, const Point &, const Point &, Point & );
	static LD angle( const Point &, const Point &, const Point & );
	static LD cross_product( const Vector &, const Vector & );
	static bool ccw( const Point &, const Point &, const Point & );
	static bool ccw_cl( const Point &, const Point &, const Point & );
	static bool collinear( const Point &, const Point &, const Point & );
};

class Shapes {
public:
	static int inside_circle( const Point &, const Point &, const LD & );
	static bool circle_from_two_points( const Point &, const Point &, const LD &, Point & );
};

Point::Point() {
	x = y = 0;
}
Point::Point( const LD &vx, const LD &vy ) {
	x = vx;
	y = vy;
}
bool Point::operator < ( const Point &p ) const {
	if( !Geometry::are_equal( x, p.x ) )
		return x < p.x;
	return y < p.y;
}
bool Point::operator == ( const Point &p ) const {
	return Geometry::are_equal( x, p.x ) && Geometry::are_equal( y, p.y );
}

Line::Line() {
	a = b = c = 0;
}
Line::Line( const Point &p1, const Point &p2 ) {
	Geometry::points_to_line( p1, p2, *this );
}
void Line::normalize() {
	a /= b;
	c /= b;
	b = 1;
}
bool Line::operator == ( const Line &l ) const {
	return Geometry::are_lines_parallel( *this, l ) && Geometry::are_equal( c, l.c );
}

Vector::Vector() {
	x = y = 0;
}
Vector::Vector( const LD &vx, const LD &vy ) {
	x = vx;
	y = vy;
}

bool Geometry::is_zero( const LD &p ) {
	return fabs( p ) < Geometry::precision;
}
bool Geometry::are_equal( const LD &p, const LD &q ) {
	return fabs( p - q ) < Geometry::precision;
}
bool Geometry::less_than( const LD &p, const LD &q ) {
	return p + Geometry::precision < q;
}
LD Geometry::point_distance( const Point &p, const Point &q ) {
	return hypot( p.x - q.x, p.y - q.y );
}
LD Geometry::deg_to_rad( const LD &ang ) {
	return ang * M_PI / 180.0;
}
Point Geometry::rotate_wrt_origin( const Point &p, const LD &ang ) {
	LD rad = Geometry::deg_to_rad( ang );
	return Point(
		p.x * cos( rad ) - p.y * sin( rad ),
		p.x * sin( rad ) + p.y * cos( rad )
	);
}
void Geometry::points_to_line( const Point &p, const Point &q, Line &line ) {
	if( Geometry::are_equal( p.x, q.x ) ) {
		line.a = 1;
		line.b = 0;
		line.c = -p.x;
	} else {
		line.a = -( p.y - q.y ) / ( p.x - q.x );
		line.b = 1;
		line.c = -( line.a * p.x ) - p.y;
	}
}
bool Geometry::are_lines_parallel( const Line &l1, const Line &l2 ) {
	return Geometry::are_equal( l1.a, l2.a ) && Geometry::are_equal( l1.b, l2.b );
}
bool Geometry::line_intersection( const Line &l1, const Line &l2, Point &p ) {
	if( Geometry::are_lines_parallel( l1, l2 ) ) return false;
	p.x = ( l2.b * l1.c - l1.b * l2.c ) / ( l2.a * l1.b - l1.a * l2.b );
	p.y = ( Geometry::is_zero( l1.b ) ? -( l2.a * p.x + l2.c ) : -( l1.a * p.x + l1.c ) );
	return true; 
}
Vector Geometry::points_to_vector( const Point &p, const Point &q ) {
	return Vector( q.x - p.x, q.y - p.y );
}
Vector Geometry::scale_vector( const Vector &v, const LD &s ) {
	return Vector( v.x * s, v.y * s );
}
Point Geometry::translate_point( const Point &p, const Vector &v ) {
	return Point( p.x + v.x, p.y + v.y );
}
LD Geometry::dot_product( const Vector &v1, const Vector &v2 ) {
	return ( v1.x * v2.x + v1.y * v2.y );
}
LD Geometry::vector_norm_sq( const Vector &v ) {
	return v.x * v.x + v.y * v.y;
}
LD Geometry::dist_point_to_line( const Point &p, const Point &a, const Point &b, Point &c ) {
	Vector ap = Geometry::points_to_vector( a, p );
	Vector ab = Geometry::points_to_vector( a, b );
	LD u = Geometry::dot_product( ap, ab ) / Geometry::vector_norm_sq( ab );
	c = Geometry::translate_point( a, Geometry::scale_vector( ab, u ) );
	return Geometry::point_distance( p, c );
}
LD Geometry::dist_point_to_segment( const Point &p, const Point &a, const Point &b, Point &c ) {
	Vector ap = Geometry::points_to_vector( a, p );
	Vector ab = Geometry::points_to_vector( a, b );
	LD u = Geometry::dot_product( ap, ab ) / Geometry::vector_norm_sq( ab );
	if( u < 0.0 ) {
		c = Point( a.x, a.y );
		return Geometry::point_distance( p, a );
	} 
	if( u > 1.0 ) {
		c = Point( b.x, b.y );
		return Geometry::point_distance( p, b );
	}
	return Geometry::dist_point_to_line( p, a, b, c );
}
LD Geometry::angle( const Point &a, const Point &o, const Point &b ) {
	Vector oa = Geometry::points_to_vector( o, a );
	Vector ob = Geometry::points_to_vector( o, b );
	return acos( 
		Geometry::dot_product( oa, ob ) / 
		sqrt( Geometry::vector_norm_sq( oa ) * Geometry::vector_norm_sq( ob ) ) 
	);
}
LD Geometry::cross_product( const Vector &a, const Vector &b ) {
	return a.x * b.y - a.y * b.x;
}
bool Geometry::ccw( const Point &p, const Point &q, const Point &r ) {
	return Geometry::cross_product(
		Geometry::points_to_vector( p, q ), Geometry::points_to_vector( p, r )
	) > Geometry::precision;
}
bool Geometry::ccw_cl( const Point &p, const Point &q, const Point &r ) {
	return Geometry::cross_product(
		Geometry::points_to_vector( p, q ), Geometry::points_to_vector( p, r )
	) > -Geometry::precision;
}
bool Geometry::collinear( const Point &p, const Point &q, const Point &r ) {
	return Geometry::is_zero( Geometry::cross_product( 
			Geometry::points_to_vector( p, q ), Geometry::points_to_vector( p, r ) 
		)
	);
}

int Shapes::inside_circle( const Point &p, const Point &c, const LD &r ) {
	LD dx = p.x - c.x;
	LD dy = p.y - c.y;
	LD euc = dx * dx + dy * dy;
	LD rsq = r * r;
	return Geometry::less_than( euc, rsq ) ? 0 : Geometry::are_equal( euc, rsq ) ? 1 : 2;
}
bool Shapes::circle_from_two_points( const Point &p1, const Point &p2, const LD &r, Point &c ) {
	LD d2 = ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y );
	LD det = r * r / d2 - 0.25;
	if( det < 0 ) return false;
	LD h = sqrt( det );
	c.x = ( p1.x + p2.x ) * 0.5 + ( p1.y - p2.y ) * h;
	c.y = ( p1.y + p2.y ) * 0.5 + ( p2.x - p1.x ) * h;
	return true;
}

int main()
{
	cout << "imi" << endl;
}
