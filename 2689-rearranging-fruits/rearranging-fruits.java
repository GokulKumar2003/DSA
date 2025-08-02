class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        
        Map<Integer, Integer> m = new HashMap<>();
        int mini = Integer.MAX_VALUE;

        for(int i=0;i<basket1.length;i++){
            m.put(basket1[i], m.getOrDefault(basket1[i], 0) + 1);
            m.put(basket2[i], m.getOrDefault(basket2[i], 0) - 1);
            mini = Math.min(mini, Math.min(basket1[i], basket2[i]));
        }

        List<Integer> arr = new ArrayList<>();
        for(var entry : m.entrySet()){
            int cnt = entry.getValue();
            if(cnt%2 != 0){
                return -1;
            }
            for(int i=0;i<Math.abs(cnt)/2;i++){
                arr.add(entry.getKey());
            }
        }

        Collections.sort(arr);
        long ans = 0;
        for(int i=0;i<arr.size()/2;i++){
            ans += Math.min(2*mini, arr.get(i));
        }
        return ans;
    }
}