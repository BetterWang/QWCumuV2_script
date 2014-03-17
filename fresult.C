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

	int bShift = 0;


//	double sys6pA[7] = {0.0792, 0.1762, 0.0212, 0.0727, 0.1238, 0.0917, 0.0180};
//	double sys8pA[4] = {0.0412, 0.0411, 0.0892, 0.0184};

	double sys6pA[7] = {0.0374, 0.1168, 0.0161, 0.0150, 0.0275, 0.0165, 0.0582};
        double sys8pA[4] = {0.0619, 0.0412, 0.1014, 0.0248};

	double sys6AA[13] = {0.0184,	0.0185,	0.0197,	0.0187,	0.0185,	0.0182,	0.0192,	0.0187,	0.0181,	0.0245,	0.0148,	0.0251,	0.0321};
        double sys8AA[12] = {0.0184,	0.0186,	0.0198,	0.0186,	0.0183,	0.0183,	0.0191,	0.0189,	0.0182,	0.0235,	0.0143,	0.0573};

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
//	gStyle->SetTextFont(42);
//	gStyle->SetLegendFont(42);

	gROOT->Macro("HIN-13-002.C");
	gROOT->Macro("LYZ_pPb.C");
	gROOT->Macro("OLLITRAULT.C");


	double * Noff6 = gr_pPb_v26->GetX();
	double * Noff8 = gr_pPb_v28->GetX();
	double * Noff6PbPb = gr_PbPb_v26->GetX();
	double * Noff8PbPb = gr_PbPb_v28->GetX();

	double * v26 = gr_pPb_v26->GetY();
	double * v28 = gr_pPb_v28->GetY();
	double * v26PbPb = gr_PbPb_v26->GetY();
	double * v28PbPb = gr_PbPb_v28->GetY();

	double v26sys[20];
	double v28sys[20];
	double v26sysAA[20];
	double v28sysAA[20];

	for ( int i = 0; i < gr_pPb_v26->GetN(); i++ ) {
		v26sys[i] = v26[i]*sys6pA[i];
	}
	for ( int i = 0; i < gr_pPb_v28->GetN(); i++ ) {
		v28sys[i] = v28[i]*sys8pA[i];
	}

	for ( int i = 0; i < gr_PbPb_v26->GetN(); i++ ) {
		v26sysAA[i] = v26PbPb[i]*sys6AA[i];
	}
	for ( int i = 0; i < gr_PbPb_v28->GetN(); i++ ) {
		v28sysAA[i] = v28PbPb[i]*sys8AA[i];
	}


	TGraphErrors * gr_pPb_v26s = new TGraphErrors(gr_pPb_v26->GetN(), Noff6, v26, 0, v26sys);
	TGraphErrors * gr_pPb_v28s = new TGraphErrors(gr_pPb_v28->GetN(), Noff8, v28, 0, v28sys);
	gr_pPb_v26s->SetLineColor(gr_pPb_v26->GetLineColor());
	gr_pPb_v28s->SetLineColor(gr_pPb_v28->GetLineColor());

	TColor red(1001, 1, 0, 0, "red", 0.2);
	TColor blue(1002, 0, 1, 0, "red", 0.2);
	TColor green(1003, 0, 0, 1, "red", 0.2);
	gr_pPb_v26s->SetFillColor(1003);
	gr_pPb_v28s->SetFillColor(1001);
	grLYZpPbv2s->SetFillColor(1002);

	TGraphErrors * gr_PbPb_v26s = new TGraphErrors(gr_PbPb_v26->GetN(), Noff6PbPb, v26PbPb, 0, v26sysAA);
	TGraphErrors * gr_PbPb_v28s = new TGraphErrors(gr_PbPb_v28->GetN(), Noff8PbPb, v28PbPb, 0, v28sysAA);
	gr_PbPb_v26s->SetLineColor(gr_PbPb_v26->GetLineColor());
	gr_PbPb_v28s->SetLineColor(gr_PbPb_v28->GetLineColor());

	gr_PbPb_v26s->SetFillColor(1003);
	gr_PbPb_v28s->SetFillColor(1001);
	grLYZPbPbv2s->SetFillColor(1002);

	gr_HIN_13_002_PbPbv22->SetMarkerSize(1.5);
	gr_HIN_13_002_PbPbv24->SetMarkerSize(1.5);
	gr_HIN_13_002_pPbv22->SetMarkerSize(1.5);
	gr_HIN_13_002_pPbv24->SetMarkerSize(1.5);

	gr_PbPb_v26->SetMarkerSize(2.1);
	gr_PbPb_v28->SetMarkerSize(2.1);
	gr_pPb_v26->SetMarkerSize(2.1);
	gr_pPb_v28->SetMarkerSize(2.1);

	grLYZPbPbv2->SetMarkerSize(1.7);
	grLYZpPbv2->SetMarkerSize(1.7);

	TLegend * legLeft = new TLegend(0.35, 0.23, 0.85, 0.5);
	legLeft->SetFillColor(kWhite);
	legLeft->SetTextSize(0.04);
	legLeft->SetBorderSize(0);
	legLeft->AddEntry(gr_HIN_13_002_PbPbv22, "v_{2}{2PC} PLB 730 (2014) 243", "p");
	legLeft->AddEntry(gr_HIN_13_002_PbPbv24, "v_{2}{4} PLB 730 (2014) 243", "p");
	legLeft->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	legLeft->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	legLeft->AddEntry(grLYZpPbv2, "v_{2}{LYZ}", "p");

	TLatex latex;
	latex.SetTextFont(23);
	latex.SetTextSize(20);
	latex.SetTextAlign(13);

	if ( bShift ) {
		for ( int i = 0; i < gr_PbPb_v26->GetN(); i++ ) { gr_PbPb_v26->GetX()[i] -= 5; gr_PbPb_v26s->GetX()[i] -=5; }
		for ( int i = 0; i < gr_pPb_v26->GetN(); i++ ) { gr_pPb_v26->GetX()[i] -= 5; gr_pPb_v26s->GetX()[i] -=5; }
		for ( int i = 0; i < gr_PbPb_v28->GetN(); i++ ) { gr_PbPb_v28->GetX()[i] += 5; gr_PbPb_v28s->GetX()[i] +=5; }
		for ( int i = 0; i < gr_pPb_v28->GetN(); i++ ) { gr_pPb_v28->GetX()[i] += 5; gr_pPb_v28s->GetX()[i] +=5; }
	}

	TCanvas * cSum2 = MakeCanvas("cSum2", "cSum2", 900, 500);
	makeMultiPanelCanvas(cSum2, 2, 1, 0., 0., 0.15, 0.18, 0.02);
	cSum2->cd(1);
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_PbPbv22->Draw("Psame");
	gr_HIN_13_002_PbPbv24->Draw("Psame");
	grLYZPbPbv2s->Draw("[]3");
	gr_PbPb_v26s->Draw("[]3");
	gr_PbPb_v28s->Draw("[]3");
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
	grLYZpPbv2s->Draw("[]3");
	gr_pPb_v26s->Draw("[]3");
	gr_pPb_v28s->Draw("[]3");
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
	legLeftR->SetTextSize(0.038);

	TLegend * legRightR = new TLegend(0.32, 0.25, 0.9, 0.4);
	legRightR->SetFillColor(kWhite);
	legRightR->SetBorderSize(0);
	legRightR->AddEntry(ffit86, "v_{2}{8}/v_{2}{6} arXiv:1312.6555" , "l");
	legRightR->AddEntry(gr_Ratio86, "v_{2}{8}/v_{2}{6} pPb" , "p");
	legRightR->SetTextSize(0.038);


	TCanvas * cSumR = MakeCanvas("cSumR", "cSumR", 900, 500);
	makeMultiPanelCanvas(cSumR, 2, 1, 0., 0., 0.14, 0.18, 0.04);
	cSumR->cd(1);
	TH2D * frame_ratio64 = new TH2D("frame_ratio64", "frame_ratio64", 1, 0.41, 0.98, 1, 0.7, 1.3);
	InitHist(frame_ratio64, "v_{2}{4}/v_{2}{2}", "Ratio");
	frame_ratio64->Draw();
	ffit64->Draw("same");
	gr_Ratio64->Draw("psame");
	legLeftR->Draw();
	latex.DrawLatexNDC(0.18, 0.92, "(a)");

	cSumR->cd(2);
	frame_ratio64->Draw();
	ffit86->Draw("same");
	gr_Ratio86->Draw("psame");
	legRightR->Draw();
	latex.DrawLatexNDC(0.05, 0.92, "(b) CMS");
	latex.DrawLatexNDC(0.05, 0.85, "    pPb #sqrt{s_{NN}} = 5.02 TeV");

	TCanvas * cC26pPb = MakeCanvas("cC26pPb", "cC26pPb");
	TCanvas * cC28pPb = MakeCanvas("cC28pPb", "cC28pPb");
	TCanvas * cC26PbPb = MakeCanvas("cC26PbPb", "cC26PbPb");
	TCanvas * cC28PbPb = MakeCanvas("cC28PbPb", "cC28PbPb");

	TH2D * frame_c26pPb = new TH2D("frame_c26pPb", "frame_c26pPb", 1, -5, 350, 1, 1e-10, 0.1e-6);
	TH2D * frame_c28pPb = new TH2D("frame_c28pPb", "frame_c28pPb", 1, -5, 350, 1, -5e-9, -1.e-12);
	TH2D * frame_c26PbPb = new TH2D("frame_c26PbPb", "frame_c26PbPb", 1, -5, 350, 1, 1e-8, 2e-6);
	TH2D * frame_c28PbPb = new TH2D("frame_c28PbPb", "frame_c28PbPb", 1, -5, 350, 1, -1e-7, -1e-10);
	InitHist(frame_c26pPb, "N_{trk}^{offline}", "c_{2}{6}");
	InitHist(frame_c28pPb, "N_{trk}^{offline}", "c_{2}{8}");
	InitHist(frame_c26PbPb, "N_{trk}^{offline}", "c_{2}{6}");
	InitHist(frame_c28PbPb, "N_{trk}^{offline}", "c_{2}{8}");
	
	cC26pPb->SetBottomMargin(0.2);
	cC26pPb->SetLeftMargin(0.2);
	cC28pPb->SetBottomMargin(0.2);
	cC28pPb->SetLeftMargin(0.2);

	cC26PbPb->SetBottomMargin(0.2);
	cC26PbPb->SetLeftMargin(0.2);
	cC28PbPb->SetBottomMargin(0.2);
	cC28PbPb->SetLeftMargin(0.2);

	frame_c26pPb->GetXaxis()->SetTitleSize(0.065);
