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

	int s1 = 33;
	int s2 = 20;
	int s3 = 20;

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

	TProfile* hMultCent = (TProfile*) f->Get("hMultCent");

	//	f->Close();

	double dC22[500];
	double dC24[500];
	double dC26[500];
	double dC28[500];
	double dW22[500];
	double dW24[500];
	double dW26[500];
	double dW28[500];
	double dMult[500];
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
		dW22[c] = hW22Cent->GetBinContent(c);
		dW24[c] = hW24Cent->GetBinContent(c);
		dW26[c] = hW26Cent->GetBinContent(c);
		dW28[c] = hW28Cent->GetBinContent(c);
		dMult[c] = hMultCent->GetBinContent(c);
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
			double w2 = dMult[n]*(dMult[n]-1);
			double w4 = dMult[n]*(dMult[n]-1)*(dMult[n]-2)*(dMult[n]-3);
			double w6 = dMult[n]*(dMult[n]-1)*(dMult[n]-2)*(dMult[n]-3)*(dMult[n]-4)*(dMult[n]-5);
			double w8 = dMult[n]*(dMult[n]-1)*(dMult[n]-2)*(dMult[n]-3)*(dMult[n]-4)*(dMult[n]-5)*(dMult[n]-6)*(dMult[n]-7);
			sum2 += dC22[n]*w2;
			sum4 += dC24[n]*w4;
			sum6 += dC26[n]*w6;
			sum8 += dC28[n]*w8;
			weight2 += w2;
			weight4 += w4;
			weight6 += w6;
			weight8 += w8;

			noff += hNoff->GetBinContent(n)*n;
			nevt += hNoff->GetBinContent(n);
		}
		hC22CentS->SetBinContent(i+1, sum2);
		hC24CentS->SetBinContent(i+1, sum4);
		hC26CentS->SetBinContent(i+1, sum6);
		hC28CentS->SetBinContent(i+1, sum8);

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
