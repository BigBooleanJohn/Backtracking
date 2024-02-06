#include <iostream>
#include <vector>
using std::string;
using std::vector;

class Test
{
public:
    vector<int> vals;

    Test(vector<int> v)
    {
        vals = v;
    }

    void Backtrack(vector<vector<int>> &permutations, vector<bool> &booleans, vector<int> givenData, vector<int> &curPermutation)
    {
        if (curPermutation.size() == givenData.size())
        {
            permutations.push_back(curPermutation);
            return;
        }
        else
        {
            for (int i = 0; i < givenData.size(); i++)
            {
                if (booleans[i] == true)
                {
                    curPermutation.push_back(givenData[i]);
                    booleans[i] = false;
                    Backtrack(permutations, booleans, givenData, curPermutation);
                    booleans[i] = true;
                    curPermutation.pop_back();
                }
            }
        }
    }

    vector<vector<int>> allpermutations(vector<int> input)
    {
        vector<vector<int>> permutations;
        vector<int> curPermutation;
        vector<bool> booleans;
        for (int i = 0; i < input.size(); i++)
        {
            booleans.push_back(true);
        }
        Backtrack(permutations, booleans, input, curPermutation);
        return permutations;
    }
};

int main(int argc, char *argv[])
{
    vector<int> vec3 = {5, 8, 6, 10};
    Test T = Test(vec3);

    vector<vector<int>> vec = T.allpermutations(vec3);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            std::cout << vec[i][j];
        }
        std::cout << std::endl;
    }
    return 0;
};