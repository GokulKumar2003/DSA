class ZeroEvenOdd {
    private int n;
    
    private Semaphore zero;
    private Semaphore odd;
    private Semaphore even;
    public ZeroEvenOdd(int n) {
        this.n = n;
        this.zero = new Semaphore(1);
        this.even = new Semaphore(0);
        this.odd = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        
        boolean isOdd = true;
        for(int i=0;i<n;i++){
            zero.acquire();
            printNumber.accept(0);

            if(isOdd){
                odd.release();
            }
            else{
                even.release();
            }

            isOdd = !isOdd;

        }
    
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        int evenNum = 2;
        while(evenNum<=n){
            even.acquire();
            printNumber.accept(evenNum);
            evenNum += 2;
            zero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        int oddNum = 1;
        while(oddNum <= n){
            odd.acquire();
            printNumber.accept(oddNum);
            oddNum += 2;
            zero.release();
        }
    }
}