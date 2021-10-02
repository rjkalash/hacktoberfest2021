package l3_net_progamming;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
/**
 *
 * @author Lakshitha Samod
 */
public class SimpleServer {
    
    public static void main(String[] args) {
        try {
            System.out.println("1. about to create server socket");
            ServerSocket server = new ServerSocket(50001);
            System.out.println("2. server socket created");
            
            System.out.println("3. about to  accept client");
            Socket client = server.accept();
            System.out.println("4. client accepted");
            
             System.out.println("5. about to  write data to client");
            DataOutputStream os = new DataOutputStream(client.getOutputStream());
             System.out.println("6. finished writing data to a client client");
            
            //os.writeBytes("hello sockets\n");
             System.out.println("7. about to  close client connection");
            client.close();
             System.out.println("8. client connection closed");
            
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
