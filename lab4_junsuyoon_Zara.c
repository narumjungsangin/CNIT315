/*
Name: Junsu Yoon
Email: yoon188@purdue.edu
TA: Zara Ghorrati
Lab Session: Thursday 730-930 am
Descritption: Finding Route in Maze
*/


#include <stdio.h>
#define ROW 6
#define COL 6

int dirX[] = {1, -1, 0, 0};  
int dirY[] = {0, 0, 1, -1};  

int mazeGo(int x, int y, char maze[ROW][COL]) {
    
    //base case
    if (maze[y][x] == 'G') {
        return 1; 
    }
    
    //track location
    maze[y][x] = '+'; 
    
    //printing current maze
    for(int x = 0; x < 6; x++){
        for (int y = 0; y < 6; y++){
             printf("%c" , maze[x][y]);
        }
        printf("\n");
    } 
    printf("\n");
            
            
    //check four side
    for (int i = 0; i < 4; i++) {
        int newX = x + dirX[i];
        int newY = y + dirY[i];
        
        //check if it is possible to go, if so, then recurssive
        if (newX >= 0 && newX < COL && newY >= 0 && newY < ROW && maze[newY][newX] != '#' && maze[newY][newX] != '+') {
          int tf = 0;
          tf = mazeGo(newX, newY, maze);
            if (tf == 1){
             return 1;
            }
        }
    }
}


int main() {
    char maze[ROW][COL] = {
        {'S', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '#', '.', 'G'},
        {'#', '#', '.', '.', '.', '#'}
    };
    
    //checking limits
    // int i =0;
    // int j = 0;
    // if(i > y || j > x){
        
    // }
    
    
    // for(int x = 0; x < 6; x++){
    //     for (int y = 0; y < 6; y++){
    //          printf("%c" , maze[x][y]);
    //     }
    //     printf("\n");
    // }
    
    //Finding startpoint
    int s_x = 0;
    int s_y = 0;
    for(int y = 0; y < 6; y++){
        for (int x = 0; x < 6; x++){
            if(maze[y][x] == 'S'){
              s_x = x;
              s_y = y;
            }
        }
    }
    
    int tf = mazeGo(s_x,s_y,maze);
    if (tf == 1) {
    printf("Sucess!\n");
    }

    return 0;
}





