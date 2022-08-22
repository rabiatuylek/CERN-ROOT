void data2()
{

    TH1F *hist = new TH1F("hist", "Histogram", 100, 0, 15);  
    
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
    
    hist->SetFillColor(kGreen-9);  //color of histogram

    hist->GetXaxis()->SetTitle("Distribution");  
    hist->GetYaxis()->SetTitle("Entries");
    
    hist->GetXaxis()->SetTitleSize(0.05);
    hist->GetYaxis()->SetTitleSize(0.05);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetLabelSize(0.05);
    
    
    //TF1 *fit = new TF1("fit", "gaus", 0,10);  //from 0 to 10 at x axis
    TF1 *fit = new TF1("fit", "gaus", 0,10); 
    
    fit->SetLineWidth(4);  //width of line(gauss fit)
    fit->SetLineColor(kBlue);
    fit->SetLineStyle(3);   // to arrange line style
    
    fit->SetParameter(0,40);
    fit->SetParameter(1, 5);
    fit->SetParameter(2,1);
    
    TCanvas *c1 = new TCanvas();
    hist->SetStats(0);
    c1->SetTickx();
    c1->SetTicky();
    
    c1->SetGridx();
    c1->SetGridy();
    hist->Draw();     // create Hist
    
    hist->Fit("fit"); 
    // We can write gaussian distribution that we want >>> R
    
    //Add Legends
    TLegend *leg = new TLegend(0.5, 0.6, 0.8, 0.8);
    leg->SetBorderSize(0);  // to cancel border of board
    leg->AddEntry(hist, "Measured Data", "f");
    leg->AddEntry(fit, "Fit Function","l");
    leg->Draw();
    
    // to write line
    TLine *l = new TLine(0,20,15,20);
    l->SetLineWidth(2);
    l->SetLineColor(kOrange);
    l->Draw();
    
    double x0= 6.3;
    int bin = hist->FindBin(x0);
    double y0 = hist->GetBinContent(bin);
    
    TArrow *arr = new TArrow(10,30,x0,y0);
    arr->SetLineWidth(2);
    arr->SetArrowSize(0.02);
    arr->SetLineColor(kRed);
    arr->Draw();
    
    //Latex
    TLatex *t = new TLatex(10, 30, "Important Point");
    t->Draw();
    
    double mean = fit->GetParameter(1);
    double sigma = fit->GetParameter(2);
    
    cout << mean/sigma << endl;

}
