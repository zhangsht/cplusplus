# include<stdio.h>
# include<string.h>

int str[1005][1005];

int main() {
 int i, j, lena, lenb;
 char str1[1005], str2[1005];
 while(scanf("%s",str1) != EOF) {
     scanf("%s",str1);
      lena = strlen(str1);
      lenb = strlen(str2);
      str[0][lena] = 0;
      str[lenb][0] = 0;
      for(j=0; j <= lena; j++)
       for(i=0; i <= lenb; i++) {
           if (!i || !j) {
               str[i][j] = 0;
           }
            else if(str1[j] == str2[i])
             str[i+1][j+1] = str[i][j] + 1;
            else str[i + 1][j + 1]= (str[i][ j+ 1] > str[i + 1][j] ? str[i][j + 1] : str[i + 1][j]);
       }

       printf("%d\n",str[lenb][lena]);
    }
    return 0;
}
