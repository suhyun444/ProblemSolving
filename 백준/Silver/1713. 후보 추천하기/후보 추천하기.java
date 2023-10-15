import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
class Main {

    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<Integer>();
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[]vote = new int[n];
        int[]arr = new int[101];
        for(int i=0;i<m;++i)
        {
            int a =sc.nextInt();
            ++arr[a];
            if(q.size() < n)
            {
                int size = q.size();
                boolean hasVote = false;
                for(int j=0;j<size;++j)
                {
                    int cur = q.poll();
                    q.add(cur);
                    if(cur == a)
                    {
                        hasVote = true;
                    }
                }
                if(!hasVote)
                {
                    q.add(a);
                }
            }
            else
            {
                int min = 1001;
                int minIndex = 0;
                int size = q.size();
                boolean hasVote = false;
                for(int j=0;j<size;++j)
                {
                    int cur = q.poll();
                    q.add(cur);
                    if(cur == a)
                    {
                        hasVote = true;
                    }
                    if(arr[cur] < min)
                    {
                        min = arr[cur];
                        minIndex = cur;
                    }
                }
                if(!hasVote)
                {
                    for(int j=0;j<size;++j)
                    {
                        int cur = q.poll();
                        if(cur != minIndex)q.add(cur);
                    }
                    arr[minIndex] = 0;
                    q.add(a);
                }
            }
        }
        n = q.size();
        for(int i=0;i<n;++i)
        {
            vote[i] = q.poll();
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-1;++j)
            {
                if(vote[j] > vote[j + 1])
                {
                    int tmp = vote[j];
                    vote[j] = vote[j + 1];
                    vote[j + 1] = tmp;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            System.out.printf("%d ",vote[i]);
        }
        sc.close();
    }
}