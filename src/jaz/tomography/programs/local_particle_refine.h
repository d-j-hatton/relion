#ifndef LOCAL_PARTICLE_REFINE_PROGRAM_H
#define LOCAL_PARTICLE_REFINE_PROGRAM_H

#include "refinement.h"
#include <src/jaz/optics/aberrations_cache.h>
#include <src/jaz/optics/aberration_fit.h>
#include <src/jaz/math/tensor2x2.h>


class LocalParticleRefineProgram : public RefinementProgram
{
	public:


		LocalParticleRefineProgram(int argc, char *argv[]);

			int max_iterations;
			double eps, xtol;
			bool verbose_opt;

		void readParams(IOParser& parser);
		void run();
};

#endif
