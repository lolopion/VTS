package RMI5;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.time.LocalTime;

public class DaytimeImpl extends UnicastRemoteObject implements Daytime {
    public DaytimeImpl() throws RemoteException {
    }
    
    @Override
    public LocalTime getDayTime() throws RemoteException {
        return LocalTime.now();
    }
}
