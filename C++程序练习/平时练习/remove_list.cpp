#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
class Salary {
    public:
        Salary(string S) :name(S) {}
        Salary(string S, double f) :name(S), banlance(f) {}
        friend bool operator==(const Salary& first, const Salary& second) {
            return first.name == second.name;
        }
        void print() {
            cout << name << " " << banlance << endl;
        }
    private:
        string name;
        double banlance;
};
int main() {
    list<Salary> mylist;
    mylist.push_back(Salary("dajvghscfg", 5748));
    mylist.push_back(Salary("tergkunbguj", 5748));
    mylist.push_back(Salary("hjgdhj", 5748));
    list<Salary>::iterator it = mylist.begin();
    while (it != mylist.end())
      (it++)->print();
    mylist.remove(Salary("tergkunbguj"));
    it = mylist.begin();
    while (it != mylist.end())
      (it++)->print();
    return 0;
}

