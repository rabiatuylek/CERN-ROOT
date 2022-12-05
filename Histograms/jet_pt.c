////////////////////// ELECTRON ETA /////////////////////////
void jet_pt(){

    TCanvas *c1 = new TCanvas();
    
    TFile *file = new TFile("top-ljets-input.root", "read");  

    TTree *nominal = (TTree*)file->Get("nominal");

      
    double Particle;    
    nominal->SetBranchAddress("jet_pt", &Particle);
    
    
    int entries = nominal->GetEntries();   
    TH1F *hist = new TH1F("hist", "Histogram of Jet Transverse Momentum", 140,0,570);

    
    for(int i=0; i<entries; i++)
    {
        nominal->GetEntry(i);
        
        hist->Fill(Particle);
        
    }   
 
    hist->SetLineColor(0);
    hist->SetFillColor(kOrange-3);
    hist->GetXaxis()->SetTitle("X Axis: PT");
    hist->GetYaxis()->SetTitle("Y Axis: Number");
    nominal->Draw("jet_pt>>hist");
    //gPad->BuildLegend();
    c1->Print("jet_pt.pdf");
}
