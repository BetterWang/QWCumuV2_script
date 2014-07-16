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
	int bRatioSys = 1;


//	double sys6pA[7] = {0.0792, 0.1762, 0.0212, 0.0727, 0.1238, 0.0917, 0.0180};
//	double sys8pA[4] = {0.0412, 0.0411, 0.0892, 0.0184};

	double sys6pA[7] = {0.05, 0.05, 0.05, 0.05, 0.05, 0.05, 0.05};
	double sys8pA[4] = {0.06, 0.06, 0.06, 0.06};

	double sys6AA[13] = {0.0184,	0.0185,	0.0197,	0.0187,	0.0185,	0.0182,	0.0192,	0.0187,	0.0181,	0.0245,	0.0148,	0.0251,	0.0321};
        double sys8AA[12] = {0.0184,	0.0186,	0.0198,	0.0186,	0.0183,	0.0183,	0.0191,	0.0189,	0.0182,	0.0235,	0.0143,	0.0573};


	double xe6pA[7] = {0.021, 0.013, 0.006, 0.004, 0.004, 0.006, 0.025};
	double xe8pA[4] = {0.004, 0.004, 0.006, 0.025};
	double xe6pAs[7] = {0.072, 0.052, 0.053, 0.039, 0.041, 0.042, 0.042};
	double xe8pAs[4] = {0.039, 0.041, 0.042, 0.042};

//	double ye6pAYs[7] = {0.0621180223,	0.1176494255,	0.01447037168,	0.007016761734,	0.02696280641,	0.006004923697,	0.05873763201};
//	double ye8pAYs[4] = {0.05500183388,	0.1307786536,	0.1049608983,	0.02506903903};

	double ye6pAYs[7] = {
		0.0621,
		0.1176,
		0.0145,
		0.0070,
		0.0270,
		0.0060,
		0.0587
	};
	double ye8pAYs[4] = {
		0.0607,
		0.0207,
		0.0982,
		0.0622
	};

//	double ye6pAYs[7] = {0.042, 0.042, 0.042, 0.042, 0.042, 0.042, 0.042};
//	double ye8pAYs[4] = {0.079, 0.079, 0.079, 0.079};
	double ye6pAXs[7] = {0.028, 0.028, 0.028, 0.028, 0.028, 0.028, 0.028};
//	double ye6pAYs[7] = {0.020, 0.020, 0.020, 0.020, 0.020, 0.020, 0.020};
	double ye8pAXs[4] = {0.028, 0.028, 0.028, 0.028};
//	double ye8pAYs[4] = {0.020, 0.020, 0.020, 0.020};

//	double ye6AAYs[14] = {0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472, 0.00767557472};
//	double ye8AAYs[13] = {0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445, 0.006553631445};

	double ye6AAYs[14] = {0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};
	double ye8AAYs[13] = {0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01};


	double xe6AA[13] = {0.002736804941,	0.003428621839,	0.003564100269,	0.003980242459,	0.004074275775,	0.004453031198,	0.003790468728,	0.004694625687,	0.006843366966,	0.01162882142,	0.0164999545,	0.02705426654,	0.07014889026};
	double xe8AA[12] = {0.002736804941,	0.003428621839,	0.003564100269,	0.003980242459,	0.004074275775,	0.004453031198,	0.003790468728,	0.004694625687,	0.006843366966,	0.01162882142,	0.0164999545,	0.02705426654};

	double xe6AAs[13] = {0.03527442652,	0.03508141488,	0.03532715065,	0.03487510094,	0.03522836525,	0.03468048882,	0.03485269024,	0.03490851704,	0.0350050094,	0.03467187907,	0.03547679277,	0.03568730193,	0.03537572179};
	double xe8AAs[12] = {0.03527442652,	0.03508141488,	0.03532715065,	0.03487510094,	0.03522836525,	0.03468048882,	0.03485269024,	0.03490851704,	0.0350050094,	0.03467187907,	0.03547679277,	0.03568730193};

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

	TGraphErrors * gr_pPb_c26s = gr_pPb_c26->Clone("gr_pPb_c26s");
	TGraphErrors * gr_pPb_c28s = gr_pPb_c28->Clone("gr_pPb_c28s");
	TGraphErrors * gr_PbPb_c26s = gr_PbPb_c26->Clone("gr_PbPb_c26s");
	TGraphErrors * gr_PbPb_c28s = gr_PbPb_c28->Clone("gr_PbPb_c28s");

	TGraphErrors * gr_Ratio64 = (TGraphErrors*) f1->Get("gr_Ratio64");
	TGraphErrors * gr_Ratio64s = gr_Ratio64->Clone("gr_Ratio64s");
	TGraphErrors * gr_Ratio86 = (TGraphErrors*) f1->Get("gr_Ratio86");
	TGraphErrors * gr_Ratio86s = gr_Ratio86->Clone("gr_Ratio86s");
	TGraphErrors * gr_AARatio64 = (TGraphErrors*) f2->Get("gr_Ratio64");
	TGraphErrors * gr_AARatio64s = gr_AARatio64->Clone("gr_AARatio64s");
	TGraphErrors * gr_AARatio86 = (TGraphErrors*) f2->Get("gr_Ratio86");
	TGraphErrors * gr_AARatio86s = gr_AARatio86->Clone("gr_AARatio86s");

