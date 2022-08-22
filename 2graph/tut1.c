// create graph

void tut1()
{
    double x[6] = {1,2,3,3.5,4,5};
    double y[6] = {1,4,9,12,16,25};
    
    TGraph *gr = new TGraph(6,x,y);  // 5 points
    
    TCanvas *c1 = new TCanvas();
    
    gr->Draw("AL*");

}
