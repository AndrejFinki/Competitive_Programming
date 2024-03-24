#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)
const bool DEBUG = false;

struct Quest{
    int energy;
    int gold;

    Quest(){}
    Quest( int _energy, int _gold ) : energy(_energy), gold(_gold) {}

    const bool operator < ( const Quest &quest ) const {
        if( energy != quest.energy ) return energy < quest.energy;
        return gold < quest.gold;
    }

    const bool operator == ( const Quest &o ) const {
        return energy == o.energy && gold == o.gold;
    }

    friend ostream & operator << ( ostream &out, const Quest &o ) {
        return out << "[ " << o.energy << ", " << o.gold << " ]";
    }

};

void add_quest( int, int );
long long query( int );

multiset <Quest> quest_list;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    quest_list.insert( Quest( -1, -1 ) );

    int Q; cin >> Q;
    while( Q-- ){

        string cmd; cin >> cmd;

        if( cmd == "add" ){
            int energy, gold; cin >> energy >> gold;
            add_quest( energy, gold );
        }

        if( cmd == "query" ){
            int energy; cin >> energy;
            cout << query(energy) << endl;
        }

    }

}

void add_quest( int energy, int gold ){
    quest_list.insert( Quest( energy, gold ) );
}

long long query( int session_energy ){

    long long session_gold = 0;

    while( session_energy ){

        Quest search_q = Quest( session_energy, INF );

        if( DEBUG ){ for( auto it : quest_list ) cout << it << ' '; cout << endl; }
        
        set <Quest>::iterator find_q = quest_list.upper_bound( search_q );

        find_q--;

        if( find_q->energy == -1 || find_q->energy > session_energy ) break; 

        if( DEBUG ) cout << search_q << ' ' << *find_q << endl;

        session_energy -= find_q->energy;
        session_gold += find_q->gold;

        quest_list.erase( find_q );

    }

    return session_gold;

}
