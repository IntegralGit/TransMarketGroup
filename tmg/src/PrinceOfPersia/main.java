package PrinceOfPersia;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Piotr
 * Date: 8/22/13
 * Time: 7:16 PM
 * To change this template use File | Settings | File Templates.
 */
public class main {

    public static void main(String[] args)
    {

        Maze test = new Maze();
        //test.printMap();
        //going to be the update
    }






    public static void moveRight(String[][] maze)
    {
    boolean start = true;

    int px = 1;
    int py = 1;
    int k  = 1;
    int l  = 1;

    maze[px][py] = ".";
    maze[k][l+1] = "1";
    //maze[px][py] = maze[k+1][l];

    update(maze);
    }




    public static void update(String[][] maze)
    {
        for (int i = 1; i < 4; ++i){
            for (int j = 1; j < 4; ++j){
                System.out.print(maze[i][j]);
                System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}