//	gr_pPb_c26->SetLineWidth(2);
//	gr_pPb_c28->SetLineWidth(2);
//	gr_PbPb_c26->SetLineWidth(2);
//	gr_PbPb_c28->SetLineWidth(2);
//
//	gr_pPb_v26->SetLineWidth(2);
//	gr_pPb_v28->SetLineWidth(2);
//	gr_PbPb_v26->SetLineWidth(2);
//	gr_PbPb_v28->SetLineWidth(2);

	for ( int i = 0; i < gr_Ratio64->GetN(); i++ ) {
		gr_Ratio64->GetEX()[i] = xe6pA[i];
		gr_Ratio64s->GetEX()[i] = xe6pAs[i];
	}
	for ( int i = 0; i < gr_AARatio64->GetN(); i++ ) {
		gr_AARatio64->GetEX()[i] = xe6AA[i];
		gr_AARatio64s->GetEX()[i] = xe6AAs[i];
	}
	for ( int i = 0; i < gr_Ratio86->GetN(); i++ ) {
		gr_Ratio86->GetEX()[i] = xe8pA[i];
		gr_Ratio86s->GetEX()[i] = xe8pAs[i];
	}
	for ( int i = 0; i < gr_AARatio86->GetN(); i++ ) {
		gr_AARatio86->GetEX()[i] = xe8AA[i];
		gr_AARatio86s->GetEX()[i] = xe8AAs[i];
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
		if ( bRatioSys == 1 ) {
			gr_Ratio64s->GetEY()[i] = ye6pAYs[i]*gr_Ratio64s->GetY()[i];
			gr_Ratio64s->GetEX()[i] = ye6pAXs[i]*gr_Ratio64s->GetX()[i];
		}
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
		if ( bRatioSys == 1 ) {
			gr_AARatio64s->GetEY()[i] = ye6AAYs[i] * gr_AARatio64s->GetY()[i]; 
		}
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
		if ( bRatioSys == 1 ) {
			gr_Ratio86s->GetEY()[i] = ye8pAYs[i]*gr_Ratio86s->GetY()[i];
			gr_Ratio86s->GetEX()[i] = ye8pAXs[i]*gr_Ratio86s->GetX()[i];
		}
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
		if ( bRatioSys == 1 ) {
			gr_AARatio86s->GetEY()[i] = ye8AAYs[i] * gr_AARatio86s->GetY()[i]; 
		}
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
				t = gr_Ratio64s->GetEX()[i];
				gr_Ratio64s->GetEX()[i] = gr_Ratio64s->GetEX()[j];
				gr_Ratio64s->GetEX()[j] = t;
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
				t = gr_AARatio64s->GetEX()[i];
				gr_AARatio64s->GetEX()[i] = gr_AARatio64s->GetEX()[j];
				gr_AARatio64s->GetEX()[j] = t;
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
				t = gr_Ratio86s->GetEX()[i];
				gr_Ratio86s->GetEX()[i] = gr_Ratio86s->GetEX()[j];
				gr_Ratio86s->GetEX()[j] = t;
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
				t = gr_AARatio86s->GetEX()[i];
				gr_AARatio86s->GetEX()[i] = gr_AARatio86s->GetEX()[j];
				gr_AARatio86s->GetEX()[j] = t;
			}
		}
	}



	TGraphErrors * gr_pPb_v26s = new TGraphErrors(gr_pPb_v26->GetN(), Noff6, v26, 0, v26sys);
	TGraphErrors * gr_pPb_v28s = new TGraphErrors(gr_pPb_v28->GetN(), Noff8, v28, 0, v28sys);
	gr_pPb_v26s->SetLineColor(gr_pPb_v26->GetLineColor());
	gr_pPb_v28s->SetLineColor(gr_pPb_v28->GetLineColor());
	for ( int i = 0; i < gr_pPb_c26s->GetN(); i++ ) {
		gr_pPb_c26s->GetEY()[i] = 6 * gr_pPb_c26s->GetY()[i] * gr_pPb_v26s->GetEY()[i] / gr_pPb_v26s->GetY()[i];
	}
	for ( int i = 0; i < gr_pPb_c28s->GetN(); i++ ) {
		gr_pPb_c28s->GetEY()[i] = 8 * gr_pPb_c28s->GetY()[i] * gr_pPb_v28s->GetEY()[i] / gr_pPb_v28s->GetY()[i];
	}

	TColor red(1001, 1, 0, 0, "red", 0.2);
	TColor blue(1002, 0, 1, 0, "red", 0.2);
	TColor green(1003, 0, 0, 1, "red", 0.2);
	gr_pPb_v26s->SetFillColor(1003);
	gr_pPb_v28s->SetFillColor(1001);
	grLYZpPbv2s->SetFillColor(1002);

	gr_pPb_c26s->SetFillColor(1003);
	gr_pPb_c28s->SetFillColor(1001);

