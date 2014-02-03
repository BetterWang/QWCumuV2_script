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
	ifstream fLYZpt("txt/Shengquan_pPbLYZpt.txt");
	ifstream fLYZnoff("txt/Shengquan_pPbLYZnoff.txt");
	double LYZpt[10];
	double LYZnoff[10];
	double LYZv2pt[10];
	double LYZv2pte[10];
	double LYZv2noff[10];
	double LYZv2noffe[10];
	int NLYZpt=0;
	int NLYZnoff=0;
	while (!fLYZpt.eof())
	{
		fLYZpt >> LYZpt[NLYZpt] >> LYZv2pt[NLYZpt] >> LYZv2pte[NLYZpt];
		NLYZpt++;
	}
	NLYZpt--;
	while (!fLYZnoff.eof())
	{
		fLYZnoff >> LYZnoff[NLYZnoff] >> LYZv2noff[NLYZnoff] >> LYZv2noffe[NLYZnoff];
		NLYZnoff++;
	}
	NLYZnoff--;
	TGraphErrors * grLYZpt = new TGraphErrors(NLYZpt, LYZpt, LYZv2pt, 0, LYZv2pte);
	TGraphErrors * grLYZnoff = new TGraphErrors(NLYZnoff, LYZnoff, LYZv2noff, 0, LYZv2noffe);

	grLYZpt->SetMarkerStyle(kFullCircle);
	grLYZpt->SetMarkerColor(kGreen);
	grLYZpt->SetLineColor(kBlue);
	grLYZpt->SetMarkerSize(1.5);

	grLYZnoff->SetMarkerStyle(kFullCircle);
	grLYZnoff->SetMarkerColor(kGreen);
	grLYZnoff->SetLineColor(kBlue);
	grLYZnoff->SetMarkerSize(2.5);
}
