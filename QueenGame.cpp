#include <iostream>
#include <ios>

using std::string;
using std::vector;

class Queen
{
public:
    vector<vector<int>> chessBoard;

    void PrintBoard(vector<vector<int>> &chessBoard)
    {
        for (int i = 0; i < chessBoard.size(); i++)
        {
            for (int x = 0; x < chessBoard[0].size(); x++)
            {
                std::cout << chessBoard[i][x];
                std::cout << "   ";
            }
            std::cout << std::endl;
        }
    }

    bool isSafe(vector<int> newLocation, vector<vector<int>> chessBoard)
    {
        bool safe = true;
        /* this loop is for the horizontal row the queen is in */
        for (int i = 0; i < chessBoard.size(); i++)
        {
            if (chessBoard[newLocation[0]][i] != -1 || chessBoard[i][newLocation[1]] != -1)
            {
                safe = false;
            }
        }

        vector<int> v = newLocation;
        while (v[0] >= 0 && v[1] >= 0)
        {
            if (chessBoard[v[0]][v[1]] != -1)
            {
                safe = false;
            }
            v[0]--;
            v[1]--;
        }

        vector<int> ve = newLocation;
        while (v[0] < chessBoard.size() && v[1] < chessBoard.size())
        {
            if (chessBoard[v[0]][v[1]] != -1)
            {
                safe = false;
            }
            v[0]++;
            v[1]++;
        }
        vector<int> vec = newLocation;
        while (v[0] >= 0 && v[1] < chessBoard.size())
        {
            if (chessBoard[v[0]][v[1]] != -1)
            {
                safe = false;
            }
            v[0]--;
            v[1]++;
        }
        vector<int> vect = newLocation;
        while (v[0] < chessBoard.size() && v[1] >= 0)
        {
            if (chessBoard[v[0]][v[1]] != -1)
            {
                safe = false;
            }
            v[0]++;
            v[1]--;
        }
        return safe;
    }

    bool FindPath(vector<int> &newLocation, vector<vector<int>> &chessBoard, int numQueens, int QueenGoal)
    {
        if (numQueens == QueenGoal)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < chessBoard.size(); i++)
            {
                vector<int> possibleLocation = {numQueens, i};
                if (isSafe(possibleLocation, chessBoard))
                {
                    chessBoard[possibleLocation[0]][possibleLocation[1]] = numQueens;
                    if (FindPath(possibleLocation, chessBoard, numQueens + 1, QueenGoal))
                    {
                        return true;
                    }
                    else
                    {
                        /* this is where the backtracking occurs */
                        chessBoard[possibleLocation[0]][possibleLocation[1]] = -1;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Queen Q = Queen();
    vector<vector<int>> board;
    vector<int> start = {0, 0};
    for (int i = 0; i < 8; i++)
    {
        vector<int> newV(8);
        fill(newV.begin(), newV.end(), -1);
        board.push_back(newV);
    }
    bool result = Q.FindPath(start, board, 0, 8);
    std::cout << result << std::endl;
    Q.PrintBoard(board);
    return 0;
}