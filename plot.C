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

	int s1 = 10;
	int cent = 3;
	int save = 1;


#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	TFile * f = new TFile(Form("%s/fit.root", ftxt[s1]));
	gROOT->Macro("bGetFit.C");
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");

	TH1D* hV22CentE = (TH1D*) f->Get("hV22CentE");
	TH1D* hV24CentE = (TH1D*) f->Get("hV24CentE");
	TH1D* hV26CentE = (TH1D*) f->Get("hV26CentE");
	TH1D* hV28CentE = (TH1D*) f->Get("hV28CentE");

	TCanvas * cSum = MakeCanvas("cSum", "cSum");
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_pPbv24->Draw("Psame");
	gr_HIN_13_002_pPbv22->Draw("Psame");
//	grLYZnoff->Draw("Psame");

	double pPb_v22[20];
	double pPb_v24[20];
	double pPb_v26[20];
	double pPb_v28[20];
	double pPb_v22e[20];
	double pPb_v24e[20];
	double pPb_v26e[20];
	double pPb_v28e[20];
	for ( int i = 0; i < 20; i++ ) {
		pPb_v22[i] = hV22CentE->GetBinContent(i+1);
		pPb_v24[i] = hV24CentE->GetBinContent(i+1);
		pPb_v26[i] = hV26CentE->GetBinContent(i+1);
		pPb_v28[i] = hV28CentE->GetBinContent(i+1);

		pPb_v22e[i] = hV22CentE->GetBinError(i+1);
		pPb_v24e[i] = hV24CentE->GetBinError(i+1);
		pPb_v26e[i] = hV26CentE->GetBinError(i+1);
		pPb_v28e[i] = hV28CentE->GetBinError(i+1);
	}
	TGraphErrors * gr_pPb_v22 = new TGraphErrors( 9, dNoff4, pPb_v22, 0, pPb_v22e);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( 9, dNoff4, pPb_v24, 0, pPb_v24e);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( 8, dNoff6, pPb_v26, 0, pPb_v26e);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( 6, dNoff8, pPb_v28, 0, pPb_v28e);

	gr_pPb_v22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_v24->SetMarkerStyle(kOpenSquare);
	gr_pPb_v26->SetMarkerStyle(kOpenStar);
	gr_pPb_v28->SetMarkerStyle(kOpenDiamond);

	gr_pPb_v22->SetMarkerColor(kBlack);
	gr_pPb_v24->SetMarkerColor(kBlack);
	gr_pPb_v26->SetMarkerColor(kCyan);
	gr_pPb_v28->SetMarkerColor(kRed);

	gr_pPb_v22->SetMarkerSize(2);
	gr_pPb_v24->SetMarkerSize(2);
	gr_pPb_v26->SetMarkerSize(2);
	gr_pPb_v28->SetMarkerSize(2);

	gr_pPb_v22->Draw("Psame");
	gr_pPb_v24->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");

	TLegend * leg = new TLegend(0.2, 0.7, 0.4, 0.9);
	leg->SetFillColor(kWhite);
	leg->SetBorderSize(0);
	leg->AddEntry(gr_pPb_v22, "v_{2}{2}", "p");
	leg->AddEntry(gr_pPb_v24, "v_{2}{4}", "p");
	leg->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	leg->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	leg->Draw();

	if ( save ) {
		cSum->SaveAs("cSum.png");
	}


}
