import matplotlib.pyplot as plt

# groups
# keys
# values
# desFileName
# title
# sortValue


def keyValueSort(keys = list, values = list, sortByValue = True):
    pool = [ (k,v) for k, v in zip(keys, values)]
    pool = sorted(pool, key= lambda x : x[1] if sortByValue else x[0])
    keys = [k for k, v in pool]
    values = [v for k, v in pool]
    return keys, values



def pie_plot(**kwargs):
    grp_count = len(kwargs.get("groups", 1))
    fig, axes = plt.subplots(1, grp_count)
    keys = kwargs.get("keys")
    values = kwargs.get("values")
    for grp in range(grp_count):
        ax = axes[grp] if grp_count >= 2 else axes
        if kwargs.get("sortValue", False):
            keys[grp], values[grp] = keyValueSort(keys[grp], values[grp])
        ax.pie(values[grp], labels=keys[grp], autopct='%1.1f%%')
        ax.set_title(kwargs.get("title"))

    plt.tight_layout()
    plt.show()

def bar_plot(**kwargs):
    grp_count = len(kwargs.get("groups", 1))
    fig, axes  = plt.subplots(1, grp_count)
    keys   = kwargs.get("keys")
    values = kwargs.get("values")

    for grp in range(grp_count):
        ax = axes[grp] if grp_count >= 2 else axes
        if kwargs.get("sortValue", False):
            keys[grp], values[grp] = keyValueSort(keys[grp], values[grp])
        ax.bar(keys[grp], values[grp])

    plt.show()


def readStatFile(filePath: str, interestWord: str, excludeShow: str, enInterestWord: bool):
    keys = []
    values = []
    with open(filePath) as file:
        lines = file.readlines()
        ###### read line
        for line in lines:
            if (interestWord not in line) and enInterestWord:
                continue
            line = line.replace(excludeShow, "")
            ####### exclude $
            line = line.replace("$", "x")
            #print(line)
            splitedLine = line.split()
            key   = "".join(splitedLine[0:-1])
            value = int(splitedLine[-1])
            keys.append(key)
            values.append(value)
    return keys, values

# keys, values = readStatFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/blackscholes/stat_medium",
#                             "mopGen::",
#                             "mopGen::",
#                             True
#                            )
#
#
# pie_plot(groups = ["blackscholes"],
#          keys = [keys],
#          values = [values],
#          title = "tracebuilder blackholes uop",
#          sortValue = True)
# #
# #
# keys, values = readStatFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/stat_medium",
#                             "mopGen::",
#                             "mopGen::",
#                             True
#                             )
#
# pie_plot(groups = ["fluidAnimate"],
#          keys = [keys],
#          values = [values],
#          title = "tracebuilder fluidAnimate uop",
#          sortValue = True)

# bar_plot(
#     groups=["fluidAnimate", "blackholes"],
#     keys= [["TBD", "gem5_selfTrace", "gem5"], ["TBD", "gem5_selfTrace", "gem5"]],
#     values=[[3006838442, 3032482304, 3032482304],[715703968, 765839348, 765839348]],
#     title = "instruction comparison"
# )




############################################################################################


keys, values = readStatFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/blackscholes/stat_medium",
                            "dynTrace::needUpgrade::",
                            "dynTrace::needUpgrade::",
                            True
                            )


pie_plot(groups = ["blackscholes"],
         keys = [keys],
         values = [values],
         title = "tracebuilder blackholes uop need upgrade",
         sortValue = True)
#
#
keys, values = readStatFile("/media/tanawin/tanawin1701e/Project/sms/pintool/msmsPin/traceBuilder/pin/TbOutput/fluidanimate/stat_medium",
                            "dynTrace::needUpgrade::",
                            "dynTrace::needUpgrade::",
                            True
                            )

pie_plot(groups = ["fluidAnimate"],
         keys = [keys],
         values = [values],
         title = "tracebuilder fluidAnimate uop need upgrade",
         sortValue = True)