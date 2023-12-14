import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long m = sc.nextInt();
        long result = 0;
        if(n == 1)
        {
            result = 8 * m;
        }
        else if(n == 5)
        {
            result = 8 * (m + 1) - 4;
        }
        else 
        {
            result = (4 * m) + 1 + ((m % 2 == 0) ? n-2 : 4-n); 
        }
        System.out.print(result);
    }
}