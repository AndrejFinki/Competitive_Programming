#include<bits/stdc++.h>
using namespace std;
#define LL long long

void getPointsAtCorrectDistance();
int countConnections(pair<int,int>);

const int maxN = 100005;
int N;
pair <int, int> pairList[maxN];
set < pair<int, int> > pointSet;
vector < pair<int, int> > correctDistancePoints;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    getPointsAtCorrectDistance();

    cin >> N;

    for( int i = 0 ; i < N ; i++ ){ cin >> pairList[i].first >> pairList[i].second; pointSet.insert( pairList[i] ); }

    int rv = 0;
    for( int i = 0 ; i < N ; i++ ){
        rv += countConnections( pairList[i] );
    }

    cout << rv/2 << endl;

}

int countConnections( pair <int, int> p ){
    set < pair<int, int> > temp_set;
    for( const pair <int, int> &cdp : correctDistancePoints ){
        if( pointSet.count( { p.first + cdp.first, p.second + cdp.second } ) ) temp_set.insert( { p.first + cdp.first, p.second + cdp.second } );
        if( pointSet.count( { p.first - cdp.first, p.second + cdp.second } ) ) temp_set.insert( { p.first - cdp.first, p.second + cdp.second } );
        if( pointSet.count( { p.first + cdp.first, p.second - cdp.second } ) ) temp_set.insert( { p.first + cdp.first, p.second - cdp.second } );
        if( pointSet.count( { p.first - cdp.first, p.second - cdp.second } ) ) temp_set.insert( { p.first - cdp.first, p.second - cdp.second } );
    }
    return temp_set.size();
}

void getPointsAtCorrectDistance(){
    for( LL x = 0 ; x <= 2018 ; x++ ) for( LL y = 0 ; y <= 2018 ; y++ ){
        LL dist = x*x + y*y;
        if( dist == 2018*2018 ) correctDistancePoints.push_back( {x, y} );
    }
}
