import sys
import os
import inspect
import base.generator.header  as gen_main
import X86.genGroup.gen_group as gen_grp

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
gen_main.initializeDir()
grps = inspect.getmembers(gen_grp, inspect.isclass)
for grpMeta in grps:
    grp = grpMeta[1]()
    grp.gen()
gen_main.flush()