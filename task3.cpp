#include <iostream>
using namespace std;

bool issafe(int** arr, int x, int y, int n) {
    if (x < n && y < n && arr[x][y] == 1) {
        return true;
    }
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solarr) {
    if (x == n-1 && y == n-1) {   
        solarr[x][y] = 1;
        return true;
    }

    if (issafe(arr, x, y, n)) {
        solarr[x][y] = 1;

        if (ratinMaze(arr, x+1, y, n, solarr)) { 
            return true;
        }

        if (ratinMaze(arr, x, y+1, n, solarr)) {  
            return true;
        }

        solarr[x][y] = 0;  
        return false;
    }
    return false;
}

int main() {
    int n = 4;
    int maze[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 1}
    };

    
    int** arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = maze[i][j];
        }
    }

    int** solarr = new int*[n];
    for (int i = 0; i < n; i++) {
        solarr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            solarr[i][j] = 0;
        }
    }

    if (ratinMaze(arr, 2, 0, n, solarr)) {
        cout << "Path found:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solarr[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists";
    }
}
