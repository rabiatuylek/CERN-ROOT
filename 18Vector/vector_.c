void vector_() {

    TVector3 v1(1,2,3);  // v(X,Y,Z)
    // v1[0] = x
    // v1[1] = y
    // v1[2] = z
    
    cout << v1.X() << endl;
    cout << v1.Y() << endl;
    cout << v1.Z() << endl;
    cout << v1[2] << endl;
    
    v1.Print();
    // result of print function >> TVector3 A 3D physics vector (x,y,z)=(1.000000,2.000000,3.000000) (rho,theta,phi)=(3.741657,36.699225,63.434949)
}
