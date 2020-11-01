//
// Created by Sari Abed on 30/09/2020.
//

#include "AssistFunction.h"


void mergeSort(int* array, int size){
    int* arr2 = new int[size];
    mergeAux(array, size, arr2);
    delete [] arr2;
}

void mergeAux(int* array, int size, int* arr2){
    if(size==1){
        return;
    }

    mergeAux(array, size/2, arr2);
    mergeAux(array+size/2, size - (size/2), arr2);
    merge(array, size/2, array+size/2, size - (size/2), arr2);
    for(int i = 0; i<size; i++){
        array[i] = arr2[i];
    }
}

void merge(int* arr1, int n, int* arr2, int m, int* arr3){
    int i=0, j=0, k=0;


    while(i<n && j<m){
        if(arr1[i] >= arr2[j]){
            arr3[k] = arr2[j];
            j++;
        }
        else{
            arr3[k] = arr1[i];
            i++;
        }
        k++;
    }

    while(i<n){
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j<m){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
}

string compress(string& s){
    // Checking if there is no need for compression
    bool flag = false;
    for(int i=1; i<s.size(); i++){
        if(s[i] == s[i-1]){
            flag = true;
            break;
        }
    }
    if(!flag){
        return s;
    }

    string compressed;
    char current = s[0];
    int count = 1;
    string::iterator it = s.begin();
    ++it;
    while(it!=s.end()){
        if(*it != current){
            compressed += current;
            compressed += std::to_string(count);
            current = *it;
            count = 1;
        }
        else{
            count++;
        }

        ++it;
    }
    compressed += current;
    compressed += std::to_string(count);

    return compressed;
}

void partition(std::list<int>& list1, int x){
    auto it1 = list1.begin();
    auto it2 = list1.begin();
    ++it2;

    while(it2!=list1.end()){
        if(*it1<x){
            ++it1;
            if(it1==it2){
                ++it2;
            }
        }
        else{
            while(*it2>=x){
                ++it2;
                if(it2==list1.end()) {
                    return;
                }
            }
            if(it2==list1.end()){
                break;
            }

            int temp = *it1;
            *it1 = *it2;
            *it2 = temp;

            ++it1;
            ++it2;
        }
    }

}

void swap(std::list<int>::iterator it1, std::list<int>::iterator it2){
    int temp = *it1;
    *it1 = *it2;
    *it2 = temp;
}

std::list<int> sumLists(std::list<int>& list1, std::list<int>& list2){
    int carry = 0;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    std::list<int> list3;

    while(it1!= list1.end() && it2!= list2.end()){
        int res = *it1 + *it2 + carry;
        if(res>=10){
            carry = 1;
            res = res % 10;
        }
        list3.push_back(res);
        ++it1;
        ++it2;
    }
    while(it1!=list1.end()){
        if(*it1 + carry >= 10){
            int res = *it1 + carry;
            list3.push_back(res%10);
            list3.push_back(1);
        }
        else {
            list3.push_back(*it1 + carry);
        }
        carry = 0;
        ++it1;
    }

    while(it2!=list2.end()){
        if(*it2 + carry >= 10){
            int res = *it2 + carry;
            list3.push_back(res%10);
            list3.push_back(1);
        }
        else {
            list3.push_back(*it2 + carry);
        }
        carry = 0;
        ++it2;
    }

    return list3;
}

int myMax(int a, int b){
    if(a>=b){
        return a;
    }
    else{
        return b;
    }
}

int maxSubArray(const vector<int>& A){
    if(A.size()==1){
        return A[0];
    }
    int sum = 0, max = A[0];
    for(int it : A){
        if(sum < 0){
            sum = 0;
        }
        sum += it;
        if(sum > max){
            max = sum;
        }
    }



    return max;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K){
    std::sort(arrive.begin(), arrive.end());
    std::sort(depart.begin(), depart.end());

    int max = 0, curr = 0, i=0, j=0;
    while(i<arrive.size() && j<depart.size()){
        if(arrive[i] < depart[j]){
            curr++;
            if(curr > max){
                max = curr;
            }
            i++;
        }
        else{
            curr--;
            j++;
        }
    }

    return (max <= K);
}

int trailingZeroes(int A){
    int x = A;
    int highest_power = 0;
    while(x>=5){
        highest_power++;
        x /= 5;
    }
    if(highest_power==0){
        return 0;
    }

    int fives = 0, factor = 5;
    for(int i=0; i<highest_power; i++){
        fives += (A/factor);
        factor *= 5;
    }

    return fives;
}

vector<int> plusOne(vector<int>& A){
    list<int> res;
    int carry = 1, x;


    for(int i = (A.size() - 1); i >=0; i--){
        x = A[i] + carry;
        if(x == 10){
            res.push_front(0);
            carry = 1;
        }
        else{
            res.push_front(x);
            carry = 0;
        }
    }
    if(carry==1){
        res.push_front(1);
    }

    vector<int> final;
    auto it = res.begin();
    while(*it==0){
        ++it;
    }
    while(it!=res.end()) {
        final.push_back(*it);
        ++it;
    }

    return final;
}

int numberOfWays(vector<int>& arr, int k) {
    unordered_map<int, int> map;

    for(int i : arr){
        if(i>k){
            continue;
        }
        map[i]++;
    }

    int pairs = 0;
    for(int i : arr){
        pairs += map[k-i];

        if((k - i) == i){
            pairs--;
        }
    }

    return pairs/2;
}

string rotationalCipher(string input, int rotationFactor) {
    string s;
    for(char c : input){
        if(isalnum(c)){
            s += rotateChar(c, rotationFactor);
        }
        else{
            s += c;
        }
    }

    return s;
}

char rotateChar(char c, int n){
    char res=c;
    if(isalpha(c)){
        if(c >= 'A' && c<='Z'){
            res = 'A' + ((c-'A')+n)%ABC_SIZE;
        }
        else if(c >= 'a' && c<= 'z'){
            res = 'a' + ((c-'a')+n)%ABC_SIZE;
        }
    }
    else{
        res = '0' + (c-'0'+n)%10;
    }

    return res;
}

vector<int> closestBigger(vector<int> &arr){
    vector<int> res;
    stack<pairs> stack;
    for(int i=0; i<arr.size(); i++){
        if(stack.empty()){
            res.push_back(-1);
            stack.push(pairs(arr[i], i));
        }
        else{
            while (!(stack.empty()) && (arr[i]>=stack.top().first)){
                stack.pop();
            }
            if(stack.empty()){
                res.push_back(-1);
                stack.push(pairs(arr[i], i));
            }
            else{
                res.push_back(stack.top().second);
                stack.push(pairs(arr[i],i));
            }
        }
    }

    return res;
}

vector<int> countSubArrays(vector<int>& arr){
    vector<int> subs;
    vector<int> l = closestBigger(arr);
    for(int i=0; i<arr.size(); i++){
        if(l[i]!= -1){
            subs.push_back(i-l[i]);
        }
        else{
            subs.push_back(i+1);
        }
    }
    vector<int> reverse = reverseArray(arr);
    l = closestBigger(reverse);
    for(int i=0; i<arr.size(); i++){
        if(l[i]!= -1){
            subs[arr.size()-1-i] += (i-l[i]);
        }
        else{
            subs[arr.size()-1-i] += (i+1);
        }
        subs[i]--;
    }

    return subs;
}

vector<int> reverseArray(vector<int>& arr){
    vector<int> reversed;
    for(int i = arr.size()-1; i>=0; i--){
        reversed.push_back(arr[i]);
    }

    return reversed;
}

int editDistance(string& s, string& t){
    const int n = s.size(), m = t.size();
    vector<vector<int>> mat(2, vector<int>(m+1));
    for(int i=0; i<2; i++){
        mat[i][0] = i;
    }
    for(int j=0; j<m+1; j++){
        mat[0][j] = j;
    }

    int bit = 0;

    for(int i=1; i<n+1;i++){
        bit = 1-bit;
        for(int j=1; j<m+1; j++){
            mat[bit][0] = i;
            if(s[i-1]==t[j-1]){
                mat[bit][j] = mat[1-bit][j-1];
            }
            else{
                mat[bit][j] = 1+min(mat[1-bit][j-1], mat[1-bit][j], mat[bit][j-1]);
            }
        }
    }

    return mat[bit][m];
}

int min(int a, int b, int c){
    int min1;
    if(a<=b){
        min1 = a;
    }
    else{
        min1 = b;
    }
    if(min1 <= c){
        return min1;
    }
    else{
        return c;
    }
}

vector<int> makeArray(int n){
    vector<int> v;
    for(int i = 1; i <= n; i++){
        v.push_back(i);
    }

    return v;
}

int findSqrt(int A){
    int start = 1, end = A, mid;

    if(!A){
        return 0;
    }

    while(end>=start){
        mid = (start+end)/2;
        if(mid*mid==A){
            return mid;
        }
        if(end==start){
            if(start*start>A){
                return start-1;
            }
            if ((start+1)*(start+1)>A){
                return start;
            }
        }
        if(mid*mid>A){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }


    return end;
}

vector<int> inOrder(TreeNode* A){
    stack<TreeNode*> s;
    TreeNode* v = A;
    vector<int> res;

    do{
        while(v!= nullptr){
            s.push(v);
            v = v->left;
        }
        if(!s.empty()){
            v = s.top();
            s.pop();
            res.push_back(v->val);
            v = v->right;
        }
    }while(!s.empty() || v!=nullptr);

    return res;
}

vector <int> bfs(vector<int> g[], int N) {
    queue<int> q;
    vector<bool> visited;
    vector<int> res;
    for(int i=0; i<N; i++){
        visited.push_back(false);
    }
    q.push(0);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i : g[x]){
            if(!visited[i]){
                q.push(i);
            }
        }
        visited[x] = true;
        res.push_back(x);
    }
}

