####### blackholes row hit
import matplotlib.pyplot as plt

# Define the data to use for the chartd
# smsRowHit      = [65.27, 71.27]
# frfcfs         = [64.91, 91.42]
# fcfs           = [62.97, 65.16]

def plotBarCompare(tbd, gem_trace, gem5, header, ylabel, xlable, typeA, typeB):

# Create the bar chart
    fig, ax = plt.subplots()
    bar_width = 0.35
    ax.bar([0          , 1.5              ], tbd, width=bar_width, label='traceBuilder')
    ax.bar([bar_width  , 1.5 + bar_width  ], gem_trace, width=bar_width, label='gem_replay')
    ax.bar([bar_width*2, 1.5 + bar_width*2], gem5, width=bar_width, label='gem5')


    ax.text(- 0.175, tbd[0] + 1, str(tbd[0]), color='black', fontweight='bold')
    ax.text(1.5 - 0.175, tbd[1] + 1, str(tbd[1]), color='black', fontweight='bold')

    ax.text(- 0.175 + 0.35, gem_trace[0] + 1, str(gem_trace[0]), color='black', fontweight='bold')
    ax.text(1.5 - 0.175 + 0.35, gem_trace[1] + 1, str(gem_trace[1]), color='black', fontweight='bold')


    ax.text(- 0.175 + 0.35 * 2, gem5[0] + 1, str(gem5[0]), color='black', fontweight='bold')
    ax.text(1.5 - 0.175 + 0.35 * 2, gem5[1] + 1, str(gem5[1]), color='black', fontweight='bold')

    # Customize the chart as needed
    ax.set_title(header)
    ax.set_xticks([0.17, 1.85])
    ax.set_xticklabels([typeA, typeB])
    ax.set_xlabel(xlable)
    ax.set_ylabel(ylabel)
    ax.legend()

    # Display the chart
    plt.show()

#plotBarCompare([43030, 49974], [34640, 35869], [36794, 38853], f"service by write queue instead dram (compared to ~ {48821 + 47342})", "serviceCount (count K)", "workload", "fluidAnimate", "blackholes")
#plotBarCompare([602190, 980841], [585105, 965964], [659852, 1241359], "execute time ", "times (kilo tick)", "workload", "fluidAnimate", "blackholes")


#plotBarCompare([3006, 715], [3032, 765], [3032, 765], "instruction count", "count (Million)", "workload", "fluidAnimate", "blackholes")
#plotBarCompare([4652, 1168], [5496, 1412], [5469, 1408], "micro-op count", "count (Million)", "workload", "fluidAnimate", "blackholes")
plotBarCompare([1097, 304], [853, 396], [0, 0], "d-side attempted", "count", "workload", "fluidAnimate", "blackholes")
