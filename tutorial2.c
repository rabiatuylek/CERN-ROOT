void tutorial2()
{

    TH1F *hist = new TH1F("hist", "Histogram", 50, 25, 50);  //determine intervals and start from 25 for x axis
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();     // create Hist

}
