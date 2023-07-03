import matplotlib.pyplot as plt



def barplot(title, fluidValues, blacksholesValue, yTitle):
    fig, ax = plt.subplots()
    bar_width = 0.35
    ax.bar([0          , 1.25              ], [fluidValues[0], blacksholesValue[0]], width=bar_width, label='traceBuilder')
    ax.bar([bar_width  , 1.25 + bar_width  ], [fluidValues[1], blacksholesValue[1]], width=bar_width, label='gem5')


    ax.text(- 0.175    , fluidValues[0] + 1     , str(fluidValues[0]     ), color='black', fontweight='bold')
    ax.text(1.25 - 0.175, blacksholesValue[0] + 1, str(blacksholesValue[0]), color='black', fontweight='bold')

    ax.text(- 0.175 + 0.35, fluidValues[1] + 1, str(fluidValues[1]), color='black', fontweight='bold')
    ax.text(1.25 - 0.175 + 0.35, blacksholesValue[1] + 1, str(blacksholesValue[1]), color='black', fontweight='bold')

    # Customize the chart as needed
    ax.set_title(title)
    ax.set_xticks([0.17, 1.85-0.35])
    ax.set_xticklabels(["fluidAnimate", "blacksholes"])
    #ax.set_xlabel()
    ax.set_ylabel(yTitle)
    ax.legend()

    # Display the chart
    plt.show()



result = [
["execute time"     , [1037	,1180	],[207	,206  ]	 ,"millisec"],
["dcache read hit"  , [640	,646	],[185	,181  ]	 ,"M count"],
["dcache read miss" , [64	,71  	],[1.1	,0.9  ]	 ,"M count"],
["dcache write hit" , [114	,116	],[53	,58	  ]  ,"M count"],
["dcache write miss", [6.6	,1.5	],[0.24	,0.12 ]	 ,"M count"],
["fetch"            , [3012 ,3425	],[708	,806  ]	 ,"M count"],
["readRowhit"       , [9648	,9901	],[757	,718  ]	 ,"K count"],
["writeRowhit"      , [2334	,2377	],[111	,111  ]	 ,"K count"],
["readRowhit rate"  , [84.28,83.81	],[79.86,81.73]	 ,"percent"],
["writeRowhit rate" , [75.67,75.47	],[87.45,89.15]	 ,"percent"]
]


for res in result:
    barplot(*res)