//	gr_Ratio64s->SetFillColor(1003);
//	gr_Ratio86s->SetFillColor(1001);
//	gr_AARatio64s->SetFillColor(1003);
//	gr_AARatio86s->SetFillColor(1001);
	gr_Ratio64s->SetFillColor(kGray);
	gr_Ratio86s->SetFillColor(kGray);
	gr_AARatio64s->SetFillColor(kGray);
	gr_AARatio86s->SetFillColor(kGray);

	TGraphErrors * gr_PbPb_v26s = new TGraphErrors(gr_PbPb_v26->GetN(), Noff6PbPb, v26PbPb, 0, v26sysAA);
	TGraphErrors * gr_PbPb_v28s = new TGraphErrors(gr_PbPb_v28->GetN(), Noff8PbPb, v28PbPb, 0, v28sysAA);
	gr_PbPb_v26s->SetLineColor(gr_PbPb_v26->GetLineColor());
	gr_PbPb_v28s->SetLineColor(gr_PbPb_v28->GetLineColor());
	for ( int i = 0; i < gr_PbPb_c26s->GetN(); i++ ) {
		gr_PbPb_c26s->GetEY()[i] = 6 * gr_PbPb_c26s->GetY()[i] * gr_PbPb_v26s->GetEY()[i] / gr_PbPb_v26s->GetY()[i];
	}
	for ( int i = 0; i < gr_PbPb_c28s->GetN(); i++ ) {
		gr_PbPb_c28s->GetEY()[i] = 8 * gr_PbPb_c28s->GetY()[i] * gr_PbPb_v28s->GetEY()[i] / gr_PbPb_v28s->GetY()[i];
	}

	gr_PbPb_v26s->SetFillColor(1003);
	gr_PbPb_v28s->SetFillColor(1001);
	grLYZPbPbv2s->SetFillColor(1002);
	gr_PbPb_c26s->SetFillColor(1003);
	gr_PbPb_c28s->SetFillColor(1001);

	gr_HIN_13_002_PbPbv22s->SetFillColor(kGray);
	gr_HIN_13_002_PbPbv24s->SetFillColor(kGray);
	gr_HIN_13_002_pPbv22s->SetFillColor(kGray);
	gr_HIN_13_002_pPbv24s->SetFillColor(kGray);
	for ( int i = 0; i < gr_HIN_13_002_PbPbv22s->GetN(); i++ ) {
		gr_HIN_13_002_PbPbv22s->GetEX()[i] = 8;
	}
	for ( int i = 0; i < gr_HIN_13_002_PbPbv24s->GetN(); i++ ) {
		gr_HIN_13_002_PbPbv24s->GetEX()[i] = 8;
	}
	for ( int i = 0; i < gr_HIN_13_002_pPbv22s->GetN(); i++ ) {
		gr_HIN_13_002_pPbv22s->GetEX()[i] = 8;
	}
	for ( int i = 0; i < gr_HIN_13_002_pPbv24s->GetN(); i++ ) {
		gr_HIN_13_002_pPbv24s->GetEX()[i] = 8;
	}

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
	TLegendEntry * legEnV2 = legLeft->AddEntry(gr_HIN_13_002_PbPbv22, "v_{2}{2, |#Delta#eta|>2}", "p");
	TLegendEntry * legEnV4 = legLeft->AddEntry(gr_HIN_13_002_PbPbv24, "v_{2}{4}", "p");
	TLegendEntry * legEnV6 = legLeft->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	TLegendEntry * legEnV8 = legLeft->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	TLegendEntry * legEnVLYZ = legLeft->AddEntry(grLYZpPbv2, "v_{2}{LYZ}", "p");

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
	gr_HIN_13_002_PbPbv22s->Draw("[]2");
	gr_HIN_13_002_PbPbv24s->Draw("[]2");
	gr_HIN_13_002_PbPbv22->Draw("Psame");
	gr_HIN_13_002_PbPbv24->Draw("Psame");
	grLYZPbPbv2s->Draw("[]3");
	gr_PbPb_v26s->Draw("[]3");
	gr_PbPb_v28s->Draw("[]3");
	grLYZPbPbv2->Draw("Psame");
	gr_PbPb_v26->Draw("Psame");
	gr_PbPb_v28->Draw("Psame");
	legLeft->Draw();
	latex.DrawLatexNDC(0.20, 0.94, "#splitline{PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");

