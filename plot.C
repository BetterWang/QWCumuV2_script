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
	int s3 = 20;
	int sN = 3;
	int save = 1;
	int bFin = 0;

	int bPbPb = 1;
	if ( s1 == 1  ) {s2 = 25; bPbPb = 0;} // pPb
	if ( s1 == 3  ) {s2 = 27; bPbPb = 0;} // Pbp
	if ( s1 == 10 ) {s2 = 28; bPbPb = 0;} // pPb+Pbp
	if ( s1 == 33 ) {s2 = 33; bPbPb = 1;} // PbPb
	if ( s1 == 34 ) {s2 = 34; bPbPb = 0;} // Hijing non-flow
	if ( s1 == 36 ) {s2 = 36; bPbPb = 0;} // Hijing v2=0.05, fv2=0.01
	if ( s1 == 37 ) {s2 = 37; bPbPb = 0;} // Hijing v2=0.05, fv2=0.01, non-flow
	if ( s1 == 38 ) {s2 = 38; bPbPb = 0;} // Hijing v2=0.05, fv2=0.00
	if ( s1 == 39 ) {s2 = 39; bPbPb = 0;} // Hijing v2=0.05, fv2=0.01 double stat
	if ( s1 == 44 ) {s2 = 44; bPbPb = 0;} // Hijing v2=0
	if ( s1 == 48 ) {s2 = 28; bPbPb = 0;} // pPb sysHLT
	if ( s1 == 52 ) {s2 = 56; bPbPb = 0;} // pPb sysTrkLoose
	if ( s1 == 60 ) {s2 = 64; bPbPb = 0;} // pPb sysTrkTight
	if ( s1 == 68 ) {s2 = 72; bPbPb = 0;} // pPb sysTrkPU
	if ( s1 == 76 ) {s2 = 80; bPbPb = 0;} // pPb sysVtx0  ! v26 one bin down
	if ( s1 == 84 ) {s2 = 88; bPbPb = 0;} // pPb sysVtx1  !!! MB
	if ( s1 == 92 ) {s2 = 96; bPbPb = 0;} // pPb sysEff  ??
	if ( s1 == 97 ) {s2 = 97; bPbPb = 1;} // PbPb sysPU
	if ( s1 == 98 ) {s2 = 98; bPbPb = 1;} // PbPb sysTrkLoose
	if ( s1 == 99 ) {s2 = 99; bPbPb = 1;} // PbPb sysTrkTight
	if ( s1 == 100 ) {s2 = 100; bPbPb = 1;} // PbPb sysVtx0
	if ( s1 == 101 ) {s2 = 101; bPbPb = 1;} // PbPb sysVtx1
	if ( s1 == 102 ) {s2 = 102; bPbPb = 1;} // PbPb sysEff

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
	if ( s1==10 && bFin ) {
		lim6U = 0.1e-6;
		lim8L = -5e-9;
		lim8U = 0;
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
	if ( s1==44) {
		lim2L = -5e-4;
		lim2U = 5e-4;
		lim4L = -1e-6;
		lim4U =  1e-6;
		lim6L = -2e-8;
		lim6U =  2e-8;
		lim8L = -5e-10;
		lim8U =  5e-10;
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
	int blimit04 = 1;
	int blimit06 = 1;
	int blimit08 = 1;
	if ( bPbPb ) {
		blimit4 = 16;
		blimit6 = 14;
		blimit8 = 13;
	}
	if ( s1 == 39 || s1 == 34 || s1 == 44 ) {
		blimit4 = 12;
		blimit6 = 12;
		blimit8 = 12;

		blimit04 = 6;
		blimit06 = 6;
		blimit08 = 6;
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

	TBox * boxNSigma = new TBox(-5, -2, 350, 2);
	TColor * clNSigma = new TColor(1001, 0, 0, 0, "shade",.3);
	clNSigma->SetGrayscale();
	boxNSigma->SetFillColor(1001);
//	grNSigma2->Draw("Psame");
	grNSigma4->Draw("Psame");
	grNSigma6->Draw("Psame");
	grNSigma8->Draw("Psame");
	TLine * l1 = new TLine(-5, 2.0, 350, 2.0);
	TLine * l2 = new TLine(-5, -2.0, 350, -2.0);
	l1->SetLineColor(kRed);
	l2->SetLineColor(kRed);
	boxNSigma->Draw("same");
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
	TGraphErrors * gr_LYZ = grLYZpPbv2;
	if ( bPbPb ) {
		gr_HIN_13_002_v22 = gr_HIN_13_002_PbPbv22;
		gr_HIN_13_002_v24 = gr_HIN_13_002_PbPbv24;
		gr_LYZ = grLYZPbPbv2;
	}

	TCanvas * cSum = MakeCanvas("cSum", "cSum");
	TH2D * frame_cent = new TH2D("frame_cent", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	gr_HIN_13_002_v24->SetMarkerColor(kBlue);
	gr_HIN_13_002_v22->SetMarkerColor(kRed);

	gr_HIN_13_002_v24->Draw("Psame");
	gr_HIN_13_002_v22->Draw("Psame");

	TGraphErrors * gr_pPb_v22 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dV22+blimit04, 0, eV22+blimit04);
	TGraphErrors * gr_pPb_v24 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dV24+blimit04, 0, eV24+blimit04);
	TGraphErrors * gr_pPb_v26 = new TGraphErrors( blimit6-blimit06, dNoff6+blimit06, dV26+blimit06, 0, eV26+blimit06);
	TGraphErrors * gr_pPb_v28 = new TGraphErrors( blimit8-blimit08, dNoff8+blimit08, dV28+blimit08, 0, eV28+blimit08);

	TGraphErrors * gr_pPb_c22 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dC22+blimit04, 0, eC22+blimit04);
	TGraphErrors * gr_pPb_c24 = new TGraphErrors( blimit4-blimit04, dNoff4+blimit04, dC24+blimit04, 0, eC24+blimit04);
	TGraphErrors * gr_pPb_c26 = new TGraphErrors( blimit6-blimit06, dNoff6+blimit06, dC26+blimit06, 0, eC26+blimit06);
	TGraphErrors * gr_pPb_c28 = new TGraphErrors( blimit8-blimit08, dNoff8+blimit08, dC28+blimit08, 0, eC28+blimit08);

	if ( bPbPb == 0 ) {
		gr_pPb_v26->RemovePoint(0);
		gr_pPb_v26->RemovePoint(7);
		gr_pPb_v26->RemovePoint(7);

		gr_pPb_v28->RemovePoint(0);
		gr_pPb_v28->RemovePoint(0);
		gr_pPb_v28->RemovePoint(4);
		gr_pPb_v28->RemovePoint(4);

		if ( bFin ) {
			gr_pPb_c26->RemovePoint(0);
			gr_pPb_c26->RemovePoint(7);
			gr_pPb_c26->RemovePoint(7);

			gr_pPb_c28->RemovePoint(0);
			gr_pPb_c28->RemovePoint(0);
			gr_pPb_c28->RemovePoint(4);
			gr_pPb_c28->RemovePoint(4);
		}
	}
	gr_pPb_v22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_v24->SetMarkerStyle(kFullSquare);
	gr_pPb_v26->SetMarkerStyle(kFullStar);
	gr_pPb_v28->SetMarkerStyle(kFullDiamond);
	gr_pPb_c22->SetMarkerStyle(kOpenTriangleUp);
	gr_pPb_c24->SetMarkerStyle(kFullSquare);
	gr_pPb_c26->SetMarkerStyle(kFullStar);
	gr_pPb_c28->SetMarkerStyle(kFullDiamond);

	gr_pPb_v22->SetMarkerColor(kGreen);
	gr_pPb_v24->SetMarkerColor(kBlack);
	gr_pPb_v26->SetMarkerColor(kBlue);
	gr_pPb_v28->SetMarkerColor(kRed);
	gr_pPb_c22->SetMarkerColor(kBlack);
	gr_pPb_c24->SetMarkerColor(kBlack);
	gr_pPb_c26->SetMarkerColor(kBlue);
	gr_pPb_c28->SetMarkerColor(kRed);

	gr_pPb_v22->SetLineColor(kGreen);
	gr_pPb_v24->SetLineColor(kBlack);
	gr_pPb_v26->SetLineColor(kBlue);
	gr_pPb_v28->SetLineColor(kRed);
	gr_pPb_c22->SetLineColor(kBlack);
	gr_pPb_c24->SetLineColor(kBlack);
	gr_pPb_c26->SetLineColor(kBlue);
	gr_pPb_c28->SetLineColor(kRed);

	gr_pPb_v22->SetMarkerSize(2);
	gr_pPb_v24->SetMarkerSize(2);
	gr_pPb_v26->SetMarkerSize(2.5);
	gr_pPb_v28->SetMarkerSize(2.5);
	gr_pPb_c22->SetMarkerSize(2);
	gr_pPb_c24->SetMarkerSize(2);
	gr_pPb_c26->SetMarkerSize(2.5);
	gr_pPb_c28->SetMarkerSize(2.5);

//	gr_pPb_v22->Draw("Psame");
	if ( !bFin ) gr_pPb_v24->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");
	if ( bFin ) gr_LYZ->Draw("Psame");

	TLegend * leg = new TLegend(0.18, 0.75, 0.45, 0.9);
	leg->SetFillColor(kWhite);
	leg->SetBorderSize(0);
//	leg->AddEntry(gr_pPb_v22, "v_{2}{2}", "p");
//	leg->AddEntry(gr_HIN_13_002_v22, "v_{2}{2PC} published", "p");
//	leg->AddEntry(gr_HIN_13_002_v24, "v_{2}{4} published", "p");
	if ( !bFin ) leg->AddEntry(gr_pPb_v24, "v_{2}{4}", "p");
	leg->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	leg->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	if ( bFin ) leg->AddEntry(gr_LYZ, "v_{2}{LYZ}", "p");
	leg->Draw();

	TLine * linev2 = new TLine(0, 0.049, 300, 0.049);
	linev2->SetLineColor(kRed);
	if ( s1 == 39 ) linev2->Draw();

	TCanvas * cSumC2 = MakeCanvas("cSumC2", "cSumC2");
	TCanvas * cSumC4 = MakeCanvas("cSumC4", "cSumC4");
	TCanvas * cSumC6 = MakeCanvas("cSumC6", "cSumC6");
	TCanvas * cSumC8 = MakeCanvas("cSumC8", "cSumC8");

	cSumC2->SetGrid();
	cSumC4->SetGrid();
	if (!bFin) cSumC6->SetGrid();
	if (!bFin) cSumC8->SetGrid();

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
	if (s1 == 10) {
		if (!bFin) boxNSigma->DrawBox(-5, lim6L, 100, lim6U);
		if (!bFin) boxNSigma->DrawBox(300, lim6L, 350, lim6U);
	}
	TLegend * legC6 = new TLegend(0.65, 0.83, 0.9, 0.9);
	legC6->SetFillColor(kWhite);
	legC6->SetBorderSize(0);
	legC6->SetTextSize(0.05);
	legC6->AddEntry(gr_pPb_c26, Form("%s c_{2}{6}", bPbPb?"PbPb":"pPb"), "p");
	if ( bFin ) legC6->Draw();

	cSumC8->cd();
	frame_centC8->Draw();
	gr_pPb_c28->Draw("Psame");
	if (s1 == 10) {
		if (!bFin) boxNSigma->DrawBox(-5, lim8L, 100, lim8U);
		if (!bFin) boxNSigma->DrawBox(220, lim8L, 350, lim8U);
	}
	TLegend * legC8 = new TLegend(0.65, 0.20, 0.9, 0.3);
	legC8->SetFillColor(kWhite);
	legC8->SetBorderSize(0);
	legC8->SetTextSize(0.05);
	legC8->AddEntry(gr_pPb_c28, Form("%s c_{2}{8}", bPbPb?"PbPb":"pPb"), "p");
	if ( bFin ) legC8->Draw();


	gROOT->Macro("OLLITRAULT.C");
//	TF1 * fHIN_13_002_v24 = new TF1("fHIN_13_002_v24", "pol6", 0, 350);
//	gr_HIN_13_002_v24->Fit(fHIN_13_002_v24, "N");
//	TF1 * fHIN_13_002_v22 = new TF1("fHIN_13_002_v22", "pol6", 0, 350);
//	gr_HIN_13_002_v22->Fit(fHIN_13_002_v22, "N");

//	TF1 * fpPb_v24 = new TF1("fpPb_v24", "pol6", 0, 350);
//	TF1 * fpPb_v26 = new TF1("fpPb_v26", "pol6", 0, 350);
//	TF1 * fpPb_v28 = new TF1("fpPb_v28", "pol6", 0, 350);
//	gr_pPb_v24->Fit(fpPb_v24, "N");
//	gr_pPb_v26->Fit(fpPb_v26, "N");
//	gr_pPb_v28->Fit(fpPb_v28, "N");

	TCanvas * cRatio = MakeCanvas("cRatio", "cRatio");
	TH2D * frame_ratio = new TH2D("frame_ratio", "frame_ratio", 1, 0, 1, 1, 0.6, 1.3);
	InitHist(frame_ratio, "v_{2}{4}/v_{2}{2}", "");
	frame_ratio->Draw();
	ffit64->Draw("same");
	ffit86->Draw("same");

	double xRatio86[20];
	double dRatio86[20];
	double eRatio86[20];
	double Noff86[20];

	double dRatio84[20];
	double eRatio84[20];
	double Noff84[20];

	double xRatio64[20];
	double dRatio64[20];
	double eRatio64[20];
	double Noff64[20];

	double Noff62[20];
	double Noff82[20];
	for ( int i = 0; i < 20; i++ ) {
		xRatio86[i] = 0;
		dRatio86[i] = 0;
		eRatio86[i] = 0;
		Noff86[i] = 0;

		xRatio64[i] = 0;
		dRatio64[i] = 0;
		eRatio64[i] = 0;
		Noff64[i] = 0;

		Noff84[i] = 0;
		dRatio84[i] = 0;
		eRatio84[i] = 0;
	}

	for ( int i = 0 ; i < gr_pPb_v26->GetN(); i++ ) {
		double v24 = 0;
		double ev24 = 0;
		double noff4 = 0;
		for ( int idx = 0; idx < gr_HIN_13_002_v24->GetN(); idx++ ) {
			if ( fabs( gr_pPb_v26->GetX()[i] - gr_HIN_13_002_v24->GetX()[idx] ) < 5 ) {
				v24 = gr_HIN_13_002_v24->GetY()[idx];
				ev24 = gr_HIN_13_002_v24->GetEY()[idx];
				noff4 = gr_HIN_13_002_v24->GetX()[idx];
				break;
			}
		}
		Noff64[i] = noff4;
		double v22 = 0;
		double ev22 = 0;
		double noff2 = 0;
		for ( int idx = 0; idx < gr_HIN_13_002_v22->GetN(); idx++ ) {
			if ( fabs( gr_pPb_v26->GetX()[i] - gr_HIN_13_002_v22->GetX()[idx] ) < 5 ) {
				v22 = gr_HIN_13_002_v22->GetY()[idx];
				ev22 = gr_HIN_13_002_v22->GetEY()[idx];
				noff2 = gr_HIN_13_002_v22->GetX()[idx];
			}
		}
		Noff62[i] = noff2;

		double v26 = gr_pPb_v26->GetY()[i];
		double ev26 = gr_pPb_v26->GetEY()[i];

		xRatio64[i] = v24 / v22;
		dRatio64[i] = v26 / v24;
		eRatio64[i] = sqrt( ev26*ev26/v26/v26 + ev24*ev24/v24/v24) * dRatio64[i];
	}
	for ( int i = 0 ; i < gr_pPb_v28->GetN(); i++ ) {
		double v24 = 0;
		double ev24 = 0;
		double noff4 = 0;
		for ( int idx = 0; idx < gr_HIN_13_002_v24->GetN(); idx++ ) {
			if ( fabs( gr_pPb_v28->GetX()[i] - gr_HIN_13_002_v24->GetX()[idx] ) < 5 ) {
				v24 = gr_HIN_13_002_v24->GetY()[idx];
				ev24 = gr_HIN_13_002_v24->GetEY()[idx];
				noff4 = gr_HIN_13_002_v24->GetX()[idx];
				break;
			}
		}
		Noff84[i] = noff4;
		double v22 = 0;
		double ev22 = 0;
		double noff2 = 0;
		for ( int idx = 0; idx < gr_HIN_13_002_v22->GetN(); idx++ ) {
			if ( fabs( gr_pPb_v28->GetX()[i] - gr_HIN_13_002_v22->GetX()[idx] ) < 5 ) {
				v22 = gr_HIN_13_002_v22->GetY()[idx];
				ev22 = gr_HIN_13_002_v22->GetEY()[idx];
				noff2 = gr_HIN_13_002_v22->GetX()[idx];
			}
		}
		Noff82[i] = noff2;

		double v26 = 0;
		double ev26 = 0;
		double noff6 = 0;
		for ( int idx = 0; idx < gr_pPb_v26->GetN(); idx++ ) {
			if ( fabs( gr_pPb_v28->GetX()[i] - gr_pPb_v26->GetX()[idx] ) < 5 ) {
				v26 = gr_pPb_v26->GetY()[idx];
				ev26 = gr_pPb_v26->GetEY()[idx];
				noff6 = gr_pPb_v26->GetX()[idx];
			}
		}
		Noff86[i] = noff6;

		double v28 = gr_pPb_v28->GetY()[i];
		double ev28 = gr_pPb_v28->GetEY()[i];

		xRatio86[i] = v24 / v22;
		dRatio86[i] = v28 / v26;
		eRatio86[i] = sqrt( ev26*ev26/v26/v26 + ev28*ev28/v28/v28) * dRatio86[i];
		dRatio84[i] = v28 / v24;
		eRatio84[i] = sqrt( ev24*ev24/v24/v24 + ev28*ev28/v28/v28) * dRatio84[i];

	}
	TGraphErrors * gr_Ratio64 = new TGraphErrors(gr_pPb_v26->GetN(), xRatio64, dRatio64, 0, eRatio64);
	TGraphErrors * gr_Ratio86 = new TGraphErrors(gr_pPb_v28->GetN(), xRatio86, dRatio86, 0, eRatio86);
	gr_Ratio64->SetMarkerColor(kBlue);
	gr_Ratio86->SetMarkerColor(kRed);
	gr_Ratio64->SetMarkerStyle(kOpenSquare);
	gr_Ratio86->SetMarkerStyle(kOpenCircle);

	gr_Ratio64->Draw("psame");
	gr_Ratio86->Draw("psame");

	TLegend * legR = new TLegend(0.18, 0.65, 0.6, 0.9);
	legR->SetFillColor(kWhite);
	legR->SetBorderSize(0);
	legR->AddEntry(ffit86, "v_{2}{8}/v_{2}{6} arXiv:1312.6555", "l");
	legR->AddEntry(ffit64, "v_{2}{6}/v_{2}{4} arXiv:1312.6555", "l");
	legR->AddEntry(gr_Ratio86, "v_{2}{8}/v_{2}{6} data", "p");
	legR->AddEntry(gr_Ratio64, "v_{2}{6}/v_{2}{4} data", "p");
	legR->Draw();

	TCanvas * cRatioNoff = MakeCanvas("cRatioNoff", "cRatioNoff", 600, 250);
	cRatioNoff->SetGridy();
	TH2D * frame_rnoff = new TH2D("frame_rnoff", ";N_{trk}^{offline};NSigma", 1, -5, 350, 1, 0.8, 1.2);
	InitHist(frame_rnoff, "N_{trk}^{offline}", "Ratio");
	frame_rnoff->Draw();
	TGraphErrors * gr_r84 = new TGraphErrors(gr_pPb_v28->GetN(), gr_pPb_v28->GetX(), dRatio84, 0, eRatio84);
	TGraphErrors * gr_r86 = new TGraphErrors(gr_pPb_v28->GetN(), gr_pPb_v28->GetX(), dRatio86, 0, eRatio86);
	TGraphErrors * gr_r64 = new TGraphErrors(gr_pPb_v26->GetN(), gr_pPb_v26->GetX(), dRatio64, 0, eRatio64);
	gr_r84->SetLineColor(kRed);
	gr_r64->SetLineColor(kBlue);
	gr_r86->SetLineColor(kBlack);
	gr_r84->SetLineWidth(2);
	gr_r64->SetLineWidth(2);
	gr_r86->SetLineWidth(2);
	gr_r84->Draw("lxsame");
	gr_r64->Draw("lxsame");
//	gr_r86->Draw("lxsame");

	TLegend * legRnoff = new TLegend(0.16, 0.2, 0.35, 0.45);
	legRnoff->SetFillColor(kWhite);
	legRnoff->SetBorderSize(0);
	legRnoff->AddEntry(gr_r84, "v_{2}{8}/v_{2}{4}", "l");
	legRnoff->AddEntry(gr_r64, "v_{2}{6}/v_{2}{4}", "l");
//	legRnoff->AddEntry(gr_r86, "v_{2}{8}/v_{2}{6}", "l");
	legRnoff->Draw();

	if ( save ) {
		cNsigma->SaveAs(Form("cNsigma_%i_%i.pdf", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i.pdf", s1, s3));
		cSumC2->SaveAs(Form("cSumC2_%i_%i.pdf", s1, s3));
		cSumC4->SaveAs(Form("cSumC4_%i_%i.pdf", s1, s3));
		cSumC6->SaveAs(Form("cSumC6_%i_%i.pdf", s1, s3));
		cSumC8->SaveAs(Form("cSumC8_%i_%i.pdf", s1, s3));
		cRatio->SaveAs(Form("cRatio_%i_%i.pdf", s1, s3));

		cNsigma->SaveAs(Form("cNsigma_%i_%i_C.C", s1, s3));
		cSum->SaveAs(Form("cSum_%i_%i_C.C", s1, s3));
		cSumC2->SaveAs(Form("cSumC2_%i_%i_C.C", s1, s3));
		cSumC4->SaveAs(Form("cSumC4_%i_%i_C.C", s1, s3));
		cSumC6->SaveAs(Form("cSumC6_%i_%i_C.C", s1, s3));
		cSumC8->SaveAs(Form("cSumC8_%i_%i_C.C", s1, s3));
		cRatio->SaveAs(Form("cRatio_%i_%i_C.C", s1, s3));

		cRatioNoff->SaveAs(Form("cRatioNoff_%i_%i.pdf", s1, s3));

		TFile * fsave;
		if ( sN == 3 ) {
			fsave = new TFile(Form("%s/fsave_%i.root", ftxt[s1], sN), "recreate");
		} else {
			fsave = new TFile(Form("%s/fsave.root", ftxt[s1]), "recreate");
		}
		grNSigma2->SetName("grNSigma2");
		grNSigma4->SetName("grNSigma4");
		grNSigma6->SetName("grNSigma6");
		grNSigma8->SetName("grNSigma8");
		grNSigma2->Write();
		grNSigma4->Write();
		grNSigma6->Write();
		grNSigma8->Write();

		gr_pPb_v22->SetName("gr_v22");
		gr_pPb_v24->SetName("gr_v24");
		gr_pPb_v26->SetName("gr_v26");
		gr_pPb_v28->SetName("gr_v28");
		gr_pPb_v22->Write();
		gr_pPb_v24->Write();
		gr_pPb_v26->Write();
		gr_pPb_v28->Write();

		gr_pPb_c22->SetName("gr_c22");
		gr_pPb_c24->SetName("gr_c24");
		gr_pPb_c26->SetName("gr_c26");
		gr_pPb_c28->SetName("gr_c28");
		gr_pPb_c22->Write();
		gr_pPb_c24->Write();
		gr_pPb_c26->Write();
		gr_pPb_c28->Write();

		gr_Ratio64->SetName("gr_Ratio64");
		gr_Ratio86->SetName("gr_Ratio86");
		gr_Ratio64->Write();
		gr_Ratio86->Write();
		fsave->Close();
	}
}
