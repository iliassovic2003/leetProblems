class Solution {
    public boolean isValid(String s)
    {
        Deque<Character> deque = new ArrayDeque<>();

        for (char c : s.toCharArray())
        {
            switch (c)
            {
                case '(' -> deque.push(')');
                case '{' -> deque.push('}');
                case '[' -> deque.push(']');
                default -> {
                    if (deque.isEmpty() || deque.pop() != c)
                        return false;
                }
            }
        }

        return deque.isEmpty();
    }
}