////////////////////// ELECTRON ETA /////////////////////////
void met_phi(){

    TCanvas *c1 = new TCanvas();
    
    TFile *file = new TFile("top-ljets-input.root", "read");  

    TTree *nominal = (TTree*)file->Get("nominal");

      
    double Particle;    
    nominal->SetBranchAddress("met_phi", &Particle);
    
    
    int entries = nominal->GetEntries();   
    TH1F *hist = new TH1F("hist", "Histogram of MET Phi", 170,-3.8,3.7);

    
    for(int i=0; i<entries; i++)
    {
        nominal->GetEntry(i);
        
        hist->Fill(Particle);
        
    }   
 
    hist->SetLineColor(kOrange);
    hist->SetLineWidth(0);
    hist->SetFillColor(11);
    hist->GetXaxis()->SetTitle("X Axis: Phi");
    hist->GetYaxis()->SetTitle("Y Axis: Number");
    nominal->Draw("met_phi>>hist");
    //gPad->BuildLegend();
    c1->Print("met_phi.pdf");
}
