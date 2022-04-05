# Generate IP Addresses
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a string <strong>S</strong>&nbsp;containing only digits, Your task is to complete the function <strong>genIp()&nbsp;</strong>which returns a vector containing all possible combinations&nbsp;of valid IPv4 IP addresses and takes only a string <strong>S</strong>&nbsp;as its only argument.<br>
<strong>Note: </strong>Order doesn't matter.<br>
<br>
For string 11211 the IP address possible are&nbsp;<br>
1.1.2.11<br>
1.1.21.1<br>
1.12.1.1<br>
11.2.1.1</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>S = 1111
<strong>Output: </strong>1.1.1.1
</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
S = 55
<strong>Output:</strong> -1</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong></span></p>

<p><span style="font-size:18px">Your task is to complete the function <strong>genIp()&nbsp;</strong>which returns a vector containing all possible combinations&nbsp;of valid IPv4 IP addresses in sorted order or <strong>-1 if no such IP address could be generated</strong> through the input string <strong>S</strong>,&nbsp;the only argument to the function.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N * N * N * N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(N * N * N * N)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=16<br>
here, N = length of S.<br>
S only contains digits(i.e. 0-9)</span></p>
 <p></p>
            </div>