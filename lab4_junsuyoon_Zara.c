
#include <stdio.h>


void mazeGo(string direction, location[y][x]){
    
    
    if(direction == east){
     location[y][x+1];   
    }
    
    if(sucess) exit;
    else
    {
        mazeGo(east);
        mazeGo(west);
        mazeGo(south);
        mazeGo(north);
    }
}


int main() {
    int x = 6;
    int y = 6;
    char maze[y][x] = {
        {'S', '#', '#', '#', '#', '#'},
        {'.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'#', '.', '#', '#', '#', '#'},
        {'.', '.', '.', '#', '.', 'G'},
        {'#', '#', '.', '.', '#', '.'}
    };
    
    //checking limits
    int i =0;
    int j = 0;
    if(i > y || j > x){
        
    }
    
    
    for(int x = 0; x < 6; x++){
        for (int y = 0; y < 6; y++){
             printf("%c" , maze[x][y]);
        }
        printf("\n");
    }
    
    
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

    return 0;
}


