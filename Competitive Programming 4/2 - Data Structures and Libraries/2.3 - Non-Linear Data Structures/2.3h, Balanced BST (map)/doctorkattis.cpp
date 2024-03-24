#include<bits/stdc++.h>
using namespace std;

struct Cat{
    string cat_name;
    int severity = 0;
    int arrive_time = 0;

    Cat(){}
    Cat( string cat_name, int severity, int arrive_time ) : cat_name(cat_name), severity(severity), arrive_time(arrive_time) {}

    const bool operator < ( const Cat &cat ) const {
        if( severity != cat.severity ) return severity > cat.severity;
        return arrive_time < cat.arrive_time;
    }

    const bool operator == ( const Cat &cat ) const {
        return cat_name == cat.cat_name && severity == cat.severity && arrive_time == cat.arrive_time;
    }
};

void arrive_at_clinic( string, int );
void update_infection_level( string, int );
void treated( string );
void query();

int N;
set <Cat> pq;
map <string, Cat> cat_info;
int arrive_idx = 1;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    while( N-- ){

        int command; cin >> command;

        if( command == 0 ){
            string cat_name;
            int infection_level;
            cin >> cat_name >> infection_level;
            arrive_at_clinic( cat_name, infection_level );
        }

        if( command == 1 ){
            string cat_name;
            int increase_infection;
            cin >> cat_name >> increase_infection;
            update_infection_level( cat_name, increase_infection );
        }

        if( command == 2 ){
            string cat_name;
            cin >> cat_name;
            treated( cat_name );
        }

        if( command == 3 ){
            query();
        }

    }

}

void arrive_at_clinic( string cat_name, int infection_level ){
    Cat cat = Cat( cat_name, infection_level, arrive_idx++ );
    cat_info[cat_name] = cat;
    pq.insert(cat);
}

void update_infection_level( string cat_name, int increase_infection ){
    Cat cat = cat_info[cat_name];
    pq.erase(cat);
    cat.severity += increase_infection;
    cat_info[cat_name] = cat;
    pq.insert(cat);
}

void treated( string cat_name ){
    Cat cat = cat_info[cat_name];
    pq.erase(cat);
}

void query(){
    if( pq.empty() ) cout << "The clinic is empty" << endl;
    else             cout << pq.begin()->cat_name << endl;
}
