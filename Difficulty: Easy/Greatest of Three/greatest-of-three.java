//Back-end complete function Template for Java
import java.util.*;

public class Solution {
    public static void main(String args[]) {
         Scanner s = new Scanner(System.in);
        int a=s.nextInt();
        int b=s.nextInt();
        int c=s.nextInt();
        int ans = a > b ? a > c ? a : c : b > c ? b : c;
        System.out.println(ans);
    }
}