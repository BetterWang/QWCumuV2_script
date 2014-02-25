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

	int s1 = 44;
	int s2 = 28;
	int s3 = 20;
	int save = 1;

	int bPbPb = 1;
	if ( s1 == 10 ) bPbPb = 0;
	if ( s1 == 33 ) s2 = 33;
	if ( s1 == 34 ) {s2 = 34; bPbPb = 0;}
	if ( s1 == 36 ) {s2 = 36; bPbPb = 0;}
	if ( s1 == 37 ) {s2 = 37; bPbPb = 0;}
	if ( s1 == 38 ) {s2 = 38; bPbPb = 0;}
	if ( s1 == 39 ) {s2 = 39; bPbPb = 0;}
	if ( s1 == 44 ) {s2 = 44; bPbPb = 0;}

	double lim2L = 1e-5;
	double lim2U = 2.e-2;
	double lim4L = -12e-6;
	double lim4U = -1e-8;
	double lim6L = 1e-10;
	double lim6U = 2.0e-7;
	double lim8L = -7.6e-9;
	double lim8U = -1.e-12;
	if ( bPbPb ) {
		lim2L = 1e-5;
		lim2U = 2e-2;
		lim4L = -6e-5;
		lim4U = -1e-8;
		lim6L = 1e-8;
		lim6U = 2e-6;
		lim8L = -1e-7;
		lim8U = -1e-10;
	}

	if ( s1==39) {
		lim2L = 1e-5;
		lim2U = 5e-3;
		lim4L = -9e-6;
		lim4U = -1e-8;
		lim6L = 1e-8;
		lim6U = 2e-7;
		lim8L = -4e-9;
		lim8U = -1e-10;
	}


#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");

	gROOT->Macro("bGetFit.C");

	int blimit4 = 14;
	int blimit6 = 11;
	int blimit8 = 9;
	int blimit04 = 0;
	int blimit06 = 0;
	int blimit08 = 0;
	if ( bPbPb ) {
		blimit4 = 16;
		blimit6 = 14;
		blimit8 = 13;
	}
	if ( s1 == 39 || s1 == 34 || s1 == 44 ) {
		blimit4 = 13;
		blimit6 = 13;
		blimit8 = 13;
	}


	TGraphErrors * grNSigma2 = new TGraphErrors(blimit4-blimit04, dNoff4+blimit04, dNSigma2+blimit04, 0, 0);
	TGraphErrors * grNSigma4 = new TGraphErrors(blimit4-blimit04, dNoff4+blimit04, dNSigma4+blimit04, 0, 0);
	TGraphErrors * grNSigma6 = new TGraphErrors(blimit6-blimit06, dNoff6+blimit06, dNSigma6+blimit06, 0, 0);
	TGraphErrors * grNSigma8 = new TGraphErrors(blimit8-blimit08, dNoff8+blimit08, dNSigma8+blimit08, 0, 0);

	TCanvas * cNsigma = MakeCanvas("cNsigma", "cNsigma");
	cNsigma->SetGrid();
	grNSigma2->SetMarkerColor(kBlack);
	grNSigma4->SetMarkerColor(kBlack);
	grNSigma6->SetMarkerColor(kBlue);
	grNSigma8->SetMarkerColor(kRed);
	grNSigma2->SetMarkerStyle(kOpenTriangleUp);
	grNSigma4->SetMarkerStyle(kFullSquare);
	grNSigma6->SetMarkerStyle(kFullStar);
	grNSigma8->SetMarkerStyle(kFullDiamond);

	grNSigma4->SetMarkerSize(2);
	grNSigma6->SetMarkerSize(2.5);
	grNSigma8->SetMarkerSize(2.5);

	TH2D * frame_nsigma = new TH2D("frame_nsigma", ";N_{trk}^{offline};NSigma", 1, -5, 350, 1, -20, 20);
	InitHist(frame_nsigma, "N_{trk}^{offline}", "NSigma");
	frame_nsigma->Draw();
//	grNSigma2->Draw("Psame");
	grNSigma4->Draw("Psame");
	grNSigma6->Draw("Psame");
	grNSigma8->Draw("Psame");
	TLine * l1 = new TLine(-5, 1.5, 350, 1.5);
	TLine * l2 = new TLine(-5, -1.5, 350, -1.5);
	l1->SetLineColor(kRed);
	l2->SetLineColor(kRed);
	l1->Draw();
	l2->Draw();

	TLegend * legC;
	if ( bPbPb ) legC = new TLegend(0.7, 0.6, 0.9, 0.79);
	else legC = new TLegend(0.75, 0.7, 0.92, 0.89);
	legC->SetFillColor(kWhite);
	legC->SetBorderSize(0);
//	legC->AddEntry(grNSigma2, "c_{2}{2}", "p");
	legC->AddEntry(grNSigma4, "c_{2}{4}", "p");
	legC->AddEntry(grNSigma6, "c_{2}{6}", "p");
	legC->AddEntry(grNSigma8, "c_{2}{8}", "p");
	legC->Draw();



	TGraphErrors * gr_HIN_13_002_v22 = gr_HIN_13_002_pPbv22;
	TGraphErrors * gr_HIN_13_002_v24 = gr_HIN_13_002_pPbv24;
	if ( bPbPb ) {
		gr_HIN_13_002_v22 = gr_HIN_13_002_PbPbv22;
		gr_HIN_13_002_v24 = gr_HIN_13_002_PbPbv24;
	}

	TCanvas * cSum = MakeCanvas("cSum", "cSum");
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_v24->SetMarkerColor(kBlue);
	gr_HIN_13_002_v22->SetMarkerColor(kRed);

	gr_HIN_13_002_v24->Draw("Psame");
	gr_HIN_13_002_v22->Draw("Psame");
