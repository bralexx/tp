import os
path = os.path.dirname(os.path.abspath(__file__))
with open(path + "/index.h", 'w') as f:
    f.write("int aaa = 1; int get(int x) {return x;}")
