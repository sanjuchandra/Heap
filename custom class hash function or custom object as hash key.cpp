#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class students{
    public:
    string first_name , last_name;
    int roll_no;
    
        students(string x , string y , int z){
            first_name = x;
            last_name = y;
            roll_no = z;
        }
        bool operator == (const students &s) const{
            return roll_no == s.roll_no;
        }
};

class haskFn{
    public:
        size_t operator() (const students &s) const{
            return s.first_name.length() + s.last_name.length() + (s.roll_no % 100);
        }
};

int main(){
    students s1("Prateek" , "Narang" , 120);
    students s2("Prateek" , "Kumar" , 110);
    students s3("Sanju" , "Chandra" , 90);
    students s4("Sanju"  , "Chandra" , 190);

    unordered_map<students , int , haskFn> students_map;
    students_map[s1] = 100;
    students_map[s2] = 200;
    students_map[s3] = 98;
    students_map[s4] = 12;

    for(auto x : students_map){
        cout<<x.first.first_name<<" "<<x.first.last_name<<" "<<x.first.roll_no<<" marks "<<x.second<<endl;
    }
    //marks of s3
    cout<<students_map[s3]<<endl;
}
