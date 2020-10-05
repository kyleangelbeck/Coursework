
public class Symbol {

    String name;
    int pointer;

    public Symbol(String n, int p) {
        name = n;
        pointer = p;
    }

    public String getSymbol() {
        return name;
    }

    public int getPointer() {
        return pointer;
    }

    public void updatePointer(int p) {
        pointer = p;
    }

}
