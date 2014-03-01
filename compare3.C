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
	int s2 = 76;
	int s3 = 3;

	TString text1 = "Combined";
	TString text2 = "pPb";
	TString text3 = "Pbp";
	int b3 = 1;

	if ( s2 == 48 ) {
		s3 = 48;
		text1 = "Standard";
		text2 = "Single HLT path";
		b3 = 0;
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
		text2 = "|vz| < 3cm";
		text3 = "3 < |vz| < 15 cm";
		b3 = 1;
	}



	TFile * f1 = new TFile(Form("%s/fsave.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/fsave.root", ftxt[s2]));
	TFile * f3 = new TFile(Form("%s/fsave.root", ftxt[s3]));

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

	gr1_v26->Draw("psame");
	gr2_v26->Draw("psame");
	if ( b3 ) gr3_v26->Draw("psame");

	TLegend * leg6 = new TLegend(0.18, 0.75, 0.55, 0.9);
	leg6->SetFillColor(kWhite);
	leg6->SetBorderSize(0);
	leg6->AddEntry(gr1_v26, Form("v_{2}{6} %s", text1.Data()), "p");
	leg6->AddEntry(gr2_v26, Form("v_{2}{6} %s", text2.Data()), "p");
	if ( b3 ) leg6->AddEntry(gr3_v26, Form("v_{2}{6} %s", text3.Data()), "p");
	leg6->Draw();


	cComp8->cd();
	frame_cent->Draw();

	gr1_v28->SetMarkerStyle(kFullDiamond);
	gr2_v28->SetMarkerStyle(kOpenDiamond);
	gr3_v28->SetMarkerStyle(kOpenDiamond);

	gr1_v28->SetMarkerColor(kBlack);
	gr2_v28->SetMarkerColor(kRed);
	gr3_v28->SetMarkerColor(kBlue);

	gr1_v28->Draw("psame");
	gr2_v28->Draw("psame");
	if ( b3 ) gr3_v28->Draw("psame");

	TLegend * leg8 = new TLegend(0.18, 0.75, 0.55, 0.9);
	leg8->SetFillColor(kWhite);
	leg8->SetBorderSize(0);
	leg8->AddEntry(gr1_v28, Form("v_{2}{8} %s", text1.Data()), "p");
	leg8->AddEntry(gr2_v28, Form("v_{2}{8} %s", text2.Data()), "p");
	if ( b3 ) leg8->AddEntry(gr3_v28, Form("v_{2}{8} %s", text3.Data()), "p");
	leg8->Draw();

	int Nbins = gr1_v24->GetN();
	cout << "--> v24" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v24->GetX()[i];
		double y1 = gr1_v24->GetY()[i];
		double y2 = gr2_v24->GetY()[i];
		double y3 = gr3_v24->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y2 << "\t\t" << (y3-y1)/y1 << endl;
	}

	Nbins = gr1_v26->GetN();
	cout << "--> v26" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v26->GetX()[i];
		double y1 = gr1_v26->GetY()[i];
		double y2 = gr2_v26->GetY()[i];
		double y3 = gr3_v26->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y2 << "\t\t" << (y3-y1)/y1 << endl;
	}

	Nbins = gr1_v28->GetN();
	cout << "--> v28" << endl;
	cout << "idx\t Noff\t\t diff1\t\t diff2" << endl;
	for ( int i = 0; i < Nbins; i++ ) {
		double Noff = gr1_v28->GetX()[i];
		double y1 = gr1_v28->GetY()[i];
		double y2 = gr2_v28->GetY()[i];
		double y3 = gr3_v28->GetY()[i];
		cout << i << "\t" << Noff << "\t\t" << (y2-y1)/y2 << "\t\t" << (y3-y1)/y1 << endl;
	}



	{
		cComp4->SaveAs(Form("cComp4_%i_%i_%i.pdf", s1, s2, s3));
		cComp6->SaveAs(Form("cComp6_%i_%i_%i.pdf", s1, s2, s3));
		cComp8->SaveAs(Form("cComp8_%i_%i_%i.pdf", s1, s2, s3));
	}
}

