import java.util.*;
public class Solution {
    public int countSteps(int ringIndex, int i, int n) {
        int dist = Math.abs(i - ringIndex);
        int wrapAround = n - dist;
        return Math.min(dist, wrapAround);
    }
    public int findRotateSteps(String ring, String key) {
        int n = ring.length();
        int m = key.length();
        Map<Character, List<Integer>> adj = new HashMap<>();
        for (int i = 0; i < ring.length(); i++) {
            char ch = ring.charAt(i);
            if (!adj.containsKey(ch)) {
                adj.put(ch, new ArrayList<>());
            }
            adj.get(ch).add(i);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});
        Set<String> visited = new HashSet<>();
        int totalSteps = 0;
        while (!pq.isEmpty()) {
            int[] vec = pq.poll();
            totalSteps = vec[0];
            int ringIndex = vec[1];
            int keyIndex = vec[2];
            if (keyIndex == m) {
                break;
            }
            if (visited.contains(ringIndex + "-" + keyIndex)) {
                continue;
            }
            visited.add(ringIndex + "-" + keyIndex);
            for (int nextIndex : adj.get(key.charAt(keyIndex))) {
                pq.offer(new int[]{totalSteps + countSteps(ringIndex, nextIndex, n), 
                            nextIndex, keyIndex + 1});
            }
        }
        return totalSteps + m;
    }
}
