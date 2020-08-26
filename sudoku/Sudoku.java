package sudoku;

public class Sudoku {
    public static int[][] BOARD_GRID = {
            {0,9,1,2,0,0,8,3,0},
            {0,0,0,0,0,6,0,0,0},
            {0,2,0,0,0,9,0,4,7},
            {0,5,0,0,0,3,0,8,0},
            {6,0,0,4,1,0,0,0,0},
            {1,0,0,8,0,0,0,9,5},
            {0,6,0,9,0,0,0,2,0},
            {0,0,2,3,0,0,0,0,4},
            {8,3,0,0,4,0,1,6,0},
    };

    private int [][] board;
    public static final int EMPTY_GRID = 0; //treat 0 as an empty cell
    public static final int GRID_SIZE = 9;

    public Sudoku(int[][] board) {
        this.board = new int[GRID_SIZE][GRID_SIZE];

        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                this.board[i][j] = board[i][j];
            }
        }
    }

    private boolean isRow(int row, int number){
        for (int i = 0; i < GRID_SIZE; i++){
            if (board[row][i] == number)
                return true;
        }
        return false;
    }

    private boolean isColumn(int column, int number){
        for (int i = 0; i < GRID_SIZE; i++){
            if (board[i][column] == number)
                return true;
        }
        return false;
    }

    //checking if a valid number is placed on each subgrids
    private boolean isInGrid(int row, int column, int number) {
        int subRow = row/3;
        int subCol = column/3;

        for (int i = subRow; i < subRow; i++)
            for (int j = subCol; j < subCol; j++)
                if (board[i][j] == number)
                    return true;

        return false;
    }

    //check if same number is placed on same row, column
    private boolean isValid(int row, int column, int number){
        return !isRow(row,number) && !isColumn(column,number) && !isInGrid(row,column,number);
    }

    public boolean playGame(){
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                //search empty grid
                if (board[i][j] == EMPTY_GRID){
                    //place a valid number on empty grid
                    for (int number = 1; number <= GRID_SIZE; number++){
                        if (isValid(i, j, number)) {
                            board[i][j] = number;
                            //check recursively if solution is valid
                            if (playGame()) {
                                return true;
                            } else {
                                board[i][j] = EMPTY_GRID; //empty the cell if number is not valid
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public void display_board(){
        for (int i = 0; i < GRID_SIZE; i++){
            for (int j = 0; j < GRID_SIZE; j++){
                System.out.print(" " + board[i][j]);
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Sudoku play = new Sudoku(BOARD_GRID);
        System.out.println("Play Game!");

        play.display_board();

        if (play.playGame()){
            System.out.println("Solved!");
            play.display_board();
        }
        else {
            System.out.println("No Solution");
            play.display_board();
        }
    }

}
