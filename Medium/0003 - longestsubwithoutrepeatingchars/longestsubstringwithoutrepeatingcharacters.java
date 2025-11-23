class Solution {
    public int lengthOfLongestSubstring(String s)
    {
        int length = 0;
        int start = 0;

        Map<Character, Integer>   mySet = new HashMap<>();
        for (int i = 0; i < s.length(); i++)
        {
            if (mySet.containsKey(s.charAt(i)))
                start = Math.max(start, mySet.get(s.charAt(i)) + 1);
            
            mySet.put(s.charAt(i), i);
            length = Math.max(length, i - start + 1);
        }
        return length;
    }
}