#! /bin/python3
import os
import sys

def getLineNum(dir):
    total = 0
    for root, dirs, files in os.walk(dir):
        for file in files:
            if file.endswith('.cpp') or file.endswith('.hpp'):
                filePath = os.path.join(root, file)
                print(filePath)
                with open(filePath, encoding = 'gb18030', errors = 'ignore') as f:
                    lines = f.readlines()
                    total += len(lines)
                    print("%d %s\n" %(len(lines), filePath))
                    f.close()
    return total
path  = "D:\Programming_Fold\leetcode"
if len(sys.argv) > 1:
    path = sys.argv[1]
print("The total line is %d of all the cpp file in the %s\n" % (getLineNum(path), path))     