
#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __attribute__ ((visibility ("default")))
#endif

void _segfault() {
    int* wild = (int*)1;
    delete wild;
    
}

#if BUILD_EXE
int main() {
    _segfault();
    return 0;
}
#else
extern "C" {
EXPORT void segfault() {
    _segfault();
}
}
#endif
