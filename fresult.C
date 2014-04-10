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

//	double sys6pA[7] = {0.0374, 0.1168, 0.0161, 0.0150, 0.0275, 0.0165, 0.0582};
	double sys6pA[7] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
//	double sys8pA[4] = {0.0619, 0.0412, 0.1014, 0.0248};
        double sys8pA[4] = {0.06, 0.06, 0.06, 0.06};

	double sys6AA[13] = {0.0184,	0.0185,	0.0197,	0.0187,	0.0185,	0.0182,	0.0192,	0.0187,	0.0181,	0.0245,	0.0148,	0.0251,	0.0321};
        double sys8AA[12] = {0.0184,	0.0186,	0.0198,	0.0186,	0.0183,	0.0183,	0.0191,	0.0189,	0.0182,	0.0235,	0.0143,	0.0573};


	double xe6pA[7] = {0.021, 0.013, 0.006, 0.004, 0.004, 0.006, 0.025};
	double xe8pA[4] = {0.004, 0.004, 0.006, 0.025};

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
	TGraphErrors * gr_Ratio64s = gr_Ratio64->Clone("gr_Ratio64s");
	TGraphErrors * gr_Ratio86 = (TGraphErrors*) f1->Get("gr_Ratio86");
	TGraphErrors * gr_Ratio86s = gr_Ratio86->Clone("gr_Ratio86s");
	TGraphErrors * gr_AARatio64 = (TGraphErrors*) f2->Get("gr_Ratio64");
	TGraphErrors * gr_AARatio64s = gr_AARatio64->Clone("gr_AARatio64s");
	TGraphErrors * gr_AARatio86 = (TGraphErrors*) f2->Get("gr_Ratio86");
	TGraphErrors * gr_AARatio86s = gr_AARatio86->Clone("gr_AARatio86s");

	for ( int i = 0; i < gr_Ratio64->GetN(); i++ ) {
		gr_Ratio64->GetEX()[i] = xe6pA[i];
	}
	for ( int i = 0; i < gr_Ratio86->GetN(); i++ ) {
		gr_Ratio86->GetEX()[i] = xe8pA[i];
	}

