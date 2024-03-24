#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define INF ((1LL<<61)+(1LL<<30)-1)
#define LD long double
#define endl '\n'
#define print(x) "[ " << #x << ": " << x << " ]" << flush
#define printW(x,y) "[ " << #x << ": " << setw(y) << x << " ]" << flush
#define printE(a,x) "[ " << #a << "[" << x << "]: " << a[x] << " ]" << flush
#define printV(v)   cout << "[ " << #v << ": "; for(auto _i : v) cout << _i << ' '; cout << "]" << flush << endl
#define printA(a,n) cout << "[ " << #a << ": "; for(int i=0;i<n;i++) cout << a[i] << ' '; cout << "]" << flush << endl
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
const LD ERR = 1e-7; const int MOD = 1e9 + 7; bool areEqual( LD _n1, LD _n2 ){ return fabs( _n1 - _n2 ) < ERR; } bool smallerEqual( LD _n1, LD _n2 ){ return _n1 < _n2 || areEqual( _n1, _n2 ); }
int modSum( LL _n1, LL _n2 ){ return ( _n1 + _n2 ) % MOD; } int modProd( LL _n1, LL _n2 ){ return ( _n1 * _n2 ) % MOD; }
#ifdef debug
    const bool DEBUG = true;
#else
    const bool DEBUG = false;
#endif

/* CALENDAR LIBRARY */

