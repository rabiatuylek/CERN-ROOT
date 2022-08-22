void tutorial3()
{

    TH1F *hist = new TH1F("histt", "Histogram", 100, 0, 100);  
    
    hist->Fill(10); //fulfill for 10 at x-axis
    hist->Fill(90);
    
    // Write Names of Axises
    hist->GetXaxis()->SetTitle("X Axis");  
    hist->GetYaxis()->SetTitle("Y Axis");
    
    TCanvas *c1 = new TCanvas();   // to see Histogram
    hist->Draw();     // create Hist

}
