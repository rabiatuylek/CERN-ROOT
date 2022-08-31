void Object3D(){

    TCanvas *c1 = new TCanvas();
    
    // create box apart  ----> TGeoVolume and TGeoManager 
    TGLViewer *view = (TGLViewer*)gPad->GetViewer3D();
    
    TGeoManager *man = new TGeoManager();
    
    TGeoVolume *top = gGeoManager->MakeBox("TOP", NULL, 10, 10, 10);
    
    TGeoVolume *box = gGeoManager->MakeBox("BOX", NULL, 1, 1, 0.2);
    
    box->SetLineColor(kGreen);
    
        
    TGeoHMatrix *trans_rot = new TGeoHMatrix("TRANSROT");  // to rotate
    trans_rot->RotateX(135.);
    trans_rot->SetDz(2.);
    
    
    TGeoVolume *tube = man->MakeTube("TUBE", NULL, 0.5, 1.0, 1.0);
    
    
    man->SetTopVolume(top);
    //to add any objects -> AddNode()
    top->AddNode(box, 0);
    top->AddNode(box, 1, trans_rot);
    top->AddNode(tube, 2);
    
    man->CloseGeometry();
    
    top->Draw("ogl");   // to show ROOT's GL Viewer
    
    TPolyLine3D *l = new TPolyLine3D();
    l->SetLineColor(kRed);
    l->SetPoint(0,0,0,0);
    l->SetPoint(1,1,1,1);
    l->SetPoint(2,0,0,2);
    l->Draw("same");

}
