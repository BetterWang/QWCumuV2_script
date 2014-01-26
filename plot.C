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
	int s2 = 28;
	int save = 1;


#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	TFile * fHM = new TFile(Form("%s/fit.root", ftxt[s1]));
	TFile * fMB = new TFile(Form("%s/fit.root", ftxt[s2]));
	gROOT->Macro("bGetFit.C");
	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");

	TGraphErrors * grNSigma2 = new TGraphErrors(17, dNoff, dNSigma2, 0, 0);
	TGraphErrors * grNSigma4 = new TGraphErrors(17, dNoff, dNSigma4, 0, 0);
	TGraphErrors * grNSigma6 = new TGraphErrors(17, dNoff, dNSigma6, 0, 0);
	TGraphErrors * grNSigma8 = new TGraphErrors(17, dNoff, dNSigma8, 0, 0);

	TCanvas * cNsigma = MakeCanvas("cNsigma", "cNsigma");
	cNsigma->SetGrid();
	grNSigma2->SetMarkerColor(kBlack);
	grNSigma4->SetMarkerColor(kBlack);
	grNSigma6->SetMarkerColor(kCyan);
	grNSigma8->SetMarkerColor(kRed);
	grNSigma2->SetMarkerStyle(kOpenTriangleUp);
	grNSigma4->SetMarkerStyle(kOpenSquare);
	grNSigma6->SetMarkerStyle(kOpenStar);
	grNSigma8->SetMarkerStyle(kOpenDiamond);
	TH2D * frame_nsigma = new TH2D("frame_nsigma", ";N_{trk}^{offline};NSigma", 1, -5, 350, 1, -7, 7 );
	InitHist(frame_nsigma, "N_{trk}^{offline}", "NSigma");
	frame_nsigma->Draw();
	grNSigma2->Draw("Psame");
	grNSigma4->Draw("Psame");
	grNSigma6->Draw("Psame");
	grNSigma8->Draw("Psame");
	TLine * l1 = new TLine(-5, 1.5, 350, 1.5);
	TLine * l2 = new TLine(-5, -1.5, 350, -1.5);
	l1->SetLineColor(kRed);
	l2->SetLineColor(kRed);
	l1->Draw();
	l2->Draw();



	TCanvas * cSum = MakeCanvas("cSum", "cSum");
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_pPbv24->Draw("Psame");
	gr_HIN_13_002_pPbv22->Draw("Psame");
//	grLYZnoff->Draw("Psame");

	TGraphErrors * gr_pPb_v22 = new TGraphErrors( 18, dNoff, pPb_v22, 0, pPb_v22e);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( 18, dNoff, pPb_v24, 0, pPb_v24e);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( 18, dNoff, pPb_v26, 0, pPb_v26e);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( 18, dNoff, pPb_v28, 0, pPb_v28e);

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
//
//	if ( save ) {
//		cSum->SaveAs("cSum.png");
//	}
//

}
