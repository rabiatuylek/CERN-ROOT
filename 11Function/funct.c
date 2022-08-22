// Create Funtion

void funct(){

    TCanvas *c1 = new TCanvas();
    
    TF1 *func = new TF1("func", "[0] + [1]*x", 0,5);
    
    func->SetParameter(0,1);
    func->SetParameter(1,2);
    
    func->Draw();
    
    
    
}
