#!/usr/bin/env python
# -*- coding:UTF-8 -*-
# AUTHOR: Minzhang Li
# FILE: F:\MyGithubs\Python-Data-Analysis-notebook\python数据分析\python-data-analysis\code\day7\main.py
# DATE: 2020/07/12 Sun
# TIME: 21:22:31

# DESCRIPTION: This is main file


def main():
    n = int(input('Please choose a mode with a number: 1.add\t2.sub\t3.mul\t4.div\t5.sin\t6.cos\t7.sqrt\t8.power\n'))
    if n >= 5 and n < 8:
        x = int(input('Please enter your input vavlue: '))
    else:
        x, y = map(int, input('Please enter your input values: ').split())
    if n == 1:
        print(...)
    elif n == 2:
        print(...)
    elif n == 3:
        print(...)
    elif n == 4:
        print(...)
    elif n == 5:
        print(...)
    elif n == 6:
        print(...)
    elif n == 7:
        print(...)
    elif n == 8:
        print(...)
    else:
        print('ERROR: YOUR INPUTS ARE INVALID.')

if __name__ == '__main__':
    main()
