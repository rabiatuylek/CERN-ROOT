void animation_hist(){

    TCanvas *c1 = new TCanvas();
    TH1F *hist = new TH1F("hist", "Histogram", 100,-5,5);
    
    gSystem->Unlink("animation_hist.gif");   //gSystem >> to create gif
    
    TRandom *r1 = new TRandom();
    
    for(int i=0; i<1e5; i++)
    {
        double val;
        val = r1->Gaus();
        
        hist->Fill(val);

        c1->Update();  // provide continuity
        if(i%100 == 0)
        {
            hist->Draw();
            hist->Fit("gaus");
            c1->Modified();
            c1->Print("animation_hist.gif+"); 
        }
        //sleep(1);
    
    }


}
