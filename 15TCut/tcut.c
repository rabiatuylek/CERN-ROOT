void write(){

    TFile *output = new TFile("tcut.root", "recreate");
    
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






void tcut(){

    write();

}
