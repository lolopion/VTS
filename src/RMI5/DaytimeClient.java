package RMI5;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.time.LocalTime;

public class DaytimeClient {
    public static void main(String[] args) {
        String host = args[0];
        System.out.println("Local starttime ist: "+ LocalTime.now());
        System.out.println("Remote time ist: "+ getRemoteTime(host));
        System.out.println("Local endtime ist: "+LocalTime.now());
    }
    public static LocalTime getRemoteTime(String host) {
        LocalTime localTime=null;
        try {
            Daytime remote = (Daytime) Naming.lookup("//"+ host + "/daytime");
            localTime = remote.getDayTime();
        } catch(RemoteException | MalformedURLException | NotBoundException e) {
            e.printStackTrace();
            System.exit(0);
        }
        return localTime;
    }
}
