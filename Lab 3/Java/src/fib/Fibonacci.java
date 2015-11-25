package fib;

import java.util.ArrayList;

/**
 * Created by leolinhares on 24/11/15.
 */
public class Fibonacci implements Runnable{

    private int index;
    private ArrayList<Integer> fibList;

    public Fibonacci(int index){
        this.index = index;
        fibList = new ArrayList<Integer>();
    }

    public ArrayList<Integer> getFibList() {
        return fibList;
    }

    @Override
    public void run() {
        for (int i = 0; i < this.index; i++) {
            fibList.add((int)((1 / Math.sqrt(5)) * (Math.pow(((1 + Math.sqrt(5)) / 2), i) - Math.pow(((1 - Math.sqrt(5)) / 2), i))));
        }
    }
}