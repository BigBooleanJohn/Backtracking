/* this is a file that implements a backtracking algorithm to
find a solution to the Knight's-game problem. It is still in progress*/

#include <iostream>
#include <ios>

using std::string;
using std::vector;

class Knight
{
public:
    vector<vector<int>> chessBoard;
    vector<vector<int>> possibilities;
    vector<int> startingLocation;
    int numVisited;

    Knight(int width, int height)
    {
        this->numVisited = 0;
        this->startingLocation.push_back(0);
        this->startingLocation.push_back(0);
        this->possibilities = {{2, 1}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-1, -2}};
        for (int i = 0; i < height; i++)
        {
            vector<int> newV(width);
            fill(newV.begin(), newV.end(), -1);
            chessBoard.push_back(newV);
        }
    }

    /* determining if the square is an open move for the knight*/
    bool isValidSquare(vector<vector<int>> &chessBoard, vector<int> &newLocation)
    {
        if (newLocation[0] >= 0 && newLocation[0] < chessBoard.size() && newLocation[1] >= 0 && newLocation[1] < chessBoard.size() && chessBoard[newLocation[0]][newLocation[1]] == -1)
        {
            return true;
        }
        return false;
    }
    /*printing the board*/
    void PrintBoard(vector<vector<int>> &chessBoard)
    {
        for (int i = 0; i < chessBoard.size(); i++)
        {
            for (int x = 0; x < chessBoard[0].size(); x++)
            {
                std::cout << chessBoard[i][x];
                std::cout << "  | ";
            }
            std::cout << std::endl;
        }
    }
    /*FindPath is the main method that I will be using to find the Knight's Tour. It is a Backtracking algorithm*/
    bool FindPath(vector<vector<int>> &chessBoard, vector<vector<int>> &possibilities, int &curCount, vector<int> newLocation)
    {
        if (curCount == 64)
        {
            return true;
        }
        for (int i = 0; i < possibilities.size(); i++)
        {
            vector<int> possibleSq = {newLocation[0] + possibilities[i][0],
                                      newLocation[1] + possibilities[i][1]};
            printf("we are trying square %d,%d\n", possibleSq[0], possibleSq[1]);
            if (isValidSquare(chessBoard, possibleSq))
            {
                chessBoard[possibleSq[0]][possibleSq[1]] = curCount;
                int Temp = curCount + 1;
                printf("the new valid square is %d,%d, and the new count is %d now moving to it\n", possibleSq[0], possibleSq[1], curCount);
                if (FindPath(chessBoard, possibilities, Temp, possibleSq))
                {
                    return true;
                }
                else
                {
                    chessBoard[possibleSq[0]][possibleSq[1]] = -1;
                }
            }
        }
        printf("the path to %d,%d has proven FALSE\n", newLocation[0], newLocation[1]);
        return false;
    }
};

int main(int argc, char *argv[])
{
    Knight K = Knight(8, 8);
    vector<int> curLocation = {0, 0};
    bool solved = false;
    int count = 1;
    K.chessBoard[0][0] = 0;
    K.FindPath(K.chessBoard, K.possibilities, count, curLocation);
    K.PrintBoard(K.chessBoard);
}
