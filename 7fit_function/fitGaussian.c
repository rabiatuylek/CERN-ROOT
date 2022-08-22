void fitGaussian()
{

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 10);  
    
    //Random Generator
    TRandom2 *rand = new TRandom2(3);

    
    fstream file;
    file.open("data.txt", ios::out);
    
    //create gaussian
    for (int i=0; i <1000; i++)
    {
        double r;
        r= rand->Gaus(5,1);
        file <<r << endl;
        
    }
        
    file.close();
    file.open("data.txt", ios::in);
    
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
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();     // create Hist
    
    hist->Fit("gaus");  //Fit

}
