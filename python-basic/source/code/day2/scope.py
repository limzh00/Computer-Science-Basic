# GLOBAL VARIABLE
x = "Love is a "


def func1():
    x = "and yet not a "
    def func2():
        # Hint: keyword here(global x/ nonlocal x)?
        x = x + "touch."
        def func3():
            # Hint: keyword here(global / nonlocal)?
            x = x + "touch "
        func3()
    func2()
    return x

################# DO NOT MODIFY HERE ######################
def main():
    func1()
    print(x + func1())
if __name__ == '__main__':
    main()