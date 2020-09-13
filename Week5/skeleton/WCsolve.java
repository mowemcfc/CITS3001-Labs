/**
 * Applies uninformed search algorithms to Word Chess puzzles. 
 * For a problem like SICK -> WELL, you need to return a solution 
 * in the form <"SICK", "SILK", "SILL", "WILL", "WELL">.
 */
import java.util.*;

public class WCsolve
{
    public WCsolve(){}

    public static ArrayList<String> result;
    /**
     * Solves the puzzle start -> target using breadth-first search. 
     * Returns one optimal solution. 
     */
    public static ArrayList<String> solve(String start, String target)
    {
        result = new ArrayList<String>();
        BFS(start, target); 
        
        return result;
    }

    private static void BFSUtil(ArrayList<String> frontier, String target, int depth, Map<String, String> parents, Set<String> visited) {
        ArrayList<String> newFrontier = new ArrayList<String>();

        if(!result.isEmpty()) {
            return;
        }

        for(String word: frontier) {
            if (WordChess.countDifferences(word, target) == 1) {
                result.add(0, target);
                parents.put(target, word);
                String step = target;
                for(int i = 0; i < depth; i++) {
                    step = parents.get(step);
                    result.add(0, step);
                }

                return;
            }
        }

        for (String word: frontier) {
            for(int i = 0; i < target.length(); i++) {
                for(int j = 0; j < 26; j++) {
                    char[] adjWordArray = word.toCharArray();
                    adjWordArray[i] = (char) (65 + j);
                    String adjWord = String.valueOf(adjWordArray);

                    if(!visited.contains(adjWord) && WordChess.countDifferences(word, adjWord) == 1 && WordChess.isWord(adjWord)) {
                        parents.put(adjWord, word);
                        visited.add(adjWord);
                        newFrontier.add(adjWord);
                    }


                }
            }
        }

        if (newFrontier.size() == 0) {
            return;
        } else {
            BFSUtil(newFrontier, target, depth+1, parents, visited); 
        }
        
        return;

        
    }

    private static void BFS(String start, String target) {
        ArrayList<String> frontier = new ArrayList<String>();
        Set<String> visited = new HashSet<String>();
        Map<String, String> parents = new HashMap<String, String>();

        frontier.add(start);
        visited.add(start);

        int depth = 1;
        BFSUtil(frontier, target, depth, parents, visited);
    }
}
