import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cur = 1;
        int type = 1;
        while(true)
        {
            if(n < cur)
            {
                if(type == 1)
                {
                    System.out.println(cur - n);
                }
                else
                {
                    System.out.println(0);
                }
                break;
            }
            n -= cur;
            type *= -1;
            cur++;
        }
        sc.close();
    }
}