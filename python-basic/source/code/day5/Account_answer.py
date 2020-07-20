#!/usr/bin/env python
# -*- coding:UTF-8 -*-
# AUTHOR: Minzhang Li
# FILE: F:\MyGithubs\Python-Data-Analysis-notebook\python数据分析\python-data-analysis\code\day5\Account_answer.py
# DATE: 2020/07/10 Fri
# TIME: 18:06:23

# DESCRIPTION: This is a answer file

class Account:
    num  = 10
    def __init__(self, name, pwd):
        self.holder = name
        self.password = pwd
        self.balance = 0
    def deposit(self,num):
        self.balance += num
    def transfer(self, num):
        self.balance -= num

def transfer(A,B,num):
    if A.balance >= num:
        A.balance -= num
        B.balance += num
        return 1
    print("TRANSFER FAIL: YOU DO NOT HAVE ENOUGH SPARE.")
    return 0

