# The grammar of functions


# I would claim that `function` is object.
# To understand that, some properties would be revealed.

class City:
    def __init__(self, population, location, name):
        self.population = population
        self.location = location
        self.is_lockdown = False
        self.name = name
    def lockdown(self):
        self.is_lockdown = True
        print("WARNING: " + self.name + " is at the LOCKDOWN state.")
    def __call__(self):
        print(10)
    
Tsingdao = City(9000000, 'China', 'Tsingdao')
Tsingdao.lockdown()
Tsingdao()

############################