//	gStyle->SetEndErrorSize(5);
	gStyle->SetErrorX(5);
	cSum2->cd(2);
	TH2D * frame_cent2 = new TH2D("frame_cent2", ";N_{trk}^{offline};v_{2}", 1, 1, 350, 1, 0.00001, 0.12 );
	InitHist(frame_cent2, "N_{trk}^{offline}", "v_{2}");
	frame_cent->Draw();
	grLYZpPbv2s->Draw("[]3");
	gr_pPb_v26s->Draw("[]3");
	gr_pPb_v28s->Draw("[]3");
	gr_HIN_13_002_pPbv22s->Draw("[]2");
	gr_HIN_13_002_pPbv24s->Draw("[]2");
	gr_HIN_13_002_pPbv22->Draw("Psame");
	gr_HIN_13_002_pPbv24->Draw("Psame");
	grLYZpPbv2->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");
	latex.DrawLatexNDC(0.1, 0.94, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.5, 0.27, "CMS Preliminary");


	TCanvas * cSum2pA = MakeCanvas("cSum2pA", "cSum2pA", 600, 500);
	cSum2pA->SetTopMargin(0.02);
	cSum2pA->SetRightMargin(0.02);
	TH2D * frame_centpA = new TH2D("frame_centpA", ";N_{trk}^{offline};v_{2}", 1, -5, 350, 1, 0.00001, 0.099 );
	InitHist(frame_centpA, "N_{trk}^{offline}", "v_{2}");
	frame_centpA->GetYaxis()->SetTitleOffset(1.3);
	frame_centpA->GetXaxis()->SetTitleOffset(1.1);
	frame_centpA->Draw();
	grLYZpPbv2s->Draw("[]3");
	gr_pPb_v26s->Draw("[]3");
	gr_pPb_v28s->Draw("[]3");
	gr_HIN_13_002_pPbv22s->Draw("[]2");
	gr_HIN_13_002_pPbv24s->Draw("[]2");
	gr_HIN_13_002_pPbv22->Draw("Psame");
	gr_HIN_13_002_pPbv24->Draw("Psame");
	grLYZpPbv2->Draw("Psame");
	gr_pPb_v26->Draw("Psame");
	gr_pPb_v28->Draw("Psame");
	latex.DrawLatexNDC(0.19, 0.95, "CMS Preliminary");
	latex.DrawLatexNDC(0.19, 0.90, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV, L_{int} = 35 nb^{-1}}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	TLegend * legLeftpA = new TLegend(0.5, 0.18, 0.85, 0.43);
	legLeftpA->SetFillColor(kWhite);
	legLeftpA->SetTextFont(42);
	legLeftpA->SetTextSize(0.05);
	legLeftpA->SetBorderSize(0);
	TLegendEntry * legEnV2A = legLeftpA->AddEntry(gr_HIN_13_002_PbPbv22, "v_{2}{2, |#Delta#eta|>2}", "p");
	TLegendEntry * legEnV4A = legLeftpA->AddEntry(gr_HIN_13_002_PbPbv24, "v_{2}{4}", "p");
	TLegendEntry * legEnV6A = legLeftpA->AddEntry(gr_pPb_v26, "v_{2}{6}", "p");
	TLegendEntry * legEnV8A = legLeftpA->AddEntry(gr_pPb_v28, "v_{2}{8}", "p");
	TLegendEntry * legEntryLYZA = legLeftpA->AddEntry(grLYZpPbv2, "v_{2}{LYZ}", "p");
	legLeftpA->Draw();




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
	legLeftR->AddEntry(ffit64, "Fluctuation-Driven Eccentricities" , "l");
//	legLeftR->AddEntry(gr_Ratio64, "data" , "p");
	legLeftR->SetTextFont(43);
	legLeftR->SetTextSize(24);

//	TLegend * legRightR = new TLegend(0.35, 0.2, 0.95, 0.3);
	TLegend * legRightR = new TLegend(0.2, 0.15, 0.8, 0.25);
	legRightR->SetFillColor(kWhite);
	legRightR->SetBorderSize(0);
	legRightR->AddEntry(ffit86, "Fluctuation-Driven Eccentricities" , "");
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

	TLegend * legRightAAR = new TLegend(0.2, 0.15, 0.8, 0.25);
	legRightAAR->SetFillColor(kWhite);
	legRightAAR->SetBorderSize(0);
	legRightAAR->AddEntry(ffit86, "Fluctuation-Driven Eccentricities" , "");
