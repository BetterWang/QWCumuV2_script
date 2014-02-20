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
	int s1 = 43;
//	int s2 = 20;
//	int s3 = 20;

	TChain * ch = new TChain();
	if ( s1 == 10 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[1], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[2], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[3], i));
		}
	} else if ( s1 == 11 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[4], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[5], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[6], i));
		}
	} else if ( s1 == 12 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[7], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[8], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[9], i));
		}
	} else if ( s1 == 22 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[13], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[14], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[15], i));
		}
	} else if ( s1 == 28 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[25], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[26], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[27], i));
		}
	} else if ( s1 == 32 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[29], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[30], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[31], i));
		}
	} else if ( s1 == 39 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[39], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[36], i));
		}
	} else if ( s1 == 43 ) {
		for ( int i = 0; i < 80; i++ ) {
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[40], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[41], i));
			ch->Add(Form("%s/%03i/*.root/cumulant/ntResult",fname[42], i));
		}
	} else

	for ( int i = 0; i < 80; i++ ) {
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

	int Nevt[500];
	for ( int i = 0; i < 500; i++ ) Nevt[i] = 0;

	TH1::SetDefaultSumw2();

	TH1D* hMult = new TH1D("hMult", "hMult", 500, 0.5, 500.5);
	TH1D* hNoff = new TH1D("hNoff", "hNoff", 500, 0.5, 500.5);
	TH1D* hCent = new TH1D("hCent", "hCent", 500, 0.5, 500.5);

	TH1D* hC22Cent = new TH1D("hC22Cent", "hC22Cent", 500, 0.5, 500.5);
	TH1D* hC24Cent = new TH1D("hC24Cent", "hC24Cent", 500, 0.5, 500.5);
	TH1D* hC26Cent = new TH1D("hC26Cent", "hC26Cent", 500, 0.5, 500.5);
	TH1D* hC28Cent = new TH1D("hC28Cent", "hC28Cent", 500, 0.5, 500.5);

	TH1D* hV22Cent = new TH1D("hV22Cent", "hV22Cent", 500, 0.5, 500.5);
	TH1D* hV24Cent = new TH1D("hV24Cent", "hV24Cent", 500, 0.5, 500.5);
	TH1D* hV26Cent = new TH1D("hV26Cent", "hV26Cent", 500, 0.5, 500.5);
	TH1D* hV28Cent = new TH1D("hV28Cent", "hV28Cent", 500, 0.5, 500.5);

	TH1D* hW22Cent = new TH1D("hW22Cent", "hW22Cent", 500, 0.5, 500.5);
	TH1D* hW24Cent = new TH1D("hW24Cent", "hW24Cent", 500, 0.5, 500.5);
	TH1D* hW26Cent = new TH1D("hW26Cent", "hW26Cent", 500, 0.5, 500.5);
	TH1D* hW28Cent = new TH1D("hW28Cent", "hW28Cent", 500, 0.5, 500.5);

	TH1D* hQ22Cent = new TH1D("hQ22Cent", "hQ22Cent", 500, 0.5, 500.5);
	TH1D* hQ24Cent = new TH1D("hQ24Cent", "hQ24Cent", 500, 0.5, 500.5);
	TH1D* hQ26Cent = new TH1D("hQ26Cent", "hQ26Cent", 500, 0.5, 500.5);
	TH1D* hQ28Cent = new TH1D("hQ28Cent", "hQ28Cent", 500, 0.5, 500.5);

	TProfile* hMultCent = new TProfile("hMultCent", "hMultCent", 500, 0.5, 500.5);
	TH1D* hWeightCent2 = new TProfile("hWeightCent2", "hWeightCent2", 500, 0.5, 500.5);
	TH1D* hWeightCent4 = new TProfile("hWeightCent4", "hWeightCent4", 500, 0.5, 500.5);
	TH1D* hWeightCent6 = new TProfile("hWeightCent6", "hWeightCent6", 500, 0.5, 500.5);
	TH1D* hWeightCent8 = new TProfile("hWeightCent8", "hWeightCent8", 500, 0.5, 500.5);
	double dQ22[500];
	double dQ24[500];
	double dQ26[500];
	double dQ28[500];

	double dW22[500];
	double dW24[500];
	double dW26[500];
	double dW28[500];

	for ( int c = 0; c < 500; c++ ) {

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
		if (TMath::IsNaN(C22) || TMath::IsNaN(C24) || TMath::IsNaN(C24) || TMath::IsNaN(C24)) {
			cout << "=> ievt = " << ievt << endl;
			continue;
		}
		int c = Noff;
		if ( c >= 500 || c<=0 ) continue;
		Nevt[c]++;
		if ( s2 < s3 && Nevt[c] % s3 != s2 ) continue;
		hMult->Fill(Mult);
		hNoff->Fill(Noff);
		hCent->Fill(Cent);
		hMultCent->Fill(c, Mult);
		hWeightCent2->Fill(c, Mult*(Mult-1));
		hWeightCent4->Fill(c, Mult*(Mult-1)*(Mult-2)*(Mult-3));
		hWeightCent6->Fill(c, Mult*(Mult-1)*(Mult-2)*(Mult-3)*(Mult-4)*(Mult-5));
		hWeightCent8->Fill(c, Mult*(Mult-1)*(Mult-2)*(Mult-3)*(Mult-4)*(Mult-5)*(Mult-6)*(Mult-7));

		dQ22[c] += C22;
		dQ24[c] += C24;
		dQ26[c] += C26;
		dQ28[c] += C28;

		dW22[c] += wC22;
		dW24[c] += wC24;
		dW26[c] += wC26;
		dW28[c] += wC28;

	}
	for ( int c = 0; c < 500; c++ ) {
		hQ22Cent->SetBinContent(c, dQ22[c]);
		hQ24Cent->SetBinContent(c, dQ24[c]);
		hQ26Cent->SetBinContent(c, dQ26[c]);
		hQ28Cent->SetBinContent(c, dQ28[c]);
		if ( dW22[c] == 0. ) dQ22[c] = 0.; else dQ22[c] /= dW22[c];
		if ( dW24[c] == 0. ) dQ24[c] = 0.; else dQ24[c] /= dW24[c];
		if ( dW26[c] == 0. ) dQ26[c] = 0.; else dQ26[c] /= dW26[c];
		if ( dW28[c] == 0. ) dQ28[c] = 0.; else dQ28[c] /= dW28[c];
		hW22Cent->SetBinContent(c, dW22[c]);
		hW24Cent->SetBinContent(c, dW24[c]);
		hW26Cent->SetBinContent(c, dW26[c]);
		hW28Cent->SetBinContent(c, dW28[c]);

		double C2 = dQ22[c];
		double C4 = dQ24[c] - 2*dQ22[c]*dQ22[c];
		double C6 = dQ26[c] - 9*dQ24[c]*dQ22[c] + 12*dQ22[c]*dQ22[c]*dQ22[c];
		double C8 = dQ28[c] - 16*dQ26[c]*dQ22[c] - 18*dQ24[c]*dQ24[c] + 144*dQ24[c]*dQ22[c]*dQ22[c] - 144*dQ22[c]*dQ22[c]*dQ22[c]*dQ22[c];

		double V2, V4, V6, V8;
		if ( C2 > 0 ) V2 = pow(C2, 1./2); else V2 = -pow(-C2, 1./2);
		if ( C4 > 0 ) V4 = -pow(C4, 1./4); else V4 = pow(-C4, 1./4);
		if ( C6 > 0 ) V6 = pow(C6/4., 1./6); else V6 = -pow(-C6/4., 1./6);
		if ( C8 > 0 ) V8 = -pow(C8/33., 1./8); else V8 = pow(-C8/33., 1./8);

//		cout << " c = " << c << "\tdQ22 = " << dQ22[c] << "\tdQ24 = " << dQ24[c] << "\tdQ26 = " << dQ26[c] << "\tdQ28 = " << dQ28[c] << endl;
//		cout << " c = " << c << "\tdC22 = " << C2 << "\tdC24 = " << C4 << "\tdQ26 = " << C6 << "\tdQ28 = " << C8 << endl;
//		cout << " c = " << c << "\tdV22 = " << V2 << "\tdV24 = " << V4 << "\tdV26 = " << V6 << "\tdV28 = " << V8 << endl;
		hC22Cent->SetBinContent(c, C2);
		hC24Cent->SetBinContent(c, C4);
		hC26Cent->SetBinContent(c, C6);
		hC28Cent->SetBinContent(c, C8);

		hV22Cent->SetBinContent(c, V2);
		hV24Cent->SetBinContent(c, V4);
		hV26Cent->SetBinContent(c, V6);
		hV28Cent->SetBinContent(c, V8);
	}
	char *fwname;
	if ( s2 < s3 ) fwname = Form("%s/output_mult_%i_%i.root", ftxt[s1], s2, s3);
	else fwname = Form("%s/output_mult.root", ftxt[s1]);
	TFile *fw = new TFile(fwname, "recreate");
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

		hQ22Cent->Write();
		hQ24Cent->Write();
		hQ26Cent->Write();
		hQ28Cent->Write();

		hW22Cent->Write();
		hW24Cent->Write();
		hW26Cent->Write();
		hW28Cent->Write();

		hMultCent->Write();
		hWeightCent2->Write();
		hWeightCent4->Write();
		hWeightCent6->Write();
		hWeightCent8->Write();
	}
	fw->Close();
};
