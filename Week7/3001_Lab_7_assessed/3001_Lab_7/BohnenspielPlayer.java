/**
 * Implements an intelligent player for Bohnenspiel. 
 */
import java.util.*;

public class BohnenspielPlayer
{
    // what's my name?
    private final String name;
    // what colour do I have?
    private final Farbe farbe;
    // used to index the board
    private final int turn;

    /**
     * Constructs a Bohnenspiel player.
     */
    public BohnenspielPlayer(Farbe f)
    {
        name = "Jesse";
        farbe = f;
        turn = farbe.ordinal();
    }
    
    /**
     * Returns the player's name.
     */
    public String getName()
    {
        return name;
    }
    
    /**
     * Returns the player's colour.
     */
    public Farbe getFarbe()
    {
        return farbe;
    }
    
    public int eval(Bohnenspiel game) {
        return 0;
    }

    public int minimax(Bohnenspiel game, int depth) {

        if(game.isOver()) return eval(game.getBoard());
        
        if(depth == 0) return eval(game.getBoard());

        if(farbe.ordinal() == 0) {
            int maxValue = Integer.MIN_VALUE;
            int maxIndex = -1;
            for(int i = 0; i < board.length / 2; i++) {
                int curValue = minimax(board, depth-1);
                if(curValue > maxValue) maxValue = curValue; maxIndex = i;
            }      

            return maxIndex;
        }

        if(farbe.ordinal() == 1) {
            double minValue = Integer.MIN_VALUE;
            int minIndex = -1;
            for(int j = 6; j < board.length; j++) {
                int curValue = minimax(board, depth-1);
                if( curValue > minValue ) minValue = curValue; minIndex = j;
            }

            return minIndex;
        }

    }

    /**
     * Returns a legal move in game, i.e. a number h in [1, 6]. 
     * h must denote a non-empty house on this player's side of the board. 
     * You can assume that at least one legal move is available. 
     * DO NOT RETURN AN ILLEGAL MOVE - that's an automatic loss of game. 
     */
    public int chooseMove(Bohnenspiel game)
    {
        // COMPLETE THIS 
        // Placeholder simply plays a random move

        while(true) {


        }
    }
}