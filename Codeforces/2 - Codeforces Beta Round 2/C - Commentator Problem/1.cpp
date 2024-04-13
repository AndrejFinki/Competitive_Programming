#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define INF (1<<30)
#define ERR (1e-9)
#define endl '\n'

int main()
{
	ios::sync_with_stdio( false );
	
}

/*
	Let R be the distance from point А to a circle with center О and radius r. From this point the circle is observed at the angle 
	2*arcsin( r / R ).

	Circle center: O1, O2, O3 - known
	Circle radius: r1, r2, r3 - known
	Distance to center: R1, R2, R3 - unknown
	ri > 0, Ri > 0, ri/Ri < 1

	r1/R1 = r2/R2 = r3/R3

	Let's find all the points that look at two circles at the same angle.

	if r1 == r2:
		This is the perpendicular bisector of the line between O1, O2
	else
		There is a circle that describes where this point lies

	Find the point space for circles 1 and 2, and circles 2 and 3.
	Any intersections between these two spaces should contain the valid results.
	
*/