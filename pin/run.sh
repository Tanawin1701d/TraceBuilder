make PIN_ROOT=/media/tanawin/tanawin1701d/Project/sms/pintool/pin-3.25-98650-g8f6168173-gcc-linux  obj-intel64/testOp2.so
make PIN_ROOT=/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/traceBuilder/pin/pin-3.25-98650-g8f6168173-gcc-linux  obj-intel64/tracer.so
sudo ../pin-3.25-98650-g8f6168173-gcc-linux/pin -t obj-intel64/testPid.so -- /bin/ls

sudo ../pin-3.25-98650-g8f6168173-gcc-linux/pin -t obj-intel64/testOp2.so -- /bin/ls


sudo ../pin-3.25-98650-g8f6168173-gcc-linux/pin -t obj-intel64/testOp.so -- /media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/memstress/fluidanimate 1 5 /media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/memstress/in_100K.fluid


sudo ../pin-3.25-98650-g8f6168173-gcc-linux/pin -t obj-intel64/testOp2.so -- /media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/memstress/fluidanimate 1 5 /media/tanawin/tanawin1701d/Project/sms/compiledEle/meta_workloads/test-progs/memstress/in_100K.fluid


python3 cleanData.py
python3 /media/tanawin/tanawin1701d/Project/sms/gem5/util/encode_inst_dep_trace.py \
 /media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/dynamicData.txt \
  /media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/dynamicData


python3 /media/tanawin/tanawin1701d/Project/sms/gem5/util/encode_packet_trace.py \
/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/generatedFile/instrBeta.txt \
/media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/protoFile/instrBeta



sudo pin-3.25-98650-g8f6168173-gcc-linux/pin -t obj-intel64/tracer.so \
-i /media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testserst \
-d /media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testserRT \
-db /media/tanawin/tanawin1701d/Project/sms/pintool/msmsPin/rawFile/testserdbg
-- /bin/ls
