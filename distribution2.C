void distribution2()
{
    int max_multiplicity = 0;
    TGraph *gr = new TGraph();
    gr->SetMarkerStyle(6);
    gr->GetXaxis()->SetTitle("Multiplicity");
    gr->GetYaxis()->SetTitle("Px (GeV)");
    gr->SetTitle("Px distribution versus multiplicity");

    fstream file;
    file.open("data2.txt", ios::in);
    while (1)
    {
        float x, y;
        file >> x >> y;
        if (x > max_multiplicity)
            max_multiplicity = x;
        gr->SetPoint(gr->GetN(), x, y);
        if (file.eof())
            break;
    }
    file.close();
    
    TGraph *gr1 = new TGraph();
    gr1->SetMarkerColor(kRed);
    gr1->SetLineColor(kRed);
    gr1->SetMarkerStyle(kFullCircle);
    for (int i = 1; i < max_multiplicity+1; i++)
    {
        float num = 0;
        float total = 0;
        fstream file;
        file.open("data2.txt",ios::in);
        while (1)
        {
            float x, y;
            file >> x >> y;
            if (x == i)
            {
                num += 1;
                total += y;
            }
            if (file.eof())
                break;
        }
        
        float mean = total/num;
        cout << mean << endl;
        gr1->SetPoint(gr1->GetN(), i,mean);
    	file.close();
    }
    TCanvas *c1 = new TCanvas();  
    gr->Draw("AP");
    gr1->Draw("PL");

}
