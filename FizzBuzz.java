/*
Write a program that outputs the string representation of numbers from 1 to n, however:

If the number is divisible by 3, output "fizz".
If the number is divisible by 5, output "buzz".
If the number is divisible by both 3 and 5, output "fizzbuzz".
For example, for n = 15, we output: 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz.

Suppose you are given the following code:

class FizzBuzz {
  public FizzBuzz(int n) { ... }               // constructor
  public void fizz(printFizz) { ... }          // only output "fizz"
  public void buzz(printBuzz) { ... }          // only output "buzz"
  public void fizzbuzz(printFizzBuzz) { ... }  // only output "fizzbuzz"
  public void number(printNumber) { ... }      // only output the numbers
}
Implement a multithreaded version of FizzBuzz with four threads. The same instance of FizzBuzz will be passed to four different threads:

Thread A will call fizz() to check for divisibility of 3 and outputs fizz.
Thread B will call buzz() to check for divisibility of 5 and outputs buzz.
Thread C will call fizzbuzz() to check for divisibility of 3 and 5 and outputs fizzbuzz.
Thread D will call number() which should only output the numbers.

Sample :
Input:  15
Output: 1
        2
        fizz
        4
        buzz
        fizz
        7
        8
        fizz
        buzz
        11
        fizz
        13
        14
        fizzbuzz

*/

import java.util.function.IntConsumer; 
import java.io.*;
import java.util.Scanner;

    //};

class One implements Runnable{
    FizzBuzz c;
    public One(FizzBuzz fb){c=fb;}
    public void run()
    {
        c.fizz();
    }
}	
class Two implements Runnable{
    FizzBuzz c;
    public Two(FizzBuzz fb){c=fb;}
    public void run()
    {
        c.buzz();
    }
}	
class Three implements Runnable{
    FizzBuzz c;
    public Three(FizzBuzz fb){c=fb;}
    public void run()
    {
        c.fizzbuzz();
    }
}	
class Four implements Runnable{
    FizzBuzz c;
    public Four(FizzBuzz fb){c=fb;}
    public void run()
    {
        c.num();
    }
}	
class FizzBuzz{
    int i,n=1;
   // Runnable fizz=new Runnable(){
        public synchronized void fizz()
        {
            while(n<=i){
         if(n%3==0&&n%5!=0)
            {System.out.println("fizz");n++;
            notifyAll();}
         else try{wait();}catch(Exception e){}}
        }
    //};
  //  Runnable buzz=new Runnable(){
        public synchronized void buzz()
        {
         while(n<=i){    
         if(n%5==0&&n%3!=0)
            {System.out.println("buzz");n++;
            notifyAll();}
        else try{wait();}catch(Exception e){}}
        }
//    };
//	Runnable fizzbuzz=new Runnable(){
        public synchronized void fizzbuzz()
        {
        while(n<=i){
         if(n%3==0&&n%5==0)
            {System.out.println("fizzbuzz");n++;
            notifyAll();}
        else try{wait();}catch(Exception e){}}
        }
  //  };
	//Runnable num=new Runnable(){
        public synchronized void num()
        {
            while(n<=i){
            if(n%3!=0&&n%5!=0){
            System.out.println(n);n++;
            notifyAll();}
            else try{wait();}catch(Exception e){}}
            
        }
	public static void main(String[] args) throws IOException {
    	Scanner sc=new Scanner(System.in);
    	int n=sc.nextInt();
    	FizzBuzz f=new FizzBuzz();
    	f.i=n;
    	    One o=new One(f);
    	    Two oo=new Two(f);
    	    Three ooo=new Three(f);
    	    Four oooo=new Four(f);
    	    Thread t1=new Thread(o);
    	    Thread t2=new Thread(oo);
    	    Thread t3=new Thread(ooo);
    	    Thread t4=new Thread(oooo);
    	    t1.start();
    	    t2.start();
    	    t3.start();
    	    t4.start();
    	
	}
}
