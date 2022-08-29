void vector2() {

    TVector3 v1(1,2,3);  // v(X,Y,Z)   

    v1.Print();
    
    double rho = v1.Mag();
    double theta = v1.Theta()*180./TMath::Pi();
    double phi = v1.Phi();
    
    cout << rho << "\t" << theta << "\t" << phi << endl;
    
    v1.RotateZ(90*TMath::Pi()/180.);  // to rotate Z = Z+90    
    v1.Print();
    
    
    //TVector3 v2;
    TVector3 v2(4,5,6);
    v2.SetX(4);
    v2.SetY(5);
    v2.SetZ(6);
    
    v2.Print();
    
    TVector3 v3 = v1 + v2;
    v3.Print("");
    
    cout << v1.Dot(v2) << endl;
  
}
