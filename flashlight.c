#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int dir[4][2] = {{-1,0},
                {0,1},
                {1,0},
                {0,-1}
};

struct array2d { //renomear esse bgl
    int matrix[6][9];
    int height;
    int length;
    int start[2];
};

void updateCanvas(struct array2d *canvas,int position[2]) {
    canvas->matrix[canvas->start[0]][canvas->start[1]] = 34;
    canvas->start[0] = position[0];
    canvas->start[1] = position[1];
    canvas->matrix[canvas->start[0]][canvas->start[1]] = 79;
}

void drawCanvas(struct array2d *canvas, int characterPosition[2]) {
    if(canvas->start[0] != characterPosition[0] || canvas->start[1] != characterPosition[1]) {
        system("cls");
        updateCanvas(canvas, characterPosition);
        for(int i = 0; i<canvas->height;i++) {
            for(int j = 0; j<canvas->length; j++) {
                printf("%c",canvas->matrix[i][j]);
            }
            printf("\n");
        }
        Sleep(500);
    }
}

void createStructsFromFile(char *fileName, struct array2d *map, struct array2d *canvas) {
    canvas->height = sizeof(canvas->matrix)/sizeof(canvas->matrix[0]);
    canvas->length = sizeof(canvas->matrix[0])/sizeof(int);
    map->height = sizeof(map->matrix)/sizeof(map->matrix[0]);
    map->length = sizeof(map->matrix[0])/sizeof(int);
    FILE *fptr;
    fptr = fopen(fileName,"r");
    int B = 2 + '0'; //B stands for beggining
    char c;
    int row = 0;
    int collumn = 0;
    c = fgetc(fptr);
    while(c!=-1) {
        if(c=='\n') {
            collumn++;
            row = 0;
        } else {
            map->matrix[collumn][row] = c - 48; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            canvas->matrix[collumn][row] = c - 15; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            if(c==B) {
                canvas->start[0] = collumn;
                canvas->start[1] = row;
                map->start[0] = collumn;
                map->start[1] = row;
            }
            row++;
        }
        c = fgetc(fptr);
    } 
    fclose(fptr);
}

int walk(struct array2d *map, struct array2d *canvas, int current[2], int seen[map->height][map->length]) {
    if(current[0] >= map->height || current[0] < 0) {
        return 1;
    }
    if(current[1] >= map->length || current[1] < 0) {
        return 1;
    }if(seen[current[0]][current[1]]) {
        return 0;
    }
    int value = map->matrix[current[0]][current[1]];
    if(value==0) {
        return 0;
    }
    // printf("%d,%d ", current[0], current[1]);
    seen[current[0]][current[1]] = 1;
    drawCanvas(canvas,current);
    for(int i = 0; i < 4; i++) {
        int next[2] = {current[0]+dir[i][0], current[1]+dir[i][1]};
        if(walk(map, canvas, next, seen)) {
            return 1;
        } else {
            drawCanvas(canvas,current);
        }
    }
    return 0;
}
int main() {
    char *name = "matriz.txt";
    struct array2d *canvas = calloc(1, sizeof(struct array2d));
    struct array2d *map = calloc(1, sizeof(struct array2d));
    createStructsFromFile(name, map, canvas);
    int debugPosition[2] = {canvas->start[0],canvas->start[1]};
    drawCanvas(canvas,debugPosition);
    int seen[6][9] = {0};
    int goal = walk(map, canvas, map->start, seen);
    free(canvas);
    free(map);
    return 0;
}