file = open("ne")
resDict = set()
resFile = open("reF", "w")
for line in file.readlines():
    ls = line.split()
    if "F" in ls[0]:
        resDict.add(ls[0])

resDict = list(resDict)
resDict = sorted(resDict)

for e in resDict:
    resFile.write(e + "\n")