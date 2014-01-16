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

	TFile * f = new TFile(Form("%s/output.root", ftxt[s1]));
	gROOT->Macro("bGet.C");
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");

	TCanvas * cQ2 = new TCanvas("cQ2", "cQ2", 600, 600);
	cQ2->SetGrid();
	cQ2->SetLogy();
	hQ22[cent]->SetTitle(";Q_{2}{2};Nevt");
	hQ22[cent]->Draw();

	TCanvas * cQ4 = new TCanvas("cQ4", "cQ4", 600, 600);
	cQ4->SetGrid();
	cQ4->SetLogy();
	hQ24[cent]->SetTitle(";Q_{2}{4};Nevt");
	hQ24[cent]->Draw();

	TCanvas * cQ6 = new TCanvas("cQ6", "cQ6", 600, 600);
	cQ6->SetGrid();
	cQ6->SetLogy();
	hQ26[cent]->SetTitle(";Q_{2}{6};Nevt");
	hQ26[cent]->Draw();

	TCanvas * cQ8 = new TCanvas("cQ8", "cQ8", 600, 600);
	cQ8->SetGrid();
	cQ8->SetLogy();
	hQ28[cent]->SetTitle(";Q_{2}{8};Nevt");
	hQ28[cent]->Draw();

	TCanvas * cC2 = new TCanvas("cC2", "cC2", 600, 600);
	cC2->SetGrid();
	cC2->SetLogy();
	hC22[cent]->SetTitle(";C_{2}{2};Nevt");
	hC22[cent]->Draw();

	TCanvas * cC4 = new TCanvas("cC4", "cC4", 600, 600);
	cC4->SetGrid();
	cC4->SetLogy();
	hC24[cent]->SetTitle(";C_{2}{4};Nevt");
	hC24[cent]->Draw();

	TCanvas * cC6 = new TCanvas("cC6", "cC6", 600, 600);
	cC6->SetGrid();
	cC6->SetLogy();
	hC26[cent]->SetTitle(";C_{2}{6};Nevt");
	hC26[cent]->Draw();

	TCanvas * cC8 = new TCanvas("cC8", "cC8", 600, 600);
	cC8->SetGrid();
	cC8->SetLogy();
	hC28[cent]->SetTitle(";C_{2}{8};Nevt");
	hC28[cent]->Draw();

	TCanvas * cV2 = new TCanvas("cV2", "cV2", 600, 600);
	cV2->SetGrid();
	cV2->SetLogy();
	hV22[cent]->SetTitle(";V_{2}{2};Nevt");
	hV22[cent]->Draw();

	TCanvas * cV4 = new TCanvas("cV4", "cV4", 600, 600);
	cV4->SetGrid();
	cV4->SetLogy();
	hV24[cent]->SetTitle(";V_{2}{4};Nevt");
	hV24[cent]->Draw();

	TCanvas * cV6 = new TCanvas("cV6", "cV6", 600, 600);
	cV6->SetGrid();
	cV6->SetLogy();
	hV26[cent]->SetTitle(";V_{2}{6};Nevt");
	hV26[cent]->Draw();

	TCanvas * cV8 = new TCanvas("cV8", "cV8", 600, 600);
	cV8->SetGrid();
	cV8->SetLogy();
	hV28[cent]->SetTitle(";V_{2}{8};Nevt");
	hV28[cent]->Draw();

	TCanvas * cV2cent = new TCanvas("cV2cent", "cV2cent", 600, 600);
	hV22Cent->SetTitle(";Cent;C22");
	hV22Cent->Draw();
	
	TCanvas * cV4cent = new TCanvas("cV4cent", "cV4cent", 600, 600);
	hV24Cent->SetTitle(";Cent;C24");
	hV24Cent->Draw();

	TCanvas * cV6cent = new TCanvas("cV6cent", "cV6cent", 600, 600);
	hV26Cent->SetTitle(";Cent;C26");
	hV26Cent->Draw();

	TCanvas * cV8cent = new TCanvas("cV8cent", "cV8cent", 600, 600);
	hV28Cent->SetTitle(";Cent;C28");
	hV28Cent->Draw();

	TCanvas * cC2cent = new TCanvas("cC2cent", "cC2cent", 600, 600);
	hC22Cent->SetTitle(";Cent;C22");
	hC22Cent->Draw();
	
	TCanvas * cC4cent = new TCanvas("cC4cent", "cC4cent", 600, 600);
	hC24Cent->SetTitle(";Cent;C24");
	hC24Cent->Draw();

	TCanvas * cC6cent = new TCanvas("cC6cent", "cC6cent", 600, 600);
	hC26Cent->SetTitle(";Cent;C26");
	hC26Cent->Draw();

	TCanvas * cC8cent = new TCanvas("cC8cent", "cC8cent", 600, 600);
	hC28Cent->SetTitle(";Cent;C28");
	hC28Cent->Draw();

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
	for ( int i = 0; i < 20; i++ ) {
		pPb_v22[i] = hV22Cent->GetBinContent(i+1);
		pPb_v24[i] = hV24Cent->GetBinContent(i+1);
		pPb_v26[i] = hV26Cent->GetBinContent(i+1);
		pPb_v28[i] = hV28Cent->GetBinContent(i+1);
	}
	TGraphErrors * gr_pPb_v22 = new TGraphErrors( 10, dNoff, pPb_v22, 0, 0);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( 10, dNoff, pPb_v24, 0, 0);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( 10, dNoff, pPb_v26, 0, 0);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( 10, dNoff, pPb_v28, 0, 0);

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
		cQ2->SaveAs(Form("cQ2_%i.png", cent));
		cQ4->SaveAs(Form("cQ4_%i.png", cent));
		cQ6->SaveAs(Form("cQ6_%i.png", cent));
		cQ8->SaveAs(Form("cQ8_%i.png", cent));

		cC2->SaveAs(Form("cC2_%i.png", cent));
		cC4->SaveAs(Form("cC4_%i.png", cent));
		cC6->SaveAs(Form("cC6_%i.png", cent));
		cC8->SaveAs(Form("cC8_%i.png", cent));

		cV2->SaveAs(Form("cV2_%i.png", cent));
		cV4->SaveAs(Form("cV4_%i.png", cent));
		cV6->SaveAs(Form("cV6_%i.png", cent));
		cV8->SaveAs(Form("cV8_%i.png", cent));

		cC2cent->SaveAs("cC2cent.png");
		cC4cent->SaveAs("cC4cent.png");
		cC6cent->SaveAs("cC6cent.png");
		cC8cent->SaveAs("cC8cent.png");

		cV2cent->SaveAs("cV2cent.png");
		cV4cent->SaveAs("cV4cent.png");
		cV6cent->SaveAs("cV6cent.png");
		cV8cent->SaveAs("cV8cent.png");
		cSum->SaveAs("cSum.png");
	}


}
