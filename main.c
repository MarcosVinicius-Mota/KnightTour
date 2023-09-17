#include <stdio.h>
#include <memory.h>

#define BOARD_SIZE 6
#define MAX_MOVES 8

int moves_row[] = {2, 1, 2, 1, -2, -1, -2, -1};
int moves_col[] = {1, 2, -1, -2, 1, 2, -1, -2};

int valid_move(int board[BOARD_SIZE][BOARD_SIZE], int row, int col){
    return (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == -1);
}


int backtrack(int board[BOARD_SIZE][BOARD_SIZE], int row, int col, int move_count)
{
    if(move_count == BOARD_SIZE * BOARD_SIZE)
    {
        return 1;
    }
    else
    {
        for(int i = 0; i < MAX_MOVES; i++)
        {
        

            if(valid_move(board, row + moves_row[i], col + moves_col[i]))
            {
                
                board[row + moves_row[i]][col + moves_col[i]] = move_count;

                if(backtrack(board, row + moves_row[i], col + moves_col[i], move_count + 1)){
                    return 1;
                }
                else{
                    board[row + moves_row[i]][col + moves_col[i]] = -1;
                }

            }
            
        }

        return 0;
    }

}

int knight_tour(int board[BOARD_SIZE][BOARD_SIZE], int initial_row, int initial_col)
{
    memset(board, -1, sizeof(int) * BOARD_SIZE * BOARD_SIZE);
    board[initial_row][initial_col] = 0;
    return backtrack(board, initial_row, initial_col, 1);
}


void print_board(int board[BOARD_SIZE][BOARD_SIZE])
{

    for(int i = 0; i < BOARD_SIZE; i++)
    {
        for(int j = 0; j < BOARD_SIZE; j++)
        {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }

}



int main() {
    
    int initialrow;
    int initialcol;
    int board[BOARD_SIZE][BOARD_SIZE];

    printf("Digite a linha inicial (0 - 7): ");
    scanf("%d", &initialrow);
    printf("Digite a Coluna inicial (0 - 7): ");
    scanf("%d", &initialcol);

    printf("Computando...\nEsse processo pode demandar um bom tempo...\n");

    if(knight_tour(board, initialrow, initialcol)){
        printf("Solução encontrada: \n\n");
        print_board(board);
        printf("\n");
    }   
    else{
        printf("Não há solução para o problema!!!\n");
    }

    return 0;
}
