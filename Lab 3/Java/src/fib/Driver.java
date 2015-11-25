package fib;

/**
 * Created by leolinhares on 24/11/15.
 */
public class Driver {

    public static void main(String[] args){
        int quantity = Integer.parseInt(args[0]);
        Fibonacci fib = new Fibonacci(quantity);
        Thread worker = new Thread(fib);
        worker.start();
        try{
            worker.join();
            System.out.println(fib.getFibList());
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
