/***************************************************************************
 *
 * Author: "Sjors H.W. Scheres"
 * MRC Laboratory of Molecular Biology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * This complete copyright notice must be included in any revised version of the
 * source code. Additional authorship citations may be added, but existing
 * author citations must be preserved.
 ***************************************************************************/

#ifndef MOTIONCORR_OWN_DEVOLVED_H_
#define MOTIONCORR_OWN_DEVOLVED_H_

#include "src/motioncorr_runner.h"
#include "src/parallel.h"

class MotioncorrOwnDevolved: public MotioncorrRunner
{
public:
    /** Read
     * This could take care of mpi-parallelisation-dependent variables
     */
    void read(int argc, char **argv);

    void initialise() {return;};
    void addClArgs() override;

    // Parallelized run function
    void run();

    FileName getOutputFileNames(FileName fn_mic, bool continue_even_odd = false) override;

    FileName movie_path;
    FileName micrograph_path;

};

#endif /* MOTIONCORR_RUNNER_MPI_H_ */
