class Solution {
    public String reverseByType(String s){
        StringBuilder str1 = new StringBuilder();
        StringBuilder str2 = new StringBuilder();

        // Separate lowercase letters and others
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                str1.append(ch);
            } else {
                str2.append(ch);
            }
        }

        // Reverse both
        str1.reverse();
        str2.reverse();

        StringBuilder ans = new StringBuilder();
        int j = 0, k = 0;

        // Rebuild answer
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                ans.append(str1.charAt(k));
                k++;
            } else {
                ans.append(str2.charAt(j));
                j++;
            }
        }

        return ans.toString();
    }
}
