package Threads41;

public class Position extends Figur{
    public Position(char X, int Y) {
        x=X;
        y=Y;
    }
    public synchronized String getPosition() {
        MachMal.eineSekundeLangGarNichts();
        return "Queen ist auf dem Feld "+x+y+"\n";
    }

    public synchronized void setPosition(char Buchstabe, int Zahl) {
        x = Buchstabe;
        MachMal.eineZehntelSekundeLangGarNichts();
        y= Zahl;
    }
}
