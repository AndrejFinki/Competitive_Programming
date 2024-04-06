#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

/* Geometry Library Begin */

class Point { public:
	LD x, y;

	Point() = default;
	Point( const LD &, const LD & );

	bool operator < ( const Point & ) const;
	bool operator == ( const Point & ) const;
};

class Vector { public:
	LD x, y;

	Vector() = default;
	Vector( const LD &, const LD & );

	LD operator * ( const Vector & ) const;
	LD modulo() const;
	LD modulo_nsq() const;
};

class Line_Segment { public:
	Point t1, t2;
	LD a, b, c;

	Line_Segment() = default;
	Line_Segment( const Point &, const Point & );

	LD length() const;
	bool contains( const Point & ) const;
	bool operator == ( const Line_Segment & ) const;
};

class Line { public:
	LD a, b, c;

	Line() = default;
	Line( const LD &, const LD &, const LD & );
	Line( const Point &, const Point & );
	Line( const Line_Segment & );

	bool operator == ( const Line & ) const;
	bool contains( const Point & ) const;
	void normalize();
	bool is_normalized() const;
	Line find_perpendicular( const Point & ) const;
	bool is_valid() const;
};

class Circle { public:
	Point o;
	LD r;

	Circle() = default;
	Circle( const LD & );
	Circle( const Point &, const LD & );
	Circle( const Point &, const Point &, const LD & );

	LD diameter() const;
	LD perimeter() const;
	LD area() const;
	LD arc( const LD & ) const;
	LD chord( const LD & ) const;
	LD sector( const LD & ) const;
	LD segment( const LD & ) const;
	bool contains( const Point & ) const;
	bool on( const Point & ) const;
};

class Geometry { public:
	static bool is_zero( const LD & );
	static bool are_equal( const LD &, const LD & );
	static bool less_than( const LD &, const LD & );
	static LD deg_to_rad( const LD & );
	static LD angle( const Point &, const Point &, const Point & );
	static LD distance( const Point &, const Point & );
	static LD ccw( const Point &, const Point &, const Point & );
	static bool collinear( const Point &, const Point &, const Point & );
	static Vector to_vector( const Point &, const Point & );
	static Vector scale( const Vector &, const LD & );
	static Point translate( const Point &, const Vector & );
	static Point intersection_point( const Line &, const Line & );
};

Circle::Circle( const LD &r ) : r(r) {
	o = Point( 0, 0 );
}
Circle::Circle( const Point &o, const LD &r ) : o(o), r(r){
}
Circle::Circle( const Point &p1, const Point &p2, const LD &r ) : r(r) {
	LD _T = ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.y ) * ( p1.y - p2.y );
	LD __T = r * r / _T - 0.25;
	if( Geometry::less_than( __T, 0 ) ) {
		o = Point( NAN, NAN );
		return;
	}
	LD h = sqrt( __T );
	o = Point(	( p1.x + p2.x ) * 0.5 + ( p1.y - p2.y ) * h,
				( p1.y + p2.y ) * 0.5 + ( p2.x - p1.x ) * h );
}
LD Circle::diameter() const {
	return 2 * r;
}
LD Circle::perimeter() const {
	return 2 * M_PI * r;
}
LD Circle::area() const {
	return M_PI * r * r;
}
LD Circle::arc( const LD &ang ) const {
	return ang * perimeter() / 360.0;
}
LD Circle::chord( const LD &ang ) const {
	return 2 * r * sin( Geometry::deg_to_rad( ang ) / 2 );
}
LD Circle::sector( const LD &ang ) const {
	return ang * area() / 360.0;
}
LD Circle::segment( const LD &ang ) const {
	LD s = ( r + r + chord( ang ) ) / 2;
	LD TA = sqrt( s * ( s - r ) * ( s - r ) * ( s - chord( ang ) ) );
	return sector( ang ) - TA;
}
bool Circle::contains( const Point &T ) const {
	return r * r - ( T.x - o.x ) * ( T.x - o.x ) - ( T.y - o.y ) * ( T.y - o.y ) > ERR;
}
bool Circle::on( const Point &T ) const {
	return Geometry::is_zero( r * r - ( T.x - o.x ) * ( T.x - o.x ) - ( T.y - o.y ) * ( T.y - o.y ) );
};

Line::Line( const LD &a, const LD &b, const LD &c ) : a(a), b(b), c(c) {
	normalize();
}
Line::Line( const Point &A, const Point &B ) {
	if( Geometry::are_equal( A.x, B.x ) ) {
		a = 1.0;
		b = 0.0;
		c = -A.x;
	} else {
		a = -( A.y - B.y ) / ( A.x - B.x );
		b = 1.0;
		c = -( a * A.x ) - A.y;
	}
}
Line::Line( const Line_Segment &LS ) {
	a = LS.a; b = LS.b; c = LS.c;
	normalize();
}
bool Line::operator == ( const Line &o ) const {
	assert( is_normalized() );
	assert( o.is_normalized() );
	return	Geometry::are_equal( a, o.a ) &&
			Geometry::are_equal( b, o.b ) &&
			Geometry::are_equal( c, o.c );
}
bool Line::contains( const Point &P ) const {
	return Geometry::is_zero( a*P.x + b*P.y + c );
}
void Line::normalize() {
	if( Geometry::is_zero( b ) ) return;
	a /= b;
	c /= b;
	b = 1.0;
}
bool Line::is_normalized() const {
	return	Geometry::is_zero( b ) ||
			Geometry::are_equal( b, 1.0 );
}
Line Line::find_perpendicular( const Point &M ) const {
	assert( is_normalized() );
	if( Geometry::is_zero( a ) ) return Line( 1, 0, -M.x );
	if( Geometry::is_zero( b ) ) return Line( 0, 1, -M.y );
	LD a2 = -1.0 / a;
	LD k2 = -M.y - a2 * M.x;
	return Line( a2, 1, k2 );
}
bool Line::is_valid() const {
	return !( Geometry::is_zero(a) && Geometry::is_zero(b) );
}

