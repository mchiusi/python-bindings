import cppyy

# This class has a single member variable m_data of type int, 
# and a constructor that takes an integer i and initializes the 
# m_data member with the provided value.

cppyy.cppdef("""
class Integer1 {
public:
    Integer1(int i) : m_data(i) {}
    int m_data;
};""")

# gbl is the global namespace, top level to cppyy
print(cppyy.gbl.Integer1)

# ----------
from cppyy.gbl import Integer1

# create a C++ Integer1 object
i = Integer1(42)

# use Python inspection
print("Variable has an 'm_data' data member?", hasattr(i, 'm_data') and 'Yes!' or 'No!')
print("Variable is an instance of int?", isinstance(i, int) and 'Yes!' or 'No!')
print("Variable is an instance of Integer1?", isinstance(i, Integer1) and 'Yes!' or 'No!')


# ----------
# Conjunct this class with another class

from cppyy.gbl.std import vector

# create a vector of Integer1 objects; 
# note how [] instantiates the template and () instantiates the class
v = vector[Integer1]()

# populate it
v += [Integer1(j) for j in range(10)]

# display our vector
print(v)

# conversion for printing
Integer1.__repr__ = lambda self: repr(self.m_data)
print(list(v))
