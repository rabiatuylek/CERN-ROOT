void write(){

    TFile *output = new TFile("tcut2.root", "recreate");
   
    TTree *tree = new TTree("tree", "tree");
    
    double x,y;
    // to create trees
    tree->Branch("x", &x, "x/D");
    tree->Branch("y", &y, "y/D");
    
    TRandom2 *r = new TRandom2();  //created random number with TRandom2
    
    for(int i=0; i<1e6; i++){
        x = 1+(r->Rndm()*9);
        y =x*2;
        tree->Fill();
    }
    
    output->Write();
    output->Close();
}

void cut(){

    //TCut cut1 = "x > 5";
    //TCut cut2 = "x < 6";
    TCut cut1 = "x < 5";
    TCut cut2 = "x > 6";
    
    TFile *input = new TFile("tcut2.root", "read");  // to run root tcut2.root on terminal
    
    TTree *tree = (TTree*)input->Get("tree");
    
    //tree->Draw("y", cut1&&cut2);
    tree->Draw("y", cut1||cut2);
}

void tcut2(){

    write();
    cut();
}
