#!/usr/bin/env python
# -*- coding:UTF-8 -*-
# AUTHOR: Minzhang Li
# FILE: C:\Users\Administrator\Desktop\day6\steps.py
# DATE: 2020/07/12 Sun
# TIME: 02:46:25

# DESCRIPTION: This is a file for recurrence tutorial

def f(n):
    # When the layer is 1 or 2, we can achieve with 1 step directly.
    if n <= 2:
        return 1
    # else, we divide the problem into two small subproblems of same structure of the original problem.
    # That is, f(n) = min(f(n-1), f(n-2)) + 1
    return min(f(n-1), f(n-2)) + 1
    
print(f(10))
# Try run this line:
# print(f(100)), it is very slow.

# We have an alternative to calculate f(100)
# memo is a list of 1000 zeros.
memo = [0 for i in range(1000)]
memo[1], memo[2] = 1, 1
def f1(n):
    if n <= 2:
        return memo[n]
    # check whether we have a copy in memo
    if memo[n] == 0:
        memo[n] = min(f1(n-1), f1(n-2)) + 1
    return memo[n]

print(f1(100))