//	legRightAAR->AddEntry(gr_Ratio86, "data" , "p");
	legRightAAR->SetTextFont(43);
	legRightAAR->SetTextSize(22);




	TCanvas * cSumR = MakeCanvas("cSumR", "cSumR", 500, 900);
	makeMultiPanelCanvas(cSumR, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumR->cd(1);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio64 = new TH2D("frame_ratio64", "frame_ratio64", 1, 0.59, 0.829, 1, 0.7, 1.3);
	InitHist(frame_ratio64, "v_{2}{4} / v_{2}{2}", "v_{2}{6} / v_{2}{4}");
	frame_ratio64->GetXaxis()->SetTitleFont(43);
	frame_ratio64->GetYaxis()->SetTitleFont(43);
	frame_ratio64->GetXaxis()->SetTitleSize(26);
	frame_ratio64->GetYaxis()->SetTitleSize(26);
	frame_ratio64->GetXaxis()->SetTitleOffset(1.8);
	frame_ratio64->GetYaxis()->SetTitleOffset(2.2);
	frame_ratio64->Draw();
	ffit64->Draw("same");
	gr_Ratio64s->Draw("[]2");
	gr_Ratio64->Draw("psame");
//	legLeftR->Draw();
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");
//	latex.DrawLatexNDC(0.18, 0.92, "(a)");

	cSumR->cd(2);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio86 = frame_ratio64->Clone("frame_ratio86");
	frame_ratio86->SetYTitle("v_{2}{8} / v_{2}{6}");
	frame_ratio86->Draw();
	ffit86->Draw("same");
	gr_Ratio86s->Draw("[]2");
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
	lr->SetLineWidth(3);
	TLine *lb = lr->Clone();
	lb->SetLineColor(kBlue);

	lr->DrawLineNDC(0.23, 0.18, 0.34, 0.18);
	lb->DrawLineNDC(0.23, 0.205, 0.34, 0.205);

	TCanvas * cSumAAR = MakeCanvas("cSumAAR", "cSumAAR", 500, 900);
	makeMultiPanelCanvas(cSumAAR, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumAAR->cd(1);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_AAratio64 = new TH2D("frame_AAratio64", "frame_AAratio64", 1, 0.801, 0.849, 1, 0.751, 1.3);
	InitHist(frame_AAratio64, "v_{2}{4} / v_{2}{2}", "v_{2}{6} / v_{2}{4}");
	frame_AAratio64->GetXaxis()->SetTitleFont(43);
	frame_AAratio64->GetYaxis()->SetTitleFont(43);
	frame_AAratio64->GetXaxis()->SetTitleSize(26);
	frame_AAratio64->GetYaxis()->SetTitleSize(26);
	frame_AAratio64->GetXaxis()->SetTitleOffset(1.8);
	frame_AAratio64->GetYaxis()->SetTitleOffset(2.2);
	frame_AAratio64->Draw();
	ffit64->Draw("same");
	gr_AARatio64s->Draw("[]2");
	gr_AARatio64->Draw("psame");
//	legLeftR->Draw();
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");
//	latex.DrawLatexNDC(0.18, 0.92, "(a)");

	cSumAAR->cd(2);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_AAratio86 = frame_AAratio64->Clone("frame_AAratio86");
	frame_AAratio86->SetYTitle("v_{2}{8} / v_{2}{6}");
	frame_AAratio86->Draw();
	ffit86->Draw("same");
	gr_AARatio86s->Draw("[]2");
	gr_AARatio86->Draw("psame");
//	legLeftR->Draw();
	legRightAAR->Draw();

	lr->DrawLineNDC(0.23, 0.225, 0.34, 0.225);
	lb->DrawLineNDC(0.23, 0.25, 0.34, 0.25);


	TCanvas * cSumRSame = MakeCanvas("cSumRSame", "cSumRSame", 500, 900);
	makeMultiPanelCanvas(cSumRSame, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumRSame->cd(1);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio64same = new TH2D("frame_ratio64same", "frame_ratio64same", 1, 0.591, 0.92, 1, 0.61, 1.5);
	InitHist(frame_ratio64same, "v_{2}{4} / v_{2}{2}", "v_{2}{6} / v_{2}{4}");
	frame_ratio64same->GetXaxis()->SetTitleFont(43);
	frame_ratio64same->GetYaxis()->SetTitleFont(43);
	frame_ratio64same->GetXaxis()->SetTitleSize(26);
	frame_ratio64same->GetYaxis()->SetTitleSize(26);
	frame_ratio64same->GetXaxis()->SetTitleOffset(1.8);
	frame_ratio64same->GetYaxis()->SetTitleOffset(2.2);
	frame_ratio64same->Draw();
//	ffit64->Draw("same");
	gr_Ratio64s->SetFillColor(1003);
	gr_Ratio64s->Draw("[]2");
	gr_AARatio64s->SetFillColor(kBlue);
	gr_AARatio64s->SetMarkerStyle(kOpenSquare);
	gr_AARatio64s->SetFillStyle(3004);
	gr_AARatio64s->Draw("[]2");
	gr_Ratio64->Draw("psame");
	gr_AARatio64->SetMarkerStyle(kOpenSquare);
	gr_AARatio64->Draw("psame");
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV, PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");

	TLegend * legRatioSamepA = new TLegend(0.4, 0.05, 0.65, 0.13);
	legRatioSamepA->SetFillColor(kWhite);
	legRatioSamepA->SetBorderSize(0);
	legRatioSamepA->SetTextFont(43);
	legRatioSamepA->SetTextSize(22);
	legRatioSamepA->AddEntry(gr_Ratio64, "pPb", "p");
	legRatioSamepA->Draw("same");

	TLegend * legRatioSameAA = new TLegend(0.7, 0.05, 0.95, 0.13);
	legRatioSameAA->SetFillColor(kWhite);
	legRatioSameAA->SetBorderSize(0);
	legRatioSameAA->SetTextFont(43);
	legRatioSameAA->SetTextSize(22);
	legRatioSameAA->AddEntry(gr_AARatio64, "PbPb", "p");
	legRatioSameAA->Draw("same");




	cSumRSame->cd(2);
	gPad->SetLeftMargin(0.15);
	TH2D * frame_ratio86same = frame_ratio64same->Clone("frame_ratio86same");
	frame_ratio86same->SetYTitle("v_{2}{8} / v_{2}{6}");
	frame_ratio86same->Draw();
//	ffit86->Draw("same");
	gr_Ratio86s->SetFillColor(1001);
	gr_Ratio86s->Draw("[]2");
	gr_AARatio86s->SetFillColor(kRed);
	gr_AARatio86s->SetFillStyle(3004);
	gr_AARatio86s->Draw("[]2");
	gr_Ratio86->Draw("psame");
	gr_AARatio86->SetMarkerStyle(kOpenCircle);
	gr_AARatio86->Draw("psame");
//	legRightAAR->Draw();

	TLegend * legRatioSamepA1 = new TLegend(0.4, 0.25, 0.65, 0.35);
	legRatioSamepA1->SetFillColor(kWhite);
	legRatioSamepA1->SetBorderSize(0);
	legRatioSamepA1->SetTextFont(43);
	legRatioSamepA1->SetTextSize(22);
	legRatioSamepA1->AddEntry(gr_Ratio86, "pPb", "p");
	legRatioSamepA1->Draw("same");

	TLegend * legRatioSameAA1 = new TLegend(0.7, 0.25, 0.95, 0.35);
	legRatioSameAA1->SetFillColor(kWhite);
	legRatioSameAA1->SetBorderSize(0);
	legRatioSameAA1->SetTextFont(43);
	legRatioSameAA1->SetTextSize(22);
	legRatioSameAA1->AddEntry(gr_AARatio86, "PbPb", "p");
	legRatioSameAA1->Draw("same");

	////////////
	TCanvas * cSumRSame1 = MakeCanvas("cSumRSame1", "cSumRSame1", 500, 900);
	makeMultiPanelCanvas(cSumRSame1, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumRSame1->cd(1);
	gPad->SetLeftMargin(0.15);
	frame_ratio64same->Draw();
	ffit64->Draw("same");
	gr_Ratio64s->SetFillColor(1003);
	gr_Ratio64s->Draw("[]2");
	gr_Ratio64->Draw("psame");
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");


	cSumRSame1->cd(2);
	gPad->SetLeftMargin(0.15);
	frame_ratio86same->Draw();
	ffit86->Draw("same");
	gr_Ratio86s->SetFillColor(1001);
	gr_Ratio86s->Draw("[]2");
	gr_Ratio86->Draw("psame");
	legRightAAR->Draw();

	lr->DrawLineNDC(0.23, 0.18, 0.34, 0.18);
	lb->DrawLineNDC(0.23, 0.205, 0.34, 0.205);


	////////////
	TCanvas * cSumRSame2 = MakeCanvas("cSumRSame2", "cSumRSame2", 500, 900);
	makeMultiPanelCanvas(cSumRSame2, 1, 2, 0.0, 0., 0.01, 0.12, 0.01);
	cSumRSame2->cd(1);
	gPad->SetLeftMargin(0.15);
	frame_ratio64same->Draw();
//	TF1 * ffit64c = ffit64->Clone("ffit64c");
//	TF1 * ffit64a = ffit64->Clone("ffit64a");
//	ffit64c->SetRange(0.3, 0.78);
//	ffit64a->SetRange(0.78, 1.0);
//	ffit64a->SetLineStyle(kDashed);
//	ffit64c->Draw("same");
//	ffit64a->Draw("same");
	ffit64->Draw("same");
	gr_Ratio64s->SetFillColor(1003);
	gr_Ratio64s->Draw("[]2");
	gr_AARatio64s->Draw("[]2");
	gr_Ratio64->Draw("psame");
	gr_AARatio64->Draw("psame");
	latex.DrawLatexNDC(0.20, 0.88, "#splitline{pPb #sqrt{s_{NN}} = 5.02 TeV, PbPb #sqrt{s_{NN}} = 2.76 TeV}{0.3 < p_{T} < 3.0 GeV/c; |#eta| < 2.4}");
	latex.DrawLatexNDC(0.2, 0.94, "CMS Preliminary");

	legRatioSamepA->Draw("same");
	legRatioSameAA->Draw("same");

	cSumRSame2->cd(2);
	gPad->SetLeftMargin(0.15);
	frame_ratio86same->Draw();
//	TF1 * ffit86c = ffit86->Clone("ffit86c");
//	TF1 * ffit86a = ffit86->Clone("ffit86a");
//	ffit86c->SetRange(0.3, 0.78);
//	ffit86a->SetRange(0.78, 1.0);
//	ffit86a->SetLineStyle(kDashed);
//	ffit86c->Draw("same");
//	ffit86a->Draw("same");
	ffit86->Draw("same");
	gr_Ratio86s->SetFillColor(1001);
	gr_Ratio86s->Draw("[]2");
	gr_AARatio86s->Draw("[]2");
	gr_Ratio86->Draw("psame");
	gr_AARatio86->Draw("psame");
	legRightAAR->Draw();

	lr->DrawLineNDC(0.23, 0.18, 0.34, 0.18);
	lb->DrawLineNDC(0.23, 0.205, 0.34, 0.205);

	legRatioSamepA1->Draw("same");
	legRatioSameAA1->Draw("same");



	{
  Double_t pw = 0.45;
  Double_t ph = 0.45;
  Double_t rm = 0.02;
  Double_t lm = 0.03;
  Double_t bmtoprow = 0.00;
  Double_t bm = 0.03;
  Double_t tm = 0.04;
  Double_t tmbot = 0.0;
  Int_t xaxlab = 807;
  TH1D * h1 = new TH1D("h1","h1",100,0,380);
  h1->GetXaxis()->SetNdivisions(xaxlab);
  h1->GetXaxis()->CenterTitle(kTRUE);
  h1->GetXaxis()->SetTitleOffset(1.4);
  h1->SetMinimum(1.001e-9);
  h1->SetMaximum(1e-5);
  h1->GetYaxis()->SetLabelFont(43);
  h1->GetYaxis()->SetLabelSize(24);
  h1->GetXaxis()->SetLabelSize(0);
  h1->GetYaxis()->SetTitleFont(43);
  h1->GetYaxis()->SetTitleSize(32);
  h1->GetYaxis()->SetTitleOffset(2.4);
  h1->GetYaxis()->CenterTitle(kTRUE);
  h1->SetYTitle("c_{2}\{6\}");
  TH1D * h2 = (TH1D *) h1->Clone("h2");
  h2->GetXaxis()->SetLabelSize(0);
  h2->GetYaxis()->SetLabelSize(0);
  TH1D * h3 = new TH1D("h3","h3",100,0,380);
  h3->GetXaxis()->SetNdivisions(xaxlab);
  h3->GetXaxis()->CenterTitle(kTRUE);
  h3->GetXaxis()->SetTitleOffset(2.0);
  h3->GetXaxis()->SetTitleFont(43);
  h3->GetXaxis()->SetTitleSize(32);
  h3->SetXTitle("N_{trk}^{offline}");
  h3->GetYaxis()->SetLabelFont(43);
  h3->GetYaxis()->SetLabelSize(24);
  h3->GetXaxis()->SetLabelFont(43);
  h3->GetXaxis()->SetLabelSize(24);
  h3->SetMinimum(1e-10);
  h3->SetMaximum(0.999e-6);
  h3->GetYaxis()->SetTitleFont(43);
  h3->GetYaxis()->SetTitleSize(32);
  h3->GetYaxis()->CenterTitle(kTRUE);
  h3->GetYaxis()->SetTitleOffset(2.4);
  h3->SetYTitle("- c_{2}\{8\}");
  TH1D * h4 = (TH1D *) h3->Clone("h4");
  h4->GetYaxis()->SetLabelSize(0);
  h4->GetXaxis()->SetLabelFont(43);
  h4->GetXaxis()->SetLabelSize(24);
  h4->SetMinimum(1e-10);
  h4->SetMaximum(1e-6);

  TCanvas * c = new TCanvas("c","c",900,900);

  TPad * p1 = new TPad("p1","p1",0,1.0-ph,1.0-pw,1.0);
  p1->SetRightMargin(rm);
  p1->SetBottomMargin(bmtoprow);
  p1->SetTopMargin(tm);
  p1->SetLeftMargin( (1 - (pw/(1-pw))*(1-lm-rm)) - rm);
  c->cd();
  p1->Draw();
  p1->cd();
  p1->SetLogy();
  h1->Draw();
  gr_PbPb_c26->SetMarkerStyle(kFullCross);
  gr_PbPb_c26s->Draw("[]3");
  gr_PbPb_c26->Draw("p");


  c->cd();
  TPad * p2 = new TPad("p2","p2",1.0-pw,1.0-ph,1.0,1.0);
  p2->SetLeftMargin(lm);
  p2->SetRightMargin(rm);
  p2->SetTopMargin(tm);
  p2->SetBottomMargin(bmtoprow);
  p2->Draw();
  p2->cd();
  p2->SetLogy();
  h2->Draw();
  gr_pPb_c26->SetMarkerStyle(kFullCross);
  gr_pPb_c26s->Draw("[]3");
  gr_pPb_c26->Draw("p");

  TPad * p3 = new TPad("p3","p3",0,0.0,1.0-pw,1.0-ph);
  p3->SetRightMargin(rm);
  p3->SetTopMargin(tmbot);
  p3->SetLeftMargin((1 - (pw/(1-pw))*(1-lm-rm)) - rm);
  p3->SetBottomMargin( (1 - (ph/(1-ph))*(1-tm-bm)) - bm);
  c->cd();
  p3->Draw();
  p3->cd();
  p3->SetLogy();
  h3->Draw();
  for ( int i = 0; i < gr_PbPb_c28->GetN(); i++ ) {
	  gr_PbPb_c28->GetY()[i] *= -1;
	  gr_PbPb_c28s->GetY()[i] *= -1;
  }
  gr_PbPb_c28s->Draw("[]3");
  gr_PbPb_c28->Draw("p");


  TPad * p4 = new TPad("p4","p4",1.0-pw,0.0,1.0,1.0-ph);
  p4->SetRightMargin(rm);
  p4->SetTopMargin(tmbot);
  p4->SetLeftMargin(lm);
  p4->SetBottomMargin( (1 - (ph/(1-ph))*(1-tm-bm)) - bm);
  c->cd();
  p4->Draw();
  p4->cd();
  p4->SetLogy();
  h4->Draw();
  for ( int i = 0; i < gr_pPb_c28->GetN(); i++ ) {
	  gr_pPb_c28->GetY()[i] *= -1;
	  gr_pPb_c28s->GetY()[i] *= -1;
  }
  gr_pPb_c28s->Draw("[]3");
  gr_pPb_c28->Draw("p");

  Double_t prescale = 0.43;
  p1->cd();
  TLatex * l1 = new TLatex(0.3, 0.2,"PbPb #sqrt{s_{NN}} = 2.76 TeV");
  l1->SetNDC();
  l1->SetTextFont(43);
  l1->SetTextSize(28);
  l1->Draw();
  TLatex * l1a = new TLatex(0.3, 0.1,"0.3 < p_{T} < 3.0 GeV/c;  |#eta| < 2.4");
  l1a->SetNDC();
  l1a->SetTextFont(43);
  l1a->SetTextSize(24);
  l1a->Draw();
  TLatex * prelim = new TLatex(0.3, 0.3,"CMS Preliminary");
  prelim->SetNDC();
  prelim->SetTextFont(43);
  prelim->SetTextSize(24);
  prelim->Draw();

  p2->cd();
  TLatex * l2 = new TLatex(0.1, 0.75,"pPb #sqrt{s_{NN}} = 5.02 TeV");
  l2->SetNDC();
  l2->SetTextFont(43);
  l2->SetTextSize(28);
  l2->Draw();
  TLatex * l2a = new TLatex(0.1, 0.65,"0.3 < p_{T} < 3.0 GeV/c;  |#eta| < 2.4");
  l2a->SetNDC();
  l2a->SetTextFont(43);
  l2a->SetTextSize(24);
  l2a->Draw();
  TLatex * prelim2 = new TLatex(0.1, 0.85,"CMS Preliminary");
  prelim2->SetNDC();
  prelim2->SetTextFont(43);
  prelim2->SetTextSize(24);
  prelim2->Draw();

  p4->cd();
  TLegend * legc26 = new TLegend(0.6, 0.75, 0.9, 0.9);
  legc26->SetFillColor(kWhite);
  legc26->SetBorderSize(0);
  legc26->SetTextFont(43);
  legc26->SetTextSize(24);
  legc26->AddEntry(gr_pPb_c26, "c_{2}{6}", "p");
  legc26->AddEntry(gr_pPb_c28, "#scale[1.1]{|} c_{2}{8} #scale[1.1]{|}", "p");
  legc26->Draw();
	}








	cSum2->SaveAs("final_v2.pdf");
	cSumR->SaveAs("final_ratio.pdf");
	cSumAAR->SaveAs("final_ratioAA.pdf");
	cSum2->SaveAs("final_v2_C.C");
	cSumR->SaveAs("final_ratio_C.C");
	cSumAAR->SaveAs("final_ratioAA_C.C");
	c->SaveAs("cResults.pdf");
	c->SaveAs("cResults_C.C");


	cSum2pA->SaveAs("final_v2pA.pdf");
	cSum2pA->SaveAs("final_v2pA_C.C");

	cSumRSame->SaveAs("final_ratioSame.pdf");
	cSumRSame->SaveAs("final_ratioSame_C.C");
	cSumRSame1->SaveAs("final_ratioSame1.pdf");
	cSumRSame1->SaveAs("final_ratioSame1_C.C");
	cSumRSame2->SaveAs("final_ratioSame2.pdf");
	cSumRSame2->SaveAs("final_ratioSame2_C.C");
//	cC26pPb->SaveAs("final_pPb_c26.pdf");
//	cC28pPb->SaveAs("final_pPb_c28.pdf");
//	cC26PbPb->SaveAs("final_PbPb_c26.pdf");
//	cC28PbPb->SaveAs("final_PbPb_c28.pdf");


	legEnVLYZ->SetObject((TObject*)0);
	legEnVLYZ->SetLabel("");
	legEnVLYZ->SetOption("");
	legEntryLYZA->SetObject((TObject*)0);
	legEntryLYZA->SetLabel("");
	legEntryLYZA->SetOption("");
	grLYZPbPbv2->Delete();
	grLYZpPbv2->Delete();
	grLYZPbPbv2s->Delete();
	grLYZpPbv2s->Delete();
	cSum2->SaveAs("final_v2_5.pdf");
	cSum2pA->SaveAs("final_v2pA_5.pdf");

	legEnV8->SetObject((TObject*)0);
	legEnV8->SetLabel("");
	legEnV8->SetOption("");
	legEnV8A->SetObject((TObject*)0);
	legEnV8A->SetLabel("");
	legEnV8A->SetOption("");
	gr_PbPb_v28->Delete();
	gr_PbPb_v28s->Delete();
	gr_pPb_v28->Delete();
	gr_pPb_v28s->Delete();
	cSum2->SaveAs("final_v2_4.pdf");
	cSum2pA->SaveAs("final_v2pA_4.pdf");

	legEnV6->SetObject((TObject*)0);
	legEnV6->SetLabel("");
	legEnV6->SetOption("");
	legEnV6A->SetObject((TObject*)0);
	legEnV6A->SetLabel("");
	legEnV6A->SetOption("");
	gr_PbPb_v26->Delete();
	gr_PbPb_v26s->Delete();
	gr_pPb_v26->Delete();
	gr_pPb_v26s->Delete();
	cSum2->SaveAs("final_v2_3.pdf");
	cSum2pA->SaveAs("final_v2pA_3.pdf");

	legEnV4->SetObject((TObject*)0);
	legEnV4->SetLabel("");
	legEnV4->SetOption("");
	legEnV4A->SetObject((TObject*)0);
	legEnV4A->SetLabel("");
	legEnV4A->SetOption("");
	gr_HIN_13_002_PbPbv24->Delete();
	gr_HIN_13_002_PbPbv24s->Delete();
	gr_HIN_13_002_pPbv24->Delete();
	gr_HIN_13_002_pPbv24s->Delete();
	cSum2->SaveAs("final_v2_2.pdf");
	cSum2pA->SaveAs("final_v2pA_2.pdf");


}
