// Open empty Histogram

void tutorial1()
{

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 100);  //determine intervals start from 0 for x axis
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();     // create Hist

}
