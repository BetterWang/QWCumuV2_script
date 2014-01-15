/*
 * =====================================================================================
 *
 *       Filename:  process.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/10/14 07:39:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
#include "../interface/QWConstV2.h"
#include "label.h"
	int s1 = 13;

	TChain * ch = new TChain();
	if ( s1 == 10 ) {
		for ( int i = 0; i < 20; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[1], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[2], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[3], i));
		}
	} else if ( s1 == 11 ) {
		for ( int i = 0; i < 20; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[4], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[5], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[6], i));
		}
	} else if ( s1 == 12 ) {
		for ( int i = 0; i < 20; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[7], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[8], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[9], i));
		}
	} else if ( s1 == 22 ) {
		for ( int i = 0; i < 20; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[13], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[14], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[15], i));
		}
	} else
	for ( int i = 0; i < 20; i++ ) {
		ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[s1], i));
	}
//	ch->Add("../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1/000/cumu_100.root/cumulant/ntResult");
	double Noff,Mult,Cent,C22,C24,C26,C28,iC22,iC24,iC26,iC28,wC22,wC24,wC26,wC28,C32,C34,C36,C38,iC32,iC34,iC36,iC38,wC32,wC34,wC36,wC38;
	ch->SetBranchAddress("Noff", &Noff);
	ch->SetBranchAddress("Mult", &Mult);
	ch->SetBranchAddress("Cent", &Cent);
	ch->SetBranchAddress("C22",  &C22);
	ch->SetBranchAddress("C24",  &C24);
	ch->SetBranchAddress("C26",  &C26);
	ch->SetBranchAddress("C28",  &C28);
	ch->SetBranchAddress("iC22", &iC22);
	ch->SetBranchAddress("iC24", &iC24);
	ch->SetBranchAddress("iC26", &iC26);
	ch->SetBranchAddress("iC28", &iC28);
	ch->SetBranchAddress("wC22", &wC22);
	ch->SetBranchAddress("wC24", &wC24);
	ch->SetBranchAddress("wC26", &wC26);
	ch->SetBranchAddress("wC28", &wC28);
	ch->SetBranchAddress("C32",  &C32);
	ch->SetBranchAddress("C34",  &C34);
	ch->SetBranchAddress("C36",  &C36);
	ch->SetBranchAddress("C38",  &C38);
	ch->SetBranchAddress("iC32", &iC32);
	ch->SetBranchAddress("iC34", &iC34);
	ch->SetBranchAddress("iC36", &iC36);
	ch->SetBranchAddress("iC38", &iC38);
	ch->SetBranchAddress("wC32", &wC32);
	ch->SetBranchAddress("wC34", &wC34);
	ch->SetBranchAddress("wC36", &wC36);
	ch->SetBranchAddress("wC38", &wC38);

	TH1::SetDefaultSumw2();

	TH1D* hMult = new TH1D("hMult", "hMult", 400, 0, 400);
	TH1D* hNoff = new TH1D("hNoff", "hNoff", 400, 0, 400);
	TH1D* hCent = new TH1D("hCent", "hCent", 20, 0, 20);

	TH1D* hQ22 [20] ;
	TH1D* hQ22i[20] ;
	TH1D* hQ24 [20] ;
	TH1D* hQ24i[20] ;
	TH1D* hQ26 [20] ;
	TH1D* hQ26i[20] ;
	TH1D* hQ28 [20] ;
	TH1D* hQ28i[20] ;
	TH1D* hC22 [20] ;
	TH1D* hC24 [20] ;
	TH1D* hC26 [20] ;
	TH1D* hC28 [20] ;
	TH1D* hV22 [20] ;
	TH1D* hV24 [20] ;
	TH1D* hV26 [20] ;
	TH1D* hV28 [20] ;

	TH1D* hC22Cent = new TH1D("hC22Cent", "hC22Cent", 20, 0, 20);
	TH1D* hC24Cent = new TH1D("hC24Cent", "hC24Cent", 20, 0, 20);
	TH1D* hC26Cent = new TH1D("hC26Cent", "hC26Cent", 20, 0, 20);
	TH1D* hC28Cent = new TH1D("hC28Cent", "hC28Cent", 20, 0, 20);

	TH1D* hV22Cent = new TH1D("hV22Cent", "hV22Cent", 20, 0, 20);
	TH1D* hV24Cent = new TH1D("hV24Cent", "hV24Cent", 20, 0, 20);
	TH1D* hV26Cent = new TH1D("hV26Cent", "hV26Cent", 20, 0, 20);
	TH1D* hV28Cent = new TH1D("hV28Cent", "hV28Cent", 20, 0, 20);

	double dQ22[20];
	double dQ24[20];
	double dQ26[20];
	double dQ28[20];

	double dW22[20];
	double dW24[20];
	double dW26[20];
	double dW28[20];

	for ( int c = 0; c < 20; c++ ) {
		hQ22 [c] = new TH1D(Form("%s_%i", "hQ22" , c), Form("%s_%i", "hQ22", c),  400, -0.2, 0.2);
		hQ22i[c] = new TH1D(Form("%s_%i", "hQ22i", c), Form("%s_%i","hQ22i", c), 400, -0.2, 0.2);
		hQ24 [c] = new TH1D(Form("%s_%i", "hQ24" , c), Form("%s_%i", "hQ24", c),  400, -0.02, 0.02);
		hQ24i[c] = new TH1D(Form("%s_%i", "hQ24i", c), Form("%s_%i","hQ24i", c), 400, -0.02, 0.02);
		hQ26 [c] = new TH1D(Form("%s_%i", "hQ26" , c), Form("%s_%i", "hQ26", c),  400, -0.002, 0.002);
		hQ26i[c] = new TH1D(Form("%s_%i", "hQ26i", c), Form("%s_%i","hQ26i", c), 400, -0.002, 0.002);
		hQ28 [c] = new TH1D(Form("%s_%i", "hQ28" , c), Form("%s_%i", "hQ28", c),  400, -0.0002, 0.0002);
		hQ28i[c] = new TH1D(Form("%s_%i", "hQ28i", c), Form("%s_%i","hQ28i", c), 400, -0.0002, 0.0002);
	
		hC22 [c] = new TH1D(Form("%s_%i", "hC22" , c), Form("%s_%i", "hC22", c),  400, -0.2, 0.2);
		hC24 [c] = new TH1D(Form("%s_%i", "hC24" , c), Form("%s_%i", "hC24", c),  400, -0.02, 0.02);
		hC26 [c] = new TH1D(Form("%s_%i", "hC26" , c), Form("%s_%i", "hC26", c),  400, -0.002, 0.002);
		hC28 [c] = new TH1D(Form("%s_%i", "hC28" , c), Form("%s_%i", "hC28", c),  400, -0.0002, 0.0002);
	
		hV22 [c] = new TH1D(Form("%s_%i", "hV22" , c), Form("%s_%i", "hV22", c),  400, -0.2, 0.2);
		hV24 [c] = new TH1D(Form("%s_%i", "hV24" , c), Form("%s_%i", "hV24", c),  400, -0.2, 0.2);
		hV26 [c] = new TH1D(Form("%s_%i", "hV26" , c), Form("%s_%i", "hV26", c),  400, -0.2, 0.2);
		hV28 [c] = new TH1D(Form("%s_%i", "hV28" , c), Form("%s_%i", "hV28", c),  400, -0.2, 0.2);

		dQ22[c] = 0;
		dQ24[c] = 0;
		dQ26[c] = 0;
		dQ28[c] = 0;

		dW22[c] = 0;
		dW24[c] = 0;
		dW26[c] = 0;
		dW28[c] = 0;
	}


	int ievt = 0;
	while ( ch->GetEntry(ievt) )
	{
		if ( !(ievt%100000) ) cout << "!! ievt = " << ievt << endl;
		hMult->Fill(Mult);
		hNoff->Fill(Noff);
		hCent->Fill(Cent);
		double Q2 = C22/wC22;
		double Q4 = C24/wC24;
		double Q6 = C26/wC26;
		double Q8 = C28/wC28;

		int c = int(Cent);

		hQ22[c]->Fill( Q2 );
		hQ24[c]->Fill( Q4 );
		hQ26[c]->Fill( Q6 );
		hQ28[c]->Fill( Q8 );

		hQ22i[c]->Fill( iC22/wC22 );
		hQ24i[c]->Fill( iC24/wC24 );
		hQ26i[c]->Fill( iC26/wC26 );
		hQ28i[c]->Fill( iC28/wC28 );

		double C2 = Q2;
		double C4 = Q4 - Q2*Q2;
		double C6 = Q6 - 9*Q4*Q2 + 12*Q2*Q2*Q2;
		double C8 = Q8 - 16*Q6*Q2 - 18*Q4*Q4 + 144*Q4*Q2*Q2*Q2 - 144*Q2*Q2*Q2*Q2;

		hC22[c]->Fill( C2 );
		hC24[c]->Fill( C4 );
		hC26[c]->Fill( C6 );
		hC28[c]->Fill( C8 );

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

		hV22[c]->Fill( V2 );
		hV24[c]->Fill( V4 );
		hV26[c]->Fill( V6 );
		hV28[c]->Fill( V8 );

		dQ22[c] += C22;
		dQ24[c] += C24;
		dQ26[c] += C26;
		dQ28[c] += C28;

		dW22[c] += wC22;
		dW24[c] += wC24;
		dW26[c] += wC26;
		dW28[c] += wC28;

		ievt++;
	}
	for ( int c = 0; c < 20; c++ ) {
		if ( dW22[c] == 0. ) dQ22[c] = 0.; else dQ22[c] /= dW22[c];
		if ( dW24[c] == 0. ) dQ24[c] = 0.; else dQ24[c] /= dW24[c];
		if ( dW26[c] == 0. ) dQ26[c] = 0.; else dQ26[c] /= dW26[c];
		if ( dW28[c] == 0. ) dQ28[c] = 0.; else dQ28[c] /= dW28[c];

		double C2 = dQ22[c];
		double C4 = dQ24[c] - 2*dQ22[c]*dQ22[c];
		double C6 = dQ26[c] - 9*dQ24[c]*dQ22[c] + 12*dQ22[c]*dQ22[c]*dQ22[c];
		double C8 = dQ28[c] - 16*dQ26[c]*dQ22[c] - 18*dQ24[c]*dQ24[c] + 144*dQ24[c]*dQ22[c]*dQ22[c] - 144*dQ22[c]*dQ22[c]*dQ22[c]*dQ22[c];

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

		cout << " c = " << c << "\tdQ22 = " << dQ22[c] << "\tdQ24 = " << dQ24[c] << "\tdQ26 = " << dQ26[c] << "\tdQ28 = " << dQ28[c] << endl;
		cout << " c = " << c << "\tdC22 = " << C2 << "\tdC24 = " << C4 << "\tdQ26 = " << C6 << "\tdQ28 = " << C8 << endl;
		cout << " c = " << c << "\tdV22 = " << V2 << "\tdV24 = " << V4 << "\tdV26 = " << V6 << "\tdV28 = " << V8 << endl;
		hC22Cent->SetBinContent(c+1, C2);
		hC24Cent->SetBinContent(c+1, C4);
		hC26Cent->SetBinContent(c+1, C6);
		hC28Cent->SetBinContent(c+1, C8);

		hV22Cent->SetBinContent(c+1, V2);
		hV24Cent->SetBinContent(c+1, V4);
		hV26Cent->SetBinContent(c+1, V6);
		hV28Cent->SetBinContent(c+1, V8);
	}
	TFile *fw = new TFile(Form("%s/output.root", ftxt[s1]), "recreate");
	{
		hMult->Write();
		hNoff->Write();
		hCent->Write();

		hC22Cent->Write();
		hC24Cent->Write();
		hC26Cent->Write();
		hC28Cent->Write();

		hV22Cent->Write();
		hV24Cent->Write();
		hV26Cent->Write();
		hV28Cent->Write();

		for ( int c = 0; c < 20; c++ ) {

			hC22[c]->Write();
			hC24[c]->Write();
			hC26[c]->Write();
			hC28[c]->Write();
	
			hV22[c]->Write();
			hV24[c]->Write();
			hV26[c]->Write();
			hV28[c]->Write();
	
			hQ22[c]->Write();
			hQ24[c]->Write();
			hQ26[c]->Write();
			hQ28[c]->Write();
	
			hQ22i[c]->Write();
			hQ24i[c]->Write();
			hQ26i[c]->Write();
			hQ28i[c]->Write();
		}
	}
};
