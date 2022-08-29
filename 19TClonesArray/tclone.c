void write(){

    TClonesArray *arr = new TClonesArray("TVector3");
    TClonesArray &ar = *arr;

    TFile *file = new TFile("file.root", "recreate");
    
    TTree *tree = new TTree("tcl", "tcl");
    
    tree->Branch("array", &arr);
    
    TRandom2 *rand = new TRandom2(1);
    for(int i=0; i<100; i++)
    {
        arr->Clear();
        for(int j=0; j<1000; j++)
        
        {
            double x = rand->Rndm();
            double y = rand->Rndm();
            double z = rand->Rndm();
            
            new (ar[j]) TVector3(x,y,z);
            
        }
        tree->Fill();
    
    }
    
    file->Write();
    file->Close();

}

void read()
{
    TFile *file = new TFile("file.root");
    
    TTree * tree = (TTree*)file->Get("tcl");
    
    TClonesArray *arr = new TClonesArray("TVector3");
    
    tree->SetBranchAddress("array", &arr);
    
    int entries = tree->GetEntries();
    for(int a=0; a < entries; a++)
    {
        tree->GetEntry(a);
        int lines = arr->GetEntries();
        
        for (int b=0; b < lines; b++)
        {
            TVector3 *vec = (TVector3*)arr->At(b);
            cout << vec->X()  << endl;
        }
    }

}

void tclone()
{
    write();
    read();
}
