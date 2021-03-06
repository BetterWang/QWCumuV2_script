void LoadData();
TGraphErrors * g6_PbPb;
TGraphErrors * g8_PbPb;
TGraphErrors * g6_pPb;
TGraphErrors * g8_pPb;

void cResults(Bool_t IsPreliminary = kTRUE){
  LoadData();
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
  g6_PbPb->Draw("p");


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
  g6_pPb->Draw("p");

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
  g8_PbPb->Draw("p");


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
  g8_pPb->Draw("p");

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
  if(IsPreliminary) prelim->Draw();

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
  if(IsPreliminary) prelim2->Draw();

  p4->cd();
  TLegend * legc26 = new TLegend(0.6, 0.75, 0.9, 0.9);
  legc26->SetFillColor(kWhite);
  legc26->SetBorderSize(0);
  legc26->SetTextFont(43);
  legc26->SetTextSize(24);
  legc26->AddEntry(g6_pPb, "c_{2}{6}", "p");
  legc26->AddEntry(g8_pPb, "#scale[1.1]{|} c_{2}{8} #scale[1.1]{|}", "p");
  legc26->Draw();

//  p1->cd();
//  g8_PbPb->Draw("p");
//  p2->cd();
//  g8_pPb->Draw("p");
//  p4->cd();
//  TLegend * legc28 = new TLegend(0.6, 0.8, 0.9, 0.88);
//  legc28->AddEntry(g8_pPb, "c_{2}{8}");
//  legc28->Draw();

  c->Print("cResults.pdf","pdf");
}
void LoadData(){
  g6_PbPb = new TGraphErrors();
  Int_t ci;   // for color index setting
  ci = TColor::GetColor("#0000ff");
  g6_PbPb->SetMarkerColor(ci);
  g6_PbPb->SetMarkerStyle(34);
  g6_PbPb->SetMarkerSize(2.5);
  g6_PbPb->SetPoint(0,334.3291,1.263856e-06);
  g6_PbPb->SetPointError(0,0,6.791055e-08);
  g6_PbPb->SetPoint(1,309.4283,1.170796e-06);
  g6_PbPb->SetPointError(1,0,6.35926e-08);
  g6_PbPb->SetPoint(2,289.4099,1.128812e-06);
  g6_PbPb->SetPointError(2,0,6.312395e-08);
  g6_PbPb->SetPoint(3,269.4217,1.004198e-06);
  g6_PbPb->SetPointError(3,0,5.404879e-08);
  g6_PbPb->SetPoint(4,249.3933,9.581513e-07);
  g6_PbPb->SetPointError(4,0,5.372999e-08);
  g6_PbPb->SetPoint(5,229.3969,8.675316e-07);
  g6_PbPb->SetPointError(5,0,4.884535e-08);
  g6_PbPb->SetPoint(6,201.6081,7.547818e-07);
  g6_PbPb->SetPointError(6,0,4.268482e-08);
  g6_PbPb->SetPoint(7,166.5178,5.982704e-07);
  g6_PbPb->SetPointError(7,0,3.349665e-08);
  g6_PbPb->SetPoint(8,134.0666,4.689241e-07);
  g6_PbPb->SetPointError(8,0,3.065547e-08);
  g6_PbPb->SetPoint(9,109.2678,3.139551e-07);
  g6_PbPb->SetPointError(9,0,2.819735e-08);
  g6_PbPb->SetPoint(10,89.19993,2.989719e-07);
  g6_PbPb->SetPointError(10,0,4.038939e-08);
  g6_PbPb->SetPoint(11,69.11907,1.809245e-07);
  g6_PbPb->SetPointError(11,0,3.267492e-08);
  g6_PbPb->SetPoint(12,54.38495,1.884786e-07);
  g6_PbPb->SetPointError(12,0,7.121699e-08);
  g6_PbPb->SetLineColor(ci);
  g6_PbPb->SetLineWidth(2);

  g8_PbPb = new TGraphErrors();
  ci = TColor::GetColor("#ff0000");
  g8_PbPb->SetMarkerColor(ci);
  g8_PbPb->SetMarkerStyle(33);
  g8_PbPb->SetMarkerSize(2.5);
  g8_PbPb->SetPoint(0,334.3291,-6.988154e-08);
  g8_PbPb->SetPointError(0,0,4.122669e-09);
  g8_PbPb->SetPoint(1,309.4283,-6.302726e-08);
  g8_PbPb->SetPointError(1,0,3.754912e-09);
  g8_PbPb->SetPoint(2,289.4099,-5.897859e-08);
  g8_PbPb->SetPointError(2,0,3.653536e-09);
  g8_PbPb->SetPoint(3,269.4217,-5.080976e-08);
  g8_PbPb->SetPointError(3,0,3.016349e-09);
  g8_PbPb->SetPoint(4,249.3933,-4.731714e-08);
  g8_PbPb->SetPointError(4,0,3.078039e-09);
  g8_PbPb->SetPoint(5,229.3969,-4.188283e-08);
  g8_PbPb->SetPointError(5,0,2.743045e-09);
  g8_PbPb->SetPoint(6,201.6081,-3.475046e-08);
  g8_PbPb->SetPointError(6,0,2.392471e-09);
  g8_PbPb->SetPoint(7,166.5178,-2.479856e-08);
  g8_PbPb->SetPointError(7,0,1.724027e-09);
  g8_PbPb->SetPoint(8,134.0666,-1.82347e-08);
  g8_PbPb->SetPointError(8,0,1.65889e-09);
  g8_PbPb->SetPoint(9,109.2678,-1.110826e-08);
  g8_PbPb->SetPointError(9,0,1.546493e-09);
  g8_PbPb->SetPoint(10,89.19993,-1.086704e-08);
  g8_PbPb->SetPointError(10,0,2.087203e-09);
  g8_PbPb->SetPoint(11,69.11907,-9.133598e-09);
  g8_PbPb->SetPointError(11,0,2.524928e-09);
  for(int i = 0; i<g8_PbPb->GetN(); i++) g8_PbPb->GetY()[i] = -g8_PbPb->GetY()[i];
  g8_PbPb->SetLineColor(ci);
  g8_PbPb->SetLineWidth(2);

  g6_pPb = new TGraphErrors();
  ci = TColor::GetColor("#0000ff");
  g6_pPb->SetMarkerColor(ci);
  g6_pPb->SetMarkerStyle(34);
  g6_pPb->SetMarkerSize(2.5);
  g6_pPb->SetPoint(0,270.5324,5.19113e-08);
  g6_pPb->SetPointError(0,0,1.577041e-08);
  g6_pPb->SetPoint(1,247.1666,1.659792e-08);
  g6_pPb->SetPointError(1,0,6.82928e-09);
  g6_pPb->SetPoint(2,227.4712,3.143868e-08);
  g6_pPb->SetPointError(2,0,4.27221e-09);
  g6_pPb->SetPoint(3,196.6572,3.320824e-08);
  g6_pPb->SetPointError(3,0,3.661674e-09);
  g6_pPb->SetPoint(4,162.1051,3.23488e-08);
  g6_pPb->SetPointError(4,0,4.28718e-09);
  g6_pPb->SetPoint(5,131.3418,4.30414e-08);
  g6_pPb->SetPointError(5,0,6.874563e-09);
  g6_pPb->SetPoint(6,108.1824,5.286987e-08);
  g6_pPb->SetPointError(6,0,2.643025e-08);
  g6_pPb->SetLineColor(ci);
  g6_pPb->SetLineWidth(2);
  
  g8_pPb = new TGraphErrors();
  ci = TColor::GetColor("#ff0000");
  g8_pPb->SetMarkerColor(ci);
  g8_pPb->SetMarkerStyle(33);
  g8_pPb->SetMarkerSize(2.5);
  g8_pPb->SetPoint(0,196.6572,-3.779896e-10);
  g8_pPb->SetPointError(0,0,1.647435e-10);
  g8_pPb->SetPoint(1,162.1051,-5.716761e-10);
  g8_pPb->SetPointError(1,0,1.793562e-10);
  g8_pPb->SetPoint(2,131.3418,-6.971042e-10);
  g8_pPb->SetPointError(2,0,3.012141e-10);
  g8_pPb->SetPoint(3,108.1824,-3.447458e-09);
  g8_pPb->SetPointError(3,0,1.221046e-09);
  for(int i = 0; i<g8_pPb->GetN(); i++) g8_pPb->GetY()[i] = -g8_pPb->GetY()[i];
  g8_pPb->SetLineColor(ci);
  g8_pPb->SetLineWidth(2);
  
}
