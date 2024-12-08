import pandas as pd

# This script was used to automatically get the initializer for the
# instructions lookup table from 68H11.csv

dataframe = pd.read_csv("68H11.csv", sep=',')
inst = open("hc11_instructions.txt", "w")   # File for instructions assignment
func = open("hc11_functions.txt", "w")
inst.write(f"inst_t lookup[{len(dataframe)}]" + " = {\n")
i = 0
for row in dataframe.iloc():
    mnem = row[0] + "_" + row[2]
    if (i % 3) == 0:
        inst.write("\n\t")
    inst.write("{ \"" + mnem + "\", " + "{0x" + str(row[1]) + "}, " + "&" + mnem + ", 1 }, ")
    i = i + 1
inst.write("\n};")

for row in dataframe.iloc():
    mnem = row[0] + "_" + row[2]
    func.write("\n\nvoid " + mnem + "(hc11_t *hc11){\n\n\n}")