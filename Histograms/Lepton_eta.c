////////////////////// ELECTRON ETA /////////////////////////
void Lepton_eta(){

    TCanvas *c1 = new TCanvas();
    
    TFile *file = new TFile("top-ljets-input.root", "read");  

    TTree *nominal = (TTree*)file->Get("nominal");

      
    double Particle;    
    nominal->SetBranchAddress("lepton_eta", &Particle);
    
    
    int entries = nominal->GetEntries();   
    TH1F *hist = new TH1F("hist", "Histogram of Lepton Eta", 170,-3,3);

    
    for(int i=0; i<entries; i++)
    {
        nominal->GetEntry(i);
        
        hist->Fill(Particle);
        
    }   
    gStyle->SetPalette(kOcean); 
    hist->SetLineColor(kBlue);
    hist->SetLineWidth(1);
    hist->SetFillColor(63);
    hist->GetXaxis()->SetTitle("X Axis: Eta");
    hist->GetYaxis()->SetTitle("Y Axis: Number");
    hist->Draw();
    nominal->Draw("lepton_eta>>hist");

    c1->Print("Lepton_eta.pdf");
}
