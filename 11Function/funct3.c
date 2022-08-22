// Create Funtion

void funct3(){

    TCanvas *c1 = new TCanvas();
    
    TF1 *func = new TF1("func", "exp(-[1]*x)*[0]*sin(x)", 0,10*TMath::Pi());
    
    //f->SetTitle(""); // if we want empty title of graph
    
    func->SetParameter(0,1);
    func->SetParameter(1, 0.1);
    func->SetLineColor(kBlue);
    
    func->GetXaxis()->SetTitle("Test");
    func->GetYaxis()->SetTitle("Test");
    
    func->Draw();
    
    c1->Print("func3.png");  //record file in terms of png   
       
}
