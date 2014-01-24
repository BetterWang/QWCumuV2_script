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
#include "noff.h"
	int s1 = 10;
//	int s2 = 20;
//	int s3 = 20;

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
	} else if ( s1 == 28 ) {
		for ( int i = 0; i < 20; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[25], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[26], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[27], i));
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

	int Nevt4[20];
	int Nevt6[20];
	int Nevt8[20];
	for ( int i = 0; i < 20; i++ ) {
		Nevt4[i] = 0;
		Nevt6[i] = 0;
		Nevt8[i] = 0;
	}

	TH1::SetDefaultSumw2();

	TH1D* hMult4 = new TH1D("hMult4", "hMult4", 500, 0.5, 500.5);
	TH1D* hMult6 = new TH1D("hMult6", "hMult6", 500, 0.5, 500.5);
	TH1D* hMult8 = new TH1D("hMult8", "hMult8", 500, 0.5, 500.5);

	TH1D* hNoff4 = new TH1D("hNoff4", "hNoff4", 500, 0.5, 500.5);
	TH1D* hNoff6 = new TH1D("hNoff6", "hNoff6", 500, 0.5, 500.5);
	TH1D* hNoff8 = new TH1D("hNoff8", "hNoff8", 500, 0.5, 500.5);

	TH1D* hCent4 = new TH1D("hCent4", "hCent4", 20, 0, 20);
	TH1D* hCent6 = new TH1D("hCent6", "hCent6", 20, 0, 20);
	TH1D* hCent8 = new TH1D("hCent8", "hCent8", 20, 0, 20);

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
		hC26 [c] = new TH1D(Form("%s_%i", "hC26" , c), Form("%s_%i", "hC26", c),  1200, -0.0005, 0.0115);
		hC28 [c] = new TH1D(Form("%s_%i", "hC28" , c), Form("%s_%i", "hC28", c),  1200, -0.00115, 0.00005);
	
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
		ievt++;
		int c4 = int(Cent);
		int c6 = getNoff6(Noff);
		int c8 = getNoff8(Noff);
		Nevt4[c4]++;
		Nevt6[c6]++;
		Nevt8[c8]++;
		bool b4 = false;
		bool b6 = false;
		bool b8 = false;
		if ( s2 >= s3 ) {
			b4 = true;
			b6 = true;
			b8 = true;
		} else {
			if ( Nevt4[c4] % s3 == s2 ) b4 = true;
			if ( Nevt6[c6] % s3 == s2 ) b6 = true;
			if ( Nevt8[c8] % s3 == s2 ) b8 = true;
		}
		double Q2 = C22/wC22;
		double Q4 = C24/wC24;
		double Q6 = C26/wC26;
		double Q8 = C28/wC28;
		double C2 = Q2;
		double C4 = Q4 - Q2*Q2;
		double C6 = Q6 - 9*Q4*Q2 + 12*Q2*Q2*Q2;
		double C8 = Q8 - 16*Q6*Q2 - 18*Q4*Q4 + 144*Q4*Q2*Q2*Q2 - 144*Q2*Q2*Q2*Q2;

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

		if ( b4 ) hMult4->Fill(Mult);
		if ( b6 ) hMult6->Fill(Mult);
		if ( b8 ) hMult8->Fill(Mult);

		if ( b4 ) hNoff4->Fill(Noff);
		if ( b6 ) hNoff6->Fill(Noff);
		if ( b8 ) hNoff8->Fill(Noff);

		if ( b4 ) hCent4->Fill(c4);
		if ( b6 ) hCent6->Fill(c6);
		if ( b8 ) hCent8->Fill(c8);

		if ( b4 ) hQ22[c4]->Fill( Q2 );
		if ( b4 ) hQ24[c4]->Fill( Q4 );
		if ( b6 ) hQ26[c6]->Fill( Q6 );
		if ( b8 ) hQ28[c8]->Fill( Q8 );

		if ( b4 ) hQ22i[c4]->Fill( iC22/wC22 );
		if ( b4 ) hQ24i[c4]->Fill( iC24/wC24 );
		if ( b6 ) hQ26i[c6]->Fill( iC26/wC26 );
		if ( b8 ) hQ28i[c8]->Fill( iC28/wC28 );


		if ( b4 ) hC22[c4]->Fill( C2 );
		if ( b4 ) hC24[c4]->Fill( C4 );
		if ( b6 ) hC26[c6]->Fill( C6 );
		if ( b8 ) hC28[c8]->Fill( C8 );


		if ( b4 ) hV22[c4]->Fill( V2 );
		if ( b4 ) hV24[c4]->Fill( V4 );
		if ( b6 ) hV26[c6]->Fill( V6 );
		if ( b8 ) hV28[c8]->Fill( V8 );

		if ( b4 ) dQ22[c4] += C22;
		if ( b4 ) dQ24[c4] += C24;
		if ( b6 ) dQ26[c6] += C26;
		if ( b8 ) dQ28[c8] += C28;

		if ( b4 ) dW22[c4] += wC22;
		if ( b4 ) dW24[c4] += wC24;
		if ( b6 ) dW26[c6] += wC26;
		if ( b8 ) dW28[c8] += wC28;

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
	char *fwname;
	if ( s2 < s3 ) fwname = Form("%s/output_%i_%i.root", ftxt[s1], s2, s3);
	else fwname = Form("%s/output.root", ftxt[s1]);
	TFile *fw = new TFile(fwname, "recreate");
	{
		hMult4->Write();
		hMult6->Write();
		hMult8->Write();
		hNoff4->Write();
		hNoff6->Write();
		hNoff8->Write();
		hCent4->Write();
		hCent6->Write();
		hCent8->Write();

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
	fw->Close();
};
