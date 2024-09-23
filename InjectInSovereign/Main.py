import ctypes
import os
def Main():
    ctyp_dll = ctypes.cdll.LoadLibrary(os.getcwd() + "\\Unity3DMono-GCCollect.dll")
    ctyp_dll.Inject()

if __name__ == "__main__":
    Main()