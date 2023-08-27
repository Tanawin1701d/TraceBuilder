import numpy as np
import matplotlib.pyplot as plt

# Categories

def barplot(categoryNames: list, aType: str, bType: str, title: str):

    # Set the width of the bars
    bar_width = 0.35
    # Generate an array of indices for the x-axis
    x = np.arange(len(categoryNames))
    # Create a bar graph
    fig, ax = plt.subplots()
    bars1 = ax.bar(x - bar_width/2, [e[1] for e in categoryNames], width=bar_width, label=aType)
    bars2 = ax.bar(x + bar_width/2, [e[2] for e in categoryNames], width=bar_width, label=bType)
    # Add labels and title
    plt.xlabel('fu categories')
    plt.ylabel('count used')
    plt.title(title)
    plt.xticks(x, [e[0] for e in categoryNames], rotation=45)

    for bar1, bar2 in zip(bars1, bars2):
        height1 = bar1.get_height()
        height2 = bar2.get_height()
        ax.annotate(f'{height1//1000}k', (bar1.get_x() + bar1.get_width() / 2, height1),
                    xytext=(0, 3), textcoords="offset points",
                    ha='center', va='bottom', rotation=45)
        ax.annotate(f'{height2//1000}k', (bar2.get_x() + bar2.get_width() / 2, height2),
                    xytext=(0, 3), textcoords="offset points",
                    ha='center', va='bottom', rotation=45)

    # Add a legend
    plt.legend()
    # Display the graph
    plt.show()

# barplot([("IntAlu"       , 675632829                , 402409989),
#          ("IntMult"      , 384258                   , 384048),
#          ("IntDiv"       , 2329791                  , 0),
#          ("FltAlu"       , 90265438                 , 42739082),
#          ("FloatMult"    , 0                        , 0),
#          ("FloatDiv"     , 0                        , 0),
#          ("SimdAlu"      , 117683275+427278+16105064, 96747682),
#          ("SimdMult"     , 0                        , 0),
#          ("SimdDiv"      , 0                        , 0),
#          ("SimdFloatAlu" , 65047435 + 65047435      , 103366258),
#          ("SimdFloatMult", 94848000                 , 69856185),
#          ("SimdFloatDiv" , 6553600                  , 6551962),
#          ("MemRead"      , 81334142                 , 91778427),
#          ("MemWrite"     , 32527727                 , 32474259),
#          ("FloatMemRead" , 117354941                , 102432928),
#          ("FloatMemWrite", 26013896                 , 21040565)
#          ], "gem5BaseLine", "gem5TbdIsa", "blackholes instruction types")

barplot([("IntAlu"       , 3152917863                              , 1894181248),
         ("IntMult"      , 12070395                                , 12059118),
         ("IntDiv"       , 40221                                   , 0),
         ("FltAlu"       , 623279389+1776                          , 330648620),
         ("FloatMult"    , 0                                       , 0),
         ("FloatDiv"     , 0                                       , 0),
         ("SimdAlu"      , 7070+9920944+14492+1863919+955 , 9947452),
         ("SimdMult"     , 0                                       , 0),
         ("SimdDiv"      , 0                                       , 0),
         ("SimdFloatAlu" , 417014164+ 76055006 +4954029            , 416991523),
         ("SimdFloatMult", 306492813                               , 306479388),
         ("SimdFloatDiv" , 11759369                                , 11759081),
         ("MemRead"      , 180114173                               , 183859458),
         ("MemWrite"     , 64544519                                , 68404274),
         ("FloatMemRead" , 529221160                               , 529071590),
         ("FloatMemWrite", 52435824                                , 52282198)
         ], "gem5BaseLine", "gem5TbdIsa", "fluidAnimate instruction types")