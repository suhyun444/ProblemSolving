import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Scanner;

class Main {
    public static void main(String[] args) throws Exception {
        int[] dirY = {-1,-1,-1,0,1,1,1,0};
        int[] dirX = {-1,0,1,1,1,0,-1,-1};
        BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(sc.readLine());
        String[] board = new String[n];
        for(int i=0;i<n;++i)
        {
            board[i] = sc.readLine();
        }
        int[][] result = new int[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i].charAt(j) == '.')
                {
                    int cur = 0;
                    for(int k=0;k<8;++k)
                    {
                        int nextY = i + dirY[k];
                        int nextX = j + dirX[k];
                        if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= n)continue;
                        if(board[nextY].charAt(nextX) != '.')
                        {
                            cur += board[nextY].charAt(nextX) - '0';
                        }
                    }
                    result[i][j] = cur;
                }
                else{
                    result[i][j] = -1;
                }
            }
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(result[i][j] == -1)
                    bw.write("*");
                else if(result[i][j] >= 10)
                    bw.write("M");
                else
                    bw.write(result[i][j]+"");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
        sc.close();
    }
}