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

	TFile * f1 = new TFile(Form("%s/fsave.root", ftxt[s1]));
	TFile * f2 = new TFile(Form("%s/fsave.root", ftxt[s2]));
	TGraphErrors * gr_pPb_v26 = (TGraphErrors*) f1->Get("gr_v26");
	TGraphErrors * gr_pPb_v28 = (TGraphErrors*) f1->Get("gr_v28");
	TGraphErrors * gr_PbPb_v26 = (TGraphErrors*) f2->Get("gr_v26");
	TGraphErrors * gr_PbPb_v28 = (TGraphErrors*) f2->Get("gr_v28");

	TGraphErrors * gr_Ratio64 = (TGraphErrors*) f1->Get("gr_Ratio64");
	TGraphErrors * gr_Ratio86 = (TGraphErrors*) f1->Get("gr_Ratio86");
#include "../../style.h"
        SetStyle();
	gStyle->SetOptTitle(0);

	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");
	gROOT->Macro("OLLITRAULT.C");

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

	TLegend * legLeft = new TLegend(0.42, 0.23, 0.85, 0.5);
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

	TCanvas * cSum2 = MakeCanvas("cSum2", "cSum2", 1200, 500);
	makeMultiPanelCanvas(cSum2, 2, 1, 0., 0., 0.15, 0.18, 0.02);
	cSum2->cd(1);
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_PbPbv22->Draw("Psame");
	gr_HIN_13_002_PbPbv24->Draw("Psame");
	grLYZPbPbv2->Draw("Psame");
	gr_PbPb_v26->Draw("Psame");
	gr_PbPb_v28->Draw("Psame");
	legLeft->Draw();
	latex.DrawLatexNDC(0.2, 0.95, "#splitline{(a) PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3 GeV/#it{c}}");

	cSum2->cd(2);
	TH2D * frame_cent2 = new TH2D("frame_cent2", ";N_{trk}^{offline};v_{2}", 1, 1, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent2, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_pPbv22->Draw("Psame");
	gr_HIN_13_002_pPbv24->Draw("Psame");
	grLYZpPbv2->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");
	latex.DrawLatexNDC(0.1, 0.95, "(b) CMS pPb #sqrt{s_{NN}} = 5.02 TeV");


	gr_Ratio64->SetMarkerStyle(kFullSquare);
	gr_Ratio64->SetMarkerSize(1.7);
	gr_Ratio86->SetMarkerStyle(kFullCircle);
	gr_Ratio86->SetMarkerSize(1.7);

	TLegend * legLeftR = new TLegend(0.13, 0.62, 0.6, 0.82);
	legLeftR->SetFillColor(kWhite);
	legLeftR->SetBorderSize(0);
	legLeftR->AddEntry(ffit64, "v_{2}{6}/v_{2}{4} arXiv:1312.6555" , "l");
	legLeftR->AddEntry(gr_Ratio64, "v_{2}{6}/v_{2}{4} pPb" , "p");

	TLegend * legRightR = new TLegend(0.05, 0.62, 0.6, 0.82);
	legRightR->SetFillColor(kWhite);
	legRightR->SetBorderSize(0);
	legRightR->AddEntry(ffit86, "v_{2}{8}/v_{2}{6} arXiv:1312.6555" , "l");
	legRightR->AddEntry(gr_Ratio86, "v_{2}{8}/v_{2}{6} pPb" , "p");


	TCanvas * cSumR = MakeCanvas("cSumR", "cSumR", 1200, 500);
	makeMultiPanelCanvas(cSumR, 2, 1, 0., 0., 0.1, 0.18, 0.04);
	cSumR->cd(1);
	TH2D * frame_ratio64 = new TH2D("frame_ratio64", "frame_ratio64", 1, 0, 0.98, 1, 0.6, 1.3);
	InitHist(frame_ratio64, "v_{2}{4}/v_{2}{2}", "");
	frame_ratio64->Draw();
	ffit64->Draw("same");
	gr_Ratio64->Draw("psame");
	legLeftR->Draw();
	latex.DrawLatexNDC(0.15, 0.9, "(a) CMS pPb #sqrt{s_{NN}} = 5.02 TeV");

	cSumR->cd(2);
	frame_ratio64->Draw();
	ffit86->Draw("same");
	gr_Ratio86->Draw("psame");
	legRightR->Draw();
	latex.DrawLatexNDC(0.09, 0.9, "(b)");




	cSum2->SaveAs("final_v2.pdf");
	cSumR->SaveAs("final_ratio.pdf");
	cSum2->SaveAs("final_v2_C.C");
	cSumR->SaveAs("final_ratio_C.C");

}
