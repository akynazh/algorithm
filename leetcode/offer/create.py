import os
i = int(input())
path = f'{os.getenv("CODE")}/algorithm/leetcode/offer/{i}'
os.mkdir(path)

with open(path + "/" + str(i) + ".cpp", "w") as f:
    f.write("#include <bits/stdc++.h>\n")
    f.write("using namespace std;\n\n")
    f.write("class Solution {\n")
    f.write("\n")
    f.write("};\n\n")
    f.write("int main() {\n")
    f.write("    \n")
    f.write("    Solution solution;\n")
    f.write("    \n")
    f.write("    return 0;\n")
    f.write("}\n")