#include "../../style.h"
	SetStyle();
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
//	gStyle->SetLegendFont(42);
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

	cout << "!! Ratio 64 !!" << endl; 
	for ( int i = 0; i < gr_pPb_v26->GetN(); i++ ) {
		double sys = 99999.;
		double v24 = 99999.;
		double v24e = 99999.;
		for ( int idx = 0; idx < gr_HIN_13_002_pPbv24->GetN(); idx++ ) {
			if ( fabs(gr_pPb_v26->GetX()[i] - gr_HIN_13_002_pPbv24s->GetX()[idx]) < 5 ) {
				sys = gr_HIN_13_002_pPbv24s->GetEY()[idx];
				v24 = gr_HIN_13_002_pPbv24s->GetY()[idx];
				v24e = gr_HIN_13_002_pPbv24->GetEY()[idx];
				break;
			}
		}
		gr_Ratio64s->GetEY()[i] = gr_Ratio64s->GetY()[i] * sqrt(sys*sys/v24/v24 + v26sys[i]*v26sys[i]/gr_pPb_v26->GetY()[i]/gr_pPb_v26->GetY()[i]);
		cout <<gr_Ratio64s->GetX()[i] << "\t" << gr_pPb_v26->GetX()[i] << "\t" << gr_pPb_v26->GetY()[i] << "\\pm" << gr_pPb_v26->GetEY()[i] << "\t" << v24 << "\\pm" << v24e << "\t" << gr_Ratio64->GetY()[i] <<"\\pm"<< gr_Ratio64->GetEY()[i] << endl;
	}

	for ( int i = 0; i < gr_PbPb_v26->GetN(); i++ ) {
		double sys = 99999.;
		double v24 = 99999.;
		for ( int idx = 0; idx < gr_HIN_13_002_PbPbv24->GetN(); idx++ ) {
			if ( fabs(gr_PbPb_v26->GetX()[i] - gr_HIN_13_002_PbPbv24s->GetX()[idx]) < 4 ) {
				sys = gr_HIN_13_002_PbPbv24s->GetEY()[idx];
				v24 = gr_HIN_13_002_PbPbv24s->GetY()[idx];
				break;
			}
		}
		gr_AARatio64s->GetEY()[i] = gr_AARatio64s->GetY()[i] * sqrt(sys*sys/v24/v24 + v26sysAA[i]*v26sysAA[i]/gr_PbPb_v26->GetY()[i]/gr_PbPb_v26->GetY()[i]);
	}


	cout << "!! Ratio 86 !!" << endl; 
	for ( int i = 0; i < gr_pPb_v28->GetN(); i++ ) {
		double sys = 99999.;
		double y6 = 99999.;
		double y6e = 99999.;
		for ( int idx = 0; idx < gr_pPb_v26->GetN(); idx++ ) {
			if ( fabs(gr_pPb_v28->GetX()[i] - gr_pPb_v26->GetX()[idx]) < 5 ) {
				sys = v26sys[idx];
				y6 = gr_pPb_v26->GetY()[idx];
				y6e = gr_pPb_v26->GetEY()[idx];
				break;
			}
		}
		gr_Ratio86s->GetEY()[i] = gr_Ratio86s->GetY()[i] * sqrt(sys*sys/y6/y6 + v28sys[i]*v28sys[i]/gr_pPb_v28->GetY()[i]/gr_pPb_v28->GetY()[i]);
		cout << gr_pPb_v28->GetX()[i] << "\t" << gr_pPb_v28->GetY()[i] << "\\pm" << gr_pPb_v28->GetEY()[i] << "\t" << y6 << "\\pm" << y6e << "\t" << gr_Ratio86->GetY()[i] <<"\\pm"<< gr_Ratio86->GetEY()[i] << endl;
	}

	for ( int i = 0; i < gr_PbPb_v28->GetN(); i++ ) {
		double sys = 99999.;
		double y6 = 99999.;
		for ( int idx = 0; idx < gr_PbPb_v26->GetN(); idx++ ) {
			if ( fabs(gr_PbPb_v28->GetX()[i] - gr_PbPb_v26->GetX()[idx]) < 4 ) {
				sys = v26sysAA[idx];
				y6 = gr_PbPb_v26->GetY()[idx];
				break;
			}
		}
		gr_AARatio86s->GetEY()[i] = gr_AARatio86s->GetY()[i] * sqrt(sys*sys/y6/y6 + v28sysAA[i]*v28sysAA[i]/gr_PbPb_v28->GetY()[i]/gr_PbPb_v28->GetY()[i]);
	}


	// sort ratio
	for ( int i = 0; i < gr_Ratio64s->GetN(); i++ ) {
		for ( int j = i+1; j < gr_Ratio64s->GetN(); j++ ) {
			if (gr_Ratio64s->GetX()[i]> gr_Ratio64s->GetX()[j]) {
				double t = gr_Ratio64s->GetX()[i];
				gr_Ratio64s->GetX()[i] = gr_Ratio64s->GetX()[j];
				gr_Ratio64s->GetX()[j] = t;
				t = gr_Ratio64s->GetY()[i];
				gr_Ratio64s->GetY()[i] = gr_Ratio64s->GetY()[j];
				gr_Ratio64s->GetY()[j] = t;
				t = gr_Ratio64s->GetEY()[i];
				gr_Ratio64s->GetEY()[i] = gr_Ratio64s->GetEY()[j];
				gr_Ratio64s->GetEY()[j] = t;
			}
		}
	}
	for ( int i = 0; i < gr_AARatio64s->GetN(); i++ ) {
		for ( int j = i+1; j < gr_AARatio64s->GetN(); j++ ) {
			if (gr_AARatio64s->GetX()[i]> gr_AARatio64s->GetX()[j]) {
				double t = gr_AARatio64s->GetX()[i];
				gr_AARatio64s->GetX()[i] = gr_AARatio64s->GetX()[j];
				gr_AARatio64s->GetX()[j] = t;
				t = gr_AARatio64s->GetY()[i];
				gr_AARatio64s->GetY()[i] = gr_AARatio64s->GetY()[j];
				gr_AARatio64s->GetY()[j] = t;
				t = gr_AARatio64s->GetEY()[i];
				gr_AARatio64s->GetEY()[i] = gr_AARatio64s->GetEY()[j];
				gr_AARatio64s->GetEY()[j] = t;
			}
		}
	}


	for ( int i = 0; i < gr_Ratio86s->GetN(); i++ ) {
		for ( int j = i+1; j < gr_Ratio86s->GetN(); j++ ) {
			if (gr_Ratio86s->GetX()[i]> gr_Ratio86s->GetX()[j]) {
				double t = gr_Ratio86s->GetX()[i];
				gr_Ratio86s->GetX()[i] = gr_Ratio86s->GetX()[j];
				gr_Ratio86s->GetX()[j] = t;
				t = gr_Ratio86s->GetY()[i];
				gr_Ratio86s->GetY()[i] = gr_Ratio86s->GetY()[j];
				gr_Ratio86s->GetY()[j] = t;
				t = gr_Ratio86s->GetEY()[i];
				gr_Ratio86s->GetEY()[i] = gr_Ratio86s->GetEY()[j];
				gr_Ratio86s->GetEY()[j] = t;
			}
		}
	}
	for ( int i = 0; i < gr_AARatio86s->GetN(); i++ ) {
		for ( int j = i+1; j < gr_AARatio86s->GetN(); j++ ) {
			if (gr_AARatio86s->GetX()[i]> gr_AARatio86s->GetX()[j]) {
				double t = gr_AARatio86s->GetX()[i];
				gr_AARatio86s->GetX()[i] = gr_AARatio86s->GetX()[j];
				gr_AARatio86s->GetX()[j] = t;
				t = gr_AARatio86s->GetY()[i];
				gr_AARatio86s->GetY()[i] = gr_AARatio86s->GetY()[j];
				gr_AARatio86s->GetY()[j] = t;
				t = gr_AARatio86s->GetEY()[i];
				gr_AARatio86s->GetEY()[i] = gr_AARatio86s->GetEY()[j];
				gr_AARatio86s->GetEY()[j] = t;
			}
		}
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

	gr_Ratio64s->SetFillColor(1003);
	gr_Ratio86s->SetFillColor(1001);
	gr_AARatio64s->SetFillColor(1003);
	gr_AARatio86s->SetFillColor(1001);

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

	gr_PbPb_v26->SetMarkerSize(2.2);
	gr_PbPb_v28->SetMarkerSize(2.0);
	gr_pPb_v26->SetMarkerSize(2.2);
	gr_pPb_v28->SetMarkerSize(2.0);

	gr_PbPb_v26->SetMarkerStyle(kFullCross);
	gr_pPb_v26->SetMarkerStyle(kFullCross);

	grLYZPbPbv2->SetMarkerSize(1.7);
	grLYZpPbv2->SetMarkerSize(1.7);

	TLegend * legLeft = new TLegend(0.55, 0.23, 0.95, 0.53);
	legLeft->SetFillColor(kWhite);
	legLeft->SetTextFont(42);
	legLeft->SetTextSize(0.05);
	legLeft->SetBorderSize(0);
	legLeft->AddEntry(gr_HIN_13_002_PbPbv22, "v_{2}{2, |#Delta#eta|>2}", "p");
	legLeft->AddEntry(gr_HIN_13_002_PbPbv24, "v_{2}{4}", "p");
	legLeft->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	legLeft->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	legLeft->AddEntry(grLYZpPbv2, "v_{2}{LYZ}", "p");

	TLatex latex;
	latex.SetTextFont(43);
	latex.SetTextSize(20);
	latex.SetTextAlign(13);

	if ( bShift ) {
		for ( int i = 0; i < gr_PbPb_v26->GetN(); i++ ) { gr_PbPb_v26->GetX()[i] -= 5; gr_PbPb_v26s->GetX()[i] -=5; }
		for ( int i = 0; i < gr_pPb_v26->GetN(); i++ ) { gr_pPb_v26->GetX()[i] -= 5; gr_pPb_v26s->GetX()[i] -=5; }
		for ( int i = 0; i < gr_PbPb_v28->GetN(); i++ ) { gr_PbPb_v28->GetX()[i] += 5; gr_PbPb_v28s->GetX()[i] +=5; }
		for ( int i = 0; i < gr_pPb_v28->GetN(); i++ ) { gr_pPb_v28->GetX()[i] += 5; gr_pPb_v28s->GetX()[i] +=5; }
	}

	TCanvas * cSum2 = MakeCanvas("cSum2", "cSum2", 900, 500);
	makeMultiPanelCanvas(cSum2, 2, 1, 0.0, 0., 0.15, 0.15, 0.01);
	cSum2->cd(1);
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->GetYaxis()->SetTitleOffset(1.3);
	frame_cent->GetXaxis()->SetTitleOffset(1.1);
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
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3 GeV/c; |#eta| < 2.4}");

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
	latex.DrawLatexNDC(0.1, 0.94, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV}{0.3 < p_{T} < 3 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.5, 0.27, "CMS Preliminary");


	gr_Ratio64->SetMarkerStyle(kFullSquare);
	gr_Ratio64->SetMarkerSize(1.7);
	gr_Ratio86->SetMarkerStyle(kFullCircle);
	gr_Ratio86->SetMarkerSize(1.7);

	gr_Ratio64s->SetMarkerStyle(kFullSquare);
	gr_Ratio64s->SetMarkerSize(1.7);
	gr_Ratio86s->SetMarkerStyle(kFullCircle);
	gr_Ratio86s->SetMarkerSize(1.7);

	gr_AARatio64->SetMarkerStyle(kFullSquare);
	gr_AARatio64->SetMarkerSize(1.7);
	gr_AARatio86->SetMarkerStyle(kFullCircle);
	gr_AARatio86->SetMarkerSize(1.7);

//	TLegend * legLeftR = new TLegend(0.40, 0.05, 0.95, 0.22);
	TLegend * legLeftR = new TLegend(0.30, 0.15, 0.85, 0.3);
	legLeftR->SetFillColor(kWhite);
	legLeftR->SetBorderSize(0);
	legLeftR->AddEntry(ffit64, "hydro Yan" , "l");
//	legLeftR->AddEntry(gr_Ratio64, "data" , "p");
	legLeftR->SetTextFont(43);
	legLeftR->SetTextSize(24);

	TLegend * legRightR = new TLegend(0.35, 0.2, 0.95, 0.3);
	legRightR->SetFillColor(kWhite);
	legRightR->SetBorderSize(0);
	legRightR->AddEntry(ffit86, "hydro (Yan and Ollitrault)" , "");
//	legRightR->AddEntry(gr_Ratio86, "data" , "p");
	legRightR->SetTextFont(43);
	legRightR->SetTextSize(22);

	TLegend * legLeftAAR = new TLegend(0.40, 0.15, 0.85, 0.35);
	legLeftAAR->SetFillColor(kWhite);
	legLeftAAR->SetBorderSize(0);
	legLeftAAR->AddEntry(ffit64, "v_{2}{6}/v_{2}{4} hydro" , "l");
	legLeftAAR->AddEntry(gr_Ratio64, "v_{2}{6}/v_{2}{4}" , "p");
	legLeftAAR->SetTextSize(0.05);
	legLeftAAR->SetTextFont(42);

	TLegend * legRightAAR = new TLegend(0.40, 0.15, 0.85, 0.35);
	legRightAAR->SetFillColor(kWhite);
	legRightAAR->SetBorderSize(0);
	legRightAAR->AddEntry(ffit86, "v_{2}{8}/v_{2}{6} hydro" , "l");
	legRightAAR->AddEntry(gr_Ratio86, "v_{2}{8}/v_{2}{6}" , "p");
	legRightAAR->SetTextSize(0.05);
	legRightAAR->SetTextFont(42);



	TCanvas * cSumR = MakeCanvas("cSumR", "cSumR", 500, 900);
	makeMultiPanelCanvas(cSumR, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumR->cd(1);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio64 = new TH2D("frame_ratio64", "frame_ratio64", 1, 0.621, 0.799, 1, 0.7, 1.3);
	InitHist(frame_ratio64, "v_{2}{4} / v_{2}{2}", "v_{2}{6} / v_{2}{4}");
	frame_ratio64->GetXaxis()->SetTitleOffset(0.93);
	frame_ratio64->GetYaxis()->SetTitleOffset(1.1);
	frame_ratio64->Draw();
	ffit64->Draw("same");
	gr_Ratio64s->Draw("[]3");
	gr_Ratio64->Draw("psame");
//	legLeftR->Draw();
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV}{0.3 < p_{T} < 3 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");
//	latex.DrawLatexNDC(0.18, 0.92, "(a)");

	cSumR->cd(2);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio86 = frame_ratio64->Clone("frame_ratio86");
	frame_ratio86->SetYTitle("v_{2}{8} / v_{2}{6}");
	frame_ratio86->Draw();
	ffit86->Draw("same");
	gr_Ratio86s->Draw("[]3");
	gr_Ratio86->Draw("psame");
//	legLeftR->Draw();
	legRightR->Draw();
//	latex.DrawLatexNDC(0.05, 0.92, "(b) CMS Preliminary");
//	latex.DrawLatexNDC(0.05, 0.85, "    pPb #sqrt{s_{NN}} = 5.02 TeV");
//	latex.DrawLatexNDC(0.05, 0.92, "(b)");
//	latex.DrawLatexNDC(0.1, 0.36, "pPb #sqrt{s_{NN}} = 5.02 TeV");
//	latex.DrawLatexNDC(0.2, 0.9, "CMS Preliminary");

	TLine *lr = new TLine();
	lr->SetLineColor(kRed);
	lr->SetLineWidth(2);
	TLine *lb = lr->Clone();
	lb->SetLineColor(kBlue);

	lr->DrawLineNDC(0.38, 0.225, 0.47, 0.225);
	lb->DrawLineNDC(0.38, 0.25, 0.47, 0.25);

	TCanvas * cSumAAR = MakeCanvas("cSumAAR", "cSumAAR", 900, 500);
	makeMultiPanelCanvas(cSumAAR, 2, 1, 0., 0., 0.12, 0.12, 0.01);
	TH2D * frame_AAratio64 = new TH2D("frame_AAratio64", "frame_AAratio64", 1, 0.801, 0.849, 1, 0.751, 1.399);
	InitHist(frame_AAratio64, "v_{2}{4} / v_{2}{2}", "Ratio");
	frame_AAratio64->GetXaxis()->SetTitleOffset(0.93);
	frame_AAratio64->GetYaxis()->SetTitleOffset(0.97);
	cSumAAR->cd(1);
	frame_AAratio64->Draw();
	ffit64->Draw("same");
	gr_AARatio64s->Draw("[]3");
	gr_AARatio64->Draw("psame");
	legLeftAAR->Draw();
//	latex.DrawLatexNDC(0.18, 0.92, "(a)");
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{CMS PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3 GeV/c; |#eta| < 2.4}");

	cSumAAR->cd(2);
	frame_AAratio64->Draw();
	ffit86->Draw("same");
	gr_AARatio86s->Draw("[]3");
	gr_AARatio86->Draw("psame");
	legRightAAR->Draw();
//	latex.DrawLatexNDC(0.05, 0.92, "(b) CMS Preliminary");
//	latex.DrawLatexNDC(0.05, 0.85, "    PbPb #sqrt{s_{NN}} = 2.76 TeV");
	latex.DrawLatexNDC(0.12, 0.9, "CMS Preliminary");



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
	
	cC26pPb->SetTopMargin(0.1);
	cC26pPb->SetBottomMargin(0.23);
	cC26pPb->SetLeftMargin(0.25);
	cC28pPb->SetTopMargin(0.1);
	cC28pPb->SetBottomMargin(0.23);
	cC28pPb->SetLeftMargin(0.25);

	cC26PbPb->SetTopMargin(0.1);
	cC26PbPb->SetBottomMargin(0.23);
	cC26PbPb->SetLeftMargin(0.25);
	cC28PbPb->SetTopMargin(0.1);
	cC28PbPb->SetBottomMargin(0.23);
	cC28PbPb->SetLeftMargin(0.25);


	frame_c26pPb->GetXaxis()->SetTitleSize(0.07);
	frame_c26pPb->GetXaxis()->SetLabelSize(0.065);
	frame_c26pPb->GetYaxis()->SetTitleSize(0.07);
	frame_c26pPb->GetYaxis()->SetLabelSize(0.065);
	frame_c26pPb->GetXaxis()->SetTitleOffset(1.5);
	frame_c26pPb->GetYaxis()->SetTitleOffset(1.5);
	frame_c26pPb->SetLineWidth(5);

	frame_c28pPb->GetXaxis()->SetTitleSize(0.07);
	frame_c28pPb->GetXaxis()->SetLabelSize(0.065);
	frame_c28pPb->GetYaxis()->SetTitleSize(0.07);
	frame_c28pPb->GetYaxis()->SetLabelSize(0.065);
	frame_c28pPb->GetXaxis()->SetTitleOffset(1.5);
	frame_c28pPb->GetYaxis()->SetTitleOffset(1.5);
	frame_c28pPb->SetLineWidth(5);

	frame_c26PbPb->GetXaxis()->SetTitleSize(0.07);
	frame_c26PbPb->GetXaxis()->SetLabelSize(0.065);
	frame_c26PbPb->GetYaxis()->SetTitleSize(0.07);
	frame_c26PbPb->GetYaxis()->SetLabelSize(0.065);
	frame_c26PbPb->GetXaxis()->SetTitleOffset(1.5);
	frame_c26PbPb->GetYaxis()->SetTitleOffset(1.5);
	frame_c26PbPb->SetLineWidth(5);

	frame_c28PbPb->GetXaxis()->SetTitleSize(0.07);
	frame_c28PbPb->GetXaxis()->SetLabelSize(0.065);
	frame_c28PbPb->GetYaxis()->SetTitleSize(0.07);
	frame_c28PbPb->GetYaxis()->SetLabelSize(0.065);
	frame_c28PbPb->GetXaxis()->SetTitleOffset(1.5);
	frame_c28PbPb->GetYaxis()->SetTitleOffset(1.5);
	frame_c28PbPb->SetLineWidth(5);



	gr_pPb_c26->SetMarkerSize(3.5);
	gr_pPb_c28->SetMarkerSize(3.5);
	gr_PbPb_c26->SetMarkerSize(3.5);
	gr_PbPb_c28->SetMarkerSize(3.5);

	cC26pPb->cd();
	frame_c26pPb->Draw();
	gr_pPb_c26->SetLineColor(kBlack);
	gr_pPb_c26->Draw("psame");
	TLegend * legC6pPb = new TLegend(0.6, 0.8, 0.9, 0.88);
	legC6pPb->SetFillColor(kWhite);
	legC6pPb->SetBorderSize(0);
	legC6pPb->SetTextSize(0.05);
	legC6pPb->AddEntry(gr_pPb_c26, "pPb c_{2}{6}", "p");
	legC6pPb->SetTextSize(0.058);
	legC6pPb->Draw();
	latex->DrawLatexNDC(0.3, 0.86, "CMS Preliminary");


	cC28pPb->cd();
	frame_c28pPb->Draw();
	gr_pPb_c28->SetLineColor(kBlack);
	gr_pPb_c28->Draw("psame");
	TLegend * legC8pPb = new TLegend(0.5, 0.28, 0.9, 0.3);
	legC8pPb->SetFillColor(kWhite);
	legC8pPb->SetBorderSize(0);
	legC8pPb->SetTextSize(0.05);
	legC8pPb->AddEntry(gr_pPb_c28, "pPb c_{2}{8}", "p");
	legC8pPb->SetTextSize(0.058);
	legC8pPb->Draw();
	latex->DrawLatexNDC(0.56, 0.4, "CMS Preliminary");

	cC26PbPb->cd();
	frame_c26PbPb->Draw();
	gr_PbPb_c26->SetLineColor(kBlack);
	gr_PbPb_c26->Draw("psame");
	TLegend * legC6PbPb = new TLegend(0.6, 0.8, 0.9, 0.88);
	legC6PbPb->SetFillColor(kWhite);
	legC6PbPb->SetBorderSize(0);
	legC6PbPb->SetTextSize(0.05);
	legC6PbPb->AddEntry(gr_PbPb_c26, "PbPb c_{2}{6}", "p");
	legC6PbPb->SetTextSize(0.058);
	legC6PbPb->Draw();
	latex->DrawLatexNDC(0.3, 0.86, "CMS Preliminary");


	cC28PbPb->cd();
	frame_c28PbPb->Draw();
	gr_PbPb_c28->SetLineColor(kBlack);
	gr_PbPb_c28->Draw("psame");
	TLegend * legC8PbPb = new TLegend(0.5, 0.28, 0.9, 0.3);
	legC8PbPb->SetFillColor(kWhite);
	legC8PbPb->SetBorderSize(0);
	legC8PbPb->SetTextSize(0.05);
	legC8PbPb->AddEntry(gr_PbPb_c28, "PbPb c_{2}{8}", "p");
	legC8PbPb->SetTextSize(0.058);
	legC8PbPb->Draw();
	latex->DrawLatexNDC(0.56, 0.4, "CMS Preliminary");


	cSum2->SaveAs("final_v2.pdf");
	cSumR->SaveAs("final_ratio.pdf");
	cSumAAR->SaveAs("final_ratioAA.pdf");
	cSum2->SaveAs("final_v2_C.C");
	cSumR->SaveAs("final_ratio_C.C");
	cSumAAR->SaveAs("final_ratioAA_C.C");

	cC26pPb->SaveAs("final_pPb_c26.pdf");
	cC28pPb->SaveAs("final_pPb_c28.pdf");
	cC26PbPb->SaveAs("final_PbPb_c26.pdf");
	cC28PbPb->SaveAs("final_PbPb_c28.pdf");

}
