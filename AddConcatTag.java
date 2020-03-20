/*
Given a string s and a list of strings dictionary, 
you need to add a closed pair of 'concat' tag <c> and </c> to wrap the substrings
in s that exist in dictionary. If two such substrings overlap, 
you need to wrap them together by only one pair of closed concat tag. 
Also, if two substrings wrapped by concat tags are consecutive, you need to combine them.


Example 1:

Input=	abcxyz123
		abc 123
Output= <c>abc</c>xyz<c>123</c>

Example 2:
Input=	aaabbcc
		aaa aab bc
Output= <c>aaabbc</c>c

Example 3:
Input=	abcdef
		ghijkl abc
Output= <c>abc</c>def

Note:
The given dictionary won't contain duplicates, and its length won't exceed 100.
 

----------TestCase------------

case =1
input =abcdefghijklmn
abc fgh kmln
OP ='<c>abc</c>de<c>fgh</c>ijklmn'

case =2
input =keshavmemorialinstituteoftechnology
keshav memorial institute technology
OP ='<c>keshavmemorialinstitute</c>of<c>technology</c>'

case =3
input =abcdefghijklm
nopqrstuv wxyz abc
OP ='<c>abc</c>defghijklm'

case =4
input =abcdefghijklmnopqrstuvwxyz
no a hi cd nop
OP ='<c>a</c>b<c>cd</c>efg<c>hi</c>jklm<c>nop</c>qrstuvwxyz'

case =5
input =netajisubhashchandrabose
chandra bose netaji
OP ='<c>netaji</c>subhash<c>chandrabose</c>'

case =6
input =kmit
ngit
OP ='kmit'

*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class AddConcatTag {

	public static String addconcatTag(String s, String[] dict) {
        int n = s.length();
        int[] mark = new int[n+1];
        for(String d : dict) {
            int i = -1;
            while((i = s.indexOf(d, i+1)) >= 0) {
                mark[i]++;
                mark[i + d.length()]--;
            }
        }
        StringBuilder sb = new StringBuilder();
        int sum = 0;
        for(int i = 0; i <= n; i++) {
            int cur = sum + mark[i];
            if (cur > 0 && sum == 0) sb.append("<c>");
            if (cur == 0 && sum > 0) sb.append("</c>");
            if (i == n) break;
            sb.append(s.charAt(i));
            sum = cur;
        }
        return sb.toString();
    }
	
	public static void main(String args[] ) throws IOException {

	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String word = br.readLine();
		String line = br.readLine();
		String[] dic = line.split(" ");
		System.out.println(addconcatTag(word,dic)); 
		
		}
}
