/*
 * =====================================================================================
 *
 *       Filename:  OLLITRAULT.C
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/25/2014 19:43:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */


{
//	TF1 * fx = new TF1("fx", "((2/((exp(x)+1)**2*(exp(x)+2)))**.25)/(sqrt(1/(exp(x)+1)))", -8, 8);
//	TF1 * fv86 = new TF1("fv86", "((48*(1+5*exp(x)/11)/((exp(x)+1)**4*(exp(x)+2)**2*(exp(x)+3)*(exp(x)+4)))**(1./8.))/((6/((exp(x)+1)**3*(exp(x)+2)*(exp(x)+3)))**(1./6.))", -8, 8);
//	TF1 * fv64 = new TF1("fv64", "((6/((exp(x)+1)**3*(exp(x)+2)*(exp(x)+3)))**(1./6.))/((2/((exp(x)+1)**2*(exp(x)+2)))**.25)", -8, 8);
//
//	double dx[8000], d86[8000], d64[8000];
//	TH1D * hx = new TH1D("hx", "hx", 8000, -8, 8);
//	for ( int i = 0; i < 8000; i++ ) {
//		double x = hx->GetBinCenter(i+1);
//		dx[i] = fx->Eval(x);
//		d86[i] = fv86->Eval(x);
//		d64[i] = fv64->Eval(x);
//	}
//	TGraph * gr86 = new TGraph(8000, dx, d86);
//	TGraph * gr64 = new TGraph(8000, dx, d64);

	TF1 * ffit64 = new TF1("ffit64", "pol6", 0.2, 1);
	TF1 * ffit86 = new TF1("ffit86", "pol6", 0.2, 1);
	ffit64->SetParameters(0.318186, 2.25153, -4.95326, 8.50799, -9.04852, 5.1117, -1.18764);
	ffit86->SetParameters(0.592835, 1.69652, -4.30736, 7.82505, -8.72909, 5.15827, -1.23624);

	ffit64->SetLineColor(kBlue);
	ffit86->SetLineColor(kRed);
	ffit64->SetLineWidth(3);
	ffit86->SetLineWidth(3);
}
