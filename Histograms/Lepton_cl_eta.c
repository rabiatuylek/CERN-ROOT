////////////////////// ELECTRON ETA /////////////////////////
void Lepton_cl_eta(){

    TCanvas *c1 = new TCanvas();
    
    TFile *file = new TFile("top-ljets-input.root", "read");  

    TTree *nominal = (TTree*)file->Get("nominal");

      
    double Particle;    
    nominal->SetBranchAddress("lepton_cl_eta", &Particle);
    
    
    int entries = nominal->GetEntries();   
    TH1F *hist = new TH1F("hist", "Histogram of Lepton cl Eta", 170,-3,3);

    
    for(int i=0; i<entries; i++)
    {
        nominal->GetEntry(i);
        
        hist->Fill(Particle);
        
    }   
 
    hist->SetLineColor(kBlue);
    hist->SetLineWidth(1);
    hist->SetFillColor(68);
    hist->GetXaxis()->SetTitle("X Axis: Eta");
    hist->GetYaxis()->SetTitle("Y Axis: Number");
    nominal->Draw("lepton_cl_eta>>hist");
    //gPad->BuildLegend();
    c1->Print("lepton_cl_eta.pdf");
}
