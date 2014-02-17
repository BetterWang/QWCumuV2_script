/*
 * =====================================================================================
 *
 *       Filename:  bGetError.C
 *
 *    Description:  get error bar
 *
 *        Version:  1.0
 *        Created:  02/05/2014 18:33:13
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
	int s1 = 36;
	int s3 = 20;

	TFile * f[100];

	TH1D * hC22CentS[100];
	TH1D * hC24CentS[100];
	TH1D * hC26CentS[100];
	TH1D * hC28CentS[100];

	TH1D * hC22CentW[100];
	TH1D * hC24CentW[100];
	TH1D * hC26CentW[100];
	TH1D * hC28CentW[100];

	TProfile* hMultCent[100];

	for ( int i = 0; i <= s3; i++ ) {
		if ( i == s3 ) f[i] = new TFile(Form("%s/fit_mult.root", ftxt[s1]));
		else f[i] = new TFile(Form("%s/fit_mult_%i_%i.root", ftxt[s1], i, s3));

		hC22CentS[i] = (TH1D*) f[i]->Get("hC22CentS");
		hC24CentS[i] = (TH1D*) f[i]->Get("hC24CentS");
		hC26CentS[i] = (TH1D*) f[i]->Get("hC26CentS");
		hC28CentS[i] = (TH1D*) f[i]->Get("hC28CentS");

		hC22CentW[i] = (TH1D*) f[i]->Get("hC22CentW");
		hC24CentW[i] = (TH1D*) f[i]->Get("hC24CentW");
		hC26CentW[i] = (TH1D*) f[i]->Get("hC26CentW");
		hC28CentW[i] = (TH1D*) f[i]->Get("hC28CentW");

		hMultCent[i] = (TProfile*) f[i]->Get("hMultCent");
	}

	double dC22[20][100];
	double dC24[20][100];
	double dC26[20][100];
	double dC28[20][100];
	for ( int c = 0; c < 20; c++ ) {
		for ( int i = 0; i <= s3; i++ ) {
			dC22[c][i] = hC22CentS[i]->GetBinContent(c+1) ;
			dC24[c][i] = hC24CentS[i]->GetBinContent(c+1) ;
			dC26[c][i] = hC26CentS[i]->GetBinContent(c+1) ;
			dC28[c][i] = hC28CentS[i]->GetBinContent(c+1) ;
		}
	}

	double eC22[20];
	double eC24[20];
	double eC26[20];
	double eC28[20];

	double dV22[20];
	double dV24[20];
	double dV26[20];
	double dV28[20];

	double eV22[20];
	double eV24[20];
	double eV26[20];
	double eV28[20];
	for ( int c = 0; c < 20; c++ ) {
		double sum2 = 0;
		double sum4 = 0;
		double sum6 = 0;
		double sum8 = 0;
		for ( int i = 0; i <= s3; i++ ) {
			sum2 += dC22[c][i] * dC22[c][i];
			sum4 += dC24[c][i] * dC24[c][i];
			sum6 += dC26[c][i] * dC26[c][i];
			sum8 += dC28[c][i] * dC28[c][i];
		}
		eC22[c] = sqrt((sum2/s3 - dC22[c][s3] * dC22[c][s3])/s3);
		eC24[c] = sqrt((sum4/s3 - dC24[c][s3] * dC24[c][s3])/s3);
		eC26[c] = sqrt((sum6/s3 - dC26[c][s3] * dC26[c][s3])/s3);
		eC28[c] = sqrt((sum8/s3 - dC28[c][s3] * dC28[c][s3])/s3);

		double C2 = dC22[c][s3];
		double C4 = dC24[c][s3];
		double C6 = dC26[c][s3];
		double C8 = dC28[c][s3];

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

		dV22[c] = V2;
		dV24[c] = V4;
		dV26[c] = V6;
		dV28[c] = V8;

		eV22[c] = fabs( V2 / dC22[c] * eC22[c] / 2.);
		eV24[c] = fabs( V4 / dC24[c] * eC24[c] / 4.);
		eV26[c] = fabs( V6 / dC26[c] * eC26[c] / 6.);
		eV28[c] = fabs( V8 / dC28[c] * eC28[c] / 8.);
	}
//	double rC22[20];
//	double rC24[20];
//	double rC26[20];
//	double rC28[20];
//	for ( int c = 0; c < 20; c++ ) {
//		if ( eC22[c] != 0. ) rC22[c] = dC22[c] / eC22[c]; else rC22[c] = 0.;
//		if ( eC24[c] != 0. ) rC24[c] = dC24[c] / eC24[c]; else rC24[c] = 0.;
//		if ( eC26[c] != 0. ) rC26[c] = dC26[c] / eC26[c]; else rC26[c] = 0.;
//		if ( eC28[c] != 0. ) rC28[c] = dC28[c] / eC28[c]; else rC28[c] = 0.;
//	}

	TH1D * hC22f = new TH1D("hC22f", "hC22f", 20, 0, 20);
	TH1D * hC24f = new TH1D("hC24f", "hC24f", 20, 0, 20);
	TH1D * hC26f = new TH1D("hC26f", "hC26f", 20, 0, 20);
	TH1D * hC28f = new TH1D("hC28f", "hC28f", 20, 0, 20);

	TH1D * hV22f = new TH1D("hV22f", "hV22f", 20, 0, 20);
	TH1D * hV24f = new TH1D("hV24f", "hV24f", 20, 0, 20);
	TH1D * hV26f = new TH1D("hV26f", "hV26f", 20, 0, 20);
	TH1D * hV28f = new TH1D("hV28f", "hV28f", 20, 0, 20);
	for ( int c = 0; c < 20; c++ ) {
		hC22f->SetBinContent(c+1, dC22[c][s3]);
		hC24f->SetBinContent(c+1, dC24[c][s3]);
		hC26f->SetBinContent(c+1, dC26[c][s3]);
		hC28f->SetBinContent(c+1, dC28[c][s3]);

		hC22f->SetBinError(c+1, eC22[c]);
		hC24f->SetBinError(c+1, eC24[c]);
		hC26f->SetBinError(c+1, eC26[c]);
		hC28f->SetBinError(c+1, eC28[c]);

		hV22f->SetBinContent(c+1, dV22[c]);
		hV24f->SetBinContent(c+1, dV24[c]);
		hV26f->SetBinContent(c+1, dV26[c]);
		hV28f->SetBinContent(c+1, dV28[c]);

		hV22f->SetBinError(c+1, eV22[c]);
		hV24f->SetBinError(c+1, eV24[c]);
		hV26f->SetBinError(c+1, eV26[c]);
		hV28f->SetBinError(c+1, eV28[c]);
	}

	TH1D * hNoffCent = (TH1D*) f[s3]->Get("hNoffCent");

	TFile *fw = new TFile(Form("%s/Cerror_%i.root", ftxt[s1], s3), "recreate");

	hC22f->Write();
	hC24f->Write();
	hC26f->Write();
	hC28f->Write();

	hV22f->Write();
	hV24f->Write();
	hV26f->Write();
	hV28f->Write();

	hNoffCent->Write();
}
