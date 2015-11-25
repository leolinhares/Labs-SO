package fib;

/**
 * Created by leolinhares on 24/11/15.
 */
public class Fibonacci implements Runnable{

    int index;

    public Fibonacci(int index){
        this.index = index;
    }

    @Override
    public void run() {
        for (int i = 0; i < this.index; i++) {
            System.out.format("%.0f\n",(1 / Math.sqrt(5)) * (Math.pow(((1 + Math.sqrt(5)) / 2), i) - Math.pow(((1 - Math.sqrt(5)) / 2), i)));
        }
    }
}