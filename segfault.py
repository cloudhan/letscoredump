import ctypes
import multiprocessing as mp

_LIB = ctypes.cdll.LoadLibrary("build/libsegfault_dll.so")

def lets_segfault():
    _LIB.segfault()

if __name__ == "__main__":
    ps = []
    for i in range(4):
        p = mp.Process(target=lets_segfault)
        p.start()
        ps.append(p)

    for p in ps:
        p.join()

