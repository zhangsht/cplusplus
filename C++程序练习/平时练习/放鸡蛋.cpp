// Problem#: 15772
// Submission#: 3940763
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
 using namespace std;

 int find_num_of_ways(int num_of_eggs,int num_of_baskets); //�������������������ӵ��������ط��ü�������������

  int main(){
      int t;
      cin>>t;
      while(t--){
        int num_of_eggs,num_of_baskets;
         cin>>num_of_eggs>>num_of_baskets;
         cout<<find_num_of_ways(num_of_eggs,num_of_baskets)<<endl;
    }
     return 0;
 }
 int find_num_of_ways(int num_of_eggs,int num_of_baskets){
     if(num_of_baskets==1||num_of_eggs==1) //ֻ��1�����ӻ�1������ʱֻ��1�ַ��÷���
         return 1;
     if(num_of_baskets>=num_of_eggs) //���Ӷ��༦��ʱ����ÿ�����ӷ�һ�������������1�֣����ϰѼ����ŵ��ȼ���������1�����ӵ������
        return 1+find_num_of_ways(num_of_eggs,num_of_eggs-1);
    else
        return find_num_of_ways(num_of_eggs-num_of_baskets,num_of_baskets)//ÿ�����ӷ�һ��������ʣ��num_of_eggs-num_of_baskets�������ŵ�num_of_baskets��������
                 +find_num_of_ways(num_of_eggs,num_of_baskets-1);//����ȫ���������ϵ����
 }
