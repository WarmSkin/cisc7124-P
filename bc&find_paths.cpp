/*
author: Pin Chen
date: May 8th, 2018
description:
    2 dynamic programming questions for class exercises.
*/

#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;
//****************************************************************************
//Binomial coefficient. using a pair as map key to stored value.
long bc(long n, long k, map<pair<long,long>,long> &memo)
{

    long res;

    if (k>n) {
        throw "not a valid input!";
    }
    if (k == 0 || n == k) {
        return 1;
    }
    pair<long,long> key (n,k);
    if (memo.find(key) == memo.end()) {
        res = bc(n-1,k-1,memo) + bc(n-1,k,memo);
        memo[key] = res;
    } else {
        res = memo[key];
    }
    return res;
}
//***************************************************************************
//Count Paths. Using a factorial number function to help the calculation.
//for a box(n columns, k rows) from position(0,0) to (n,k)
// how many paths if you could only go further.( only go right and down).

long fac(long n, unordered_map<long,long> &memo)
{
    long res;
    if (n == 0){
        throw "invalid input!";
    }
    if (n == 1) {
        return 1;
    }
    if (memo.find(n) == memo.end()) {
        res = fac(n-1,memo)*n;
        memo[n] = res;
    } else {
        res = memo[n];
    }
    return res;
}

long find_paths(long column, long row,unordered_map<long,long> &memo)
{
    return fac(column-1+row-1,memo)/(fac(column-1,memo)*fac(row-1,memo));
}

/*
    from box(0,0) to box(column, row) you need (column-1)--right moves,
                                               (row -1)--down moves,
    to get there. all the paths are the combinations of right and down moves.
    so it is like pick red or blue balls into holes in order.
    so res = (column+row-2)!/(column-1)!*(row-1)!
*/
//************************************************************************
int main()
{
    unordered_map<long,long> memo2;
    map<pair<long,long>,long> memo;

    cout << bc(2,1,memo) << endl;
    cout << bc(8,4,memo) << endl;
    cout << find_paths(4,4,memo2)<< endl;

    return 0;
}
