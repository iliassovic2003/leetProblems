class Solution {
    public List<List<Integer>> generate(int numRows)
    {
        List<List<Integer>>     triangle = new ArrayList<>();
        
        for (int i = 0; i < numRows; i++)
        {
            List<Integer> row = new ArrayList<>(i + 1);

            for (int k = 0; k <= i; k++)
                row.add(1);

            for (int j = 1; j < i; j++)
                row.set(j, triangle.get(i - 1).get(j - 1) + triangle.get(i - 1).get(j));

            triangle.add(row);
        }
        return (triangle);
    }
}