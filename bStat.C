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

	int s1 = 28;
	int s3 = 20;

#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	TH1D::SetDefaultSumw2(false);

	TH1D * hC22[100][20];
	TH1D * hC24[100][20];
	TH1D * hC26[100][20];
	TH1D * hC28[100][20];
	TH1D * hC22Cent[100];
	TH1D * hC24Cent[100];
	TH1D * hC26Cent[100];
	TH1D * hC28Cent[100];

	TH1D * hV22Cent[100];
	TH1D * hV24Cent[100];
	TH1D * hV26Cent[100];
	TH1D * hV28Cent[100];


	TH1D * hMult;
	TH1D * hNoff;
	for ( int i = 0; i <= s3; i++ ) {
		TFile * f;
		if ( i != s3 ) {
			f = new TFile(Form("%s/output_%i_%i.root", ftxt[s1], i, s3));
		} else {
			f = new TFile(Form("%s/output.root", ftxt[s1]));
			hMult = (TH1D*)f->Get("hMult");
			hNoff = (TH1D*)f->Get("hNoff");
		}
		hC22Cent[i] = (TH1D*) f->Get("hC22Cent");
		hC24Cent[i] = (TH1D*) f->Get("hC24Cent");
		hC26Cent[i] = (TH1D*) f->Get("hC26Cent");
		hC28Cent[i] = (TH1D*) f->Get("hC28Cent");

		hV22Cent[i] = (TH1D*) f->Get("hV22Cent");
		hV24Cent[i] = (TH1D*) f->Get("hV24Cent");
		hV26Cent[i] = (TH1D*) f->Get("hV26Cent");
		hV28Cent[i] = (TH1D*) f->Get("hV28Cent");

		for ( int c = 0; c < 20; c++ ) {
			hC22[i][c] = (TH1D*) f->Get(Form("hC22_%i", c));
			hC24[i][c] = (TH1D*) f->Get(Form("hC22_%i", c));
			hC26[i][c] = (TH1D*) f->Get(Form("hC22_%i", c));
			hC28[i][c] = (TH1D*) f->Get(Form("hC22_%i", c));
		}
	//	f->Close();
	}

	TH1D * hC22Stat[20];
	TH1D * hC24Stat[20];
	TH1D * hC26Stat[20];
	TH1D * hC28Stat[20];

	TH1D * hC22StatM[20];
	TH1D * hC24StatM[20];
	TH1D * hC26StatM[20];
	TH1D * hC28StatM[20];

	TH1D * hC22StatE;
	TH1D * hC24StatE;
	TH1D * hC26StatE;
	TH1D * hC28StatE;

	TF1 * fC22M[20];
	TF1 * fC24M[20];
	TF1 * fC26M[20];
	TF1 * fC28M[20];

	for ( int c = 0; c < 20; c++ ) {
		hC22Stat[c] = new TH1D(Form("hC22Stat_%i", c), Form("hC22Stat_%i", c), 100, 0, 0.02);
		hC24Stat[c] = new TH1D(Form("hC24Stat_%i", c), Form("hC24Stat_%i", c), 100, -20e-6, 10e-6);
		hC26Stat[c] = new TH1D(Form("hC26Stat_%i", c), Form("hC26Stat_%i", c), 100, -0.1e-6, 0.3e-6);
		hC28Stat[c] = new TH1D(Form("hC28Stat_%i", c), Form("hC28Stat_%i", c), 100, -15e-9, 5e-9);

		hC22StatM[c] = new TH1D(Form("hC22StatM_%i", c), Form("hC22StatM_%i", c), 100, -0.01, 0.01);
		hC24StatM[c] = new TH1D(Form("hC24StatM_%i", c), Form("hC24StatM_%i", c), 100, -20e-6, 20e-6);
		hC26StatM[c] = new TH1D(Form("hC26StatM_%i", c), Form("hC26StatM_%i", c), 100, -1e-6, 1e-6);
		hC28StatM[c] = new TH1D(Form("hC28StatM_%i", c), Form("hC28StatM_%i", c), 100, -15e-9, 15e-9);

		fC22M[c] = new TF1(Form("fC22M_%i", c), "gaus", -0.01, 0.01);
		fC24M[c] = new TF1(Form("fC24M_%i", c), "gaus", -20e-6, 20e-6);
		fC26M[c] = new TF1(Form("fC26M_%i", c), "gaus", -1e-6, 1e-6);
		fC28M[c] = new TF1(Form("fC28M_%i", c), "gaus", -15e-9, 15e-9);
	}

	for ( int i = 0; i < s3; i++ ) {
		for ( int c = 0; c < 20; c++ ) {
			hC22Stat[c]->Fill(hC22Cent[i]->GetBinContent(c+1));
			hC24Stat[c]->Fill(hC24Cent[i]->GetBinContent(c+1));
			hC26Stat[c]->Fill(hC26Cent[i]->GetBinContent(c+1));
			hC28Stat[c]->Fill(hC28Cent[i]->GetBinContent(c+1));

			hC22StatM[c]->Fill(hC22Cent[i]->GetBinContent(c+1)-hC22Cent[s3]->GetBinContent(c+1));
			hC24StatM[c]->Fill(hC24Cent[i]->GetBinContent(c+1)-hC24Cent[s3]->GetBinContent(c+1));
			hC26StatM[c]->Fill(hC26Cent[i]->GetBinContent(c+1)-hC26Cent[s3]->GetBinContent(c+1));
			hC28StatM[c]->Fill(hC28Cent[i]->GetBinContent(c+1)-hC28Cent[s3]->GetBinContent(c+1));
		}
	}

	TH1D * hC22CentE = hC22Cent[s3]->Clone("hC22CentE");
	TH1D * hC24CentE = hC24Cent[s3]->Clone("hC24CentE");
	TH1D * hC26CentE = hC26Cent[s3]->Clone("hC26CentE");
	TH1D * hC28CentE = hC28Cent[s3]->Clone("hC28CentE");

	TH1D * hV22CentE = hV22Cent[s3]->Clone("hV22CentE");
	TH1D * hV24CentE = hV24Cent[s3]->Clone("hV24CentE");
	TH1D * hV26CentE = hV26Cent[s3]->Clone("hV26CentE");
	TH1D * hV28CentE = hV28Cent[s3]->Clone("hV28CentE");

	TH1D * hC22NSigma = hC22Cent[s3]->Clone("hC22NSigma");
	TH1D * hC24NSigma = hC24Cent[s3]->Clone("hC24NSigma");
	TH1D * hC26NSigma = hC26Cent[s3]->Clone("hC26NSigma");
	TH1D * hC28NSigma = hC28Cent[s3]->Clone("hC28NSigma");

	for ( int c = 0; c < 20; c++ ) {
		double sum2 = 0;
		double sum4 = 0;
		double sum6 = 0;
		double sum8 = 0;
		double error;
		for ( int i = 0; i < s3; i++ ) {
			sum2 += hC22Cent[i]->GetBinContent(c+1)*hC22Cent[i]->GetBinContent(c+1);
			sum4 += hC24Cent[i]->GetBinContent(c+1)*hC24Cent[i]->GetBinContent(c+1);
			sum6 += hC26Cent[i]->GetBinContent(c+1)*hC26Cent[i]->GetBinContent(c+1);
			sum8 += hC28Cent[i]->GetBinContent(c+1)*hC28Cent[i]->GetBinContent(c+1);
		}
		error = sqrt(sum2 - hC22Cent[s3]->GetBinContent(c+1)*hC22Cent[s3]->GetBinContent(c+1))/(s3);
		hC22CentE->SetBinError(c+1, error);
		hV22CentE->SetBinError(c+1, fabs(hV22CentE->GetBinContent(c+1)/hC22CentE->GetBinContent(c+1) * error / 2.));
		if ( error != 0 ) hC22NSigma->SetBinContent(c+1, hC22Cent[s3]->GetBinContent(c+1)/error);

		error = sqrt(sum4 - hC24Cent[s3]->GetBinContent(c+1)*hC24Cent[s3]->GetBinContent(c+1))/(s3);
		hC24CentE->SetBinError(c+1, error);
		hV24CentE->SetBinError(c+1, fabs(hV24CentE->GetBinContent(c+1)/hC24CentE->GetBinContent(c+1) * error / 4.));
		if ( error != 0 ) hC24NSigma->SetBinContent(c+1, hC24Cent[s3]->GetBinContent(c+1)/error);

		error = sqrt(sum6 - hC26Cent[s3]->GetBinContent(c+1)*hC26Cent[s3]->GetBinContent(c+1))/(s3);
		hC26CentE->SetBinError(c+1, error);
		hV26CentE->SetBinError(c+1, fabs(hV26CentE->GetBinContent(c+1)/hC26CentE->GetBinContent(c+1) * error / 6.));
		if ( error != 0 ) hC26NSigma->SetBinContent(c+1, hC26Cent[s3]->GetBinContent(c+1)/error);

		error = sqrt(sum8 - hC28Cent[s3]->GetBinContent(c+1)*hC28Cent[s3]->GetBinContent(c+1))/(s3);
		hC28CentE->SetBinError(c+1, error);
		hV28CentE->SetBinError(c+1, fabs(hV28CentE->GetBinContent(c+1)/hC28CentE->GetBinContent(c+1) * error / 8.));
		if ( error != 0 ) hC28NSigma->SetBinContent(c+1, hC28Cent[s3]->GetBinContent(c+1)/error);

	}


	TFile * fwrite = new TFile(Form("%s/fit.root", ftxt[s1]), "recreate");
	hMult->Write();
	hNoff->Write();

	hC22CentE->Write();
	hC24CentE->Write();
	hC26CentE->Write();
	hC28CentE->Write();

	hV22CentE->Write();
	hV24CentE->Write();
	hV26CentE->Write();
	hV28CentE->Write();

	hC22NSigma->Write();
	hC24NSigma->Write();
	hC26NSigma->Write();
	hC28NSigma->Write();
	for ( int c = 0; c < 20; c++ ) {
		hC22Stat[c]->Write();
		hC24Stat[c]->Write();
		hC26Stat[c]->Write();
		hC28Stat[c]->Write();

		hC22StatM[c]->Write();
		hC24StatM[c]->Write();
		hC26StatM[c]->Write();
		hC28StatM[c]->Write();
	}
}
