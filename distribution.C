void distribution()
{
    TH1F *hist = new TH1F("hist","Distribution of the final-state proton energy",50,-0.1,0.1);
    fstream file;
    file.open("data.txt",ios::in);
    hist->SetLineColor(1000);
    float value;
    while(1)
    {
        file >> value;
        hist->Fill(value);
        if (file.eof())
            break;
    }
    
    file.close();
    hist->GetXaxis()->SetTitle("E (GeV)");
    hist->GetYaxis()->SetTitle("Count");
    
    TCanvas *c1 = new TCanvas();
    hist->Draw();

}
