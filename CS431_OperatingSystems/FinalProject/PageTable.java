class PageTable {
    pte[] table;

    public PageTable() {
        table = new pte[256];

        for(int i=0; i<256; i++) {
            table[i] = new pte(i);
        }
    }

    //returns true if in TLB, false if not
    public pte lookup(int vpn) {
        for(int i=0; i<256; i++) {
            if(vpn == table[i].getVPN()) {
                return table[i];
            }
        }
        return null;
    }
}