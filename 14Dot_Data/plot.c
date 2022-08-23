void plot(){

    TCanvas *c1 = new TCanvas();
    
    TProfile *hprof = new TProfile("hprof", "Prof", 100,0,10, "S"); // first : for small box & second: title of graph
    
    TRandom2 *rand = new TRandom2();
    
    for (int i=0; i<1000; i++){
    
    hprof->Fill(rand->Rndm()*10, rand->Rndm());
    //hprof->Fill(1, rand->Rndm());
   
    }
    
    hprof->Draw();
}
