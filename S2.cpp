#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
#define MAXIMUM 10000000
using namespace std;

int calculate_distance(pair<int, int> a, pair<int, int> b)
{
    int maxX = max(a.first, b.first);
    int minX = min(a.first, b.first);
    int maxY = max(a.second, b.second);
    int minY = min(a.second, b.second);
    return (maxX - minX + maxY - minY);
}

void print(int x)
{
    cout << x << " ";
}

int main()
{
    int no_neighbour;
    cin >> no_neighbour;

    vector<pair<int, int>> coords;
    pair<int, int> temp;
    vector<int> nodes;
    int mat[no_neighbour + 2][no_neighbour + 2];
    for (int i = 0; i < no_neighbour + 2; i++)
    {
        cin >> temp.first >> temp.second;
        coords.push_back(temp);
    }

    for (int i = 0; i < no_neighbour + 2; i++)
    {
        for (int j = 0; j < no_neighbour + 2; j++)
        {
            mat[i][j] = calculate_distance(coords[i], coords[j]);
            // printf("%4d", mat[i][j]);
        }
        if (i != 0 && i != 1)
            nodes.push_back(i);
        cout << endl;
    }

    int mindistance = MAXIMUM;
    do
    {
        // for_each(nodes.begin(), nodes.end(), print);
        int distance = 0;
        int prev = 1;
        for (int i = 0; i < no_neighbour; i++)
        {
            distance += mat[prev][nodes[i]];
            prev = nodes[i];
        }
        distance += mat[prev][0];
        // cout<<distance<<endl;
        if (distance < mindistance)
            mindistance = distance;
    } while (next_permutation(nodes.begin(), nodes.end()));

    cout << mindistance << endl;
    return 0;
}