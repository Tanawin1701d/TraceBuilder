import glob
import os
import subprocess

def compile_protoFile():
    curFilePath = os.path.realpath(__file__)
    thisFolderPath = os.path.dirname(curFilePath)

    protoFiles = glob.glob(os.path.join(thisFolderPath, "*.proto"))

    for proto_path in protoFiles:
        print("[PROTOC] compile: {}".format(proto_path))
        subprocess.run(["protoc",
                        "-I={}".format(thisFolderPath),
                        "--cpp_out={}".format(thisFolderPath),
                        proto_path
                        ])

compile_protoFile()
print("[PROTOC] finish compile!")