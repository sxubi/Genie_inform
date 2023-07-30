void distribution3() {
   
   // create two histograms
   TH1F *h1 = new TH1F("h1","Pz distribution for final-state positrons(e+)",300,-0.5,0.5);
   TH1F *h2 = new TH1F("h2","0.3 GeV",300,-0.5,0.5);
   TH1F *h3 = new TH1F("h3","0.5 GeV",300,-0.5,0.5);
   double value;
   
   fstream file1;
   file1.open("electron_-12_0.1_pz.txt");
   while(1)
   {
   	file1 >> value;
   	h1->Fill(value);
   	if (file1.eof())
   	    break;
   }
   file1.close();
   
   fstream file2;
   file2.open("electron_-12_0.3_pz.txt");
   while(1)
   {
   	file2 >> value;
   	h2->Fill(value);
   	if (file2.eof())
   	    break;
   }
   file2.close();
   
   fstream file3;
   file3.open("electron_-12_0.5_pz.txt");
   while(1)
   {
   	file3 >> value;
   	h3->Fill(value);
   	if (file3.eof())
   	    break;
   }
   file3.close();
   
   TColor *color1 = new TColor(2221, 179, 0, 0);
   TColor *color2 = new TColor(2222, 0, 134, 179);
   TColor *color3 = new TColor(2223, 47, 79, 79);
   
   h1->SetStats(0);
   h1->SetLineColor(1000);
   h2->SetLineColor(1070);
   h3->SetLineColor(1140);
   h1->GetXaxis()->SetTitle("Pz (GeV)");
   h1->GetYaxis()->SetTitle("Count");
   TCanvas *c1 = new TCanvas("c1","E distribution for final-state nuclei");
   // draw the histograms on the same canvas
   h1->Draw();
   h2->Draw("same");
   h3->Draw("same");
   // add a legend
   TLegend *legend = new TLegend(0.78,0.78,0.9,0.9);
   legend->AddEntry(h1,"0.1GeV","l");
   legend->AddEntry(h2,"0.3GeV","l");
   legend->AddEntry(h3,"0.5GeV","l");
   legend->Draw();

   // update the canvas
   c1->Update();
   c1->Update();
   
   
   double mean1 = h1->GetMean();
   TLatex *text1 = new TLatex(-0.4,220,Form("Mean(0.1GeV) = %.5f",mean1));
   text1->SetTextSize(0.03);
   text1->SetTextColor(1000);
   text1->SetTextAlign(12);
   text1->Draw();
   c1->Update();
   
   double mean2 = h2->GetMean();
   TLatex *text2 = new TLatex(-0.4,200,Form("Mean(0.3GeV) = %.5f",mean2));
   text2->SetTextSize(0.03);
   text2->SetTextColor(1070);
   text2->SetTextAlign(12);
   text2->Draw();
   c1->Update();
   
   double mean3 = h3->GetMean();
   TLatex *text3 = new TLatex(-0.4,180,Form("Mean(0.5GeV) = %.5f",mean3));
   text3->SetTextSize(0.03);
   text3->SetTextColor(1140);
   text3->SetTextAlign(12);
   text3->Draw();
   c1->Update();
   
   double entry1 = h1->GetEntries();
   TLatex *text11 = new TLatex(-0.4,140,Form("Entries(0.1GeV) = %.0f",entry1));
   text11->SetTextSize(0.03);
   text11->SetTextColor(1000);
   text11->SetTextAlign(12);
   text11->Draw();
   c1->Update();
   
   double entry2 = h2->GetEntries();
   TLatex *text22 = new TLatex(-0.4,120,Form("Entries(0.3GeV) = %.0f",entry2));
   text22->SetTextSize(0.03);
   text22->SetTextColor(1070);
   text22->SetTextAlign(12);
   text22->Draw();
   c1->Update();
   
   double entry3 = h3->GetEntries();
   TLatex *text33 = new TLatex(-0.4,100,Form("Entries(0.5GeV) = %.0f",entry3));
   text33->SetTextSize(0.03);
   text33->SetTextColor(1140);
   text33->SetTextAlign(12);
   text33->Draw();
   c1->Update();
   
   
}
