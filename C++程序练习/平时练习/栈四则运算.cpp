//����Ĵ���ֻ��֧��һЩ�򵥵������ļӼ��˳����㣬���Ҳ�֧�ָ������������������ִ���9�����ֵ����㣬ֻ��
//�Լ��򵥵�дһ�����룬��������̽��еļ���֤�������Ҫ������ӵļ������⣬������������������ʵ�֣�
#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
using namespace std;

stack<char> s;
stack<int> ss;

int main()
{
    int len1, len2, len, i, j;
    string str1, str2;//str1Ϊ��׺���ʽ��str2Ϊ��׺���ʽ
    while (1){
          //��׺���ʽת��Ϊ��׺���ʽ
          getline(cin, str1);
          len1 = str1.length();
          str2.clear();
          for (i = 0; i < len1; i++){
              if (str1[i] >= '0' && str1[i] <= '9')
                 str2.push_back(str1[i]);
              else{
                   if (s.size() == 0 || str1[i] == '(')
                       s.push(str1[i]);
                   else{
                        char tmp1 = s.top();
                        if (str1[i] == ')'){
                            len = s.size();
                           while (len){
                                 char tmp = s.top();
                                s.pop();
                                if (tmp == '(')
                                    break;
                                else
                                    str2.push_back(tmp);
                                len--;
                            }
                        }
                        else{
                             if (tmp1 == '*' || tmp1 == '/'){
                                 if (str1[i] == '*' || str1[i] == '/')
                                     s.push(str1[i]);
                                 else{
                                      len = s.size();
                                      while (len){
                                          char tmp = s.top();
                                          str2.push_back(tmp);
                                          s.pop();
                                          len--;
                                      }
                                      s.push(str1[i]);
                                 }
                             }
                             else{
                                  s.push(str1[i]);
                             }
                        }
                   }
              }
          }
          if (s.size() != 0){
              len = s.size();
              while (len){
                  char tmp = s.top();
                  str2.push_back(tmp);
                  s.pop();
                  len--;
              }
          }
          cout << str2 << endl;
          //�ɺ�׺���ʽ������
          int temp1, temp2, temp3;
          len2 = str2.length();
          for (i = 0; i < len2; i++){
              if (str2[i] >= '0' && str2[i] <= '9'){
                  int t = str2[i]-48;
                  ss.push(t);
              }
              else{
                   temp1 = ss.top();
                   ss.pop();
                   temp2 = ss.top();
                   ss.pop();
                   if (str2[i] == '+'){
                       temp3 = temp2 + temp1;
                   }
                   else if (str2[i] == '-'){
                        temp3 = temp2 - temp1;
                   }
                   else if (str2[i] == '*'){
                        temp3 = temp2 * temp1;
                   }
                   else if (str2[i] == '/'){
                        temp3 = temp2 / temp1;
                   }
                   ss.push(temp3);
              }
          }
          cout << ss.top() << endl;
    }

    return 0;
}