int maximumGap(const vector<int>& A){
    vector<NumAndIndex> vec;

    vec.reserve(A.size());

    for(int i=0; i<A.size(); i++){
        vec.emplace_back(A[i], i);
    }

    std::sort(vec.begin(), vec.end());

    vector<int> max_index;
    max_index.reserve(A.size());

    max_index[A.size()-1] = vec[A.size()-1].index;
    for(int i=A.size()-2; i>=0; i--){
        max_index[i] = max(max_index[i+1], vec[i].index);
    }
    int max1 = -1;
    for(int i=0; i<A.size(); i++){
        max1 = max(max1, (max_index[i]-vec[i].index));
    }

    return max1;
}

int max(int a, int b){
    if(a>=b){
        return a;
    }
    return b;
}

int searchRotated(const vector<int> &A, int B){
    int start = 0, end = A.size()-1;
    int mid;

    while(start<=end){
        mid = (start + end)/2;
        if(A[mid]==B){
            return mid;
        }
        if(B < A[mid]){
            if(B<A[start] && A[start]<=A[mid]){
                start = mid+1;
            }
            else{
                end = mid - 1;
            }
        }
        else{
            if(B>A[end] && A[end]>=A[mid]){
                end = mid-1;
            }
            else{
                start = mid +1;
            }
        }
    }

    return -1;
}

