/*
 * =====================================================================================
 *
 *       Filename:  bGetFit.C
 *
 *    Description:  get from fit.root
 *
 *        Version:  1.0
 *        Created:  01/24/2014 17:45:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

{
#include "noff.h"
	TH1D * hMult4;
	TH1D * hMult6;
	TH1D * hMult8;
	TH1D * hNoff4;
	TH1D * hNoff6;
	TH1D * hNoff8;

	const Int_t CentNoffCut[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
	const Int_t nCentNoff = sizeof(CentNoffCut)/sizeof(Int_t);
	const Int_t nCentNoff6 = sizeof(MergedNoff6)/sizeof(Int_t);
	const Int_t nCentNoff8 = sizeof(MergedNoff8)/sizeof(Int_t);

	double dNoff4[20];
	double dNoff6[20];
	double dNoff8[20];

	hMult4 = (TH1D*)f->Get("hMult4");
	hMult6 = (TH1D*)f->Get("hMult6");
	hMult8 = (TH1D*)f->Get("hMult8");
	hNoff4 = (TH1D*)f->Get("hNoff4");
	hNoff6 = (TH1D*)f->Get("hNoff6");
	hNoff8 = (TH1D*)f->Get("hNoff8");

	int Noff = 500;
	for ( int i = 0; i < nCentNoff-1; i++ ) {
		int NN = 0;
		double avgNoff = 0;
		while ( Noff >= CentNoffCut[i+1] ) {
			int nNN = hNoff4->GetBinContent(Noff);
			avgNoff += Noff*nNN;
			NN += nNN;
			Noff--;
		}
		if (NN > 0) dNoff4[i] = avgNoff/NN;
		else dNoff4[i] = 0;
	}
	Noff = 500;
	for ( int i = 0; i < nCentNoff6-1; i++ ) {
		int NN = 0;
		double avgNoff = 0;
		while ( Noff >= MergedNoff6[i+1] ) {
			int nNN = hNoff6->GetBinContent(Noff);
			avgNoff += Noff*nNN;
			NN += nNN;
			Noff--;
		}
		if (NN > 0) dNoff6[i] = avgNoff/NN;
		else dNoff6[i] = 0;
	}
	Noff = 500;
	for ( int i = 0; i < nCentNoff8-1; i++ ) {
		int NN = 0;
		double avgNoff = 0;
		while ( Noff >= MergedNoff8[i+1] ) {
			int nNN = hNoff8->GetBinContent(Noff);
			avgNoff += Noff*nNN;
			NN += nNN;
			Noff--;
		}
		if (NN > 0) dNoff8[i] = avgNoff/NN;
		else dNoff8[i] = 0;
	}

}
