import sys
import os
import inspect
import base.generator.header  as gen_main
import X86.genGroup.gen_group_comp as gen_grp_comp
import X86.genGroup.gen_group_mov  as gen_grp_mov
import X86.genGroup.gen_group_ctrl_flw as gen_grp_ctrl_flw

sys.path.append(os.path.dirname(os.path.realpath(__file__)))
gen_main.initializeDir()

for gen_file in [gen_grp_comp, gen_grp_mov, gen_grp_ctrl_flw]:

    gen_grps = inspect.getmembers(gen_file, inspect.isclass)
    for grpMeta in gen_grps:
        grp = grpMeta[1]()
        grp.gen()
gen_main.flush()