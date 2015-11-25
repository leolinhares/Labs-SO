import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiThreadServer implements Runnable {
    Socket csocket;
    MultiThreadServer(Socket csocket) {
        this.csocket = csocket;
    }

    public static void main(String args[])
            throws Exception {
        ServerSocket ssock = new ServerSocket(4444);
        System.out.println("Listening");
        while (true) {
            System.out.println("entrei");
            Socket sock = ssock.accept();
            System.out.println("Connected");
            new Thread(new MultiThreadServer(sock)).start();
        }
    }
    public void run() {
        try {
            System.out.println("thread");

            csocket.close();
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }
}