void histArithmetic(){

    TH1F *hist1 = new TH1F("hist1", "Histogram", 100, -10, 10);
    TH1F *hist2 = new TH1F("hist2", "Histogram", 100, -10, 10);
    
    hist1->FillRandom("gaus");
    hist2->FillRandom("gaus");
    
    //hist1->Scale(10);   //for up   
    //hist1->Scale(-10);   // for bottom
    
    hist1->Add(hist2);
    
    TH1F *hist3 = new TH1F();
    *hist3 = (*hist1)/(*hist2);
    
    
    TCanvas *c1 = new TCanvas();   
    hist1->Draw("hist");
    hist3->Draw("hist");
}
