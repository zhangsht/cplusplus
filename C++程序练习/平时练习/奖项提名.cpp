#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int num;
    while(cin >> num && num != 0)
    {
        map<string,int> records;
        map<string,int>::iterator itr;
        vector<string> qq;
        while(num--)
        {
            string name;
            cin >> name;
            int filmnum;
            cin >> filmnum;
            while(filmnum--)
            {
                string temp;
                cin >> temp;
                qq.push_back(temp);
                records[temp]++;
            }
        }
        string maxstring;
        int max = 0;
        unsigned i;
        for(i = 0;i < qq.size();i++)
        {
            itr = records.find(qq[i]);
            if(max<itr->second)
            {
                max = itr->second;
                maxstring = qq[i];
            }
        }
        cout << maxstring << endl;
    }
    return 0;
}
            
