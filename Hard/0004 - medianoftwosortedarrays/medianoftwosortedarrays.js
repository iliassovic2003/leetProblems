var findMedianSortedArrays = function(nums1, nums2)
{
    let results = [];
    let i = 0;
    let j = 0;
    
    while (i < nums1.length && j < nums2.length)
    {
        if (nums1[i] <= nums2[j])
            results.push(nums1[i++]);
        else
            results.push(nums2[j++]);
    }

    while (i < nums1.length)
        results.push(nums1[i++]);
    while (j < nums2.length)
        results.push(nums2[j++]);

    if (results.length % 2 == 0)
        return ((results[results.length / 2 - 1] + results[results.length / 2]) / 2.0);
    else
        return results[Math.floor(results.length / 2)];
};