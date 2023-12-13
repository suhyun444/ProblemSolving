import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws Exception{    
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int[] dirY = {1,0,-1,0};
        int[] dirX = {0,1,0,-1};
        int n = Integer.parseInt(bf.readLine());
        int target = Integer.parseInt(bf.readLine());
        int y = 0,x= 0;

        int[][] board = new int[n][n];
        int direction = 0;
        int count = 3;
        int size = n - 1;
        int curSize = n - 1;
        for(int i=n*n;i>0;--i)
        {
            board[y][x] = i;

            y += dirY[direction];
            x += dirX[direction];
            if(--curSize == 0)
            {
                direction++;
                direction %= 4;
                if(--count == 0)
                {
                    size--;
                    count = 2;
                }
                curSize = size;
            }
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int resultY = 0,resultX = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(target == board[i][j])
                {
                    resultY = i + 1;
                    resultX = j + 1;
                }
                bw.write(board[i][j] + " ");
                
            }
            bw.write("\n");
        }
        bw.write(resultY + " " + resultX);
        bw.flush();
        bw.close();
        bf.close();
    }
}