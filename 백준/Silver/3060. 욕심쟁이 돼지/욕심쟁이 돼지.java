import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t > 0)
        {
            int n = sc.nextInt();
            int[] pig = new int[6];
            int[] next = new int[6];
            int sum = 0;
            for(int i=0;i<6;++i)
            {
                pig[i] = sc.nextInt();
                sum += pig[i];
            }
            if(n < sum)
            {
                System.out.println(1);
                t--;
                continue;
            }
            int count = 1;
            while(true)
            {
                count++;
                int result = 0;
                for(int i=0;i<6;++i)
                {
                    next[i] = pig[i] + pig[(i-1 < 0) ? 5 : i-1] + pig[(i + 1) % 6] + pig[(i + 3) % 6];
                    result += next[i];
                }
                if(n < result)
                {
                    break;
                }
                for(int i=0;i<6;++i)pig[i] = next[i];
            }
            System.out.println(count);
            t--;
        }
        sc.close();
    }
}