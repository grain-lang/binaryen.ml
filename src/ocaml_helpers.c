#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/fail.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <stdarg.h>
#include <pthread.h>
#include <sched.h>

#include "ocaml_helpers.h"


CAMLprim value
caml_alloc_some(value v) {
  CAMLparam1(v);
  value some = caml_alloc_small(1, 0);
  Store_field(some, 0, v);
  CAMLreturn(some);
}

CAMLprim value
array_of_list(value list) {
  CAMLparam1(list);
  static const value *closure_f = NULL;
  if (closure_f == NULL) {
      /* First time around, look up by name */
      closure_f = caml_named_value("array_of_list");
  }
  CAMLreturn(caml_callback(*closure_f, list));
}

int array_length(value array) {
  CAMLparam1(array);
  static const value * closure_f = NULL;
  if (closure_f == NULL) {
    /* First time around, look up by name */
    closure_f = caml_named_value("array_length");
  }
  CAMLlocal1(res);
  res = caml_callback(*closure_f, array);
  CAMLreturnT(int, Int_val(res));
}

int __sprintf_chk(char * str, int flag, size_t strlen, const char * format, ...) {
  va_list vargs;
  va_start(vargs, format);
  int ret = vsprintf(str, format, vargs);
  va_end(vargs);
  return ret;
}

typedef void (*dtor_func) (void *);
int __cxa_thread_atexit_impl(dtor_func func, void *obj, void *dso_symbol) {
  // This is the destructor for C++ thread-local variables. It appears that there is only one such
  // variable in Binaryen: https://github.com/WebAssembly/binaryen/blob/b2c63a9665a9758c50eac60af605f0399f66580f/src/emscripten-optimizer/istring.h#L74
  // For now, we don't worry about it. We may need to reimplement this function in the future, though.
  return 0;
}

// patch for std::thread
#ifdef __cplusplus
extern "C" {
#endif

typedef pthread_t __gthread_t;
typedef pthread_key_t __gthread_key_t;
typedef pthread_once_t __gthread_once_t;
typedef struct _Mutex_Control __gthread_mutex_t;
typedef struct _Mutex_recursive_Control __gthread_recursive_mutex_t;
typedef struct _Condition_Control __gthread_cond_t;
typedef struct timespec __gthread_time_t;


int
__gthread_active_p (void)
{
  return 1;
}

int
__gthread_create (__gthread_t *__threadid, void *(*__func) (void *),
		  void *__args)
{
  return pthread_create (__threadid, NULL, __func, __args);
}

int
__gthread_join (__gthread_t __threadid, void **__value_ptr)
{
  return pthread_join (__threadid, __value_ptr);
}

int
__gthread_detach (__gthread_t __threadid)
{
  return pthread_detach (__threadid);
}

int
__gthread_equal (__gthread_t __t1, __gthread_t __t2)
{
  return pthread_equal (__t1, __t2);
}

__gthread_t
__gthread_self (void)
{
  return pthread_self ();
}

int
__gthread_yield (void)
{
  return sched_yield ();
}

int
__gthread_once (__gthread_once_t *__once, void (*__func) (void))
{
   return pthread_once (__once, __func);
}

int
__gthread_key_create (__gthread_key_t *__key, void (*__dtor) (void *))
{
  return pthread_key_create (__key, __dtor);
}

int
__gthread_key_delete (__gthread_key_t __key)
{
  return pthread_key_delete (__key);
}

void *
__gthread_getspecific (__gthread_key_t __key)
{
  return pthread_getspecific (__key);
}

int
__gthread_setspecific (__gthread_key_t __key, const void *__ptr)
{
  return pthread_setspecific (__key, __ptr);
}

int
__gthread_mutex_lock (__gthread_mutex_t *__mutex)
{
  _Mutex_Acquire (__mutex);
  return 0;
}

int
__gthread_mutex_trylock (__gthread_mutex_t *__mutex)
{
  return _Mutex_Try_acquire (__mutex);
}

int
__gthread_mutex_timedlock (__gthread_mutex_t *__mutex,
			   const __gthread_time_t *__abs_timeout)
{
  return _Mutex_Acquire_timed (__mutex, __abs_timeout);
}

int
__gthread_mutex_unlock (__gthread_mutex_t *__mutex)
{
  _Mutex_Release (__mutex);
  return 0;
}

int
__gthread_mutex_destroy (__gthread_mutex_t *__mutex)
{
  _Mutex_Destroy (__mutex);
  return 0;
}

int
__gthread_recursive_mutex_lock (__gthread_recursive_mutex_t *__mutex)
{
  _Mutex_recursive_Acquire (__mutex);
  return 0;
}

int
__gthread_recursive_mutex_trylock (__gthread_recursive_mutex_t *__mutex)
{
  return _Mutex_recursive_Try_acquire (__mutex);
}

int
__gthread_recursive_mutex_timedlock (__gthread_recursive_mutex_t *__mutex,
				     const __gthread_time_t *__abs_timeout)
{
  return _Mutex_recursive_Acquire_timed (__mutex, __abs_timeout);
}

int
__gthread_recursive_mutex_unlock (__gthread_recursive_mutex_t *__mutex)
{
  _Mutex_recursive_Release (__mutex);
  return 0;
}

int
__gthread_recursive_mutex_destroy (__gthread_recursive_mutex_t *__mutex)
{
  _Mutex_recursive_Destroy (__mutex);
  return 0;
}

int
__gthread_cond_broadcast (__gthread_cond_t *__cond)
{
  _Condition_Broadcast (__cond);
  return 0;
}

int
__gthread_cond_signal (__gthread_cond_t *__cond)
{
  _Condition_Signal (__cond);
  return 0;
}

int
__gthread_cond_wait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex)
{
  _Condition_Wait (__cond, __mutex);
  return 0;
}

int
__gthread_cond_timedwait (__gthread_cond_t *__cond, __gthread_mutex_t *__mutex,
			  const __gthread_time_t *__abs_timeout)
{
  return _Condition_Wait_timed (__cond, __mutex, __abs_timeout);
}

int
__gthread_cond_wait_recursive (__gthread_cond_t *__cond,
			       __gthread_recursive_mutex_t *__mutex)
{
  _Condition_Wait_recursive (__cond, __mutex);
  return 0;
}

int
__gthread_cond_destroy (__gthread_cond_t *__cond)
{
  _Condition_Destroy (__cond);
  return 0;
}

#ifdef __cplusplus
}
#endif
