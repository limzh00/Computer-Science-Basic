#!/usr/bin/env python
# -*- coding:UTF-8 -*-
# AUTHOR: Minzhang Li
# FILE: C:\Users\Administrator\Desktop\python数据分析\python基础语法以及配套练习\basic\section1\run.py
# DATE: 2020/07/04 Sat
# TIME: 03:46:45

# DESCRIPTION: This file is for Yanru Yang python learning.

import time
import os

def main():
    print('#####################################')
    print('Congradulation! You have been successfully validate this file.')
    print('Now, let us take a while for a tricky game.')
    print('Please enter your name in English:')
    name = input()
    sentence = name
    for char in sentence.split():
        allChar = []
        for y in range(12,-12,-1):
            lst = []
            lst_con = ''
            for x in range(-30,30):
                formula = ((x*0.05)**2+(y*0.1)**2-1)**3-(x*0.05)**2*(y*0.1)**3
                if formula <= 0:
                    lst_con += char[(x) % len(char)]
                else:
                    lst_con += ' '
            lst.append(lst_con)
            allChar += lst
        print('\n'.join(allChar))
    time.sleep(1)

if __name__ == "__main__":
    main()
