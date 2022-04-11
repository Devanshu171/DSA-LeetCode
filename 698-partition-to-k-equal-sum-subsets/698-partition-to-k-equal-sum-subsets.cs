public class Solution {
    public bool CanPartitionKSubsets(int[] nums, int k)
    {
        int totalSum = 0;
        foreach (int number in nums) totalSum += number;

        (int targetSetSum, int remainder) = Math.DivRem(totalSum, k);

        if (remainder != 0) return false;

        bool[] usedSoFar = new bool[nums.Length];

        return CanPartition(0, 0, k);
        

        bool CanPartition(int start, int sumSoFar, int subsetsRemaining)
        {            
            if (subsetsRemaining == 0) return true;
                      
            if (sumSoFar == targetSetSum) return CanPartition(0, 0, subsetsRemaining - 1);

            for (int i = start; i < nums.Length; i++)
            {
                if (usedSoFar[i] || sumSoFar + nums[i] > targetSetSum) continue;
 
                usedSoFar[i] = true;
                if (CanPartition(i + 1, sumSoFar + nums[i], subsetsRemaining)) return true;
                usedSoFar[i] = false;
            }

            return false;
        }
    }
}