struct Calendar{ // Months start from 1 and go to 12
    const int DAYS[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    const string WEEKDAY_NAMES[8] = { "None", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    string MONTH_NAMES[13] = { "None", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    map <string, int> MONTH_TO_IDX = { { "January", 1 }, { "February", 2 }, { "March", 3 }, { "April", 4 }, { "May", 5 }, { "June", 6 }, { "July", 7 }, { "August", 8 }, { "September", 9 }, { "October", 10 }, { "November", 11 }, { "December", 12 } };
    bool isLeap( int Y ){ return !(Y%400) || (!(Y%4)&&(Y%100)); }
    int daysInMonth( int M, int Y ){ return DAYS[isLeap(Y)][M]; }
};
struct Date : Calendar{
    int D=0, M=0, Y=0;
    Date(){ D = M = Y = 0; }
    Date( int d, int m, int y ) : D(d), M(m), Y(y) {}
    Date( string date_string ){ this->stringToDate(date_string); }
    Date( string date_string, string format_string ){ this->stringToDate(date_string,format_string); }
    void advanceDay();
    void advanceDay( int );
    void retractDay();
    void retractDay( int );
    string returnDate( string PRINT_FORMAT );
    void stringToDate( string DATE_STRING );
    void stringToDate( string DATE_STRING, string FORMAT_STRING );
    bool isValid();
    const bool operator == ( const Date &o ) const{ return D == o.D && M == o.M && Y == o.Y; }
    const bool operator < ( const Date &o ) const{ if( Y != o.Y ) return Y < o.Y; if( M != o.M ) return M < o.M; return D < o.D; }
    const bool operator <= ( const Date &o ) const{ return *this == o || *this < o; }
    const bool operator != ( const Date &o ) const{ return !( *this == o ); }
    Date operator = ( const Date &o ) { this->D = o.D; this->M = o.M; this->Y = o.Y; return o; }
};

void Date::advanceDay(){
    if( ++D > daysInMonth(M,Y) ){ D = 1; if( ++M == 13 ){ M = 1; Y++; } }
}
void Date::advanceDay( int DAYS_TO_ADVANCE ){
    const int DAYS_400_YEAR_BATCH = 146100-3;
    while( DAYS_TO_ADVANCE > 0 ){
        if( DAYS_TO_ADVANCE >= DAYS_400_YEAR_BATCH ){
            int K = DAYS_TO_ADVANCE / DAYS_400_YEAR_BATCH;
            Y += 400*K;
            DAYS_TO_ADVANCE %= DAYS_400_YEAR_BATCH;
            continue;
        }
        advanceDay();
        DAYS_TO_ADVANCE--;
    }
}
void Date::retractDay(){ 
    if( !(--D) ){ if( !(--M) ){ Y--; M = 12; } D = daysInMonth(M,Y); }
}
void Date::retractDay( int DAYS_TO_RETRACT ){
    while( DAYS_TO_RETRACT-- >= 0 ) retractDay();
}
string Date::returnDate( string PRINT_FORMAT ){
    bool isSpecialChar[256] = {};
    isSpecialChar['D'] = isSpecialChar['M'] = isSpecialChar['Y'] = isSpecialChar['m'] = true;
    int LEN = PRINT_FORMAT.length();
    stringstream SS;
    for( int i = 0 ; i < LEN ; i++ ){
        if( PRINT_FORMAT[i] != '|' ){ SS << PRINT_FORMAT[i]; continue; }
        if( i+1 >= LEN || !isSpecialChar[PRINT_FORMAT[i+1]] ){ SS << PRINT_FORMAT[i]; continue; }
        i++;
        if( PRINT_FORMAT[i] == 'D' )      SS << setw(2) << setfill('0') << D;
        else if( PRINT_FORMAT[i] == 'M' ) SS << setw(2) << setfill('0') << M;
        else if( PRINT_FORMAT[i] == 'Y' ) SS << Y;
        else if( PRINT_FORMAT[i] == 'm' ) SS << MONTH_NAMES[M];
    }
    return SS.str();
    /*
        SPECIAL CHARACTER '|' LEGEND:
        D - Day
        M - Month
        Y - Year
        m - Month with letters
    */
}
void Date::stringToDate( string DATE_STRING ){ // ASSUMES FORMAT DD/MM/YYYY 
    for( char &c : DATE_STRING ) if( !isalnum(c) ) c = ' ';
    stringstream SS(DATE_STRING);
    SS >> D >> M >> Y; 
}
void Date::stringToDate( string DATE_STRING, string FORMAT_STRING ){ // SAME FORMAT USED IN printDate()
    for( char &c : DATE_STRING ) if( !isalnum(c) ) c = ' ';
    stringstream SS(DATE_STRING);
    for( char c : FORMAT_STRING ){
        if( c == 'D' ) SS >> D;
        else if( c == 'M' ) SS >> M;
        else if( c == 'Y' ) SS >> Y;
        else if( c == 'm' ){
            string temp_name;
            SS >> temp_name;
            M = MONTH_TO_IDX[temp_name];
        }
    }
}
bool Date::isValid(){
    if( Y < 0 ) return false;
    if( !( M >= 1 && M <= 12 ) ) return false;
    return ( D >= 1 && D <= daysInMonth(M,Y) );
}

const Calendar GENERAL_CALENDAR;

/* CALENDAR LIBRARY */

/* TIME LIBRARY */

struct TimeZones{
    map <string, int> timeZones;
    TimeZones(){
        timeZones["GMT" ] = +0; timeZones["BST" ] = +10; timeZones["IST" ] = +10; timeZones["WET" ] = +0; timeZones["WEST"] = +10; timeZones["CET" ] = +10; timeZones["CEST"] = +20; timeZones["EET" ] = +20; timeZones["EEST"] = +30; timeZones["MSK" ] = +30; timeZones["MSD" ] = +40; timeZones["AST" ] = -40; timeZones["ADT" ] = -30; timeZones["NST" ] = -35; timeZones["NDT" ] = -25; timeZones["EST" ] = -50; timeZones["EDT" ] = -40; timeZones["CST" ] = -60; timeZones["CDT" ] = -50; timeZones["MST" ] = -70; timeZones["MDT" ] = -60; timeZones["PST" ] = -80; timeZones["PDT" ] = -70; timeZones["HST" ] = -100; timeZones["AKST"] = -90; timeZones["AKDT"] = -80; timeZones["AEST"] = +100; timeZones["AEDT"] = +110; timeZones["ACST"] = +95; timeZones["ACDT"] = +105; timeZones["AWST"] = +80;
    }
};
struct Time{
    int H = 0, M = 0, S = 0;
    string timeZone = "UTC";
    Time(){}
    Time( int h, int m ) : H(h), M(m), S(0) {}
    Time( int h, int m, int s ) : H(h), M(m), S(s) {}
    Time( string ts ) { this->stringToTime(ts); }
    void stringToTime( string );
    void advanceTime( Time );
    void changeTimeZone( string );
    void changeToUTC();
    string returnTime( bool );
    string returnTimeAMPM();
    int toSeconds();
    const bool operator == ( const Time &o ) const{ return H == o.H && M == o.M && S == o.S; }
    const bool operator != ( const Time &o ) const{ return !(*this == o); }
    const bool operator < ( const Time &o ) const{ if( H != o.H ) return H < o.H; if( M != o.M ) return M < o.M; return S < o.S; } 
}; 

TimeZones TIME_ZONES;
const Time ONE_SECOND(0,0,1), ONE_MINUTE(0,1,0), ONE_HOUR(1,0,0);

void Time::stringToTime( string ts ){ // ASSUMES FORMAT HH:MM:SS
    for( char &c : ts ) if( !isdigit(c) ) c = ' '; 
    stringstream SS(ts); SS >> H >> M >> S;
}
void Time::advanceTime( Time T ){
    while( T.S ){
        if( T.S > 0 ){ S++; T.S--; }
        else{ S--; T.S++; }
        if( S >= 60 ){ T.M++; S = 0; }
        if( S < 0 ){ T.M--; S = 59; }
    }
    while( T.M ){
        if( T.M > 0 ){ M++; T.M--; }
        else{ M--; T.M++; }
        if( M >= 60 ){ T.H++; M = 0; }
        if( M < 0 ){ T.H--; M = 59; }
    }
    while( T.H ){
        if( T.H > 0 ){ H++; T.H--; }
        else{ H--; T.H++; }
        H = ( (H % 24) + 24 ) % 24;
    }
}
void Time::changeTimeZone( string Z2 ){
    changeToUTC();
    int timeChange = TIME_ZONES.timeZones[Z2];
    if( abs(timeChange) % 10 == 5 ) advanceTime({0,(timeChange>=0?30:-30)});
    timeChange /= 10;
    advanceTime({timeChange,0});
    timeZone = Z2;
}
void Time::changeToUTC(){
    int timeChange = -TIME_ZONES.timeZones[timeZone];
    if( abs(timeChange) % 10 == 5 ) advanceTime({0,(timeChange>=0?30:-30)});
    timeChange /= 10;
    advanceTime({timeChange,0});
}
string Time::returnTime( bool includeSeconds ){
    stringstream SS;
    SS << setw(2) << setfill('0') << H << ':' << setw(2) << setfill('0') << M;
    if( includeSeconds ) SS << ':' << setw(2) << setfill('0') << S;
    return SS.str();
}
string Time::returnTimeAMPM(){
    Time T = *this;
    string postfix = "";
    if( T.H < 12 ){
        postfix = "a.m.";
        if( T.H == 0 ) T.H = 12;
    }else{
        postfix = "p.m.";
        if( T.H != 12 ) T.H -= 12;
    }
    stringstream SS;
    SS << T.H << ':' << setw(2) << setfill('0') << T.M << ' ' << postfix;
    return SS.str();
}
int Time::toSeconds(){
    return 3600*H + 60*M + S;
}
Time timeDifference( Time p, Time q ){ // ASSUMES p >= q
    Time rv(0,0,0);
    while( q != p ){
        rv.advanceTime(ONE_SECOND);
        q.advanceTime(ONE_SECOND);
    }
    return rv;
}

/* TIME LIBRARY */

bool hasBirthday[35][15] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while( N-- ){

        string name, date;
        cin >> name >> date;
        Date tempDate(date,"MD");
        hasBirthday[tempDate.D][tempDate.M] = true;

    }

    Date currentDate(28,10,1);
    Date resDate(-1,-1,-1);
    int daysSinceLastBirthday = -INF/2;
    int maxDelay = 0;
    while( currentDate != (Date){28,10,3} ){

        daysSinceLastBirthday++;
        if( hasBirthday[currentDate.D][currentDate.M] ) daysSinceLastBirthday = 0;
        else if( daysSinceLastBirthday > maxDelay ){ maxDelay = daysSinceLastBirthday; resDate = currentDate; }
        currentDate.advanceDay();
        // cout << currentDate.returnDate("|D-|M-|Y") << ' ' << daysSinceLastBirthday << endl;

    }

    currentDate = (Date){28,10,1};
    while( true ){

        daysSinceLastBirthday++;
        if( hasBirthday[currentDate.D][currentDate.M] ) daysSinceLastBirthday = 0;
        else if( daysSinceLastBirthday == maxDelay ){ resDate = currentDate; break; }
        currentDate.advanceDay();
        // cout << currentDate.returnDate("|D-|M-|Y") << ' ' << daysSinceLastBirthday << endl;

    }

    cout << resDate.returnDate("|M-|D") << endl;

}
