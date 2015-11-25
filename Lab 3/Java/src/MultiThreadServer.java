import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class MultiThreadServer implements Runnable {
    Socket client;
    MultiThreadServer(Socket client) {
        this.client = client;
    }

    public static void main(String args[])
            throws Exception {
        ServerSocket sock = new ServerSocket(6013);

        while (true) {
            Socket client = sock.accept();
            new Thread(new MultiThreadServer(client)).start();
        }
    }
    public void run() {
        try {
            PrintWriter pout = new PrintWriter(client.getOutputStream(), true);
            pout.println(new java.util.Date().toString());
            client.close();
        }
        catch (IOException e) {
            System.out.println(e);
        }
    }
}