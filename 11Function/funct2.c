// Create Funtion

void funct2(){

    TCanvas *c1 = new TCanvas();
    
    TF1 *f = new TF1("f", "exp(-[1]*x)*[0]*sin(x)", 0,10*TMath::Pi());
    
    //f->SetTitle(""); // if we want empty title of graph
    
    f->SetParameter(0,1);
    f->SetParameter(1, 0.1);
    f->SetLineColor(kBlue);
    
    f->Draw();
    

    
       
}
