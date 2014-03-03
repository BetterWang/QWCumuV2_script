/*
 * =====================================================================================
 *
 *       Filename:  LYZ_pPb.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/09/2013 10:28:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

{
	ifstream fLYZpPb("txt/Shengquan_pPbLYZnoff.txt");
	ifstream fLYZPbPb("txt/Shengquan_PbPbLYZnoff.txt");
	double LYZpPbnoff[20];
	double LYZpPbv2[20];
	double LYZpPbv2e[20];
	double LYZpPbv2s[20];
	int NLYZpPb=0;

	double LYZPbPbnoff[20];
	double LYZPbPbv2[20];
	double LYZPbPbv2e[20];
	double LYZPbPbv2s[20];
	int NLYZPbPb=0;

	while (!fLYZpPb.eof())
	{
		fLYZpPb >> LYZpPbnoff[NLYZpPb] >> LYZpPbv2[NLYZpPb] >> LYZpPbv2e[NLYZpPb] >> LYZpPbv2s[NLYZpPb];
		NLYZpPb++;
	}
	NLYZpPb--;

	while (!fLYZPbPb.eof())
	{
		fLYZPbPb >> LYZPbPbnoff[NLYZPbPb] >> LYZPbPbv2[NLYZPbPb] >> LYZPbPbv2e[NLYZPbPb] >> LYZPbPbv2s[NLYZPbPb];
		NLYZPbPb++;
	}
	NLYZPbPb--;


	TGraphErrors * grLYZpPbv2 = new TGraphErrors(NLYZpPb, LYZpPbnoff, LYZpPbv2, 0, LYZpPbv2e);
	grLYZpPbv2->SetMarkerStyle(kFullCircle);
	grLYZpPbv2->SetMarkerColor(kBlack);
	grLYZpPbv2->SetLineColor(kBlue);
	grLYZpPbv2->SetMarkerSize(1.5);

	TGraphErrors * grLYZpPbv2s = new TGraphErrors(NLYZpPb, LYZpPbnoff, LYZpPbv2, 0, LYZpPbv2s);
	grLYZpPbv2s->SetMarkerStyle(kFullCircle);
	grLYZpPbv2s->SetMarkerColor(kBlack);
	grLYZpPbv2s->SetLineColor(kBlue);
	grLYZpPbv2s->SetMarkerSize(1.5);


	TGraphErrors * grLYZPbPbv2 = new TGraphErrors(NLYZPbPb, LYZPbPbnoff, LYZPbPbv2, 0, LYZPbPbv2e);
	grLYZPbPbv2->SetMarkerStyle(kFullCircle);
	grLYZPbPbv2->SetMarkerColor(kBlack);
	grLYZPbPbv2->SetLineColor(kBlue);
	grLYZPbPbv2->SetMarkerSize(1.5);

	TGraphErrors * grLYZPbPbv2s = new TGraphErrors(NLYZPbPb, LYZPbPbnoff, LYZPbPbv2, 0, LYZPbPbv2s);
	grLYZPbPbv2s->SetMarkerStyle(kFullCircle);
	grLYZPbPbv2s->SetMarkerColor(kBlack);
	grLYZPbPbv2s->SetLineColor(kBlue);
	grLYZPbPbv2s->SetMarkerSize(1.5);
}
