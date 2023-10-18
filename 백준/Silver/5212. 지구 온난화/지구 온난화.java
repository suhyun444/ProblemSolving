import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] dirY = {0,1,0,-1};
        int[] dirX = {1,0,-1,0};
        int n = sc.nextInt();
        int m = sc.nextInt();
        char[][] board = new char[n][m];
        for(int i=0;i<n;++i)
        {
            String s = sc.next();
            for(int j=0;j<m;++j)
            {
                board[i][j] = s.charAt(j);
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j] == 'X')
                {
                    int count = 0;
                    for(int k=0;k<4;++k)
                    {
                        int nextY = i + dirY[k];
                        int nextX = j + dirX[k];
                        if(nextY < 0 || nextY >= n || nextX < 0 || nextX >= m || board[nextY][nextX] == '.') ++count;
                    }
                    if(count >= 3)
                    {
                        board[i][j] = 'O';
                    }
                }
            }
        }
        for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(board[i][j] == 'O')board[i][j] = '.';
        int minY = n - 1;
        int minX = m - 1;
        int maxY = 0;
        int maxX = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(board[i][j] == 'X')
                {
                    minY = Math.min(minY,i);
                    maxY = Math.max(maxY,i);
                    minX = Math.min(minX,j);
                    maxX = Math.max(maxX,j);
                }
            }
        }
        for(int i=minY;i<=maxY;++i)
        {
            for(int j=minX;j<=maxX;++j)
            {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }

        sc.close();
    }
}