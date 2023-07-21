import sys
import os

thisFolderPath = os.path.dirname(os.path.realpath(__file__))
projectPath    = os.path.join(thisFolderPath, "../../../")

tbdLibDirPath  = os.path.join(projectPath, "cmake-build-debug/")

tbdModelPath   = os.path.join(projectPath, "src/models/uop_model/pyMach")

##### folder
sys.path.append(tbdLibDirPath)
sys.path.append(tbdModelPath)
#####