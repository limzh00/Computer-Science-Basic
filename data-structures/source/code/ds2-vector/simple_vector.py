class Vector:
    def __init__(self, size = 0, capacity = 10, value = 0):
        self._elem = []
        self._size = size 
        self._capacity = capacity
        for i in range(size):
            self._elem.append(value)
    def get(r):
        return self._elem[r]
    def remove(r):
        del self._elem[r]
        self._size -= 1
    def replace(r,e):
        self._elem[r] = e
    def size():
        return self._size
    def insert(r,e):
        self._elem.append(0)
        for i in range(self._size-1,r,-1):
            self._elem[i+1] = self._elem[i]
        self._elem[r] = e
        self._size += 1
    def empty():
        return not self._size