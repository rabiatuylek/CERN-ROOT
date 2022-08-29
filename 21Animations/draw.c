void draw(){

    TCanvas *c1 = new TCanvas("c1", "c1", 600,600);
    TEllipse *ellipse = new TEllipse(0.5, 0.5, 0.1, 0.1);
    
    ellipse->SetFillColor(kBlue);
    
    gSystem->Unlink("draw.gif");
    
    for(int i=0; i<50; i++)
    {
        ellipse->SetX1(0.5+i*0.1);
        ellipse->Draw();
        c1->Update(); 
        c1->Print("draw.gif+");   //depend on speed of histogram
        //sleep(1);  
    }
    
}

//xdg-open draw.gif
