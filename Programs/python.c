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
__attribute__((export_name("wizer-initialize")))
void
wizer_initialize(void)
{
    Py_WizerMain();
}
#endif

int
main(int argc, char **argv)
{
    return Py_BytesMain(argc, argv);
}
#endif
