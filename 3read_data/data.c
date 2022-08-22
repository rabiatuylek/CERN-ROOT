void data()
{

    TH1F *hist = new TH1F("hist", "Histogram", 20, 0, 20);  
    
    fstream file;
    file.open("data.txt", ios::in);
    
    double value;
    
    while(1)
    {
        file >> value;
        
        hist->Fill(value);
        if(file.eof()) break;
        
    
    }

    hist->GetXaxis()->SetTitle("Grade");  
    hist->GetYaxis()->SetTitle("Entries");
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();     // create Hist

}
