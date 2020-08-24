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
        int lowestDifference, bestCurrentDifference, currentDifference, nextDifference;

        currentPath = new ArrayList<String>();
        while(d < 200) {
            for(int i = 0; i <= d; i++) {
                lowestDifference = WordChess.countDifferences(curWord, target);
                for(String word: wordlist) {
                    currentDifference = WordChess.countDifferences(word, target);
                    nextDifference = WordChess.countDifferences(curWord, word);

                    if (curWord.equals(word)) continue;

                    if (nextDifference == 1 && word.equals(target)) {
                        currentPath.add(word);
                        res.addAll(currentPath);
                        return res;
                    }

                    
                    if (nextDifference == 1 && currentDifference < lowestDifference && !currentPath.contains(word)) {
                        currentPath.add(word);
                        curWord = word;
                        break;
                    }
                }

                //TODO: ACCOUNT FOR EXHAUSTED currentDifference - 1 CHECKS, INSTEAD DO currentDifference
                //TODO: ALTERNATIVELY UPDATE A "NEXT BEST" WORD AS LOOP ITERATES
            }
            d++;
        }

        return res;
    }
}
