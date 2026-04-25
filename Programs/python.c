/* Minimal main program -- everything is loaded from the library */

#include "Python.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    return Py_Main(argc, argv);
}
#else

#ifdef __wasi__
extern int __main_void(void); /* defined by clang */

__attribute__((export_name("wizer-initialize")))
void
wizer_initialize(void)
{
    Py_WizerMain();
}

__attribute__((export_name("wizer.resume")))
void
wizer_resume(void)
{
    int r = __main_void();
    if (r != 0) {
        __wasi_proc_exit(r);
    }
}
#endif

int
main(int argc, char **argv)
{
    return Py_BytesMain(argc, argv);
}
#endif
