/**
 * Implements the Nearest Neighbour algorithm for the TSP, and
 * an iterative improvement method that uses 2-OPT greedily.
 * Results are returned as an array of indices into the table argument, 
 * e.g. if the table has length four, a valid result would be {2,0,1,3}. 
 */
import java.util.*;
import java.io.*;

public class NearestNeighbour
{
    private NearestNeighbour(){}

    private static double calcTourDist(int[] tour, double[][] table) {
        int n = tour.length;
        double z = table[tour[0]][tour[n-1]];
        for (int k = 0; k < n-1; k++) z += table[tour[k]][tour[k+1]];
        return z;
    }

    /**
     * Returns the shortest tour found by exercising the NN algorithm 
     * from each possible starting city in table.
     * table[i][j] == table[j][i] gives the cost of travel between City i and City j.
     */
    public static int[] tspnn(double[][] table)
    {
        System.out.println("START NEW TEST");
        int[] shortestTour = {};
        double shortestTourDist = Double.MAX_VALUE;

        for(int i = 0; i < table.length; i++) {
            int[] visited = new int[table.length];
            int[] res = new int[table.length];
            int cur = i;
            double tourDist = 0;

            visited[i] = 1;
            res[0] = i;

            for(int j = 1; j < table.length; j++) {
                int closestCity = j;
                double closestDistance = Double.MAX_VALUE;

                for(int k = 0; k < table.length; k++) {
                    if(cur == k) continue;

                    if((table[cur][k] < closestDistance) && (visited[k] != 1)) {
                        closestCity = k;
                        closestDistance = table[cur][k];
                    }
                }

                cur = closestCity;
                visited[cur] = 1;
                res[j] = cur;
            }
            
            tourDist = calcTourDist(res, table);
            if(tourDist < shortestTourDist) {
                shortestTourDist = tourDist;
                shortestTour = res;
            }
        }

        return shortestTour;
    }
    
    /**
     * Uses 2-OPT repeatedly to improve cs, choosing the shortest option in each iteration.
     * You can assume that cs is a valid tour initially.
     * table[i][j] == table[j][i] gives the cost of travel between City i and City j.
     */
    public static int[] tsp2opt(int[] cs, double[][] table)
    {
        // COMPLETE THIS METHOD
        return new int[] {};
    }
}
