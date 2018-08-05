#ifndef OBS_MODEL_H
#define OBS_MODEL_H

#include <src/image.h>
#include <src/fftw.h>
#include <src/complex.h>
#include <src/metadata_table.h>
#include <src/projector.h>

class BackProjector;

class ObservationModel
{
    public:

        ObservationModel();
        ObservationModel(const MetaDataTable &opticsMdt);
		
		MetaDataTable opticsMdt;
		std::vector<double> angpix, lambda, Cs;

			
		void predictObservation(
				Projector &proj, const MetaDataTable &mdt, long int particle,
				MultidimArray<Complex>& dest,
				bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;
		
		Image<Complex> predictObservation(
				Projector &proj, const MetaDataTable &mdt, long int particle,
				bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;

        std::vector<Image<Complex>> predictObservations(
                Projector &proj, const MetaDataTable &mdt, int threads,
                bool applyCtf = true, bool applyTilt = true, bool applyShift = true) const;

        void insertObservation(
                const Image<Complex>& img, BackProjector &bproj,
                const MetaDataTable& mdt, long int particle,
                bool applyCtf, bool applyTilt,
                double shift_x = 0.0, double shift_y = 0.0);

        double angToPix(double a, int s, int opticsGroup);
        double pixToAng(double p, int s, int opticsGroup);
		
		double getPixelSize(int opticsGroup = 0);
		bool allPixelSizesIdentical();
		
		
		static bool containsAllNeededColumns(const MetaDataTable& mdt);

};

#endif
