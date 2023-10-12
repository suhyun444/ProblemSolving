import java.util.Scanner;

class Main {
    public static int reverse(int cur) {
        if (cur == 0)
            return 1;
        return 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            arr[i] = sc.nextInt();
        }
        int m = sc.nextInt();
        for (int i = 0; i < m; ++i) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (a == 1) {
                for (int j = b; j <= n; j += b) {
                    arr[j] = reverse(arr[j]);
                }
            } else {
                int size = 1;
                arr[b] = reverse(arr[b]);
                while (0 < b - size && b + size <= n) {
                    if (arr[b - size] == arr[b + size]) {
                        arr[b - size] = reverse(arr[b - size]);
                        arr[b + size] = reverse(arr[b + size]);
                    } else {
                        break;
                    }
                    ++size;
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            System.out.printf("%d ", arr[j]);
            if(j % 20 == 0)System.out.println();
        }
        sc.close();
    }
}