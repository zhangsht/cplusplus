#include <iostream>
using namespace std;

// ��Ŀ�и���������Ⱥ͸߶�
#define MAX_W 20
#define MAX_H 20

// ������Ŀ�Ⱥ͸߶��Լ����ߵĲ���
int W, H;
int step = 0;

// ��д��Ķ�ά����
char room[MAX_W][MAX_H];
// ˳ʱ��Ŀ��߷���
const int direc[4][2] = {
    {0, -1},
    {1,0},
    {0, 1},
    {-1 ,0},
};


int dfs(const int& row, const int& col) {
    // �߹��ĵ�
    room[row][col] = '#';
    // ���㲽��
    ++step;
    for (int d = 0; d < 4; ++d) {
        int curRow = row + direc[d][1];
        int curCol = col + direc[d][0];
        if (curRow >= 0 && curRow < H && curCol >= 0 && curCol < W && room[curRow][curCol] == '.') {
            dfs(curRow, curCol);
        }
    }
    return step;
}

int main()
{
    bool found;
    while (cin >> W >> H, W > 0) {
        step = 0;
        int col, row;
        // ����
        for (row = 0; row < H; ++row) {
            for (col = 0; col < W; ++col) {
                cin >> room[row][col];
            }
        }
        found = false;
        // �ҵ���ʼ��
        for (row = 0; row < H; ++row) {
            for (col = 0; col < W; ++col) {
                if (room[row][col] == '@') {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        // ��ʼ����
        cout << dfs(row, col) << endl;
    }
}
