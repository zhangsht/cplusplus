# include<stdio.h>
# include<string.h>
# define N 1000
int str[N+2][N+2];

int main() {
 int i, j, la, lb;
 char str1[N+1], str2[N+1];
 while(scanf("%s%s",str1,str2) != EOF) {
      la = strlen(str1);
      lb = strlen(str2);

      for(i=0; i <= la;i++)
       str[0][i] = 0;
      for(j=0; j<= lb;j++)
       str[j][0] = 0;

      for(j=0; j<la; j++)
       for(i=0; i<lb; i++) {
        if(str1[j] == str2[i])
         str[i+1][j+1]=str[i][j]+1;
        else str[i+1][j+1]= (str[i][j+1] > str[i+1][j] ? str[i][j+1] : str[i+1][j]);
       }

       printf("%d\n",str[lb][la]);
    }
    return 0;
}
