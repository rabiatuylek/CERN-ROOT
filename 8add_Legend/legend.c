void legend()
{

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 10);  
    
    //Random Generator
    TRandom2 *rand = new TRandom2(3);

    
    fstream file;
    file.open("data2.txt", ios::out);
    
    //create gaussian
    for (int i=0; i <1000; i++)
    {
        double r;
        r= rand->Gaus(5,1);
        file <<r << endl;
        
    }
        
    file.close();
    file.open("data2.txt", ios::in);
    
    double value;
    
    //create histogram
    while(1)
    {
        file >> value;
        
        hist->Fill(value);
        if(file.eof()) break;
        
    
    }

    hist->GetXaxis()->SetTitle("Distribution");  
    hist->GetYaxis()->SetTitle("Entries");
    
    //TF1 *fit = new TF1("fit", "gaus", 0,10);  //from 0 to 10 at x axis
    TF1 *fit = new TF1("fit", "gaus", 0,10);  
    
    fit->SetParameter(0,40);
    fit->SetParameter(1, 5);
    fit->SetParameter(2,1);
    
    TCanvas *c1 = new TCanvas();
    hist->SetStats(0);
    hist->Draw();     // create Hist
    
    hist->Fit("fit"); 
    // We can write gaussian distribution that we want >>> R
    
    //Add Legends
    TLegend *leg = new TLegend(0.6, 0.7, 0.9, 0.9);
    leg->AddEntry(hist, "Measured Data", "l");
    leg->AddEntry(fit, "Fit Function","l");
    leg->Draw();
    
    
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    
    cout << mean/sigma << endl;

}
