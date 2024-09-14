import os
import gc
from uniref import WinUniRef

def Main():
    exec_input = input("Write You're EXEC File: ")
    unityref = WinUniRef("{}.exe".format(exec_input))
    monodom = unityref.injector.mono_domain_get()
    unityref.injector.mono_thread_attach(monodom)
    gc.enable()
    gc.collect(4000)    

if __name__ == "__main__":
    Main()