/* this is a file that implements a heuristic algorithm to
find a solution to the Knight's-game problem*/

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

    int numMovesFromLocation(vector<int> newLocation, vector<vector<int>> chessBoard, vector<vector<int>> possibleMoves)
    {
        int count = 0;
        for (int i = 0; i < possibleMoves.size(); i++)
        {
            vector<int> possible = {newLocation[0] + possibleMoves[i][0], newLocation[1] + possibleMoves[i][1]};
            if (possible[0] > -1 && possible[0] < chessBoard.size() && possible[1] > -1 && possible[1] < chessBoard.size() && chessBoard[possible[0]][possible[1]] == -1)
            {
                count++;
            }
        }
        return count;
    }

    vector<int> nextMove(vector<vector<int>> &chessBoard, vector<int> currentLocation, vector<vector<int>> possibleMoves)
    {
        vector<int> nextLocation;
        int curMovesCount = 10; // setting the possible moves count intentionally high to start off with
        for (int i = 0; i < possibleMoves.size(); i++)
        {
            vector<int> nextMove = {currentLocation[0] + possibleMoves[i][0], currentLocation[1] + possibleMoves[i][1]};
            if (nextMove[0] > -1 && nextMove[0] < chessBoard.size() && nextMove[1] > -1 && nextMove[1] < chessBoard.size() && chessBoard[nextMove[0]][nextMove[1]] == -1)
            {
                int numMoves = numMovesFromLocation(nextMove, chessBoard, possibleMoves);
                if (numMoves < curMovesCount)
                {
                    curMovesCount = numMoves;
                    nextLocation = nextMove;
                }
            }
        }
        return nextLocation;
    }

    bool tour(vector<vector<int>> &chessBoard, vector<int> currentLocation, vector<vector<int>> possibleMoves, int count)
    {
        if (count > 64)
        {
            return true;
        }
        vector<int> nextLocation = nextMove(chessBoard, currentLocation, possibleMoves);
        chessBoard[nextLocation[0]][nextLocation[1]] = count;
        return tour(chessBoard, nextLocation, possibleMoves, count + 1);
    }
};

int main(void)
{
    Knight K = Knight(8, 8);
    K.chessBoard[0][0] = 1;
    K.tour(K.chessBoard, {0, 0}, K.possibilities, 2);
    K.PrintBoard(K.chessBoard);
    return 0;
}