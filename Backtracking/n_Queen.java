//Kinshuk Kumar

import java.io.*;
class NQueenProblem
{
  int N;
  int board[][];
  public NQueenProblem()
  {
    N=4;
    board=new int[N][N];
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        board[i][j]=0;


  }
  public void print()
  {
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++)
        System.out.print(" "+board[i][j]);
      System.out.println();
    }

  }
  public void solveNQ()
  {
    if(placeQ(0)==false){
      System.out.println("Solution doesn't exist :(");
      return;
    }
    System.out.println("Solution: ");
    print();

  }
  public boolean placeQ(int col)
  {
    if(col>=N)
    {
      return true;
    }
    for(int i=0;i<N;i++){
      if(isSafe(i,col)){
        board[i][col]=1;
        if(placeQ(col+1)){
          return true;
        }
        board[i][col]=0;
      }
    }
    return false;
  }
  public boolean isSafe(int row,int col)
  {
    for(int i=col;i>=0;i--){
      if(board[row][i]==1){
        return false;
      }
    }//same row LS
    for(int i=row,j=col;i>=0&&j>=0;i--,j--){
      if(board[i][j]==1){
        return false;
      }
    }//upper diagonal
    for(int i=row,j=col;i<N&&j>=0;i++,j--){
      if(board[i][j]==1){
        return false;
      }
    }//lower diagonal
    return true;
  }
}

public class NQueen
{
  public static void main(String args[])
  {
    NQueenProblem NQ=new NQueenProblem();
    System.out.println("Initial State: ");
    NQ.print();
    NQ.solveNQ();
  }
}
