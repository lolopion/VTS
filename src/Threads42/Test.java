package Threads42;
import java.io.IOException;

public class Test{
    private static final int THREAD_COUNT = 5;
    private UniqueId id;
    private TestThread[] threads = new TestThread[THREAD_COUNT];
    public Test() {
        id = new UniqueId("id.dat");
        try {
            id.init(1000);
        } catch(IOException e) {
            
        }
    }
    public void run() {
        for(int i=0; i<THREAD_COUNT; i++) {
            threads[i]= new TestThread(id);
            threads[i].start();
        }
        
        try {
            for(int i =0;i<THREAD_COUNT; i++) {
                threads[i].join();
            }
        } catch (InterruptedException ignored) {
            
        }
    }
}
