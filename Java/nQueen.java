

public class nQueen {
    
    public static void main(String[] args) {
        placeQueens(5);
    }

    public static void placeQueens(int n){
        int board[][]=new int[n][n];
        placeQueen(board,0,n);
    }

    private static void placeQueen(int[][] board, int row, int n) {
        if(row==n){
            printBoard(board);
        }

        for(int i=0;i<n;i++){
            if(isBoardSafe(board,row,i)){
                board[row][i]=1;
                placeQueen(board,row+1,n);
                board[row][i]=0;
            }
        }
    }

    private static boolean isBoardSafe(int[][] board, int row, int col) {

        int n=board.length;

        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        for(int i=row+1,j=col+1;i<n && j<n;i++,j++){
            if(board[i][j]==1){
                return false;
            }
        }
        for(int i=row+1,j=col-1;i<n && j>=0;i++,j--){
            if(board[i][j]==1){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j]==1){
                return false;
            }
        }
        for(int i=row-1;i>=0;i--){
            if(board[i][col]==1){
                return false;
            }
        }
        for(int i=row+1;i<n;i++){
            if(board[i][col]==1){
                return false;
            }
        }

        return true;
    }

    private static void printBoard(int[][] board) {
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                System.out.print(board[i][j]+" ");
            }
        System.out.println();
        }
    System.out.println();
    }


}
