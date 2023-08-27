file = open("conventional", "r")
writeFile = open("x86_64","w")

lines = file.readlines()

for line in lines:
    if ("X86_64" in line):
        writeFile.write(line)


file.close()
writeFile.close()