/**

  Zadanie Q: Sudoku.
  Autor: Bartłomiej Szczepanik

  Rozwiązanie wzorcowe z wykorzystaniem:
    - sprawdzania poprawności rozwiązania po każdym uzupełnieniu pola (local check)
    - wyboru w pierwszej kolejności pól, które mają najmniej możliwości do wyboru
    - sprawdzania czy uzupełnienie pola nie spowoduje pozbawienia możliwości innego pola na jakiekolwiek uzupełnienie.

  Implementacja zapewnia dwa ostatnie warunki jednocześnie przez traktowanie zerowych możliwości również jako minimum.

**/

#include <cstdio>

using namespace std;

const int BOARD_SIZE = 9;
const int BOX_SIZE = 3;
const int EMPTY_FIELD = 0;

int board[BOARD_SIZE][BOARD_SIZE];

void possible_values(int row, int column, bool values[]) {
  for(int i=1; i<=BOARD_SIZE; ++i) {
    values[i] = true;
  }

  for(int i=0; i<BOARD_SIZE; ++i) {
    values[board[row][i]] = false;
    values[board[i][column]] = false;
  }

  for(int i=0; i<BOX_SIZE; ++i) {
    for(int j=0; j<BOX_SIZE; ++j) {
      int value = board[row - row % 3 + i][column - column % 3 + j];
      values[value] = false;
    }
  }
}

bool next_free(int* row, int* column) {
  int lowest_constraints = BOARD_SIZE + 1;

  for(int i=0; i<BOARD_SIZE; ++i) {
    for(int j=0; j<BOARD_SIZE; ++j) {
      if(board[i][j] == EMPTY_FIELD) {

        bool values[BOARD_SIZE+1];
        possible_values(i, j, values);

        int constraints = 0;
        for(int k=1; k<=BOARD_SIZE; ++k) {
          if(values[k]) {
            constraints++;
          }
        }

        if(lowest_constraints > constraints) {
          lowest_constraints = constraints;
          *row = i;
          *column = j;
        }
      }
    }
  }

  return lowest_constraints <= BOARD_SIZE;
}

bool solve_sudoku() {
  int row, column;
  if(!next_free(&row, &column)) return true;

  bool values[BOARD_SIZE+1];
  possible_values(row, column, values);

  for(int value=1; value <= BOARD_SIZE; ++value) {
    if(!values[value]) continue;

    board[row][column] = value;
    if(solve_sudoku()) {
      return true;
    }
    board[row][column] = EMPTY_FIELD;
  }

  return false;
}

int main() {
  for(int i=0; i<BOARD_SIZE; ++i) {
    for(int j=0; j<BOARD_SIZE; ++j) {
      scanf("%d", &board[i][j]);
    }
  }

  solve_sudoku();

  for(int i=0; i<BOARD_SIZE; ++i) {
    for(int j=0; j<BOARD_SIZE; ++j) {
      printf("%d ", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}