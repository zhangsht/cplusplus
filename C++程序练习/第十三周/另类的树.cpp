#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define max 100

int n,m;

struct way
{
     int road[max];
};
vector<way> vec;   //存储排列组合的方式

int ans[max];
int value_road;
int value_node[max];
int Map[max][max];

bool visit[max];

void dfs(int v,int num)   //深搜枚举排列组合的所有方式
{
   if(num==m)  //若已达到点的数目的要求
   {
            way w;

             for(int i=0;i<num;i++)
                {
                    w.road[i]=ans[i];
            }

          vec.push_back(w);

          return ;
      }

          for(int i=1;i<=n;i++)
         {
            if(num>0 && i<ans[num-1])   //保证字典序的排列组合
                      continue;

                  if(!visit[i])
                {
                    ans[num]=i;
                  visit[i]=1;

                        dfs(i,num+1);

                      visit[i]=0;
          }
    }
}

void prim(int r[])    //普里姆最小生成树算法
{
     int v=r[0];
  int low[max];
        int min;
     int closest[max],i,j,k;

    for(i=0;i<m;i++)
      {
            low[r[i]]=Map[v][r[i]];
              closest[r[i]]=v;
     }

  for(i=1;i<m;i++)
      {
            min=99999;

                 for(j=0;j<m;j++)
                      if(low[r[j]]!=0 && low[r[j]]<min)
                     {
                            min=low[r[j]];
                               k=r[j];
                      }

          value_road+=min;
             low[k]=0;

          for(j=0;j<m;j++)
                      if(Map[k][r[j]]!=0 && Map[k][r[j]]<low[r[j]])
                 {
                            low[r[j]]=Map[k][r[j]];
                              closest[r[j]]=r[k];
                  }
    }
}

int main()
{
    int times = 1;
        while(cin>>n>>m && n)
    {
//	    if (times != 1) cout << endl;
        times++;
            vec.clear();

               memset(value_node,0,sizeof(value_node));
             memset(visit,0,sizeof(visit));
               memset(Map,0,sizeof(Map));

                 for(int i=1;i<=n;i++)
                 cin>>value_node[i];

          for(int i=1;i<=n;i++)
                 for(int j=1;j<=n;j++)
                         cin>>Map[i][j];

              for(int i=1;i<=n;i++)
         {
                    visit[i]=1;
                  ans[0]=i;
                    dfs(i,1);
            }

          //只要深搜完毕，每次从储存的排列组合方式中选出一中，则点的权值已确定，则题目转化为求最小生成树

           vector<double> temp;
           for(int i=0;i<vec.size();i++)
         {
                    value_road=0;
                        int t_va_node=0;

                   for(int j=0;j<m;j++)
                          t_va_node+=value_node[vec[i].road[j]];

                     prim(vec[i].road);

                         double tt=(double)value_road/(double)t_va_node;

                    temp.push_back(tt);
          }

          double MMax=99999.0;
         int index;
           for(int i=0;i<temp.size();i++)
                {
                    if(temp[i]<MMax)   //选出最小值
                   {
                            MMax=temp[i];
                                index=i;
                     }
            }

            int i;
          for(i=0;i<m - 1;i++)
                  cout<<vec[index].road[i]<<' ';   //输出路径
          cout<<vec[index].road[i] << endl;   //输出路径
    }

  return 0;
}
