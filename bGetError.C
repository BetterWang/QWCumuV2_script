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
//	int s1 = 10;
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

	TH1D * hC22trial[20];
	TH1D * hC24trial[20];
	TH1D * hC26trial[20];
	TH1D * hC28trial[20];
	for ( int c = 0; c < 20; c++ ) {
		hC22trial[c] = new TH1D(Form("hC22trial_%i", c), Form("hC22trial_%i", c), 100, 0., 100);
		hC24trial[c] = new TH1D(Form("hC24trial_%i", c), Form("hC24trial_%i", c), 100, 0., 100);
		hC26trial[c] = new TH1D(Form("hC26trial_%i", c), Form("hC26trial_%i", c), 100, 0., 100);
		hC28trial[c] = new TH1D(Form("hC28trial_%i", c), Form("hC28trial_%i", c), 100, 0., 100);

		for ( int i = 0; i <= s3; i++ ) {
			hC22trial[c]->SetBinContent(i+1, dC22[c][i]);
			hC24trial[c]->SetBinContent(i+1, dC24[c][i]);
			hC26trial[c]->SetBinContent(i+1, dC26[c][i]);
			hC28trial[c]->SetBinContent(i+1, dC28[c][i]);
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
		for ( int i = 0; i < s3; i++ ) { // !!!!
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

	double dR22[20][100];
	double dR24[20][100];
	double dR26[20][100];
	double dR28[20][100];

	double eR22[20];
	double eR24[20];
	double eR26[20];
	double eR28[20];

	for ( int c = 0; c < 20; c++ ) {
		double sum2 = 0;
		double sum4 = 0;
		double sum6 = 0;
		double sum8 = 0;
		for ( int i = 0; i <= s3; i++ ) {
			double C2 = dC22[c][i];
			double C4 = dC24[c][i];
			double C6 = dC26[c][i];
			double C8 = dC28[c][i];

			double V2, V4, V6, V8;
			if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
			if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
			if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
			if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

			dR22[c][i] = V2;
			dR24[c][i] = V4/V2;
			dR26[c][i] = V6/V4;
			dR28[c][i] = V8/V6;
			if ( i != s3 ) {
				sum2 += dR22[c][i] * dR22[c][i];
				sum4 += dR24[c][i] * dR24[c][i];
				sum6 += dR26[c][i] * dR26[c][i];
				sum8 += dR28[c][i] * dR28[c][i];
			}
		}

		eR22[c] = sqrt( ( sum2/s3 - dR22[c][s3] * dR22[c][s3] ) / s3 );
		eR24[c] = sqrt( ( sum4/s3 - dR24[c][s3] * dR24[c][s3] ) / s3 );
		eR26[c] = sqrt( ( sum6/s3 - dR26[c][s3] * dR26[c][s3] ) / s3 );
		eR28[c] = sqrt( ( sum8/s3 - dR28[c][s3] * dR28[c][s3] ) / s3 );
	}

	TH1D * hC22f = new TH1D("hC22f", "hC22f", 20, 0, 20);
	TH1D * hC24f = new TH1D("hC24f", "hC24f", 20, 0, 20);
	TH1D * hC26f = new TH1D("hC26f", "hC26f", 20, 0, 20);
	TH1D * hC28f = new TH1D("hC28f", "hC28f", 20, 0, 20);

	TH1D * hV22f = new TH1D("hV22f", "hV22f", 20, 0, 20);
	TH1D * hV24f = new TH1D("hV24f", "hV24f", 20, 0, 20);
	TH1D * hV26f = new TH1D("hV26f", "hV26f", 20, 0, 20);
	TH1D * hV28f = new TH1D("hV28f", "hV28f", 20, 0, 20);

	TH1D * hR22f = new TH1D("hR22f", "hR22f", 20, 0, 20);
	TH1D * hR24f = new TH1D("hR24f", "hR24f", 20, 0, 20);
	TH1D * hR26f = new TH1D("hR26f", "hR26f", 20, 0, 20);
	TH1D * hR28f = new TH1D("hR28f", "hR28f", 20, 0, 20);
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

		hR22f->SetBinContent(c+1, dR22[c][s3]);
		hR24f->SetBinContent(c+1, dR24[c][s3]);
		hR26f->SetBinContent(c+1, dR26[c][s3]);
		hR28f->SetBinContent(c+1, dR28[c][s3]);

		hR22f->SetBinError(c+1, eR22[c]);
		hR24f->SetBinError(c+1, eR24[c]);
		hR26f->SetBinError(c+1, eR26[c]);
		hR28f->SetBinError(c+1, eR28[c]);
	}

	TH1D * hNoffCent4 = (TH1D*) f[s3]->Get("hNoffCent4");
	TH1D * hNoffCent6 = (TH1D*) f[s3]->Get("hNoffCent6");
	TH1D * hNoffCent8 = (TH1D*) f[s3]->Get("hNoffCent8");

	TFile *fw = new TFile(Form("%s/Cerror_%i.root", ftxt[s1], s3), "recreate");

	hC22f->Write();
	hC24f->Write();
	hC26f->Write();
	hC28f->Write();

	hV22f->Write();
	hV24f->Write();
	hV26f->Write();
	hV28f->Write();

	hR22f->Write();
	hR24f->Write();
	hR26f->Write();
	hR28f->Write();

	hNoffCent4->Write();
	hNoffCent6->Write();
	hNoffCent8->Write();
	for ( int c = 0; c < 20; c++ ) {
		hC22trial[c]->Write();
		hC24trial[c]->Write();
		hC26trial[c]->Write();
		hC28trial[c]->Write();
	}
}
