class Solution {
    public int findMaximizedCapital(int k, int capital, int[] profits, int[] capitals) {
        int n = profits.length;
        Project[] projects = new Project[n];
        for (int i = 0; i < n; ++i) {
            projects[i] = new Project(capitals[i], profits[i]);
        }
        Arrays.sort(projects, Comparator.comparingInt(Project::capital));

        var profitMaxHeap = new PriorityQueue<Integer>(Comparator.reverseOrder());
        int projectIndex = 0;
        for (int i = 0; i < k; ++i) {
            while (i < n && projects[i].capital <= capital) {
                profitMaxHeap.add(projects[projectIndex++].profit);
            }
            if (profitMaxHeap.isEmpty()) {
                break;
            }
            capital += profitMaxHeap.poll();
        }
        return capital;
    }

    record Project(int capital, int profit) {}
}