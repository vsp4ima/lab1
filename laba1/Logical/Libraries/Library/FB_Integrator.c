
#include <bur/plctypes.h>
#ifdef __cplusplus
  extern "C"
  {
#endif
#include "Library.h"
#ifdef __cplusplus
  };
#endif

void FB_Integrator(struct FB_Integrator* inst) 
{
	inst->out = inst->dt * inst->in + inst->prev_value;
	inst->prev_value = inst->out;
}