/*
 * =====================================================================================
 *
 *       Filename:  bGet.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2014 13:57:41
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
	TH1D * hCent4;
	TH1D * hCent6;
	TH1D * hCent8;
	TH1D * hNoff4;
	TH1D * hNoff6;
	TH1D * hNoff8;
	TH1D * hQ22[20];
	TH1D * hQ24[20];
	TH1D * hQ26[20];
	TH1D * hQ28[20];
	TH1D * hQ22i[20];
	TH1D * hQ24i[20];
	TH1D * hQ26i[20];
	TH1D * hQ28i[20];

	TH1D * hC22[20];
	TH1D * hC24[20];
	TH1D * hC26[20];
	TH1D * hC28[20];
	TH1D * hV22[20];
	TH1D * hV24[20];
	TH1D * hV26[20];
	TH1D * hV28[20];

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
	hCent4 = (TH1D*)f->Get("hCent4");
	hCent6 = (TH1D*)f->Get("hCent6");
	hCent8 = (TH1D*)f->Get("hCent8");
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


	TH1D* hC22Cent = (TH1D*)f->Get("hC22Cent");
	TH1D* hC24Cent = (TH1D*)f->Get("hC24Cent");
	TH1D* hC26Cent = (TH1D*)f->Get("hC26Cent");
	TH1D* hC28Cent = (TH1D*)f->Get("hC28Cent");

	TH1D* hV22Cent = (TH1D*)f->Get("hV22Cent");
	TH1D* hV24Cent = (TH1D*)f->Get("hV24Cent");
	TH1D* hV26Cent = (TH1D*)f->Get("hV26Cent");
	TH1D* hV28Cent = (TH1D*)f->Get("hV28Cent");

	for ( int c = 0; c < 20; c++ ) {
		hQ22[c] = (TH1D*) f->Get(Form("%s_%i", "hQ22", c));
		hQ24[c] = (TH1D*) f->Get(Form("%s_%i", "hQ24", c));
		hQ26[c] = (TH1D*) f->Get(Form("%s_%i", "hQ26", c));
		hQ28[c] = (TH1D*) f->Get(Form("%s_%i", "hQ28", c));

		hC22[c] = (TH1D*) f->Get(Form("%s_%i", "hC22", c));
		hC24[c] = (TH1D*) f->Get(Form("%s_%i", "hC24", c));
		hC26[c] = (TH1D*) f->Get(Form("%s_%i", "hC26", c));
		hC28[c] = (TH1D*) f->Get(Form("%s_%i", "hC28", c));

		hV22[c] = (TH1D*) f->Get(Form("%s_%i", "hV22", c));
		hV24[c] = (TH1D*) f->Get(Form("%s_%i", "hV24", c));
		hV26[c] = (TH1D*) f->Get(Form("%s_%i", "hV26", c));
		hV28[c] = (TH1D*) f->Get(Form("%s_%i", "hV28", c));

		hQ22i[c] = (TH1D*) f->Get(Form("%s_%i", "hQ22i", c));
		hQ24i[c] = (TH1D*) f->Get(Form("%s_%i", "hQ24i", c));
		hQ26i[c] = (TH1D*) f->Get(Form("%s_%i", "hQ26i", c));
		hQ28i[c] = (TH1D*) f->Get(Form("%s_%i", "hQ28i", c));
	}

}
