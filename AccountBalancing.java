/*
A group of friends went on holiday and sometimes lent each other money. 
For example, Amith paid for Babu's lunch for Rs.10. Then later Charan gave Amith Rs.5 for a taxi ride. 
We can model each transaction as a tuple (x, y, z) which means person x gave person y Rs.z. 
Assuming Amith, Babu, and Charan are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), 
the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, 
return the minimum number of transactions required to settle the debt.

Note:
A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or 
we could also have the persons 0, 2, 6.


Example 1:
	Input=	2
			0 1 10
			2 0 5
	Output= 2

	Explanation:
		Person #0 gave person #1 Rs.10.
		Person #2 gave person #0 Rs.5.
		Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 Rs.5 each.

Example 2:
	Input=	4
			0 1 10
			1 0 1
			1 2 5
			2 0 5
	Output=	1
	Explanation:
		Person #0 gave person #1 Rs.10.
		Person #1 gave person #0 Rs.1.
		Person #1 gave person #2 Rs.5.
		Person #2 gave person #0 Rs.5.
		Therefore, person #1 only need to give person #0 Rs.4, and all debt is settled.

----------TestCase------------
case =1
input =5
1 4 10
3 5 20
4 5 15
5 1 20
4 3 10
OP =2

case =2
input =6
1 2 10
2 3 20
3 4 40
4 5 50
5 6 60
6 1 10
OP =4

case =3
input =6
1 2 10
2 3 20
3 4 40
4 5 50
5 6 60
6 7 70
OP =6

case =4
input =6
1 5 50
2 5 30
5 3 70
3 2 30
3 1 40
5 1 10
OP =0

case =5
input =7
1 5 20
2 6 20
3 7 20
4 8 20
5 4 20
6 3 20
7 2 20
OP =1

case =6
input =8
1 2 5
3 7 5
2 4 5
10 3 5
7 11 5
4 8 5
9 12 5
6 9 5
OP =3

 */
import java.util.*;
public class AccountBalancing {
	public static int minTransfers(int[][] transactions) {
        Map<Integer, Integer> m = new HashMap<>();
        for (int[] t : transactions) {
            m.put(t[0], m.getOrDefault(t[0], 0) - t[2]);
            m.put(t[1], m.getOrDefault(t[1], 0) + t[2]);
        }
        return settle(0, new ArrayList<>(m.values()));
    }

    static int settle(int start, List<Integer> debt) {
        while (start < debt.size() && debt.get(start) == 0)
            start++;
        if (start == debt.size()) return 0;
        int r = Integer.MAX_VALUE;
        for (int i = start + 1; i < debt.size(); i++)
            if (debt.get(start) * debt.get(i) < 0) {
                debt.set(i, debt.get(i) + debt.get(start));
                r = Math.min(r, 1 + settle(start + 1, debt));
                debt.set(i, debt.get(i) - debt.get(start));
            }
        return r;
    }
    
    public static void main(String args[] ) {
		 Scanner scan = new Scanner(System.in);
			int n=scan.nextInt();
			
			int[][] transactions=new int[n][3];
		       for(int i=0; i<n; i++)
		       {
		           for(int j=0; j<3; j++)
		           {
		        	   transactions[i][j] = scan.nextInt();
		           }
		       }
		       System.out.println(minTransfers(transactions));
	}
}
