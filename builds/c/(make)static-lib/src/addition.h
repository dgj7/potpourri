#ifndef ADDITION__DG__H__
#define ADDITION__DG__H__

#ifdef __cplusplus
extern "C" {
#endif

#define EXPORT __attribute__((__visibility__("default")))

EXPORT int add(int leftAddend, int rightAddend);

#ifdef __cplusplus
}
#endif

#endif
