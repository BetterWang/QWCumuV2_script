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
	TH1D * hMultHM;
	TH1D * hNoffHM;
	TH1D * hMultMB;
	TH1D * hNoffMB;
//                                             0,   1,   2,   3,   4,   5,   6,   7,   8,   9, 10, 11, 12, 13, 14, 15, 16, 17,
	const Int_t CentNoffCut[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
	const Int_t nCentNoff = sizeof(CentNoffCut)/sizeof(Int_t);
	const Int_t nCentNoff6 = sizeof(MergedNoff6)/sizeof(Int_t);
	const Int_t nCentNoff8 = sizeof(MergedNoff8)/sizeof(Int_t);

	double dNoff[20];
	double dNevt[20];

	hMultHM = (TH1D*)fHM->Get("hMult");
	hMultMB = (TH1D*)fMB->Get("hMult");

	hNoffHM = (TH1D*)fHM->Get("hNoff");
	hNoffMB = (TH1D*)fMB->Get("hNoff");

	int Noff = 500;
	for ( int i = 0; i < 18; i++ ) {
		int NN = 0;
		double avgNoff = 0;
		while ( Noff >= CentNoffCut[i+1] ) {
			int nNN = 0;
			if ( i < 9 ) nNN = hNoffHM->GetBinContent(Noff);
			else nNN = hNoffMB->GetBinContent(Noff);
			avgNoff += Noff*nNN;
			NN += nNN;
			Noff--;
		}
		if (NN > 0) dNoff[i] = avgNoff/NN;
		else dNoff[i] = 0;
		dNevt[i] = NN;
	}
	
	double dNSigma2[20];
	double dNSigma4[20];
	double dNSigma6[20];
	double dNSigma8[20];
	TH1D * hC2NSgimaHM = (TH1D*) fHM->Get("hC22NSigma");
	TH1D * hC4NSgimaHM = (TH1D*) fHM->Get("hC24NSigma");
	TH1D * hC6NSgimaHM = (TH1D*) fHM->Get("hC26NSigma");
	TH1D * hC8NSgimaHM = (TH1D*) fHM->Get("hC28NSigma");

	TH1D * hC2NSgimaMB = (TH1D*) fMB->Get("hC22NSigma");
	TH1D * hC4NSgimaMB = (TH1D*) fMB->Get("hC24NSigma");
	TH1D * hC6NSgimaMB = (TH1D*) fMB->Get("hC26NSigma");
	TH1D * hC8NSgimaMB = (TH1D*) fMB->Get("hC28NSigma");

	for ( int c = 0; c < 9; c++ ) {
		dNSigma2[c] = hC2NSgimaHM->GetBinContent(c+1);
		dNSigma4[c] = hC4NSgimaHM->GetBinContent(c+1);
		dNSigma6[c] = hC6NSgimaHM->GetBinContent(c+1);
		dNSigma8[c] = hC8NSgimaHM->GetBinContent(c+1);
	}
	for ( int c = 9; c < 18; c++ ) {
		dNSigma2[c] = hC2NSgimaMB->GetBinContent(c+1);
		dNSigma4[c] = hC4NSgimaMB->GetBinContent(c+1);
		dNSigma6[c] = hC6NSgimaMB->GetBinContent(c+1);
		dNSigma8[c] = hC8NSgimaMB->GetBinContent(c+1);
	}

	double pPb_v22[20];
	double pPb_v24[20];
	double pPb_v26[20];
	double pPb_v28[20];
	double pPb_v22e[20];
	double pPb_v24e[20];
	double pPb_v26e[20];
	double pPb_v28e[20];

	TH1D* hV22CentEHM = (TH1D*) fHM->Get("hV22CentE");
	TH1D* hV24CentEHM = (TH1D*) fHM->Get("hV24CentE");
	TH1D* hV26CentEHM = (TH1D*) fHM->Get("hV26CentE");
	TH1D* hV28CentEHM = (TH1D*) fHM->Get("hV28CentE");

	TH1D* hV22CentEMB = (TH1D*) fMB->Get("hV22CentE");
	TH1D* hV24CentEMB = (TH1D*) fMB->Get("hV24CentE");
	TH1D* hV26CentEMB = (TH1D*) fMB->Get("hV26CentE");
	TH1D* hV28CentEMB = (TH1D*) fMB->Get("hV28CentE");

	for ( int c = 0; c < 9; c++ ) {
		pPb_v22[c] = hV22CentEHM->GetBinContent(c+1);
		pPb_v24[c] = hV24CentEHM->GetBinContent(c+1);
		pPb_v26[c] = hV26CentEHM->GetBinContent(c+1);
		pPb_v28[c] = hV28CentEHM->GetBinContent(c+1);

		pPb_v22e[c] = hV22CentEHM->GetBinError(c+1);
		pPb_v24e[c] = hV24CentEHM->GetBinError(c+1);
		pPb_v26e[c] = hV26CentEHM->GetBinError(c+1);
		pPb_v28e[c] = hV28CentEHM->GetBinError(c+1);
	}
	for ( int c = 9; c < 18; c++ ) {
		pPb_v22[c] = hV22CentEMB->GetBinContent(c+1);
		pPb_v24[c] = hV24CentEMB->GetBinContent(c+1);
		pPb_v26[c] = hV26CentEMB->GetBinContent(c+1);
		pPb_v28[c] = hV28CentEMB->GetBinContent(c+1);

		pPb_v22e[c] = hV22CentEMB->GetBinError(c+1);
		pPb_v24e[c] = hV24CentEMB->GetBinError(c+1);
		pPb_v26e[c] = hV26CentEMB->GetBinError(c+1);
		pPb_v28e[c] = hV28CentEMB->GetBinError(c+1);
	}

}
