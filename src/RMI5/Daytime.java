package RMI5;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.time.LocalTime;
public interface Daytime extends Remote{
    LocalTime getDayTime() throws RemoteException;
}
