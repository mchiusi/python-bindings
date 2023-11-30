import cppyy
#cppyy.include('features.h')

cppyy.load_library('lib_tutorial.so')
cppyy.include('tutorial.h')

# importing thr glocal namespace and threating 
# it as a module after it has been loaded
from cppyy.gbl import Concrete
import numpy as np

c = Concrete()
c.array_method(np.array([1., 2., 3., 4.]),4)
print(c.m_int)

d = Concrete(13)
print(d.m_int)
