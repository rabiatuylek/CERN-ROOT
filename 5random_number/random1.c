
//generate 3 random numbers
void random1()

{
    TRandom2 *rand = new TRandom2();
    for(int i=0; i<3; i++)
    {
        double r = rand->Rndm();
        
        cout << r << endl;
    }

}
