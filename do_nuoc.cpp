#include<iostream>
#include<queue>
#define fastRead ios_base::sync_with_stdio("false"); ios::sync_with_stdio("false"); cin.tie(0); cout.tie(0);
using namespace std;
struct combination{
    int first;
    int second;
    int step;
};
queue<combination> combinationQueue;
int checkList[901][901];
int findCombination(int a, int b, int c)
{
    combinationQueue.push(combination{a,0,1});
    combinationQueue.push(combination{0,b,1});

    while(!combinationQueue.empty())
    {
        combination x = combinationQueue.front();
        //cout <<x.first << " " <<x.second << " "<<x.step<<endl;
        if (x.first == c || x.second == c)
            return x.step;
        else
        {
            if (checkList[x.first][x.second] == 1)
            {
                combinationQueue.pop();
                continue;
            }
            else
                checkList[x.first][x.second] = 1;
        }
        combinationQueue.pop();
        combinationQueue.push(combination{a, x.second, x.step+1}); // đổ đầy binh 1
        combinationQueue.push(combination{x.first, b, x.step+1}); // đổ đầy bình 2
        combinationQueue.push(combination{0, x.second, x.step+1}); // đổ hết bình 1 đi
        combinationQueue.push(combination{x.first, 0, x.step+1}); // đổ hết bình 2 đi
        if (x.first > b- x.second)
            combinationQueue.push(combination{x.first - b + x.second, b, x.step+1});
        else
            combinationQueue.push(combination{0, x.second+x.first, x.step+1});

        if (x.second > a -  x.first)
            combinationQueue.push(combination{a , x.second - a + x.first, x.step+1});
        else
            combinationQueue.push(combination{x.first+x.second, 0, x.step+1});
    }
    return -1;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << findCombination(a, b, c);
}

/*
    <V coc 1> <V coc 2> <V can lay>
*/
