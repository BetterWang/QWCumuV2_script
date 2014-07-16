/*
 * =====================================================================================
 *
 *       Filename:  compare3.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/27/2014 01:16:45
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
	int s1 = 10;
	int s2 = 52;
	int s3 = 3;

	TString text1 = "Combined";
	TString text2 = "pPb";
	TString text3 = "Pbp";
	int b3 = 1;

	TString fname2 = Form("%s/fsave.root", ftxt[s2]);

//	if ( s2 == 10 ) {
//		s3 = 10;
//		text1 = "bin width of 5";
//		text2 = "bin width of 2";
//		fname2 = Form("%s/fsave_bin2.root", ftxt[s2]);
//		b3 = 0;
//	}
	if ( s2 == 33 ) {
		s3 = 33;
		text1 = "bin width of 5";
		text2 = "bin width of 2";
		fname2 = Form("%s/fsave_bin2.root", ftxt[s2]);
		b3 = 0;
	}


	if ( s2 == 48 ) {
		s3 = 48;
		text1 = "Standard";
		text2 = "Single HLT path";
		b3 = 0;
	}

	if ( s2 == 52 ) {
		s3 = 60;
		text1 = "Standard";
		text2 = "Loose track cuts";
		text3 = "Tight track cuts";
		b3 = 1;
	}

	if ( s2 == 68 ) {
		s3 = 68;
		text1 = "Standard";
		text2 = "Single vertex";
		b3 = 0;
	}
	if ( s2 == 76 ) {
		s3 = 84;
		text1 = "Standard";
		text2 = "|v_{z}| < 3cm";
		text3 = "3 < |v_{z}| < 15 cm";
		b3 = 1;
	}
	if ( s2 == 92 ) {
		s3 = 92;
		text1 = "HIJING";
		text2 = "PYTHIA";
		b3 = 0;
	}

	if ( s2 == 97 ) {
		s3 = 97;
		text1 = "Standard";
		text2 = "Single vertex";
		b3 = 0;
	}
	if ( s2 == 98 ) {
		s3 = 99;
		text1 = "Standard";
		text2 = "Loose track cuts";
		text3 = "Tight track cuts";
		b3 = 1;
	}
	if ( s2 == 100 ) {
		s3 = 101;
		text1 = "Standard";
		text2 = "|v_{z}| < 3cm";
		text3 = "3 < |v_{z}| < 15 cm";
		b3 = 1;
	}
	if ( s2 == 102 ) {
		s3 = 102;
		text1 = "Standard HIJING Efficiency";
		text2 = "PYTHIA Efficiency";
		b3 = 0;
	}




	TString fname1 = Form("%s/fsave.root", ftxt[s1]);
	TString fname3 = Form("%s/fsave.root", ftxt[s3]);

	TFile * f1 = new TFile(fname1.Data());
	TFile * f2 = new TFile(fname2.Data());
	TFile * f3 = new TFile(fname3.Data());

	TGraphErrors * gr1_v22 = (TGraphErrors*) f1->Get("gr_v22");
	TGraphErrors * gr1_v24 = (TGraphErrors*) f1->Get("gr_v24");
	TGraphErrors * gr1_v26 = (TGraphErrors*) f1->Get("gr_v26");
	TGraphErrors * gr1_v28 = (TGraphErrors*) f1->Get("gr_v28");

	TGraphErrors * gr2_v22 = (TGraphErrors*) f2->Get("gr_v22");
	TGraphErrors * gr2_v24 = (TGraphErrors*) f2->Get("gr_v24");
	TGraphErrors * gr2_v26 = (TGraphErrors*) f2->Get("gr_v26");
	TGraphErrors * gr2_v28 = (TGraphErrors*) f2->Get("gr_v28");

	TGraphErrors * gr3_v22 = (TGraphErrors*) f3->Get("gr_v22");
	TGraphErrors * gr3_v24 = (TGraphErrors*) f3->Get("gr_v24");
	TGraphErrors * gr3_v26 = (TGraphErrors*) f3->Get("gr_v26");
	TGraphErrors * gr3_v28 = (TGraphErrors*) f3->Get("gr_v28");

#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");

	TCanvas * cComp2 = MakeCanvas("cComp2", "cComp2");
	TCanvas * cComp4 = MakeCanvas("cComp4", "cComp4");
	TCanvas * cComp6 = MakeCanvas("cComp6", "cComp6");
	TCanvas * cComp8 = MakeCanvas("cComp8", "cComp8");

	cComp4->cd();
	frame_cent->Draw();

	gr1_v24->SetMarkerStyle(kFullSquare);
	gr2_v24->SetMarkerStyle(kOpenSquare);
	gr3_v24->SetMarkerStyle(kOpenSquare);

	gr1_v24->SetMarkerColor(kBlack);
	gr2_v24->SetMarkerColor(kRed);
	gr3_v24->SetMarkerColor(kBlue);

	gr1_v24->Draw("psame");
	gr2_v24->Draw("psame");
	if ( b3 ) gr3_v24->Draw("psame");

	TLegend * leg4 = new TLegend(0.18, 0.75, 0.55, 0.9);
	leg4->SetFillColor(kWhite);
	leg4->SetBorderSize(0);
	leg4->AddEntry(gr1_v24, Form("v_{2}{4} %s", text1.Data()), "p");
	leg4->AddEntry(gr2_v24, Form("v_{2}{4} %s", text2.Data()), "p");
	if ( b3 ) leg4->AddEntry(gr3_v24, Form("v_{2}{4} %s", text3.Data()), "p");
	leg4->Draw();

	cComp6->cd();
	frame_cent->Draw();

	gr1_v26->SetMarkerStyle(kFullStar);
	gr2_v26->SetMarkerStyle(kOpenStar);
	gr3_v26->SetMarkerStyle(kOpenStar);

	gr1_v26->SetMarkerColor(kBlack);
	gr2_v26->SetMarkerColor(kRed);
	gr3_v26->SetMarkerColor(kBlue);

	gr1_v26->SetLineColor(kBlack);
	gr2_v26->SetLineColor(kRed);
	gr3_v26->SetLineColor(kBlue);

	gr1_v26->Draw("psame");
	gr2_v26->Draw("psame");
	if ( b3 ) gr3_v26->Draw("psame");

	TLegend * leg6 = new TLegend(0.18, 0.7, 0.55, 0.9);
	leg6->SetFillColor(kWhite);
	leg6->SetBorderSize(0);
	leg6->AddEntry(gr1_v26, Form("v_{2}{6} %s", text1.Data()), "p");
	leg6->AddEntry(gr2_v26, Form("v_{2}{6} %s", text2.Data()), "p");
	if ( b3 ) leg6->AddEntry(gr3_v26, Form("v_{2}{6} %s", text3.Data()), "p");
	leg6->SetTextSize(0.06);
	leg6->Draw();


	cComp8->cd();
	frame_cent->Draw();

	gr1_v28->SetMarkerStyle(kFullDiamond);
	gr2_v28->SetMarkerStyle(kOpenDiamond);
	gr3_v28->SetMarkerStyle(kOpenDiamond);

	gr1_v28->SetMarkerColor(kBlack);
	gr2_v28->SetMarkerColor(kRed);
	gr3_v28->SetMarkerColor(kBlue);

	gr1_v28->SetLineColor(kBlack);
	gr2_v28->SetLineColor(kRed);
	gr3_v28->SetLineColor(kBlue);

	gr1_v28->Draw("psame");
	gr2_v28->Draw("psame");
	if ( b3 ) gr3_v28->Draw("psame");

	TLegend * leg8 = new TLegend(0.18, 0.7, 0.55, 0.9);
	leg8->SetFillColor(kWhite);
	leg8->SetBorderSize(0);
	leg8->AddEntry(gr1_v28, Form("v_{2}{8} %s", text1.Data()), "p");
	leg8->AddEntry(gr2_v28, Form("v_{2}{8} %s", text2.Data()), "p");
	if ( b3 ) leg8->AddEntry(gr3_v28, Form("v_{2}{8} %s", text3.Data()), "p");
	leg8->SetTextSize(0.06);
	leg8->Draw();

	int Nbins = gr1_v24->GetN();
	cout << "--> v24" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2 \t\t sys" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v24->GetX()[i];
		double y1 = gr1_v24->GetY()[i];
		double y2 = gr2_v24->GetY()[i];
		double y3 = gr3_v24->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y1 << "\t\t" << (y3-y1)/y1 << "\t" << (y3+y2-2*y1)/2/y1 << endl;
	}

	Nbins = gr1_v26->GetN();
	cout << "--> v26" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2 \t\t sys" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v26->GetX()[i];
		double y1 = gr1_v26->GetY()[i];
		double y2 = gr2_v26->GetY()[i];
		double y3 = gr3_v26->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y1 << "\t\t" << (y3-y1)/y1 << "\t" << (y3+y2-2*y1)/2/y1 << endl;
	}

	Nbins = gr1_v28->GetN();
	cout << "--> v28" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2 \t\t sys" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v28->GetX()[i];
		double y1 = gr1_v28->GetY()[i];
		double y2 = gr2_v28->GetY()[i];
		double y3 = gr3_v28->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y1 << "\t\t" << (y3-y1)/y1 << "\t" << (y3+y2-2*y1)/2/y1 << endl;
	}



	{
		cComp4->SaveAs(Form("cComp4_%i_%i_%i.pdf", s1, s2, s3));
		cComp6->SaveAs(Form("cComp6_%i_%i_%i.pdf", s1, s2, s3));
		cComp8->SaveAs(Form("cComp8_%i_%i_%i.pdf", s1, s2, s3));
	}
}

