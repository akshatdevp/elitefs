/*
Given a list of phrases, generate a list of Join Phrases.

A phrase is a string that consists of lowercase English letters and spaces only. 
No space appears in the start or the end of a phrase. 
There are no consecutive spaces in a phrase.

Join Phrases are phrases that are formed by merging two phrases 
where the last word of the first phrase is the same as the first word of the second phrase.

Return the Join Phrases that can be formed by every two phrases
phrases[i] and phrases[j] where i != j. Note that the order of matching two phrases matters, 
we want to consider both orders.

You should return a list of distinct strings sorted lexicographically.

Example 1:
	Input= writing code,code rocks
	Output= [writing code rocks]

Example 2:
	Input=	road,a coffee,road map,coffee bite,coffee cup
	Output= [a coffee bite, a coffee cup, road map]

Example 3:
Input=	a,b,a
Output= [a]

----------TestCase------------
case =1
input =abc def,def ghi,ghi ijk,ijk klmno,klmno pqr
OP ='[abc def ghi, def ghi ijk, ghi ijk klmno, ijk klmno pqr]'

case =2
input =ace institute,institute of enterprise
OP ='[ace institute of enterprise]'

case =3
input =creative minds,mindspace,space agency
OP ='[]'

case =4
input =creative minds,minds pace,space agency,space org,minds can
OP ='[creative minds can, creative minds pace]'

case =5
input =creative minds,mind space,space agency,space org,minds can
OP ='[creative minds can, mind space agency, mind space org]'

case =6
input =mission statement,a quick bite to eat,a chip off the old block,chocolate bar,mission impossible,a man on a mission,block party,eat my words,bar of soap
OP ='[a chip off the old block party,a man on a mission impossible, a man on a mission statement, a quick bite to eat my words, chocolate bar of soap]'

 */

import java.util.*;

public class JoinPhrases {
	public static List<String> joinPhrases(String[] phrases) {
        Map<String, List<Integer>> map = new HashMap<>();
        int i = 0;
        for(String str: phrases){
            String first = str.split(" ")[0];
            if(map.containsKey(first)==false){
                map.put(first, new ArrayList<>());
            } 
            map.get(first).add(i);
            i++;
        }
        
        i = 0;
        Set<String> res = new HashSet<>();
        for(String str: phrases){
            int ind = str.lastIndexOf(" ");
            String last = ind>=0?str.substring(ind+1):str;
            if(map.containsKey(last)){
                for(int index: map.get(last)){
                    if(index == i){
                        continue;
                    }
                    
                    res.add(str + phrases[index].substring(last.length()));
                }
            }
            i++;
        }
        
        List<String> ans = new ArrayList<>(res);
        Collections.sort(ans);
        return ans;
    }
	public static void main(String args[])
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		String[] phrases=s.split(",");
		System.out.println(joinPhrases(phrases));
	}
}
