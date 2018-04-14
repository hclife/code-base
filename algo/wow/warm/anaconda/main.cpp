// longest anaconda - main.cpp
#include <stdio.h>
#include <stdlib.h>

#define SIZE       1000
#define THICKNESS 4

int run_test(const char snake[SIZE][SIZE]);

static char snake[10][SIZE][SIZE];

void build_snake(void) {
  for (int l = 0; l < 10; l++) {
    for(int y = 0; y < SIZE; y++)
      for(int x = 0; x < SIZE; x++)
        snake[l][x][y] = 0;

	// limit of snakes
        for (int k = 0; k < 99; k++) {
          int flag = 1;
          int curX = (rand() % ((SIZE - THICKNESS * 10) / THICKNESS)) * THICKNESS + THICKNESS * 10;
          int curY = (rand() % ((SIZE - THICKNESS * 10) / THICKNESS)) * THICKNESS + THICKNESS * 10;
        
          for(int j = -10 * THICKNESS; j < 10 * THICKNESS; j++) 
            for(int i = -10 * THICKNESS; i < 10 * THICKNESS; i++) 
              if (snake[l][j + curX][i + curY]) flag = 0;

              if (flag) {
                for(int i = 0; i < SIZE / 40; i++) {
                  int dir = rand() % 4;
                  int progress = (rand() % 40) * THICKNESS + THICKNESS;

                  if (dir == 0)  // Right
                  {
                    for (; curY < progress; curY++)
                      if ((snake[l][curX][curY + THICKNESS] + snake[l][curX - 1][curY + THICKNESS] +
                      snake[l][curX + 1][curY + THICKNESS])) 
                        break; 
                      else 
                        snake[l][curX][curY] = 1;
                  }
                  else if (dir == 1) // Left
                  {
                    for (; curY > progress; curY--)
                      if ((snake[l][curX][curY - THICKNESS] + snake[l][curX - 1][curY - THICKNESS] +
                      snake[l][curX + 1][curY - THICKNESS]))
                        break; 
                      else 
                        snake[l][curX][curY] = 1;
                    }
                    else if (dir == 2) // Up
                    {
                      for (; curX > progress; curX--)
                        if ((snake[l][curX - THICKNESS][curY] + snake[l][curX - THICKNESS][curY - 1] +
                        snake[l][curX - THICKNESS][curY + 1])) 
                          break; 
                        else 
                          snake[l][curX][curY] = 1;
                    }
                    else if (dir == 3) // Down
                    {
                      for (; curX < progress; curX++)
                        if ((snake[l][curX + THICKNESS][curY] + snake[l][curX + THICKNESS][curY - 1] +
                        snake[l][curX + THICKNESS][curY + 1]))
                          break; 
                        else 
                          snake[l][curX][curY] = 1;
                    }
                  }
               }
         }
  }
}

int main(void) {
    build_snake();
    for (int count = 0; count < 10; count++)
        printf("%d\n", run_test(snake[count]));
    return 0;
}

