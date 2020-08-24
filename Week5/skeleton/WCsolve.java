/**
 * Applies uninformed search algorithms to Word Chess puzzles. 
 * For a problem like SICK -> WELL, you need to return a solution 
 * in the form <"SICK", "SILK", "SILL", "WILL", "WELL">.
 */
import java.util.*;

public class WCsolve
{
    public WCsolve(){}

    /**
     * Solves the puzzle start -> target using breadth-first search. 
     * Returns one optimal solution. 
     */
    public static ArrayList<String> solve(String start, String target)
    {

        ArrayList<String> wordlist = Lab5.wordsList;

        ArrayList<String> currentPath = new ArrayList<String>();
        ArrayList<String> res = new ArrayList<String>();
        res.add(start);

        // let d denote the number of characters by which 2 distinct words differ

        // construct levels of a tree with all valid words at distance d away from start, starting at 1 moving through to d - O(b^d)
        // perform DFS - if branch[0] = start and branch[-1] = target, return

        int d = 1;
        String curWord = start;


        for(String word: wordlist) {
            if (curWord.equals(word)) continue;

            if (word.equals(target)) {
                currentPath.add(target);
                res.addAll(currentPath);
                return res;
            }

            if (WordChess.countDifferences(curWord, word) == 1) {
                currentPath.add(word);
                curWord = word;
            }
        }

        return null;
    }
}
