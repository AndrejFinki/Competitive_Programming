#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct Team {
    int id;
    int solved;
    int penalty;

    Team(){}
    Team( int id, int solved, int penalty ) : id(id), solved(solved), penalty(penalty) {}

    const bool operator < ( const Team &o ) const {
        if( solved != o.solved ) return solved > o.solved;
        if( penalty != o.penalty ) return penalty < o.penalty;
        return id < o.id;
    }

    const bool operator == ( const Team &o ) const {
        return id == o.id && solved == o.solved && penalty == o.penalty;
    }
};

#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<Team, null_type, less<Team>, rb_tree_tag, tree_order_statistics_node_update> ost;

void update_rankings( int, int );
int get_team_rank();

const int maxN = 100005;
int N, M;
ost ranking;
Team team_info[maxN];

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    for( int i = 0 ; i < maxN ; i++ ) team_info[i] = Team( i, 0, 0 );

    cin >> N >> M;

    for( int i = 0 ; i < M ; i++ ){

        int t, p; cin >> t >> p;
        update_rankings(t, p);
        cout << get_team_rank() << endl;

    }

}

void update_rankings( int t, int p ){

    Team &current_team = team_info[t];

    ranking.erase( current_team );

    current_team.solved++;
    current_team.penalty += p;

    ranking.insert( current_team );

}

int get_team_rank(){

    return ranking.order_of_key( team_info[1] ) + 1;

}
