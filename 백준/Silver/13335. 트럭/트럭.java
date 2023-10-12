import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Truck
{
    int weight;
    int time;
}
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int l = sc.nextInt();
        int[] arr = new int[n];
        Queue<Truck> q = new LinkedList<>();
        for(int i=0;i<n;++i)
        {
            arr[i] = sc.nextInt();
        }
        int time = 0;
        int index = 0;
        int weight = 0;
        int result = 0;
        while(result < n)
        {
            while(!q.isEmpty() && q.peek().time + w <= time)
            {
                Truck t = q.poll();
                ++result;
                weight -= t.weight;
            }
            if(index < n && weight + arr[index] <= l)
            {
                Truck t = new Truck();
                t.time = time;
                t.weight = arr[index];
                weight += t.weight;
                q.add(t);
                ++index;
            }
            ++time;
        }
        System.out.print(time);
        sc.close();
    }
}