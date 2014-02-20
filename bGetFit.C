/*
 * =====================================================================================
 *
 *       Filename:  bGetpA.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/06/2014 18:10:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
	TFile * fHM = new TFile(Form("%s/Cerror_%i.root", ftxt[s1], s3));
	TFile * fMB = new TFile(Form("%s/Cerror_%i.root", ftxt[s2], s3));

	TH1D * hNoffCentHM4 = (TH1D*) fHM->Get("hNoffCent4");
	TH1D * hNoffCentHM6 = (TH1D*) fHM->Get("hNoffCent6");
	TH1D * hNoffCentHM8 = (TH1D*) fHM->Get("hNoffCent8");
	TH1D * hNoffCentMB4 = (TH1D*) fMB->Get("hNoffCent4");
	TH1D * hNoffCentMB6 = (TH1D*) fMB->Get("hNoffCent6");
	TH1D * hNoffCentMB8 = (TH1D*) fMB->Get("hNoffCent8");

	double dNoff4[20];
	double dNoff6[20];
	double dNoff8[20];
	int nCent4 = 0;
	int nCent6 = 0;
	int nCent8 = 0;

	while ( hNoffCentHM4->GetBinContent(nCent4+1) > 120 ) {
		dNoff4[nCent4] = hNoffCentHM4->GetBinContent(nCent4+1);
		nCent4++;
	}
	while ( hNoffCentHM6->GetBinContent(nCent6+1) > 120 ) {
		dNoff6[nCent6] = hNoffCentHM6->GetBinContent(nCent6+1);
		nCent6++;
	}
	while ( hNoffCentHM8->GetBinContent(nCent8+1) > 120 ) {
		dNoff8[nCent8] = hNoffCentHM8->GetBinContent(nCent8+1);
		nCent8++;
	}

	for ( int c = nCent4; c < 17; c++ ) {
		dNoff4[c] = hNoffCentMB4->GetBinContent(c+1);
	}
	for ( int c = nCent6; c < 17; c++ ) {
		dNoff6[c] = hNoffCentMB6->GetBinContent(c+1);
	}
	for ( int c = nCent8; c < 17; c++ ) {
		dNoff8[c] = hNoffCentMB8->GetBinContent(c+1);
	}


	double dC22[20];
	double dC24[20];
	double dC26[20];
	double dC28[20];

	double dV22[20];
	double dV24[20];
	double dV26[20];
	double dV28[20];

	double eC22[20];
	double eC24[20];
	double eC26[20];
	double eC28[20];

	double eV22[20];
	double eV24[20];
	double eV26[20];
	double eV28[20];

	for ( int c = 0; c < 20; c++ ) {
		dC22[c] = 0;
		dC24[c] = 0;
		dC26[c] = 0;
		dC28[c] = 0;

		eC22[c] = 0;
		eC24[c] = 0;
		eC26[c] = 0;
		eC28[c] = 0;

		dV22[c] = 0;
		dV24[c] = 0;
		dV26[c] = 0;
		dV28[c] = 0;

		eV22[c] = 0;
		eV24[c] = 0;
		eV26[c] = 0;
		eV28[c] = 0;
	}
	TH1D * hC22fHM = (TH1D*) fHM->Get("hC22f");
	TH1D * hC24fHM = (TH1D*) fHM->Get("hC24f");
	TH1D * hC26fHM = (TH1D*) fHM->Get("hC26f");
	TH1D * hC28fHM = (TH1D*) fHM->Get("hC28f");

	TH1D * hC22fMB = (TH1D*) fMB->Get("hC22f");
	TH1D * hC24fMB = (TH1D*) fMB->Get("hC24f");
	TH1D * hC26fMB = (TH1D*) fMB->Get("hC26f");
	TH1D * hC28fMB = (TH1D*) fMB->Get("hC28f");

	for ( int c = 0; c < nCent4; c++ ) {
		dC22[c] = hC22fHM->GetBinContent(c+1);
		dC24[c] = hC24fHM->GetBinContent(c+1);

		eC22[c] = hC22fHM->GetBinError(c+1);
		eC24[c] = hC24fHM->GetBinError(c+1);
	}
	for ( int c = 0; c < nCent6; c++ ) {
		dC26[c] = hC26fHM->GetBinContent(c+1);
		eC26[c] = hC26fHM->GetBinError(c+1);
	}
	for ( int c = 0; c < nCent8; c++ ) {
		dC28[c] = hC28fHM->GetBinContent(c+1);
		eC28[c] = hC28fHM->GetBinError(c+1);
	}
	for ( int c = nCent4; c < 17; c++ ) {
		dC22[c] = hC22fMB->GetBinContent(c+1);
		dC24[c] = hC24fMB->GetBinContent(c+1);

		eC22[c] = hC22fMB->GetBinError(c+1);
		eC24[c] = hC24fMB->GetBinError(c+1);
	}
	for ( int c = nCent6; c < 17; c++ ) {
		dC26[c] = hC26fMB->GetBinContent(c+1);
		eC26[c] = hC26fMB->GetBinError(c+1);
	}
	for ( int c = nCent8; c < 17; c++ ) {
		dC28[c] = hC28fMB->GetBinContent(c+1);
		eC28[c] = hC28fMB->GetBinError(c+1);
	}
	double dNSigma2[20];
	double dNSigma4[20];
	double dNSigma6[20];
	double dNSigma8[20];
	for ( int c = 0; c < 20; c++ ) {
		if ( eC22[c] != 0. ) dNSigma2[c] = dC22[c] / eC22[c]; else dNSigma2[c] = 0;
		if ( eC24[c] != 0. ) dNSigma4[c] = dC24[c] / eC24[c]; else dNSigma4[c] = 0;
		if ( eC26[c] != 0. ) dNSigma6[c] = dC26[c] / eC26[c]; else dNSigma6[c] = 0;
		if ( eC28[c] != 0. ) dNSigma8[c] = dC28[c] / eC28[c]; else dNSigma8[c] = 0;
	}


	///////////// Rebin ////////////////////
	
	//////////////// V ////////////////////
	
	for ( int c = 0; c < 20; c++ ) {
		double C2 = dC22[c];
		double C4 = dC24[c];
		double C6 = dC26[c];
		double C8 = dC28[c];

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
}
