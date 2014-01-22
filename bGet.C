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
	TH1D * hMult;
	TH1D * hCent;
	TH1D * hNoff;
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

	double dNoff[20];

	hMult = (TH1D*)f->Get("hMult");
	hCent = (TH1D*)f->Get("hCent");
	hNoff = (TH1D*)f->Get("hNoff");

	int Noff = 500;
	for ( int i = 0; i < nCentNoff-1; i++ ) {
		int NN = 0;
		double avgNoff = 0;
		while ( Noff >= CentNoffCut[i+1] ) {
			int nNN = hNoff->GetBinContent(Noff);
			avgNoff += Noff*nNN;
			NN += nNN;
			Noff--;

		}
		if (NN > 0) dNoff[i] = avgNoff/NN;
		else dNoff[i] = 0;
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
