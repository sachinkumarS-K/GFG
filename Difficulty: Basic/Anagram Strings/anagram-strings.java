// User function template for Java
class Solution {
    static int areAnagram(String S1, String S2) {
        // code here
        if(S1.length() != S2.length())
            return 0;
        int []hash = new int[26];
        for(int i = 0 ; i<S1.length() ; i++){
            hash[S1.charAt(i) - 'a']++;
            hash[S2.charAt(i) - 'a']--;
        }
        for(int i = 0 ; i<26 ; i++){
            if(hash[i] > 0)
                return 0;
        }
        return 1;
    }
}