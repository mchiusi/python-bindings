import cppyy
cppyy.include('features.h')

# importing thr glocal namespace and threating 
# it as a module after it has been loaded
from cppyy.gbl import Concrete
import numpy as np

#c = Concrete()
#c.array_method(np.array([1., 2., 3., 4.]),4)
#print(c.m_int)

d = Concrete(13)
print(d.m_int)

kwds = {'n' : 18}
c = Concrete(**kwds)
print(c.m_int)
