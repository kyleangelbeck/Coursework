class pte {
    int vpn;    //virtual page number
    int pfn;    //physical frame number
    boolean dirty, valid, protection, present;

    public pte() {
        vpn = -1;
    }

    public pte(int v) {
        vpn = v;
    }

    public int getVPN() {return vpn;}
    public void setVPN(int v) {vpn = v;}
}