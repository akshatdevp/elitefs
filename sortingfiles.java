/*
Write a program to find top 5 students list of all 3 subjects. 
From the lists print the students info who are present in all lists. 

Note : output rollnos in ascending order.
sample output : [14BD1A040F, 14BD1A0414]

*/
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.HashSet;
import java.util.concurrent.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;
public class CallableFutureTest {
	public static void main(String[] args) throws Exception {
        ExecutorService ex=Executors.newFixedThreadPool(3);
        Callable<HashSet<String>> callablem=()->{
        BufferedReader fm=new BufferedReader(new FileReader("maths.txt"));
        ArrayList<String[]> arr=new ArrayList<>();
        String s;
            while((s=fm.readLine())!=null)
            {
                arr.add(s.split(" "));
            }
            Collections.sort(arr,new Comparator<String[]>() {
                public int compare(String s1[],String s2[])
                {
                    return Integer.parseInt(s2[1])-Integer.parseInt(s1[1]);
                }});
            HashSet<String> hs=new HashSet<>();
            for(int i=0;i<5;i++) hs.add(arr.get(i)[0]);
            return hs;
        };
        Callable<HashSet<String>> callablec=()->{
        BufferedReader fm=new BufferedReader(new FileReader("chemistry.txt"));
        ArrayList<String[]> arr=new ArrayList<>();
        String s;
            while((s=fm.readLine())!=null)
            {
                arr.add(s.split(" "));
            }
            Collections.sort(arr,new Comparator<String[]>() {
                public int compare(String s1[],String s2[])
                {
                    return Integer.parseInt(s2[1])-Integer.parseInt(s1[1]);
                }});
            HashSet<String> hs=new HashSet<>();
            for(int i=0;i<5;i++) hs.add(arr.get(i)[0]);
            return hs;
        };
        Callable<HashSet<String>> callablep=()->{
        BufferedReader fm=new BufferedReader(new FileReader("physics.txt"));
        ArrayList<String[]> arr=new ArrayList<>();
        String s;
            while((s=fm.readLine())!=null)
            {
                arr.add(s.split(" "));
            }
            Collections.sort(arr,new Comparator<String[]>() {
                public int compare(String s1[],String s2[])
                {
                    return Integer.parseInt(s2[1])-Integer.parseInt(s1[1]);
                }});
            HashSet<String> hs=new HashSet<>();
            for(int i=0;i<5;i++) hs.add(arr.get(i)[0]);
            return hs;
        };
        Future<HashSet<String>> f1=ex.submit(callablem);
        Future<HashSet<String>> f2=ex.submit(callablep);
        Future<HashSet<String>> f3=ex.submit(callablec);
        while(!f1.isDone()&&!f2.isDone()&&!f3.isDone());
        HashSet<String> hs1=f1.get(),hs2=f2.get(),hs3=f3.get();
        ArrayList<String> asas=new ArrayList<>();
        //for(String sss[]:hs2)System.out.println(sss[0]);
        //for(String sss[]:hs3)System.out.println(sss[0]);
        for(String sss:hs1)
        {
            if(hs2.contains(sss)&&hs3.contains(sss)) asas.add(sss);
        }
        System.out.println(asas);
        ex.shutdown();
		// Write Your Code Here
	}
//	Thread t1=new Thread();
	
}