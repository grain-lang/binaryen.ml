#include <stdio.h>
#include <stdlib.h>
// These functions are needed for MUSL compatibility; they are marked weak
// to not interfere with glibc linkage

int __attribute__((weak)) __sprintf_chk(char * str, int flag, size_t strlen, const char * format) {
  sprintf(str, flag, strlen, format);
}

typedef void (*dtor_func) (void *);
int __attribute__((weak)) __cxa_thread_atexit_impl (dtor_func func, void *obj, void *dso_symbol) {
  // This is the destructor for C++ thread-local variables. It appears that there is only one such
  // variable in Binaryen: https://github.com/WebAssembly/binaryen/blob/b2c63a9665a9758c50eac60af605f0399f66580f/src/emscripten-optimizer/istring.h#L74
  // For now, we don't worry about it. We may need to reimplement this function in the future, though.
  return 0;
}
