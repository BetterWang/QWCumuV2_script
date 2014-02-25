/*
 * =====================================================================================
 *
 *       Filename:  plot.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/13/2014 12:56:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
#include "label.h"
#include "noff.h"

	int s1 = 44;
//	int s2 = 20;
//	int s3 = 20;

	Int_t * pCent4;
	Int_t * pCent6;
	Int_t * pCent8;

	int NCent4 = 18;
	int NCent6 = 18;
	int NCent8 = 18;
	if ( s1 == 33 ) {
		pCent4 = CentNoffCutPbPb;
		pCent6 = CentNoffCutPbPb;
		pCent8 = CentNoffCutPbPb;
	}
	if ( s1 == 10 || s1 == 28 ) {
//		pCent4 = CentNoffCut;
//		pCent6 = MergedNoff6;
//		pCent8 = MergedNoff8;

//		NCent4 = 18;
//		NCent6 = 12;
//		NCent8 = 9;

		pCent4 = CentNoffCutTest4;
		pCent6 = CentNoffCutTest6;
		pCent8 = CentNoffCutTest8;

		NCent4 = 17;
		NCent6 = 11;
		NCent8 = 9;
	}
	if ( s1 == 34 || s1 == 39 || s1 == 44) {
		pCent4 = CentNoffCutHJ;
		pCent6 = CentNoffCutHJ;
		pCent8 = CentNoffCutHJ;

		NCent4 = 13;
		NCent6 = 13;
		NCent8 = 13;
	}
//	Int_t * pCent6 = MergedNoff6;
//	Int_t * pCent8 = MergedNoff8;
//	int NCent6 = 12;
//	int NCent8 = 9;
#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	TH1D::SetDefaultSumw2(false);


	TH1D * hW22Cent;
	TH1D * hW24Cent;
	TH1D * hW26Cent;
	TH1D * hW28Cent;

	TH1D * hQ22Cent;
	TH1D * hQ24Cent;
	TH1D * hQ26Cent;
	TH1D * hQ28Cent;

	TH1D * hMult;
	TH1D * hNoff;

	TFile * f;
	if ( s2 == s3 ) f = new TFile(Form("%s/output_mult.root", ftxt[s1]));
	else f = new TFile(Form("%s/output_mult_%i_%i.root", ftxt[s1], s2, s3));
	hMult = (TH1D*)f->Get("hMult");
	hNoff = (TH1D*)f->Get("hNoff");

	hW22Cent = (TH1D*) f->Get("hW22Cent");
	hW24Cent = (TH1D*) f->Get("hW24Cent");
	hW26Cent = (TH1D*) f->Get("hW26Cent");
	hW28Cent = (TH1D*) f->Get("hW28Cent");

	hQ22Cent = (TH1D*) f->Get("hQ22Cent");
	hQ24Cent = (TH1D*) f->Get("hQ24Cent");
	hQ26Cent = (TH1D*) f->Get("hQ26Cent");
	hQ28Cent = (TH1D*) f->Get("hQ28Cent");

	TProfile* hMultCent = (TProfile*) f->Get("hMultCent");

	TH1D * hWeightCent2 = (TH1D*) f->Get("hWeightCent2");
	TH1D * hWeightCent4 = (TH1D*) f->Get("hWeightCent4");
	TH1D * hWeightCent6 = (TH1D*) f->Get("hWeightCent6");
	TH1D * hWeightCent8 = (TH1D*) f->Get("hWeightCent8");
	//	f->Close();

	double dC22[500];
	double dC24[500];
	double dC26[500];
	double dC28[500];

	double dQ22[500];
	double dQ24[500];
	double dQ26[500];
	double dQ28[500];

	double dW22[500];
	double dW24[500];
	double dW26[500];
	double dW28[500];

	double dMult[500];
	double dWeight2[500];
	double dWeight4[500];
	double dWeight6[500];
	double dWeight8[500];

	double dC22x[100];
	double dC24x[100];
	double dC26x[100];
	double dC28x[100];

	double dQ22x[100];
	double dQ24x[100];
	double dQ26x[100];
	double dQ28x[100];

	double dW22x[100];
	double dW24x[100];
	double dW26x[100];
	double dW28x[100];

	double dMultx[100];
	double dNoffx[100];
	double dNevtx[100];

	double dWeight2x[100];
	double dWeight4x[100];
	double dWeight6x[100];
	double dWeight8x[100];

	TH1D * hC22CentS = new TH1D("hC22CentS", "hC22CentS", 20, 0, 20);
	TH1D * hC24CentS = new TH1D("hC24CentS", "hC24CentS", 20, 0, 20);
	TH1D * hC26CentS = new TH1D("hC26CentS", "hC26CentS", 20, 0, 20);
	TH1D * hC28CentS = new TH1D("hC28CentS", "hC28CentS", 20, 0, 20);

	TH1D * hC22CentW = new TH1D("hC22CentW", "hC22CentW", 20, 0, 20);
	TH1D * hC24CentW = new TH1D("hC24CentW", "hC24CentW", 20, 0, 20);
	TH1D * hC26CentW = new TH1D("hC26CentW", "hC26CentW", 20, 0, 20);
	TH1D * hC28CentW = new TH1D("hC28CentW", "hC28CentW", 20, 0, 20);
	for ( int c = 1; c < 500; c++ ) {
		dC22[c] = hC22Cent->GetBinContent(c);
		dC24[c] = hC24Cent->GetBinContent(c);
		dC26[c] = hC26Cent->GetBinContent(c);
		dC28[c] = hC28Cent->GetBinContent(c);

		dQ22[c] = hQ22Cent->GetBinContent(c);
		dQ24[c] = hQ24Cent->GetBinContent(c);
		dQ26[c] = hQ26Cent->GetBinContent(c);
		dQ28[c] = hQ28Cent->GetBinContent(c);

		dW22[c] = hW22Cent->GetBinContent(c);
		dW24[c] = hW24Cent->GetBinContent(c);
		dW26[c] = hW26Cent->GetBinContent(c);
		dW28[c] = hW28Cent->GetBinContent(c);

		dMult[c] = hMultCent->GetBinContent(c);
		dWeight2[c] = hWeightCent2->GetBinContent(c);
		dWeight4[c] = hWeightCent4->GetBinContent(c);
		dWeight6[c] = hWeightCent6->GetBinContent(c);
		dWeight8[c] = hWeightCent8->GetBinContent(c);
	}
	TH1D * hNoffCent4 = new TH1D("hNoffCent4", "hNoffCent4", 20, 0, 20);
	TH1D * hNoffCent6 = new TH1D("hNoffCent6", "hNoffCent6", 20, 0, 20);
	TH1D * hNoffCent8 = new TH1D("hNoffCent8", "hNoffCent8", 20, 0, 20);

	TH1D * hNevtCent4 = new TH1D("hNevtCent4", "hNevtCent4", 20, 0, 20);
	TH1D * hNevtCent6 = new TH1D("hNevtCent6", "hNevtCent6", 20, 0, 20);
	TH1D * hNevtCent8 = new TH1D("hNevtCent8", "hNevtCent8", 20, 0, 20);

	for ( int c = 0; c < 100; c++ ) {
		dQ22x[c] = 0;
		dQ24x[c] = 0;
		dQ26x[c] = 0;
		dQ28x[c] = 0;

		dW22x[c] = 0;
		dW24x[c] = 0;
		dW26x[c] = 0;
		dW28x[c] = 0;

		dC22x[c] = 0;
		dC24x[c] = 0;
		dC26x[c] = 0;
		dC28x[c] = 0;

		dMultx[c] = 0;
		dNoffx[c] = 0;
		dNevtx[c] = 0;

		dWeight2x[c] = 0;
		dWeight4x[c] = 0;
		dWeight6x[c] = 0;
		dWeight8x[c] = 0;
	}

	for ( int c = 0; c < 500; c++ ) {
		dQ22x[c/5] += dQ22[c];
		dQ24x[c/5] += dQ24[c];
		dQ26x[c/5] += dQ26[c];
		dQ28x[c/5] += dQ28[c];

		dW22x[c/5] += dW22[c];
		dW24x[c/5] += dW24[c];
		dW26x[c/5] += dW26[c];
		dW28x[c/5] += dW28[c];

		dMultx[c/5] += dMult[c];

		dWeight2x[c/5] = dWeight2[c];
		dWeight4x[c/5] = dWeight4[c];
		dWeight6x[c/5] = dWeight6[c];
		dWeight8x[c/5] = dWeight8[c];
	}

	for ( int c = 0; c < 100; c++ ) {
		if (dW22x[c]==0.) dQ22x[c] = 0.; else dQ22x[c] /= dW22x[c];
		if (dW24x[c]==0.) dQ24x[c] = 0.; else dQ24x[c] /= dW24x[c];
		if (dW26x[c]==0.) dQ26x[c] = 0.; else dQ26x[c] /= dW26x[c];
		if (dW28x[c]==0.) dQ28x[c] = 0.; else dQ28x[c] /= dW28x[c];

		double C2 = dQ22x[c];
		double C4 = dQ24x[c] - 2*dQ22x[c]*dQ22x[c];
		double C6 = dQ26x[c] - 9*dQ24x[c]*dQ22x[c] + 12*dQ22x[c]*dQ22x[c]*dQ22x[c];
		double C8 = dQ28x[c] - 16*dQ26x[c]*dQ22x[c] - 18*dQ24x[c]*dQ24x[c] + 144*dQ24x[c]*dQ22x[c]*dQ22x[c] - 144*dQ22x[c]*dQ22x[c]*dQ22x[c]*dQ22x[c];

		dC22x[c] = C2;
		dC24x[c] = C4;
		dC26x[c] = C6;
		dC28x[c] = C8;

		double noff = 0;
		double nevt = 0;
		int n = 5*c;
		noff += hNoff->GetBinContent(n)*n;
		nevt += hNoff->GetBinContent(n);
		n = 5*c+1;
		noff += hNoff->GetBinContent(n)*n;
		nevt += hNoff->GetBinContent(n);
		n = 5*c+2;
		noff += hNoff->GetBinContent(n)*n;
		nevt += hNoff->GetBinContent(n);
		n = 5*c+3;
		noff += hNoff->GetBinContent(n)*n;
		nevt += hNoff->GetBinContent(n);
		n = 5*c+4;
		noff += hNoff->GetBinContent(n)*n;
		nevt += hNoff->GetBinContent(n);

		dNoffx[c] = noff / nevt;
	}

	for ( int i = 0; i < NCent4; i++ ) {
		double noff = 0;
		double nevt = 0;
		for ( int n = pCent4[i]-1; n >= pCent4[i+1]; n-- ) {
			if ( n >= 500 ) continue;
			noff += hNoff->GetBinContent(n)*n;
			nevt += hNoff->GetBinContent(n);
		}
		hNoffCent4->SetBinContent(i+1, noff/nevt);
		hNevtCent4->SetBinContent(i+1, nevt);
	}

	for ( int i = 0; i < NCent6; i++ ) {
		double noff = 0;
		double nevt = 0;
		for ( int n = pCent6[i]-1; n >= pCent6[i+1]; n-- ) {
			if ( n >= 500 ) continue;
			noff += hNoff->GetBinContent(n)*n;
			nevt += hNoff->GetBinContent(n);
		}
		hNoffCent6->SetBinContent(i+1, noff/nevt);
		hNevtCent6->SetBinContent(i+1, nevt);
	}

	for ( int i = 0; i < NCent8; i++ ) {
		double noff = 0;
		double nevt = 0;
		for ( int n = pCent8[i]-1; n >= pCent8[i+1]; n-- ) {
			if ( n >= 500 ) continue;
			noff += hNoff->GetBinContent(n)*n;
			nevt += hNoff->GetBinContent(n);
		}
		hNoffCent8->SetBinContent(i+1, noff/nevt);
		hNevtCent8->SetBinContent(i+1, nevt);
	}

	for ( int i = 0; i < NCent4; i++ ) {
		double sum2 = 0;
		double sum4 = 0;
		double weight2 = 0;
		double weight4 = 0;
		int cstart = pCent4[i+1] / 5;
		int cend = pCent4[i] / 5;
		if ( cend > 100 ) cend = 100;
		for ( int c = cstart; c < cend; c++ ) {
			double w2 = dWeight2x[c];
			double w4 = dWeight4x[c];

			double C2 = dC22x[c];
			double C4 = dC24x[c];

			sum2 += C2*w2;
			sum4 += C4*w4;

			weight2 += w2;
			weight4 += w4;
		}
		
		double C2 = sum2 / weight2;
		double C4 = sum4 / weight4;

		hC22CentS->SetBinContent(i+1, C2 );
		hC24CentS->SetBinContent(i+1, C4 );

		hC22CentW->SetBinContent(i+1, weight2);
		hC24CentW->SetBinContent(i+1, weight4);
	}

	for ( int i = 0; i < NCent6; i++ ) {
		double sum6 = 0;
		double weight6 = 0;
		int cstart = pCent6[i+1] / 5;
		int cend = pCent6[i] / 5;
		if ( cend > 100 ) cend = 100;
		for ( int c = cstart; c < cend; c++ ) {
			double w6 = dWeight6x[c];
			double C6 = dC26x[c];
			sum6 += C6*w6;
			weight6 += w6;
		}
		double C6 = sum6 / weight6;
		hC26CentS->SetBinContent(i+1, C6 );
		hC26CentW->SetBinContent(i+1, weight6);
	}

	for ( int i = 0; i < NCent8; i++ ) {
		double sum8 = 0;
		double weight8 = 0;
		int cstart = pCent8[i+1] / 5;
		int cend = pCent8[i] / 5;
		if ( cend > 100 ) cend = 100;
		for ( int c = cstart; c < cend; c++ ) {
			double w8 = dWeight8x[c];
			double C8 = dC28x[c];
			sum8 += C8*w8;
			weight8 += w8;
		}
		double C8 = sum8 / weight8;
		hC28CentS->SetBinContent(i+1, C8 );
		hC28CentW->SetBinContent(i+1, weight8);
	}

	TH1D * hC22x = new TH1D("hC22x", "hC22x", 100, 0, 100);
	TH1D * hC24x = new TH1D("hC24x", "hC24x", 100, 0, 100);
	TH1D * hC26x = new TH1D("hC26x", "hC26x", 100, 0, 100);
	TH1D * hC28x = new TH1D("hC28x", "hC28x", 100, 0, 100);
	TH1D * hNoffx = new TH1D("hNoffx", "hNoffx", 100, 0, 100);

	for ( int c = 0; c < 100; c++ ) {
		hNoffx->SetBinContent(c+1, dNoffx[c]);
		hC22x->SetBinContent(c+1, dC22x[c]);
		hC24x->SetBinContent(c+1, dC24x[c]);
		hC26x->SetBinContent(c+1, dC26x[c]);
		hC28x->SetBinContent(c+1, dC28x[c]);
	}

	TFile * fwrite;
	if ( s2 == s3 ) f = new TFile(Form("%s/fit_mult.root", ftxt[s1]), "recreate");
	else f = new TFile(Form("%s/fit_mult_%i_%i.root", ftxt[s1], s2, s3), "recreate");
	hMult->Write();
	hNoff->Write();

	hW22Cent->Write();
	hW24Cent->Write();
	hW26Cent->Write();
	hW28Cent->Write();
	
	hMultCent->Write();

	hC22CentS->Write();
	hC24CentS->Write();
	hC26CentS->Write();
	hC28CentS->Write();

	hC22CentW->Write();
	hC24CentW->Write();
	hC26CentW->Write();
	hC28CentW->Write();

	hNoffCent4->Write();
	hNoffCent6->Write();
	hNoffCent8->Write();

	hNevtCent4->Write();
	hNevtCent6->Write();
	hNevtCent8->Write();

	hC22x->Write();
	hC24x->Write();
	hC26x->Write();
	hC28x->Write();
	hNoffx->Write();
}
