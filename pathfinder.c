#include <stdio.h>
int matrix[3][5] = {{0,1,1,1,1},
                    {0,0,1,1,1},
                    {3,1,1,1,1}};
int seen[3][5];
int start[2] = {0,1};
int height = 3;
int length = 5;
int dir[4][2] = {{-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
//criar uma array com as direções e botar as 4 chamadas em um for
int walk(int *current) {
    if(seen[current[0]][current[1]]) {
        return 0;
    }
    if(current[0] >= height || current[0] < 0) {
        return 0;
    }
    if(current[1] >= length || current[1] < 0) {
        return 0;
    }
    int value = matrix[current[0]][current[1]];
    if(value==0) {
        return 0;
    }
    if(value == 3) {
        printf("goal is at (%d,%d)", current[0], current[1]);
        return 1;
    }
    seen[current[0]][current[1]] = 1;
    for(int i = 0; i < 4; i++) {
        int next[2] = {current[0]+dir[i][0], current[1]+dir[i][1]};
        if(walk(next)) {
            return 1;
        }
    }
    return 0;
}
int main() {
    int goal = walk(start);
    return 0;
}