int findSubStr(const string A, const string B){
    if(A.empty() || B.empty() || A.size()<B.size()){
        return -1;
    }

    int start = -1;
    for(int i=0; i<A.size(); i++){
        if(A[i]==B[0]){
            int j=0;
            start = i;
            while(i<A.size() && j<B.size() && A[i]==B[j]){
                j++;
                i++;
            }
            if(j==B.size()){
                return start;
            }
            else{
                i = start;
                start = -1;
            }
        }
    }

    return start;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int area(vector<vector<int>>& grid, int** seen, int r, int c){
    if(r < 0 || r>=grid.size() || c <0 || c> (grid[0].size()) ||
       (grid[r][c]==0) || seen[r][c]){
        return 0;
    }

    seen[r][c] = 1;

    return (1+ area(grid, seen, r-1, c) + area(grid, seen, r+1, c) +
            area(grid, seen, r, c+1) + area(grid, seen, r, c-1));
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    int** seen = new int*[rows];
    for(int i=0; i<rows; i++){
        seen[i] = new int[cols];
    }


    int max = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            seen[i][j] = 0;
        }

    }


    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int a = area(grid, seen, i, j);
            if(a>max){
                max = a;
            }
        }
    }

    for(int i=0; i<rows; i++){
        delete[] seen[i];
    }
    delete[] seen;

    return max;
}

void permuteAux(vector<int>& nums, vector<bool>& used, vector<int>& path,
                vector<vector<int>>& res){
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }

    for(int i=0; i<nums.size(); i++) {
        if (!used[i]) {
            path.push_back(nums[i]);
            used[i] = true;
            permuteAux(nums, used, path, res);
            path.pop_back();
            used[i] = false;
            int x = nums[i];
            bool flag = false;
            while (nums[i] == x && i<nums.size()) {
                i++;
                flag = true;
            }
            if (flag) {
                i--;
            }
        }

    }
}

vector<vector<int>> permuteUnique(vector<int>& nums){
    int n = nums.size();
    std::sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used(n, false);

    permuteAux(nums, used, path, res);

    return res;
}