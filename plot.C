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

	int s1 = 33;
	int s2 = 28;
	int s3 = 20;
	int save = 1;

	int bPbPb = 1;
	if ( s1 == 10 ) bPbPb = 0;
	if ( s1 == 33 ) s2 = 33;

	int bRebin6 = 0;
	int bRebin8 = 0;

#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");

	gROOT->Macro("bGetFit.C");

	int blimit6 = 17;
	int blimit8 = 17;
	if ( !bPbPb && bRebin6 ) blimit6 = 11;
	if ( bPbPb && bRebin6 ) blimit6 = 13;
	if ( !bPbPb && bRebin8 ) blimit8 = 9;
	if ( bPbPb && bRebin8 ) blimit8 = 12;


	TGraphErrors * grNSigma2 = new TGraphErrors(17, dNoff, dNSigma2, 0, 0);
	TGraphErrors * grNSigma4 = new TGraphErrors(17, dNoff, dNSigma4, 0, 0);
	TGraphErrors * grNSigma6 = new TGraphErrors(blimit6, dNoff6, dNSigma6, 0, 0);
	TGraphErrors * grNSigma8 = new TGraphErrors(blimit8, dNoff8, dNSigma8, 0, 0);

	TCanvas * cNsigma = MakeCanvas("cNsigma", "cNsigma");
	cNsigma->SetGrid();
	grNSigma2->SetMarkerColor(kBlack);
	grNSigma4->SetMarkerColor(kBlack);
	grNSigma6->SetMarkerColor(kBlack);
	grNSigma8->SetMarkerColor(kRed);
	grNSigma2->SetMarkerStyle(kOpenTriangleUp);
	grNSigma4->SetMarkerStyle(kOpenSquare);
	grNSigma6->SetMarkerStyle(kFullStar);
	grNSigma8->SetMarkerStyle(kFullDiamond);

	grNSigma4->SetMarkerSize(2);
	grNSigma6->SetMarkerSize(2.5);
	grNSigma8->SetMarkerSize(2.5);

	TH2D * frame_nsigma = new TH2D("frame_nsigma", ";N_{trk}^{offline};NSigma", 1, -5, 350, 1, -10, 10 );
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

	TLegend * legC = new TLegend(0.0, 0.8, 0.2, 0.99);
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

	TGraphErrors * gr_pPb_v22 = new TGraphErrors( 17, dNoff, dV22, 0, eV22);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( 17, dNoff, dV24, 0, eV24);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( 17, dNoff6, dV26, 0, eV26);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( 17, dNoff8, dV28, 0, eV28);

	gr_pPb_v22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_v24->SetMarkerStyle(kFullSquare);
	gr_pPb_v26->SetMarkerStyle(kFullStar);
	gr_pPb_v28->SetMarkerStyle(kFullDiamond);

	gr_pPb_v22->SetMarkerColor(kBlack);
	gr_pPb_v24->SetMarkerColor(kBlack);
	gr_pPb_v26->SetMarkerColor(kBlue);
	gr_pPb_v28->SetMarkerColor(kRed);

	gr_pPb_v22->SetMarkerSize(2);
	gr_pPb_v24->SetMarkerSize(2);
	gr_pPb_v26->SetMarkerSize(2.5);
	gr_pPb_v28->SetMarkerSize(2.5);

//	gr_pPb_v22->Draw("Psame");
	gr_pPb_v24->Draw("Psame");
//	gr_pPb_v26->Draw("Psame");
//	gr_pPb_v28->Draw("Psame");

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
//
	if ( save ) {
		cNsigma->SaveAs(Form("cNsigma_%i_%i.png", s1, s3));
		cNsigma->SaveAs(Form("cNsigma_%i_%i.eps", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i.png", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i.eps", s1, s3));
	}

}
