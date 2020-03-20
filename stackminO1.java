import java.util.*;
import java.io.*;
class STA
{
    public Stack<Integer> s;
    public int min=Integer.MAX_VALUE;
    STA()
    { 
        s=new Stack<Integer>();}
    void push(int a)
    {
     //System.out.println("PUS");   
        if(min>a)
        {s.push(min);min=a;}
        s.push(a);
    }
    void pop()
    {//System.out.println("POP");
        if(min==s.peek())
        {s.pop();
        min=s.peek();}
        s.pop();
    }
    void top()
    {  // System.out.println("SDF");
        System.out.println(s.peek());
    }
    void getMin()
    {//System.out.println("MONINDS");
        System.out.println(min);     
        
    }
    
}
public class ABc{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String[] s;
        STA st=new STA();
        do
        {
             s=sc.nextLine().split(" ");
            if(s[0].equals("top"))
            st.top();
            if(s[0].equals("pop"))
            st.pop();
            if(s[0].equals("getmin"))
            st.getMin();
            if(s[0].equals("push"))
            st.push(Integer.parseInt(s[1]));
        }while(!s[0].equals("top")&&!s[0].equals("getmin"));
        
        
    }
}
