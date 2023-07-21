import os
import threading

def getThreadId():
    cur_thread = threading.current_thread()
    tid        = cur_thread.ident
    return tid