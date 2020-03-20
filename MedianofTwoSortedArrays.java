import java.util.Scanner;
public class  MedianofTwoSortedArrays
    {
        public double findMedianSortedArrays(int[] n1, int[] n2) 
            {
                int l1=n1.length,l2=n2.length;
                if(l1>l2) return findMedianSortedArrays(n2,n1);
                int start=0,end=l1;
                while(start<=end)
                {
                    int p1=(start+end)/2,p2=(l1+l2+1)/2 -p1;
                    int n1l=p1==0?Integer.MIN_VALUE:n1[p1-1];
                    int n1r=p1==l1?Integer.MAX_VALUE:n1[p1];
                    int n2l=p2==0?Integer.MIN_VALUE:n2[p2-1];
                    int n2r=p2==l2?Integer.MAX_VALUE:n2[p2];
                    
                    if(n1l<=n2r&&n2l<=n1r) return (l1+l2)%2==0?(double)(Math.max(n1l,n2l)+Math.min(n2r,n1r))/2:Math.max(n1l,n2l);
                    else if(n1l>n2r) end=p1-1;
                    else start=p1+1;
                }
            return -1;
            }
	public static void main(String args[]){
	Scanner sc=new Scanner(System.in);
	int s1=sc.nextInt();
	int s2=sc.nextInt();
	int arr[]=new int[s1];
	int arr2[]=new int[s2];
	for(int i=0;i<s1;i++)
		arr[i]=sc.nextInt();	

	for(int i=0;i<s2;i++)
		arr2[i]=sc.nextInt();	
	System.out.println((new MedianofTwoSortedArrays()).findMedianSortedArrays(arr,arr2));
	}
	}
