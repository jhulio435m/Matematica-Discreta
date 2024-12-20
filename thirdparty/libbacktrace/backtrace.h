

#ifndef BACKTRACE_H
#define BACKTRACE_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif



struct backtrace_state;



typedef void (*backtrace_error_callback) (void *data, const char *msg,
					  int errnum);



extern struct backtrace_state *backtrace_create_state (
    const char *filename, int threaded,
    backtrace_error_callback error_callback, void *data);



typedef int (*backtrace_full_callback) (void *data, uintptr_t pc,
					const char *filename, int lineno,
					const char *function);



extern int backtrace_full (struct backtrace_state *state, int skip,
			   backtrace_full_callback callback,
			   backtrace_error_callback error_callback,
			   void *data);



typedef int (*backtrace_simple_callback) (void *data, uintptr_t pc);



extern int backtrace_simple (struct backtrace_state *state, int skip,
			     backtrace_simple_callback callback,
			     backtrace_error_callback error_callback,
			     void *data);



extern void backtrace_print (struct backtrace_state *state, int skip, FILE *);



extern int backtrace_pcinfo (struct backtrace_state *state, uintptr_t pc,
			     backtrace_full_callback callback,
			     backtrace_error_callback error_callback,
			     void *data);



typedef void (*backtrace_syminfo_callback) (void *data, uintptr_t pc,
					    const char *symname,
					    uintptr_t symval,
					    uintptr_t symsize);



extern int backtrace_syminfo (struct backtrace_state *state, uintptr_t addr,
			      backtrace_syminfo_callback callback,
			      backtrace_error_callback error_callback,
			      void *data);

#ifdef __cplusplus
}
#endif

#endif
