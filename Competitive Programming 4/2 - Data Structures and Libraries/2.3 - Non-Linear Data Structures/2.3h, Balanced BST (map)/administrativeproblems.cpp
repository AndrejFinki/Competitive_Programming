#include<bits/stdc++.h>
using namespace std;
#define ERR 1e-7

struct Car {
    string car_name = "";
    int catalog_cost = 0;
    int pickup_cost = 0;
    int kilometer_cost = 0;
};

struct Event {
    int event_time = 0;
    string spy_name = "";
    char event_type = 0;
    string pickup_name = "none";
    int distance = -1;
    int severity = -1;
};

struct Spy {
    bool consistent = true;
    int total_cost = 0;
    Car current_car = Car();
    bool has_car = false;
};

void solve();

int N, M;
map <string, Car> car_list;
map <string, Spy> spy_list;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    for( int TC = 1 ; TC <= t ; TC++ ){

        car_list.clear();
        spy_list.clear();

        solve();

    }

}

void solve(){

    function <void()> input_next_car = []() -> void {
        Car rv;
        cin >> rv.car_name >> rv.catalog_cost >> rv.pickup_cost >> rv.kilometer_cost;
        car_list[rv.car_name] = rv;
    };

    function <Event()> input_next_event = []() -> Event {
        Event rv;
        cin >> rv.event_time >> rv.spy_name >> rv.event_type;
        if( rv.event_type == 'p' ) cin >> rv.pickup_name;
        if( rv.event_type == 'r' ) cin >> rv.distance;
        if( rv.event_type == 'a' ) cin >> rv.severity;
        return rv;
    };

    function <void(const Event &)> pick_up = []( const Event &e ) -> void {
        Spy &spy = spy_list[e.spy_name];
        Car &car = car_list[e.pickup_name];
        if( spy.has_car ){
            spy.consistent = false; return;
        }
        spy.has_car = true;
        spy.current_car = car;
        spy.total_cost += car.pickup_cost;
    };

    function <void(Event)> return_car = []( Event e ) -> void {
        Spy &spy = spy_list[e.spy_name];
        int km = e.distance;
        if( !spy.has_car ){
            spy.consistent = false; return;
        }
        spy.has_car = false;
        Car &car = spy.current_car;
        spy.total_cost += km * car.kilometer_cost;
        car = Car();
    };

    function <void(Event)> accident = []( Event e ) -> void {
        Spy &spy = spy_list[e.spy_name];
        int severity = e.severity;
        if( !spy.has_car ){
            spy.consistent = false; return;
        }
        Car &car = spy.current_car;
        spy.total_cost += ceil((double)(car.catalog_cost) / 100 * severity - ERR);
    };

    cin >> N >> M;

    for( int i = 0 ; i < N ; i++ ) input_next_car();

    for( int i = 0 ; i < M ; i++ ){

        Event e = input_next_event();

        if( e.event_type == 'p' ) pick_up(e);
        if( e.event_type == 'r' ) return_car(e);
        if( e.event_type == 'a' ) accident(e);

    }

    for( pair <string, Spy> p : spy_list ){
        Spy spy = p.second;
        if( spy.has_car ) spy.consistent = false;
        cout << p.first << ' ' << ( spy.consistent ? to_string(spy.total_cost) : "INCONSISTENT" ) << endl;
    }

}