Point::Point( const LD &x, const LD &y ) : x(x), y(y) {
}
bool Point::operator < ( const Point &o ) const {
	if( !Geometry::are_equal( x, o.x ) ) return x < o.x;
	return y < o.y;
}
bool Point::operator == ( const Point &o ) const {
	return Geometry::are_equal( x, o.x ) && Geometry::are_equal( y, o.y );
}

Vector::Vector( const LD &x, const LD &y ) : x(x), y(y) {
}
LD Vector::operator * ( const Vector &o ) const {
	return x*o.x + y*o.y;
}
LD Vector::modulo() const {
	return sqrt( x*x + y*y );
}
LD Vector::modulo_nsq() const {
	return x*x + y*y;
}

Line_Segment::Line_Segment( const Point &t1, const Point &t2 ) : t1(t1), t2(t2) {
	if( Geometry::are_equal( t1.x, t2.x ) ) {
		a = 1.0;
		b = 0.0;
		c = -t1.x;
	} else {
		a = -( t1.y - t2.y ) / ( t1.x - t2.x );
		b = 1.0;
		c = -( a * t1.x ) - t1.y;
	}
}
LD Line_Segment::length() const {
	return Geometry::to_vector( t1, t2 ).modulo();
}
bool Line_Segment::contains( const Point &P ) const {
	if( !Geometry::is_zero( a * P.x + b * P.y + c ) ) return false;
	LD Lx = min( t1.x, t2.x );
	LD Rx = max( t1.x, t2.x );
	LD Ly = min( t1.y, t2.y );
	LD Ry = max( t1.y, t2.y );
	return 	( Lx < P.x || Geometry::are_equal( Lx, P.x ) ) &&
			( P.x < Rx || Geometry::are_equal( P.x, Rx ) ) &&
			( Ly < P.y || Geometry::are_equal( Ly, P.y ) ) &&
			( P.y < Ry || Geometry::are_equal( P.y, Ry ) );

}
bool Line_Segment::operator == ( const Line_Segment &o ) const {
	return 	Geometry::are_equal( a, o.a ) &&
			Geometry::are_equal( b, o.b ) && 
			Geometry::are_equal( c, o.c ) && 
			t1 == o.t1 && t2 == o.t2;
}

bool Geometry::is_zero( const LD &v ) {
	return fabs( v ) < ERR;
}
bool Geometry::are_equal( const LD &v1, const LD &v2 ) {
	return is_zero( v1 - v2 );
}
bool Geometry::less_than( const LD &v1, const LD &v2 ) {
	return v1 < v2 - ERR;
}
LD Geometry::deg_to_rad( const LD &deg ) {
	return deg * M_PI / 180.0;
}
LD Geometry::angle( const Point &A, const Point &O, const Point &B ) {
	Vector OA = Geometry::to_vector( O, A );
	Vector OB = Geometry::to_vector( O, B );
	return acos( OA * OB / sqrt( OA.modulo_nsq() * OB.modulo_nsq() ) ) * 180.0 / M_PI;
}
LD Geometry::distance( const Point &A, const Point &B ) {
	return sqrt( ( A.x - B.x ) * ( A.x - B.x ) + ( A.y - B.y ) * ( A.y - B.y ) );
}
LD Geometry::ccw( const Point &A, const Point &B, const Point &C ) {
	LD cross_p = Geometry::cross( Geometry::to_vector( A, B ), Geometry::to_vector( A, C ) );
	return cross_p > 0 || Geometry::is_zero( cross_p );
}
bool Geometry::collinear( const Point &A, const Point &B, const Point &C ) {
	return Geometry::is_zero( Geometry::point_side( A, B, C ) );
}
Vector Geometry::to_vector( const Point &A, const Point &B ) {
	return Vector( B.x - A.x , B.y - A.y );
}
Vector Geometry::scale( const Vector &V, const LD &S ) {
	return Vector( V.x * S, V.y * S );
}
Point Geometry::translate( const Point &P, const Vector &V ) {
	return Point( P.x + V.x, P.y + V.y );
}
Point Geometry::intersection_point( const Line &A, const Line &B ) {
	Point P;
    if( !A.is_valid() || !B.is_valid() ) return Point( NAN, NAN );
    if( Geometry::are_parallel(A, B) ) return Point( NAN, NAN );
    P.x = ( B.b * A.c - A.b * B.c ) / ( B.a * A.b - A.a * B.b );
    if( !Geometry::is_zero( A.b ) )
		P.y = -( A.a * P.x + A.c );
    else
		P.y = -( B.a * P.x + B.c );
    return P;
}

/* Geometry Library End */

int main()
{
	ios::sync_with_stdio( false );

	cout << "Hello imi!" << endl;
}