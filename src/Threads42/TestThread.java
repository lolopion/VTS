package Threads42;
import java.io.IOException;

public class TestThread extends Thread{
private final UniqueId id;
public TestThread(UniqueId id) {
    this.id = id;
}

public void run() {
    try {
            for(int i=0; i<10;i++) {
                int num = id.getNext();
                System.out.println("Thread Name: " + Thread.currentThread().getName() + " || " + num + "\n");
            }
    } catch(IOException ignored) {
        
    }
}
}
