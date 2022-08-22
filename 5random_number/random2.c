//Combine
// random data with Histogram

void random2()

{
    TRandom2 *rand = new TRandom2();
    
    //Combinig Histogram Step
    TH1F *hist = new TH1F("hist", "Histogram", 50,0,100);
         
    
    for(int i=0; i<1000; i++)
    {
        double r = rand->Rndm()*100;
        
        cout << r << endl;
        hist->Fill(r);   //thats so important
    }
    
    TCanvas *c1 = new TCanvas();
    hist->GetYaxis()->SetRangeUser(0,200); // arrange number of Y axis that We want 
    hist->Draw();

}
