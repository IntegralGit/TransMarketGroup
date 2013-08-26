package PrinceOfPersia;

import java.io.*;
import java.util.Scanner;
import java.util.Vector;

/**
 * Created with IntelliJ IDEA.
 * User: rotten
 * Date: 8/25/13
 * Time: 8:06 PM                  ECE 333-AB1
11052 Class
11:00 am-1:50 pm
2SEL 4050
 * To change this template use File | Settings | File Templates.
 */
public class Maze {

    public int level,rows,cols;
    public Vector<String[][]> graph;


    public Maze()
    {

       loadMap();

    }






    public void loadMap()
    {


        graph = new Vector<String[][]>();
        int k = 0;
        int p = 0;

        int px = 0;
        int py = 0;
        String [][] maze = new String[4][4];

        //String junk = scan.nextLine();


        BufferedReader reader = null;
        try {
            reader = new BufferedReader(new FileReader("/home/rotten/TransMarketGroup/tmg/src/PrinceOfPersia/gamemap1.txt"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
        String line = null;
        int count = 0;
        try {
            while ((line = reader.readLine()) != null) {

             //String[] arrayPasser = line.split("");
             //System.out.print(line+"\n");
             String[] arrayPasser = line.split("");

             for (p = k; p < 3; ++p){
              maze[k][p] = arrayPasser[p];
              System.out.print(k + "--" +p +"\n");

              }
              k++;



            if(k == 3)       level = 3;
        rows   = 9;
        cols   = 3;
            {
                System.out.print("yes\n");
                k = 0;
                count = 0;


                //graph.add(maze);


            }


            }
        } catch (IOException e) {
            e.printStackTrace();  //To change body of catch statement use Fil e | Settings | File Templates.
        }


    }




    public void printMap()
    {
        String[][] test;

        for(int i = 0; i< graph.size();++i)
        {
            test = graph.get(i);
            for (int k = 0; i < 2; ++i){
                for (int j = 0; j < 2; ++j){
                    System.out.print(test[k][j]);


                }

            }
        }

    }
}

