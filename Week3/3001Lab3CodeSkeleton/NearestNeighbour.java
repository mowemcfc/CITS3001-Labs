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
        // for each pair of edges ((x1,x2),(y1,y2)) in a tour
        //   dist1 = calculate sum of each edge
        //   swap x2, y1 s.t. ((x1,y1),(y1,x2))
        //   dist2 = calculate sum of new edges
        //   if dist2 < dist1:
        //     exchange edges
        

        for(int k = 0; k < 10; k++) {
            int x1, x2, y1, y2;
            int temp;
            double change;
    
            double tempDist;
            double shortestDist = calcTourDist(cs, table);
            int[]cs2;

            for(int i = 0; i < cs.length - 3; i++) {
                x1 = cs[i];
                x2 = cs[i+1];
                for(int j = i+2; j < cs.length - 1; j++) {
                    y1 = cs[j];
                    y2 = cs[j+1];


                    cs2 = cs.clone();
                    temp = cs2[i+1];
                    cs2[i+1] = cs2[j];
                    cs2[j] = temp;
                    
                    tempDist = calcTourDist(cs2, table);
                    if( tempDist < shortestDist) {
                        cs = cs2.clone();
                        shortestDist = tempDist;
                    }
                }
            }
        }

        return cs;
    }
}
