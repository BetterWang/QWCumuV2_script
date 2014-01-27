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
//                                             0,   1,   2,  3\,   4,  5\,  6\,  7\,  8\,   9, 10, 11, 12, 13, 14, 15, 16, 17,
	const Int_t CentNoffCut[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
//                                 {6}         0,  {1,   2,} 3\,   4,  5\,  6\,  7\,  8\,   9,{10, 11}{12, 13,}14, 15, 16, 17,
//                                             0,        1,  2\,   3,  4\,  5\,  6\,  7\,   8,      9,     10, 14, 15, 16, 17,
//                                 {8}         0,  {1,   2,  3\,} {4,  5\,} 6\,  7\,  8\,   9,{10, 11}{12, 13,}14, 15, 16, 17,
//                                             0,            1\,       2\,  3\,  4\,  5\,   6,      7,      8, 14, 15, 16, 17,
	const Int_t nCentNoff = sizeof(CentNoffCut)/sizeof(Int_t);
	const Int_t nCentNoff6 = sizeof(MergedNoff6)/sizeof(Int_t);
	const Int_t nCentNoff8 = sizeof(MergedNoff8)/sizeof(Int_t);

	double dNoff[20];
	double dNoff6[20];
	double dNoff8[20];
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
		dNoff6[i] = dNoff[i];
		dNoff8[i] = dNoff[i];
	}
	

	TH1D* hC22CentEHM = (TH1D*) fHM->Get("hC22CentE");
	TH1D* hC24CentEHM = (TH1D*) fHM->Get("hC24CentE");
	TH1D* hC26CentEHM = (TH1D*) fHM->Get("hC26CentE");
	TH1D* hC28CentEHM = (TH1D*) fHM->Get("hC28CentE");

	TH1D* hC22CentEMB = (TH1D*) fMB->Get("hC22CentE");
	TH1D* hC24CentEMB = (TH1D*) fMB->Get("hC24CentE");
	TH1D* hC26CentEMB = (TH1D*) fMB->Get("hC26CentE");
	TH1D* hC28CentEMB = (TH1D*) fMB->Get("hC28CentE");

	TH1D* hW22CentHM = (TH1D*) fHM->Get("hW22Cent");
	TH1D* hW24CentHM = (TH1D*) fHM->Get("hW24Cent");
	TH1D* hW26CentHM = (TH1D*) fHM->Get("hW26Cent");
	TH1D* hW28CentHM = (TH1D*) fHM->Get("hW28Cent");

	TH1D* hW22CentMB = (TH1D*) fMB->Get("hW22Cent");
	TH1D* hW24CentMB = (TH1D*) fMB->Get("hW24Cent");
	TH1D* hW26CentMB = (TH1D*) fMB->Get("hW26Cent");
	TH1D* hW28CentMB = (TH1D*) fMB->Get("hW28Cent");

	double pPb_c22[20];
	double pPb_c24[20];
	double pPb_c26[20];
	double pPb_c28[20];
	double pPb_c22e[20];
	double pPb_c24e[20];
	double pPb_c26e[20];
	double pPb_c28e[20];

	double pPb_w22[20];
	double pPb_w24[20];
	double pPb_w26[20];
	double pPb_w28[20];

	double pPb_c26rebin[20];
	double pPb_c26rebine[20];
	double pPb_c28rebin[20];
	double pPb_c28rebine[20];

	for ( int c = 0; c < 20; c++ ) {
		pPb_c22[c] = 0;
		pPb_c24[c] = 0;
		pPb_c26[c] = 0;
		pPb_c28[c] = 0;
		pPb_c22e[c] = 1.;
		pPb_c24e[c] = 1.;
		pPb_c26e[c] = 1.;
		pPb_c28e[c] = 1.;
		pPb_w22[c] = 0;
		pPb_w24[c] = 0;
		pPb_w26[c] = 0;
		pPb_w28[c] = 0;

		pPb_c26rebin[c] = 0;
		pPb_c26rebine[c] = 1.;
		pPb_c28rebin[c] = 0;
		pPb_c28rebine[c] = 1.;
	}

	for ( int c = 0; c < 9; c++ ) {
		pPb_c22[c] = hC22CentEHM->GetBinContent(c+1);
		pPb_c24[c] = hC24CentEHM->GetBinContent(c+1);
		pPb_c26[c] = hC26CentEHM->GetBinContent(c+1);
		pPb_c28[c] = hC28CentEHM->GetBinContent(c+1);

		pPb_c22e[c] = hC22CentEHM->GetBinError(c+1) ;
		pPb_c24e[c] = hC24CentEHM->GetBinError(c+1) ;
		pPb_c26e[c] = hC26CentEHM->GetBinError(c+1) ;
		pPb_c28e[c] = hC28CentEHM->GetBinError(c+1) ;

		pPb_w22[c] = hW22CentHM->GetBinContent(c+1);
		pPb_w24[c] = hW24CentHM->GetBinContent(c+1);
		pPb_w26[c] = hW26CentHM->GetBinContent(c+1);
		pPb_w28[c] = hW28CentHM->GetBinContent(c+1);
	}
	for ( int c = 9; c < 18; c++ ) {
		pPb_c22[c] = hC22CentEMB->GetBinContent(c+1);
		pPb_c24[c] = hC24CentEMB->GetBinContent(c+1);
		pPb_c26[c] = hC26CentEMB->GetBinContent(c+1);
		pPb_c28[c] = hC28CentEMB->GetBinContent(c+1);

		pPb_c22e[c] = hC22CentEMB->GetBinError(c+1) ;
		pPb_c24e[c] = hC24CentEMB->GetBinError(c+1) ;
		pPb_c26e[c] = hC26CentEMB->GetBinError(c+1) ;
		pPb_c28e[c] = hC28CentEMB->GetBinError(c+1) ;

		pPb_w22[c] = hW22CentMB->GetBinContent(c+1);
		pPb_w24[c] = hW24CentMB->GetBinContent(c+1);
		pPb_w26[c] = hW26CentMB->GetBinContent(c+1);
		pPb_w28[c] = hW28CentMB->GetBinContent(c+1);
	}


	/////////////////
	// Combine bins 6

	if ( bRebin6 ) {
		pPb_c26rebin[0] = pPb_c26[0];
		pPb_c26rebine[0] = pPb_c26e[0];
		dNoff6[0] = dNoff[0];
	
		pPb_c26rebin[1] = (pPb_c26[1] * pPb_w26[1] + pPb_c26[2] * pPb_w26[2]) / (pPb_w26[1]+pPb_w26[2]);
		pPb_c26rebine[1] = sqrt(pPb_c26e[1]*pPb_c26e[1]*pPb_w26[1]*pPb_w26[1] + pPb_c26e[2]*pPb_c26e[2]*pPb_w26[2]*pPb_w26[2])/(pPb_w26[1]+pPb_w26[2]);
		dNoff6[1] = (dNoff[1]*dNevt[1] + dNoff[2]*dNevt[2])/(dNevt[1]+dNevt[2]);
	
		pPb_c26rebin[2] = pPb_c26[3];
		pPb_c26rebine[2] = pPb_c26e[3];
		dNoff6[2] = dNoff[3];
	
		pPb_c26rebin[3] = pPb_c26[4];
		pPb_c26rebine[3] = pPb_c26e[4];
		dNoff6[3] = dNoff[4];
	
		pPb_c26rebin[4] = pPb_c26[5];
		pPb_c26rebine[4] = pPb_c26e[5];
		dNoff6[4] = dNoff[5];
	
		pPb_c26rebin[5] = pPb_c26[6];
		pPb_c26rebine[5] = pPb_c26e[6];
		dNoff6[5] = dNoff[6];
	
		pPb_c26rebin[6] = pPb_c26[7];
		pPb_c26rebine[6] = pPb_c26e[7];
		dNoff6[6] = dNoff[7];
	
		pPb_c26rebin[7] = pPb_c26[8];
		pPb_c26rebine[7] = pPb_c26e[8];
		dNoff6[7] = dNoff[8];
	
		pPb_c26rebin[8] = pPb_c26[9];
		pPb_c26rebine[8] = pPb_c26e[9];
		dNoff6[8] = dNoff[9];
	
		pPb_c26rebin[9] = (pPb_c26[10] * pPb_w26[10] + pPb_c26[11] * pPb_w26[11]) / (pPb_w26[10]+pPb_w26[11]);
		pPb_c26rebine[9] = sqrt(pPb_c26e[10]*pPb_c26e[10]*pPb_w26[10]*pPb_w26[10] + pPb_c26e[11]*pPb_c26e[11]*pPb_w26[11]*pPb_w26[11])/(pPb_w26[10]+pPb_w26[11]);
		dNoff6[9] = (dNoff[10]*dNevt[10] + dNoff[11]*dNevt[11])/(dNevt[10]+dNevt[11]);
	
		pPb_c26rebin[10] = (pPb_c26[12] * pPb_w26[12] + pPb_c26[13] * pPb_w26[13]) / (pPb_w26[12]+pPb_w26[13]);
		pPb_c26rebine[10] = sqrt(pPb_c26e[12]*pPb_c26e[12]*pPb_w26[12]*pPb_w26[12] + pPb_c26e[13]*pPb_c26e[13]*pPb_w26[13]*pPb_w26[13])/(pPb_w26[12]+pPb_w26[13]);
		dNoff6[10] = (dNoff[12]*dNevt[12] + dNoff[13]*dNevt[13])/(dNevt[12]+dNevt[13]);
	
		for ( int c = 0; c < 20; c++ ) {
			pPb_c26[c] = pPb_c26rebin[c];
			pPb_c26e[c] = pPb_c26rebine[c];
		}
	}
	// Done rebin 6
	/////////////////
	//
	/////////////////
	// Combine bins 8
	
	if ( bRebin8 ) {
		pPb_c28rebin[0] = pPb_c28[0];
		pPb_c28rebine[0] = pPb_c28e[0];
		dNoff8[0] = dNoff[0];

		pPb_c28rebin[1] = (pPb_c28[1]*pPb_w28[1] + pPb_c28[2]*pPb_w28[2] + pPb_c28[3]*pPb_w28[3]) / (pPb_w28[1]+pPb_w28[2]+pPb_w28[3]);
		pPb_c28rebine[1] = sqrt(pPb_c28e[1]*pPb_c28e[1]*pPb_w28[1]*pPb_w28[1] + pPb_c28e[2]*pPb_c28e[2]*pPb_w28[2]*pPb_w28[2] + pPb_c28e[3]*pPb_c28e[3]*pPb_w28[3]*pPb_w28[3]) / (pPb_w28[1]+pPb_w28[2]+pPb_w28[3]);
		dNoff8[1] = (dNoff[1]*dNevt[1] + dNoff[2]*dNevt[2] + dNoff[3]*dNevt[3])/(dNevt[1]+dNevt[2]+dNevt[3]);

		pPb_c28rebin[2] = (pPb_c28[4]*pPb_w28[4] + pPb_c28[5]*pPb_w28[5]) / (pPb_w28[4]+pPb_w28[5]);
		pPb_c28rebine[2] = sqrt(pPb_c28e[4]*pPb_c28e[4]*pPb_w28[4]*pPb_w28[4] + pPb_c28e[5]*pPb_c28e[5]*pPb_w28[5]*pPb_w28[5]) / (pPb_w28[4]+pPb_w28[5]);
		dNoff8[2] = (dNoff[4]*dNevt[4] + dNoff[5]*dNevt[5])/(dNevt[4]+dNevt[5]);

		pPb_c28rebin[3] = pPb_c28[6];
		pPb_c28rebine[3] = pPb_c28e[6];
		dNoff8[3] = dNoff[6];

		pPb_c28rebin[4] = pPb_c28[7];
		pPb_c28rebine[4] = pPb_c28e[7];
		dNoff8[4] = dNoff[7];

		pPb_c28rebin[5] = pPb_c28[8];
		pPb_c28rebine[5] = pPb_c28e[8];
		dNoff8[5] = dNoff[8];

		pPb_c28rebin[6] = pPb_c28[9];
		pPb_c28rebine[6] = pPb_c28e[9];
		dNoff8[6] = dNoff[9];

		pPb_c28rebin[7] = (pPb_c28[10] * pPb_w28[10] + pPb_c28[11] * pPb_w28[11]) / (pPb_w28[10]+pPb_w28[11]);
		pPb_c28rebine[7] = sqrt(pPb_c28e[10]*pPb_c28e[10]*pPb_w28[10]*pPb_w28[10] + pPb_c28e[11]*pPb_c28e[11]*pPb_w28[11]*pPb_w28[11])/(pPb_w28[10]+pPb_w28[11]);
		dNoff8[7] = (dNoff[10]*dNevt[10] + dNoff[11]*dNevt[11])/(dNevt[10]+dNevt[11]);
	
		pPb_c28rebin[8] = (pPb_c28[12] * pPb_w28[12] + pPb_c28[13] * pPb_w28[13]) / (pPb_w28[12]+pPb_w28[13]);
		pPb_c28rebine[8] = sqrt(pPb_c28e[12]*pPb_c28e[12]*pPb_w28[12]*pPb_w28[12] + pPb_c28e[13]*pPb_c28e[13]*pPb_w28[13]*pPb_w28[13])/(pPb_w28[12]+pPb_w28[13]);
		dNoff8[8] = (dNoff[12]*dNevt[12] + dNoff[13]*dNevt[13])/(dNevt[12]+dNevt[13]);
	
		for ( int c = 0; c < 20; c++ ) {
			pPb_c28[c] = pPb_c28rebin[c];
			pPb_c28e[c] = pPb_c28rebine[c];
		}
	}

	// done rebin 8
	/////////////////
	double dNSigma2[20];
	double dNSigma4[20];
	double dNSigma6[20];
	double dNSigma8[20];

	for ( int c = 0; c < 18; c++ ) {
		dNSigma2[c] = pPb_c22[c] / pPb_c22e[c];
		dNSigma4[c] = pPb_c24[c] / pPb_c24e[c];
		dNSigma6[c] = pPb_c26[c] / pPb_c26e[c];
		dNSigma8[c] = pPb_c28[c] / pPb_c28e[c];
	}

	double pPb_v22[20];
	double pPb_v24[20];
	double pPb_v26[20];
	double pPb_v28[20];
	double pPb_v22e[20];
	double pPb_v24e[20];
	double pPb_v26e[20];
	double pPb_v28e[20];

	for ( int c = 0; c < 18; c++ ) {
		double C2 = pPb_c22[c];
		double C4 = pPb_c24[c];
		double C6 = pPb_c26[c];
		double C8 = pPb_c28[c];

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

		pPb_v22[c] = V2;
		pPb_v24[c] = V4;
		pPb_v26[c] = V6;
		pPb_v28[c] = V8;

		pPb_v22e[c] = fabs( V2 / pPb_c22[c] * pPb_c22e[c] / 2.);
		pPb_v24e[c] = fabs( V4 / pPb_c24[c] * pPb_c24e[c] / 4.);
		pPb_v26e[c] = fabs( V6 / pPb_c26[c] * pPb_c26e[c] / 6.);
		pPb_v28e[c] = fabs( V8 / pPb_c28[c] * pPb_c28e[c] / 8.);
	}

}
