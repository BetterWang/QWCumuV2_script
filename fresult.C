/*
 * =====================================================================================
 *
 *       Filename:  fresult.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/03/2014 11:15:55
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
	int s2 = 33;



//	double sys6pA[7] = {0.0792, 0.1762, 0.0212, 0.0727, 0.1238, 0.0917, 0.0180};
//	double sys8pA[4] = {0.0412, 0.0411, 0.0892, 0.0184};

	double sys6pA[7] = {0.0374, 0.1168, 0.0161, 0.0150, 0.0275, 0.0165, 0.0582};
        double sys8pA[4] = {0.0619, 0.0412, 0.1014, 0.0248};

	TFile * f1 = new TFile(Form("%s/fsave.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/fsave.root", ftxt[s2]));
	TGraphErrors * gr_pPb_v26 = (TGraphErrors*) f1->Get("gr_v26");
	TGraphErrors * gr_pPb_v28 = (TGraphErrors*) f1->Get("gr_v28");
	TGraphErrors * gr_PbPb_v26 = (TGraphErrors*) f2->Get("gr_v26");
	TGraphErrors * gr_PbPb_v28 = (TGraphErrors*) f2->Get("gr_v28");

	TGraphErrors * gr_pPb_c26 = (TGraphErrors*) f1->Get("gr_c26");
	TGraphErrors * gr_pPb_c28 = (TGraphErrors*) f1->Get("gr_c28");
	TGraphErrors * gr_PbPb_c26 = (TGraphErrors*) f2->Get("gr_c26");
	TGraphErrors * gr_PbPb_c28 = (TGraphErrors*) f2->Get("gr_c28");

	TGraphErrors * gr_Ratio64 = (TGraphErrors*) f1->Get("gr_Ratio64");
	TGraphErrors * gr_Ratio86 = (TGraphErrors*) f1->Get("gr_Ratio86");
#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");
	gROOT->Macro("OLLITRAULT.C");


	double * Noff6 = gr_pPb_v26->GetX();
	double * Noff8 = gr_pPb_v28->GetX();
	double * v26 = gr_pPb_v26->GetY();
	double * v28 = gr_pPb_v28->GetY();
	double v26sys[20];
	double v28sys[20];
	for ( int i = 0; i < gr_pPb_v26->GetN(); i++ ) {
		v26sys[i] = v26[i]*sys6pA[i];
	}
	for ( int i = 0; i < gr_pPb_v28->GetN(); i++ ) {
		v28sys[i] = v28[i]*sys8pA[i];
	}
	TGraphErrors * gr_pPb_v26s = new TGraphErrors(gr_pPb_v26->GetN(), Noff6, v26, 0, v26sys);
	TGraphErrors * gr_pPb_v28s = new TGraphErrors(gr_pPb_v28->GetN(), Noff8, v28, 0, v28sys);
	gr_pPb_v26s->SetLineColor(gr_pPb_v26->GetLineColor());
	gr_pPb_v28s->SetLineColor(gr_pPb_v28->GetLineColor());


	gr_HIN_13_002_PbPbv22->SetMarkerSize(1.5);
	gr_HIN_13_002_PbPbv24->SetMarkerSize(1.5);
	gr_HIN_13_002_pPbv22->SetMarkerSize(1.5);
	gr_HIN_13_002_pPbv24->SetMarkerSize(1.5);

	gr_PbPb_v26->SetMarkerSize(2.1);
	gr_PbPb_v28->SetMarkerSize(2.1);
	gr_pPb_v26->SetMarkerSize(2.1);
	gr_pPb_v28->SetMarkerSize(2.1);

	grLYZPbPbv2->SetMarkerSize(2.1);
	grLYZpPbv2->SetMarkerSize(2.1);

	TLegend * legLeft = new TLegend(0.4, 0.23, 0.85, 0.5);
	legLeft->SetFillColor(kWhite);
	legLeft->SetBorderSize(0);
	legLeft->AddEntry(gr_HIN_13_002_PbPbv22, "PLB 730(2014)243 v_{2}{2, |#Delta|>2}", "p");
	legLeft->AddEntry(gr_HIN_13_002_PbPbv24, "PLB 730(2014)243 v_{2}{4}", "p");
	legLeft->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	legLeft->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	legLeft->AddEntry(grLYZpPbv2, "v_{2}{LYZ}", "p");
	legLeft->SetTextSize(0.04);

	TLatex latex;
	latex.SetTextFont(23);
	latex.SetTextSize(20);
	latex.SetTextAlign(13);

	TCanvas * cSum2 = MakeCanvas("cSum2", "cSum2", 1000, 500);
	makeMultiPanelCanvas(cSum2, 2, 1, 0., 0., 0.15, 0.18, 0.02);
	cSum2->cd(1);
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_PbPbv22->Draw("Psame");
	gr_HIN_13_002_PbPbv24->Draw("Psame");
	grLYZPbPbv2s->Draw("[]");
	grLYZPbPbv2->Draw("Psame");
	gr_PbPb_v26->Draw("Psame");
	gr_PbPb_v28->Draw("Psame");
	legLeft->Draw();
	latex.DrawLatexNDC(0.2, 0.95, "#splitline{(a) PbPb #sqrt{s_{NN}} = 2.76 TeV}{CMS 0.3 < p_{T} < 3 GeV/#it{c}}");

//	gStyle->SetEndErrorSize(5);
	gStyle->SetErrorX(5);
	cSum2->cd(2);
	TH2D * frame_cent2 = new TH2D("frame_cent2", ";N_{trk}^{offline};v_{2}", 1, 1, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent2, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_pPb_v26s->Draw("[]");
	gr_pPb_v28s->Draw("[]");
	grLYZpPbv2s->Draw("[]");
	gr_HIN_13_002_pPbv22->Draw("Psame");
	gr_HIN_13_002_pPbv24->Draw("Psame");
	grLYZpPbv2->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");
	latex.DrawLatexNDC(0.1, 0.95, "(b) pPb #sqrt{s_{NN}} = 5.02 TeV");


	gr_Ratio64->SetMarkerStyle(kFullSquare);
	gr_Ratio64->SetMarkerSize(1.7);
	gr_Ratio86->SetMarkerStyle(kFullCircle);
	gr_Ratio86->SetMarkerSize(1.7);

	TLegend * legLeftR = new TLegend(0.22, 0.8, 0.65, 0.92);
	legLeftR->SetFillColor(kWhite);
	legLeftR->SetBorderSize(0);
	legLeftR->AddEntry(ffit64, "v_{2}{6}/v_{2}{4} arXiv:1312.6555" , "l");
	legLeftR->AddEntry(gr_Ratio64, "v_{2}{6}/v_{2}{4} pPb" , "p");
	legLeftR->SetTextSize(0.037);

	TLegend * legRightR = new TLegend(0.38, 0.25, 0.9, 0.4);
	legRightR->SetFillColor(kWhite);
	legRightR->SetBorderSize(0);
	legRightR->AddEntry(ffit86, "v_{2}{8}/v_{2}{6} arXiv:1312.6555" , "l");
	legRightR->AddEntry(gr_Ratio86, "v_{2}{8}/v_{2}{6} pPb" , "p");
	legRightR->SetTextSize(0.037);


	TCanvas * cSumR = MakeCanvas("cSumR", "cSumR", 1000, 500);
	makeMultiPanelCanvas(cSumR, 2, 1, 0., 0., 0.1, 0.18, 0.04);
	cSumR->cd(1);
	TH2D * frame_ratio64 = new TH2D("frame_ratio64", "frame_ratio64", 1, 0.41, 0.98, 1, 0.7, 1.3);
	InitHist(frame_ratio64, "v_{2}{4}/v_{2}{2}", "");
	frame_ratio64->Draw();
	ffit64->Draw("same");
	gr_Ratio64->Draw("psame");
	legLeftR->Draw();
	latex.DrawLatexNDC(0.15, 0.92, "(a)");

	cSumR->cd(2);
	frame_ratio64->Draw();
	ffit86->Draw("same");
	gr_Ratio86->Draw("psame");
	legRightR->Draw();
	latex.DrawLatexNDC(0.05, 0.92, "(b) CMS pPb #sqrt{s_{NN}} = 5.02 TeV");


	gr_pPb_c26->SetMarkerStyle(kOpenStar);
	TCanvas * cSumC6 = MakeCanvas("cSumC6", "cSumC6", 1000, 500);
	makeMultiPanelCanvas(cSumC6, 2, 1, 0.02, 0., 0.15, 0.18, 0.07);
	cSumC6->cd(1);
	TH2D * frame_centC6 = new TH2D("frame_centC6", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 1e-10, 1.5e-6);
	InitHist(frame_centC6, "N_{trk}^{offline}", "c_{2}{6}");
	frame_centC6->Draw();
	gr_PbPb_c26->Draw("Psame");
	gr_pPb_c26->Draw("Psame");



	cSum2->SaveAs("final_v2.pdf");
	cSumR->SaveAs("final_ratio.pdf");
	cSum2->SaveAs("final_v2_C.C");
	cSumR->SaveAs("final_ratio_C.C");

}
