import pandas as pd

# This script was used to automatically get the initializer for the
# instructions lookup table from 68H11.csv

dataframe = pd.read_csv("68H11.csv", sep=',')
inst = open("hc11_instructions.txt", "w")   # File for instructions assignment
func = open("hc11_functions.txt", "w")
inst.write(f"inst_t lookup[{len(dataframe)}]" + " = {\n")
i = 0
for row in dataframe.iloc():
    mnem = row[0]
    if (i % 3) == 0:
        inst.write("\n\t")
    inst.write("{ \"" + mnem + "\", " + "{0x" + str(row[1]) + "}, " + "&" + mnem + ", &DIR_" + row[2] + ", 1 }, ")
    i = i + 1
inst.write("\n};")

prev = ""
for row in dataframe.iloc():
    mnem = row[0]
    if prev == mnem:
        continue
    prev = mnem
    func.write("void " + mnem + "(hc11_t*, uint16_t (*)(hc11_t*));\n")

func.write("\n\n\n")

for row in dataframe.iloc():
    mnem = row[0]
    if prev == mnem:
        continue
    prev = mnem
    func.write("\n\nvoid " + mnem + "(hc11_t *hc11, uint16_t (*arg)(hc11_t*))\n{\n\n}")