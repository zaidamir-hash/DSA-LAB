#include <iostream>
using namespace std;

#define N 5

int maze[N][N] = {
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1}
};

int sol[N][N];

bool solveMazeUtil(int x, int y) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1 && sol[x][y] == 0) {
        sol[x][y] = 1;
        if (solveMazeUtil(x + 1, y)) return true;
        if (solveMazeUtil(x, y + 1)) return true;
        if (solveMazeUtil(x - 1, y)) return true;
        if (solveMazeUtil(x, y - 1)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sol[i][j] = 0;
    if (solveMazeUtil(0, 0)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No solution" << endl;
    }
    return 0;
}
