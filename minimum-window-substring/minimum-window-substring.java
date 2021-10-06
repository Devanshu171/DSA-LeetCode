class Solution {
    public String minWindow(String s, String t) {
          Map<Character, Integer> mp = new HashMap<>();
        for(int k = 0; k < t.length(); k++)
        {
            mp.put(t.charAt(k), mp.getOrDefault(t.charAt(k), 0) +1);
        }
        int i = 0, j = 0, count = mp.size(), min = Integer.MAX_VALUE;
        int[] res = new int[2];
        while(j < s.length())
        {
            if(mp.containsKey(s.charAt(j)))
            {
                mp.put(s.charAt(j), mp.get(s.charAt(j)) - 1);
                if(mp.get(s.charAt(j)) == 0)
                {
                    count--;
                }
                j++;
            }
            else
            {
                j++;
            }
            if(count == 0)
            {
                
                while(count == 0)
                {
                    if(j-i < min)
                    {
                        min = j-i;
                        res[0] = i;
                        res[1] = j;
                    }
                    if(mp.containsKey(s.charAt(i)))
                    {
                        mp.put(s.charAt(i), mp.get(s.charAt(i)) + 1);
                        if(mp.get(s.charAt(i)) > 0)
                            count++;
                        i++;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        i = res[0];
        j = res[1];
        while(i < j)
        {
            sb.append(s.charAt(i++));
        }
        return sb.toString();
    }
}