//create object browser

void object()
{

    TFile *file = new TFile("output.root", "RECREATE");   //TFile can open TBrowser
    TH1F *hist = new TH1F("hist", "Histogram", 100, 0,100);
    
    hist->Fill(10);
    hist->Fill(90);
    
    //hist->Draw();
    file->Write();
    file->Close();

}

// run and terminal -> ls *.root -> new TBrowser
