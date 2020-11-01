//
// Created by Sari Abed on 30/09/2020.
//

#ifndef PRACTICE_ASSISTFUNCTION_H
#define PRACTICE_ASSISTFUNCTION_H
#define ABC_SIZE 26

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <unordered_map>
#include <stack>
#include <utility>
#include <queue>

using std::queue;
using std::stack;
using std::unordered_map;
using std::vector;
using std::cout;
using std::cin;
using std::string;
using std::list;

typedef  std::pair<int,int> pairs;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class NumAndIndex{
public:
    int value;
    int index;

    NumAndIndex(int num, int index): value(num), index(index){

    }
    bool operator<(const NumAndIndex& n) const{
        return (value < n.value);
    }
};

void mergeSort(int* array, int size);
void mergeAux(int* array, int size, int* arr2);
void merge(int* arr1, int n, int* arr2, int m, int* arr3);
string compress(string& s);
int longestIncSubsequence(int* array, int size);
void partition(std::list<int>& list1, int x);
void swap(int* a, int* b);
std::list<int> sumLists(std::list<int>& list1, std::list<int>& list2);
int myMax(int a, int b);
int maxSubArray(const vector<int>& A);
bool hotel(vector<int> &arrive, vector<int> &depart, int K);
int trailingZeroes(int A);
vector<int> plusOne(vector<int>& A);
int numberOfWays(vector<int>& arr, int k);
string rotationalCipher(string input, int rotationFactor);
char rotateChar(char c, int n);
vector<int> closestBigger(vector<int>& arr);
vector<int> countSubArrays(vector<int>& arr);
vector<int> reverseArray(vector<int>& arr);
int editDistance(string& s, string& t);
int min(int a, int b, int c);
int findSqrt(int A);
vector<int> inOrder(TreeNode* A);
vector <int> bfs(vector<int> g[], int N);
int maximumGap(const vector<int>& A);
int max(int a, int b);
int searchRotated(const vector<int> &A, int B);
int findSubStr(const string A, const string B);
int area(vector<vector<int>>& grid, int** seen, int r, int c);
int maxAreaOfIsland(vector<vector<int>>& grid);
void permuteAux(vector<int>& nums, vector<bool>& used, vector<int>& path,
                vector<vector<int>>& res);
vector<vector<int>> permuteUnique(vector<int>& nums);


#endif //PRACTICE_ASSISTFUNCTION_H
