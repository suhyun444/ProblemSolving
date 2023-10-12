import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        int[] dirY = {1,0,-1,0};
        int[] dirX = {0,1,0,-1};
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0)
        {
            String s = sc.next();
            int y=0,x=0,dir = 0;
            int minY =0,minX =0,maxY=0,maxX=0;
            for(int i=0;i<s.length();++i)
            {
                if(s.charAt(i) == 'F')
                {
                    y += dirY[dir];
                    x += dirX[dir];
                    minY = Math.min(minY, y);
                    minX = Math.min(minX, x);
                    maxY = Math.max(maxY, y);
                    maxX = Math.max(maxX, x);
                }
                else if(s.charAt(i)=='B')
                {
                    y -= dirY[dir];
                    x -= dirX[dir];
                    minY = Math.min(minY, y);
                    minX = Math.min(minX, x);
                    maxY = Math.max(maxY, y);
                    maxX = Math.max(maxX, x);
                }
                else if(s.charAt(i) == 'L')
                {
                    dir -= 1;
                    if(dir < 0)dir = 3;
                }
                else if(s.charAt(i) == 'R')
                {
                    dir += 1;
                    dir %= 4;
                }
            }
            System.out.println((maxX - minX) * (maxY - minY));
            t -= 1;
        }
        sc.close();
    }
}