import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[] dirY = {-1,-1,-1,0,1,1,1,0};
        int[] dirX = {-1,0,1,1,1,0,-1,-1};
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] board= new String[n];
        String[] result = new String[n];
        for(int i=0;i<n;++i)board[i] = sc.next();
        boolean isExposive = false;
        for(int i=0;i<n;++i)
        {
            result[i] = sc.next();
            for(int j=0;j<n;++j)
            {
                if(result[i].charAt(j) == 'x' && board[i].charAt(j) == '*')
                    isExposive = true;
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(result[i].charAt(j) == 'x')
                {
                    if(board[i].charAt(j) == '*')
                    {
                        System.out.print("*");
                        continue;
                    }
                    int cur = 0;
                    for(int k=0;k<8;++k)
                    {
                        int nextY = i + dirY[k];
                        int nextX = j + dirX[k];
                        if(nextY < 0 || nextY >= n || nextX < 0 || nextX >=n)continue;
                        if(board[nextY].charAt(nextX) == '*')
                        {
                            cur++;
                        }
                    }
                    System.out.print(cur);
                }
                else
                {
                    if(isExposive && board[i].charAt(j) == '*')
                        System.out.print("*");
                    else
                        System.out.print(".");
                }
            }
            System.out.println();
        }
    }
}