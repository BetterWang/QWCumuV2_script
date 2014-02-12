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

	int s1 = 10;
//	int s2 = 20;
//	int s3 = 20;

	int NCent = 18;
//	Int_t * pCent = CentNoffCut;
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
	TH1D * hNoffCent = new TH1D("hNoffCent", "hNoffCent", 20, 0, 20);
	for ( int i = 0; i < NCent; i++ ) {
		double sum2 = 0;
		double sum4 = 0;
		double sum6 = 0;
		double sum8 = 0;
		double weight2 = 0;
		double weight4 = 0;
		double weight6 = 0;
		double weight8 = 0;
		double noff = 0;
		double nevt = 0;
		for ( int n = CentNoffCut[i]-1; n >= CentNoffCut[i+1]; n-- ) {
			if ( n >= 500 ) continue;

			double w2 = dMult[n];
			double w4 = dMult[n];
			double w6 = dMult[n];
			double w8 = dMult[n];

			double C2 = dC22[n];
			double C4 = dC24[n];
			double C6 = dC26[n];
			double C8 = dC28[n];

			double V2, V4, V6, V8;
			if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
			if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
			if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
			if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

			sum2 += V2*w2;
			sum4 += V4*w4;
			sum6 += V6*w6;
			sum8 += V8*w8;

			weight2 += w2;
			weight4 += w4;
			weight6 += w6;
			weight8 += w8;

			noff += hNoff->GetBinContent(n)*n;
			nevt += hNoff->GetBinContent(n);
		}
		
		double V2;
		double V4;
		double V6;
		double V8;
		if ( w2 != 0 ) V2 = sum2 / weight2;
		if ( w4 != 0 ) V4 = sum4 / weight4;
		if ( w6 != 0 ) V6 = sum6 / weight6;
		if ( w8 != 0 ) V8 = sum8 / weight8;

		double C2 = pow(V2, 2);
		double C4 = -pow(V4, 4);
		double C6 = 4*pow(V6, 6);
		double C8 = -33*pow(V8, 8);

		if ( V2 < 0 ) C2 = -C2;
		if ( V4 < 0 ) C4 = -C4;
		if ( V6 < 0 ) C6 = -C6;
		if ( V8 < 0 ) C8 = -C8;

		hC22CentS->SetBinContent(i+1, C2 );
		hC24CentS->SetBinContent(i+1, C4 );
		hC26CentS->SetBinContent(i+1, C6 );
		hC28CentS->SetBinContent(i+1, C8 );

		hC22CentW->SetBinContent(i+1, weight2);
		hC24CentW->SetBinContent(i+1, weight4);
		hC26CentW->SetBinContent(i+1, weight6);
		hC28CentW->SetBinContent(i+1, weight8);

		hNoffCent->SetBinContent(i+1, noff/nevt);
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

	hNoffCent->Write();
}
