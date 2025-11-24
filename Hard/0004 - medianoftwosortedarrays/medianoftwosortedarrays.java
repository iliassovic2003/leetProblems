class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2)
    {
        ArrayList<Integer> results = new ArrayList<>();
        int i = 0;
        int j = 0;
        
        while (i < nums1.length && j < nums2.length)
        {
            if (nums1[i] <= nums2[j])
                results.add(nums1[i++]);
            else
                results.add(nums2[j++]);
        }

        while (i < nums1.length)
            results.add(nums1[i++]);
        while (j < nums2.length)
            results.add(nums2[j++]);

        int size = results.size();
        if (size % 2 == 0)
            return (results.get(size / 2 - 1) + results.get(size / 2)) / 2.0;
        else
            return results.get(size / 2);
    }
}