//	frame_c26pPb->GetXaxis()->SetLabelSize(0.065);
	frame_c26pPb->GetYaxis()->SetTitleSize(0.065);
//	frame_c26pPb->GetYaxis()->SetLabelSize(0.065);
	frame_c26pPb->GetYaxis()->SetTitleOffset(1.3);
	frame_c26pPb->SetLineWidth(5);
	frame_c28pPb->GetXaxis()->SetTitleSize(0.065);
//	frame_c28pPb->GetXaxis()->SetLabelSize(0.065);
	frame_c28pPb->GetYaxis()->SetTitleSize(0.065);
//	frame_c28pPb->GetYaxis()->SetLabelSize(0.065);
	frame_c28pPb->GetYaxis()->SetTitleOffset(1.3);
	frame_c28pPb->SetLineWidth(5);

	frame_c26PbPb->GetXaxis()->SetTitleSize(0.065);
//	frame_c26PbPb->GetXaxis()->SetLabelSize(0.065);
	frame_c26PbPb->GetYaxis()->SetTitleSize(0.065);
//	frame_c26PbPb->GetYaxis()->SetLabelSize(0.065);
	frame_c26PbPb->GetYaxis()->SetTitleOffset(1.3);
	frame_c26PbPb->SetLineWidth(5);
	frame_c28PbPb->GetXaxis()->SetTitleSize(0.065);
