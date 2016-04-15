#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> get_next(const vector<int>& P)
{
    int i = P.size();
    vector<int> result(i);
    int j,k;
    j = 0;
    k = -1;
    result[0] = -1;
    while(j<P.size()-1)
    {
        if(k==-1||P[j] == P[k])    //ƥ��������,P[j]==P[k]
        {
            j++;
            k++;
            result[j]=k;
        }
        else                   //p[j]!=p[k]
            k = result[k];
    }
    return result;
}

int KMPmatch(const vector<int>& S,const vector<int>& P)
{
    int i,j;
    vector<int> next;
    next = get_next(P);  //Ҳ����"next = get_next_2(P);"
    j = 0;
    i = 0;
    while(i < S.size())
    {
        if(j == -1 || S[i] == P[j])   //ǰһ�������Ǳ��Ȳŷ����Ӵ�����λ�ļ������
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];   //���߼��Ļ���
        }
        if(j == P.size())
            return i-P.size();
    }
    return -1;
}

int main()
{
    int m,n;
    while(cin >> m)
    {
        int i,j;
        vector<int> A,B;
        for(i = 0 ; i < m;i++)
        {
            cin >> j;
            A.push_back(j);
        }
        cin >> n;
        for(i = 0; i < n;i++)
        {
            cin >> j;
            B.push_back(j);
        }
        if(KMPmatch(B,A) == -1)   //ע������˭��������˭���Ӵ���
            cout << "no solution" <<endl;
        else
            cout << KMPmatch(B,A) << endl;
    }
    return 0;
}