//	grLYZnoff->Draw("Psame");

	TGraphErrors * gr_pPb_v22 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dV22+blimit04, 0, eV22+blimit04);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dV24+blimit04, 0, eV24+blimit04);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( blimit6-blimit06, dNoff6+blimit04, dV26+blimit06, 0, eV26+blimit06);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( blimit8-blimit08, dNoff8+blimit04, dV28+blimit08, 0, eV28+blimit08);

	TGraphErrors * gr_pPb_c22 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dC22+blimit04, 0, eC22+blimit04);
	TGraphErrors * gr_pPb_c24 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dC24+blimit04, 0, eC24+blimit04);
	TGraphErrors * gr_pPb_c26 = new TGraphErrors( blimit6-blimit06, dNoff6+blimit04, dC26+blimit06, 0, eC26+blimit06);
	TGraphErrors * gr_pPb_c28 = new TGraphErrors( blimit8-blimit08, dNoff8+blimit04, dC28+blimit08, 0, eC28+blimit08);

	gr_pPb_v22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_v24->SetMarkerStyle(kFullSquare);
	gr_pPb_v26->SetMarkerStyle(kFullStar);
	gr_pPb_v28->SetMarkerStyle(kFullDiamond);
	gr_pPb_c22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_c24->SetMarkerStyle(kFullSquare);
	gr_pPb_c26->SetMarkerStyle(kFullStar);
	gr_pPb_c28->SetMarkerStyle(kFullDiamond);

	gr_pPb_v22->SetMarkerColor(kBlack);
	gr_pPb_v24->SetMarkerColor(kBlack);
	gr_pPb_v26->SetMarkerColor(kBlue);
	gr_pPb_v28->SetMarkerColor(kRed);
	gr_pPb_c22->SetMarkerColor(kBlack);
	gr_pPb_c24->SetMarkerColor(kBlack);
	gr_pPb_c26->SetMarkerColor(kBlue);
	gr_pPb_c28->SetMarkerColor(kRed);

	gr_pPb_v22->SetMarkerSize(2);
	gr_pPb_v24->SetMarkerSize(2);
	gr_pPb_v26->SetMarkerSize(2.5);
	gr_pPb_v28->SetMarkerSize(2.5);
	gr_pPb_c22->SetMarkerSize(2);
	gr_pPb_c24->SetMarkerSize(2);
	gr_pPb_c26->SetMarkerSize(2.5);
	gr_pPb_c28->SetMarkerSize(2.5);

//	gr_pPb_v22->Draw("Psame");
	gr_pPb_v24->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");

	TLegend * leg = new TLegend(0.18, 0.75, 0.45, 0.9);
	leg->SetFillColor(kWhite);
	leg->SetBorderSize(0);
//	leg->AddEntry(gr_pPb_v22, "v_{2}{2}", "p");
//	leg->AddEntry(gr_HIN_13_002_v22, "v_{2}{2PC} published", "p");
//	leg->AddEntry(gr_HIN_13_002_v24, "v_{2}{4} published", "p");
	leg->AddEntry(gr_pPb_v24, "v_{2}{4}", "p");
	leg->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	leg->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
//	leg->AddEntry(grLYZnoff, "v_{2}{LYZ}", "p");
	leg->Draw();

	TLine * linev2 = new TLine(0, 0.049, 300, 0.049);
	linev2->SetLineColor(kRed);
	if ( s1 == 39 ) linev2->Draw();

	TCanvas * cSumC2 = MakeCanvas("cSumC2", "cSumC2");
	TCanvas * cSumC4 = MakeCanvas("cSumC4", "cSumC4");
	TCanvas * cSumC6 = MakeCanvas("cSumC6", "cSumC6");
	TCanvas * cSumC8 = MakeCanvas("cSumC8", "cSumC8");

	TH2D * frame_centC2 = new TH2D("frame_centC2", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, lim2L, lim2U);
	TH2D * frame_centC4 = new TH2D("frame_centC4", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, lim4L, lim4U);
	TH2D * frame_centC6 = new TH2D("frame_centC6", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, lim6L, lim6U);
	TH2D * frame_centC8 = new TH2D("frame_centC8", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, lim8L, lim8U);
	InitHist(frame_centC2, "N_{trk}^{offline}", "c_{2}{2}");
	InitHist(frame_centC4, "N_{trk}^{offline}", "c_{2}{4}");
	InitHist(frame_centC6, "N_{trk}^{offline}", "c_{2}{6}");
	InitHist(frame_centC8, "N_{trk}^{offline}", "c_{2}{8}");

	cSumC2->cd();
	frame_centC2->Draw();
	gr_pPb_c22->Draw("Psame");

	cSumC4->cd();
	frame_centC4->Draw();
	gr_pPb_c24->Draw("Psame");

	cSumC6->cd();
	frame_centC6->Draw();
	gr_pPb_c26->Draw("Psame");

	cSumC8->cd();
	frame_centC8->Draw();
	gr_pPb_c28->Draw("Psame");

	if ( save ) {
		cNsigma->SaveAs(Form("cNsigma_%i_%i.png", s1, s3));
		cNsigma->SaveAs(Form("cNsigma_%i_%i.eps", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i.png", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i.eps", s1, s3));

		cSumC2->SaveAs(Form("cSumC2_%i_%i.eps", s1, s3));
		cSumC4->SaveAs(Form("cSumC4_%i_%i.eps", s1, s3));
		cSumC6->SaveAs(Form("cSumC6_%i_%i.eps", s1, s3));
		cSumC8->SaveAs(Form("cSumC8_%i_%i.eps", s1, s3));
	}

}
