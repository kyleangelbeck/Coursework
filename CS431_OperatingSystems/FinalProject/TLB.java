import java.lang.Math;

class TLB {
    pte[] table;
    int[] LRU;
    int FIFO;

    public TLB() {
        table = new pte[4];
        LRU = new int[4];
        FIFO = 0;

        for(int i=0; i<4; i++) {
            table[i] = new pte();
        }
    }

    //returns true if in TLB, false if not
    public boolean lookup(int vpn) {
        for(int i=0; i<4; i++) {
            if(vpn == table[i].getVPN()) {
                //LRU tracking
                for(int j=0; j<4; j++) {
                    LRU[j]++;
                }
                LRU[i] = 0;
                
                return true;
            }
        }
        return false;
    }

    public void LRUinsert(pte p) {
        int tempMax = 0;
        int tempIndex = 0;

        //find highest LRU value
        for(int i=0; i<4; i++) {
            if(LRU[i] > tempMax) {
                tempIndex = i;
                tempMax = LRU[i];
            }
            LRU[i]++;
        }

        table[tempIndex] = p;
        LRU[tempIndex] = 0;
    }

    public void FIFOinsert(pte p) {
        table[FIFO] = p;

        if(FIFO < 3) {
            FIFO++;
        } else {
            FIFO = 0;
        }
    }

    public void Randominsert(pte p) {
        int r = (int) (Math.random() * 4);
        table[r] = p;
    }
}