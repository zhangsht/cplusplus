#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;


char e[10];

//首先从右边找到第一个相邻"逆序对"，e[i]<e[j]
int argument_a(int len)
{
    int i;
    for(i=len-2;i>=0;--i) //i位直接与其前一位相比较
    {
        // 因此i的左界为len为元素个数i+1,即为len-2+1
        if(e[i]<e[i+1] || i==0 )
        {
            break;
        }
    }
    return i;
}

//然后再重新从右边起找出第一个比那个"逆序对"的较小者,要大的数
int argument_b(int len, int parter )
{
    int i;
    for( i=len-1; i>=0;--i) //i是不可能为0,因为e[i](parter)<e[i+1],我们是从后面开始扫描
    {
        if( e[i]> parter|| i== 0 ) // 在连续的数组比较中的一种较为固定的控制，伪监视哨
        {
            break;
        }
    }
    return i;
}

void swap( char &a, char &b )
{
    int temp= a;
    a= b;
    b= temp;
}

void reverse(int front, int rear)
{
    int i=front, j=rear-1;
    while(i<=j)
    {
        swap( e[i], e[j] );
        ++i, --j;
    }
}

//判断是否最大的那个数
bool is_end( int len )
{
    int i;
    for( i= len- 2; i>= 0; --i )
    {
        if( e[i]< e[i+ 1] )
        {
            return false;
        }
    }
    if(i==-1) // 说明一直遍历到了最前端
    {
        return true;
    }
    return false;
}

bool next(int len )
{
    if( is_end(len) )
    {
        return false;
    }
    else
    {
        int i= argument_a(strlen(e));
        int j= argument_b(strlen(e),e[i]);
        swap(e[i], e[j]); //交换
        reverse(i+1, 4); //倒转
        return true;
    }
}
int cmp( const void *a, const void *b )
{
    return *( char * )a- *( char * )b;
}

int main()
{
    while(scanf( "%c %c %c %c", &e[0], &e[1], &e[2], &e[3]) != EOF)
    {
        qsort(e, 4, sizeof(char),cmp); //先拿到第一个,如：1234 or 1234Aa
        do
        {
            cout << e[0] << " " << e[1] << " " << e[2] << " " << e[3]<< endl;
        }
        while(next(4));
    }

    return 0;
}