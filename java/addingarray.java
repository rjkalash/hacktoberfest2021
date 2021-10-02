import java.io.*;
import java.lang.ArrayIndexOutOfBoundsExceptionjava;

class boom{
   

    public static void main(String args[]){

     
        int [][]mat1 = {{1,2,3},{3,5,6}};
        int [][]mat2 = {{3,6,7},{9,0,8}};
        int [][] result={{0,0,0},{0,0,0}};

        for(int i=0;i<mat1.length;i++){
            for(int j=0;i<mat1[i].length;j++){
                result[i][j]= mat1[i][j]+ mat2[i][j];
                System.out.print(result[i][j]+"  ");
               
            }
            System.out.println();
        }

    }
}

