#include <iostream>
#include <map>
#include <string>
using namespace std;
class student {
private:
    map<int,string> stu;
public:
    void reg(int key,string name) {
        stu[key] = name;
    }
    bool graduate(int key,string name) {
        map<int,string>::iterator it;
        it = stu.find(key);
        if (it != stu.end() && name == stu[key]) {
            stu.erase(key);
            return true;
        }
        return false;
    }
    string findName(int key) {
        if (stu.find(key) != stu.end())
           return stu[key];
        return "";
    }
};
int main() {
    student stu;
    stu.reg(1370, "zhsht");
    cout << stu.findName(1370) << endl;
    cout << stu.graduate(1370, "ii");
    return 0;
}
