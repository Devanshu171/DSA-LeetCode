# Print Anagrams Together
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.</span></p>

<p><strong><span style="font-size:18px">Note: The finial output will be in&nbsp;lexicographic order.</span></strong></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 5
words[] = {act,god,cat,dog,tac}
<strong>Output:
</strong>act cat tac<strong> 
</strong>god dog<strong>
Explanation:
</strong>There are 2 groups of
anagrams "god", "dog" make group 1.
"act", "cat", "tac" make group 2.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>N = 3
words[] = {no,on,is}
<strong>Output: 
</strong>no on
is<strong>
Explanation:
</strong>There are 2 groups of
anagrams "no", "on" make group 1.
"is" makes group 2.&nbsp;</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
The task is to complete the function <strong>Anagrams()</strong> that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*|S|*log|S|), where |S| is the length of the strings.<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N*|S|), where |S| is the length of the strings.</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=100</span></p>

<p><span style="font-size:18px">1&lt;=|S|&lt;=10</span></p>
 <p></p>
            </div>