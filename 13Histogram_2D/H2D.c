void H2D(){

    TCanvas *c1 = new TCanvas();
    
    gStyle->SetPalette(kRainBow);  // principle
    
    TH2F *hist = new TH2F("hist", "Histogram", 100, -1, 1, 100, -1,1);
    
    hist->SetStats(0);
    
    TRandom *rand = new TRandom(10);
    for(int i=0; i< 1e7; i++)
    {
    double x = rand->Gaus();
    double y = rand->Gaus();
    
    hist->Fill(x,y);
    }
    
    //Names  
    hist->GetXaxis()->SetTitle("x [cm]");
    hist->GetYaxis()->SetTitle("y [cm]");
    hist->GetZaxis()->SetTitle("Entries");
    //hist->Draw();
    hist->SetContour(1000);
    hist->Draw("colz");


}
