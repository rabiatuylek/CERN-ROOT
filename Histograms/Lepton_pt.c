////////////////////// ELECTRON ETA /////////////////////////
void Lepton_pt(){

    TCanvas *c1 = new TCanvas();
    
    TFile *file = new TFile("top-ljets-input.root", "read");  

    TTree *nominal = (TTree*)file->Get("nominal");

      
    double Particle;    
    nominal->SetBranchAddress("lepton_pt", &Particle);
    
    
    int entries = nominal->GetEntries();   
    TH1F *hist = new TH1F("hist", "Histogram of Lepton Transverse Momentum", 170,0,370);

    
    for(int i=0; i<entries; i++)
    {
        nominal->GetEntry(i);
        
        hist->Fill(Particle);
        
    }   
 
    hist->SetLineWidth(0);
    hist->SetFillColor(kAzure+1);
    hist->GetXaxis()->SetTitle("X Axis: PT");
    hist->GetYaxis()->SetTitle("Y Axis: Number");
    nominal->Draw("lepton_pt>>hist");
    //gPad->BuildLegend();
    c1->Print("Lepton_pt.pdf");
}