//	frame_c28PbPb->GetXaxis()->SetLabelSize(0.065);
	frame_c28PbPb->GetYaxis()->SetTitleSize(0.065);
//	frame_c28PbPb->GetYaxis()->SetLabelSize(0.065);
	frame_c28PbPb->GetYaxis()->SetTitleOffset(1.3);
	frame_c28PbPb->SetLineWidth(5);

	gr_pPb_c26->SetMarkerSize(3.5);
	gr_pPb_c28->SetMarkerSize(3.5);
	gr_PbPb_c26->SetMarkerSize(3.5);
	gr_PbPb_c28->SetMarkerSize(3.5);

	cC26pPb->cd();
	frame_c26pPb->Draw();
	gr_pPb_c26->SetLineColor(kBlack);
	gr_pPb_c26->Draw("psame");
	TLegend * legC6pPb = new TLegend(0.6, 0.8, 0.9, 0.9);
	legC6pPb->SetFillColor(kWhite);
	legC6pPb->SetBorderSize(0);
	legC6pPb->SetTextSize(0.05);
	legC6pPb->AddEntry(gr_pPb_c26, "pPb c_{2}{6}", "p");
	legC6pPb->SetTextSize(0.058);
	legC6pPb->Draw();


	cC28pPb->cd();
	frame_c28pPb->Draw();
	gr_pPb_c28->SetLineColor(kBlack);
	gr_pPb_c28->Draw("psame");
	TLegend * legC8pPb = new TLegend(0.5, 0.25, 0.9, 0.3);
	legC8pPb->SetFillColor(kWhite);
	legC8pPb->SetBorderSize(0);
	legC8pPb->SetTextSize(0.05);
	legC8pPb->AddEntry(gr_pPb_c28, "pPb c_{2}{8}", "p");
	legC8pPb->SetTextSize(0.058);
	legC8pPb->Draw();

	cC26PbPb->cd();
	frame_c26PbPb->Draw();
	gr_PbPb_c26->SetLineColor(kBlack);
	gr_PbPb_c26->Draw("psame");
	TLegend * legC6PbPb = new TLegend(0.6, 0.8, 0.9, 0.9);
	legC6PbPb->SetFillColor(kWhite);
	legC6PbPb->SetBorderSize(0);
	legC6PbPb->SetTextSize(0.05);
	legC6PbPb->AddEntry(gr_PbPb_c26, "PbPb c_{2}{6}", "p");
	legC6PbPb->SetTextSize(0.058);
	legC6PbPb->Draw();


	cC28PbPb->cd();
	frame_c28PbPb->Draw();
	gr_PbPb_c28->SetLineColor(kBlack);
	gr_PbPb_c28->Draw("psame");
	TLegend * legC8PbPb = new TLegend(0.5, 0.25, 0.9, 0.3);
	legC8PbPb->SetFillColor(kWhite);
	legC8PbPb->SetBorderSize(0);
	legC8PbPb->SetTextSize(0.05);
	legC8PbPb->AddEntry(gr_PbPb_c28, "PbPb c_{2}{8}", "p");
	legC8PbPb->SetTextSize(0.058);
	legC8PbPb->Draw();


	cSum2->SaveAs("final_v2.pdf");
	cSumR->SaveAs("final_ratio.pdf");
	cSum2->SaveAs("final_v2_C.C");
	cSumR->SaveAs("final_ratio_C.C");

	cC26pPb->SaveAs("final_pPb_c26.pdf");
	cC28pPb->SaveAs("final_pPb_c28.pdf");
	cC26PbPb->SaveAs("final_PbPb_c26.pdf");
	cC28PbPb->SaveAs("final_PbPb_c28.pdf");

}
