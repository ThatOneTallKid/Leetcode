class Solution {
 private:
    int colours[100] = {};
    bool exploreFromNode(vector<vector<int>>& graph, int startNode = 0, bool isGroupA = true) {
        // marking the start node
        colours[startNode] = isGroupA ? 1 : -1;
        // parsing all of startNode neighbours
        for (int n: graph[startNode]) {
            // checking if we already visited neighbour n
            if (colours[n]) {
                // if it is the same colour as the current one, we return false
                if (colours[n] == (isGroupA ? 1 : -1)) return false;
            }
            // if not, we recurse from it
            else {
                if (!exploreFromNode(graph, n, !isGroupA)) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for (int i = 0, lmt = graph.size(); i < lmt; i++) {
            // checking unexplored nodes only for bipartition
            if (!colours[i] && !exploreFromNode(graph, i)) return false;
        }
        return true;
    }
};