package fib;

/**
 * Created by leolinhares on 24/11/15.
 */
public class Driver {

    public static void main(String[] args){
        Fibonacci f1 = new Fibonacci(10);
        Thread worker = new Thread(f1);
        worker.start();
        try{
            worker.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
