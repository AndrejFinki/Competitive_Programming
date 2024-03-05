#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

const int maxK = 15;
const int maxN = 10;
const int maxM = maxK * maxK * maxN;

struct Flight{
    int idx;
    int source;
    int dest;
    int day;
    int capacity;

    const bool operator < ( const Flight &o ) const{
        if( day != o.day ) return day < o.day;
        return idx < o.idx;
    }
};

struct Airport{
    int idx = -1;
    int people = 0;
    int new_arrivals[maxN] = {};
};

bool is_optimal();

int K, N, M;
Airport airport_list[maxK];
Flight flight_list[maxM];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> K >> N >> M;

    for( int i = 1 ; i <= K ; i++ ){
        Airport &A = airport_list[i];
        A.idx = i;
        A.people = 0;
    }

    for( int i = 0 ; i < M ; i++ ){
        Flight &F = flight_list[i];
        cin >> F.source >> F.dest >> F.day >> F.capacity;
    }

    for( int i = 0 ; i < K*N ; i++ ){
        int airport, day, people;
        cin >> airport >> day >> people;
        airport_list[airport].new_arrivals[day] += people;
    }

    sort( flight_list, flight_list + M );

    cout << ( is_optimal() ? "optimal" : "suboptimal" ) << endl;

}

bool is_optimal(){

    for( int day = 1 ; day <= N ; day++ ){

        for( int i = 1 ; i <= K ; i++ ){
            Airport &A = airport_list[i];
            A.people += A.new_arrivals[day];
        }

        bool can_do_all_flights = true;
        for( int i = 0 ; i < M ; i++ ){
            Flight &F = flight_list[i];
            if( F.day != day ) continue;
            if( airport_list[F.source].people < F.capacity ){
                can_do_all_flights = false; break;
            }
            airport_list[F.source].people -= F.capacity;
        }

        if( !can_do_all_flights ) return false;

        for( int i = 0 ; i < M ; i++ ){
            Flight &F = flight_list[i];
            if( F.day != day ) continue;
            airport_list[F.dest].people += F.capacity;
        }

    }

    return true;

}
