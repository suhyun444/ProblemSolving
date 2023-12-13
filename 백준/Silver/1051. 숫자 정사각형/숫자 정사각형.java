import java.util.Scanner;

class Main {
    public static boolean Check(int[][] board,int y,int x,int size,int n,int m)
    {
        int type = board[y][x];
        if(y + size >= n || x + size >= m)return false;
        boolean result = (type == board[y + size][x + size]) && (type == board[y + size][x]) && (type == board[y][x + size]);
        return result;
    }
    public static void main(String[] args) {    
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] board = new int[n][m]; 
        for(int i=0;i<n;++i)
        {
            String s = sc.next();
            for(int j=0;j<m;++j)
            {
                board[i][j] = s.charAt(j) - '0';
            }
        }
        int size = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for(int k=size;k< Math.min(n - i, m - j);++k)
                {
                    if(Check(board, i, j, k,n,m))
                    {
                        size = k;
                    }
                }
            }
        }
        System.out.println((size + 1)* (size + 1));
    }
}