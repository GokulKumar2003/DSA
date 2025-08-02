class Solution {
    public int latestTimeCatchTheBus(int[] buses, int[] passengers, int capacity) {
        Arrays.sort(buses);
        Arrays.sort(passengers);

        int b = 0, p = 0, cnt = 0;

        while(b < buses.length){
            cnt = 0;
            while(p < passengers.length && cnt < capacity && passengers[p] <= buses[b]){
                p++;
                cnt++;
            }

            if(b == buses.length - 1){
                p--;
                if(cnt < capacity){
                    int time = buses[b];
                    while(p >= 0 && time == passengers[p]){
                        time--;
                        p--;
                    }
                    return time;
                }
                else{
                    int time = passengers[p] - 1;
                    p--;
                    while(p>=0 && time == passengers[p]){
                        time--;
                        p--;
                    }
                    return time;
                }
            }
            b++;
        }

        return buses[buses.length - 1];
    }
}