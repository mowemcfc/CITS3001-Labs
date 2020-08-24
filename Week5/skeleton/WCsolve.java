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
        // COMPLETE THIS

        // let d denote the number of characters by which 2 distinct words differ

        // construct level of a tree with all valid words at distance d away from wc[0], starting at 1
        // simultaneously construct a similar tree starting at wc[0], 
        // BIDIRECTIONAL? ITERATIVE DEPTH-LIMITED?
        //
        return null;
    }
}
