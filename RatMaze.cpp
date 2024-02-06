/*this is a program written by john miller to help a rat escape a maze.
 the program uses a recursive backtracking algorithm to check all different
 paths, allowing the mouse to escape the maze*/

#include <iostream>
#include <ios>

using std::string;
using std::vector;

/* making a rat class to contain the maze and solution objects*/
class Rat
{
public:
    vector<vector<int>> maze;
    vector<vector<int>> solution;

    /*making an initializer to set up an initially empty maze*/
    Rat(int width, int height)
    {
        for (int i = 0; i < height; i++)
        {
            vector<int> newV(width);
            fill(newV.begin(), newV.end(), -1);
            maze.push_back(newV);
        }
    }

    /* making a maze printing algorithm.
    @pre: maze is a valiz vector of integer vectors
    @post: none
    */
    void PrintMaze(vector<vector<int>> &maze)
    {
        for (int i = 0; i < maze.size(); i++)
        {
            for (int x = 0; x < maze[0].size(); x++)
            {
                std::cout << maze[i][x];
                std::cout << "   ";
            }
            std::cout << std::endl;
        }
    } // PrintMaze

    /* making a solution printing algorithm.
    @pre: solution is a valid vector of integer vectors
    @post: none
    */
    void PrintSolution(vector<vector<int>> &solution)
    {
        for (int i = 0; i < solution.size(); i++)
        {
            std::cout << solution[i][0] << ", " << solution[i][1] << std::endl;
        }
        std::cout << std::endl;
    } // PrintSolution

    /* this is a helper method used to check if a new coordinate in the maze is occupied yet\@pre: solution is a valid vector of integer vectors
    @pre: maze is a valid vector of integer vectors
    @post: returns true or false
    */

    bool isValidMove(vector<vector<int>> &maze, vector<int> &newLocation)
    {
        if (newLocation[0] < maze.size() && newLocation[1] < maze.size() && newLocation[0] >= 0 && newLocation[1] >= 0 && maze[newLocation[0]][newLocation[1]] != -1)
        {
            return true;
        }
        return false;
    }

    /* findPath is an algorithm used to find the rat's way out of the maze. it is a recursive backtracking algorithm
    @pre: maze,solution, moves is a valid vector of int vectors, newCoordinate is a valid vector of integers
    @post: returns T of F
    */
    bool findPath(vector<vector<int>> &maze, vector<vector<int>> &solution, vector<vector<int>> &moves, vector<int> &newCoordinate)
    {
        if (maze[newCoordinate[0]][newCoordinate[1]] == 1)
        {
            solution.push_back(newCoordinate);
            return true;
        }
        else
        {
            for (int i = 0; i < moves.size(); i++)
            {
                vector<int> possibleCoordinate = {newCoordinate[0] + moves[i][0], newCoordinate[1] + moves[i][1]};
                if (isValidMove(maze, possibleCoordinate))
                {
                    maze[newCoordinate[0]][newCoordinate[1]] = -1;
                    solution.push_back(newCoordinate);
                    if (findPath(maze, solution, moves, possibleCoordinate))
                    {
                        return true;
                    }
                    else
                    {
                    }
                }
            }
            solution.push_back(newCoordinate);
            maze[newCoordinate[0]][newCoordinate[1]] = -1;
            return false;
        }
    }
};

int main(void)
{
    Rat rat = Rat(5, 5);
    rat.maze[0][0] = 0;
    rat.maze[0][1] = 0;
    rat.maze[0][2] = 0;
    rat.maze[0][3] = 0;
    rat.maze[0][4] = 0;
    rat.maze[1][2] = 0;
    rat.maze[2][2] = 0;
    rat.maze[2][0] = 0;
    rat.maze[2][1] = 0;
    rat.maze[3][2] = 0;
    rat.maze[4][2] = 0;
    rat.maze[4][3] = 0;
    rat.maze[4][4] = 1;
    rat.PrintMaze(rat.maze);
    vector<vector<int>> solution;
    vector<vector<int>> moves = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    vector<int> initialPosition = {0, 0};
    bool answer = rat.findPath(rat.maze, solution, moves, initialPosition);
    rat.PrintMaze(rat.maze);
    rat.PrintSolution(solution);
    rat.PrintMaze(rat.maze);
    return 0;
}
