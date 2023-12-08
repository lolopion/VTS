package Threads41;

public class FigurenThreads{
    
    public static void main(String[] args) {
        Position position1 = new Position('A',0);
        Leser leseThread1 = new Leser(position1);
        Schreiber schreibeThread1 = new Schreiber(position1);
        
        leseThread1.setDaemon(true);
        leseThread1.start();
        
        schreibeThread1.setDaemon(true);       
        schreibeThread1.start();
        
        
        try {
           leseThread1.join();
           schreibeThread1.join();
           
        } catch (InterruptedException ignored) {
            
        }
    }
    
}
