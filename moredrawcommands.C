
htmp1->Delete();
htmp2->Delete();
htmp3->Delete();
trackTree->SetFillStyle(3001);
trackTree->SetFillColor(kBlue);
trackTree->Draw("trkNHit>>htmp1","trkFake==0&&trkPt>50&&trkPt<300","goff");
trackTree->SetFillStyle(3004);
trackTree->SetFillColor(kRed);
trackTree->Draw("trkNHit>>htmp2","trkFake==1&&trkPt>50&&trkPt<300","goff");
trackTree->SetFillStyle(3005);
trackTree->SetFillColor(kGreen);
trackTree->Draw("trkNHit>>htmp3","(pfSumHcal+pfSumEcal)/trkPt>0.5&&trkPt>50&&trkPt<300","goff");
htmp1->DrawNormalized();
htmp2->DrawNormalized("same");
htmp3->DrawNormalized("same");
c1->SaveAs("trkNHit__50_300.png");



trackTree->Draw("(pPt*mhighPurity)>>num(100,0,300)","","goff")
trackTree->Draw("pPt>>den(100,0,300)","","goff")
num->Sumw2()
num->Divide(den)
num->SetTitle("")
num->SetXTitle("pPt (highPurity)")
num->SetYTitle("eff")
num->GetYaxis()->CenterTitle()
num->GetXaxis()->CenterTitle()
num->SetAxisRange(0,1.2,"Y")
num->Draw()
TLine * l70 = new TLine(0,0.7,300,0.7)
l70->SetLineStyle(9)
l70->Draw();


trackTree->Draw("(pPt*mhighPurity*(abs(pEta)<1))>>num(100,0,300)","","goff")
trackTree->Draw("pPt*(abs(pEta)<1)>>den(100,0,300)","","goff")
num->Sumw2()
num->Divide(den)
num->SetTitle("")
num->SetXTitle("pPt (highPurity, |#eta<1|)")
num->SetYTitle("eff")
num->GetYaxis()->CenterTitle()
num->GetXaxis()->CenterTitle()
num->SetAxisRange(0,1.2,"Y")
num->Draw()
TLine * l70 = new TLine(0,0.7,300,0.7)
l70->SetLineStyle(9)
l70->Draw();

trackTree->Draw("pPt:(mtrkPfEcal+mtrkPfHcal)/cosh(pEta)>>dummy(100,0,300,100,0,300)","","goff")
dummy->SetTitle("")
dummy->SetXTitle("pPt")
dummy->SetYTitle("#Sigmacalo/cosh(#eta)")
dummy->GetYaxis()->CenterTitle()
dummy->GetYaxis()->SetTitleOffset(1.2)
dummy->GetXaxis()->CenterTitle()
dummy->Draw("colz")
c1->SetLogy(0)

trackTree->Draw("(mtrkPfEcal+mtrkPfHcal)/cosh(pEta)/pPt>>ratio(100,0,5)","","")
ratio->SetTitle("")
ratio->SetXTitle("#Sigmacalo/(pPt*cosh(#eta))")
ratio->GetXaxis()->CenterTitle()
ratio->Draw("")
c1->SetLogy(1)


c1->SetLogy(0)
trackTree->Draw("(pPt*(pPt/(mtrkPfEcal+mtrkPfHcal)*cosh(pEta)>0.2))>>sumcalonum(100,0,300)","","goff")
trackTree->Draw("pPt>>sumcaloden(100,0,300)","","goff")
sumcalonum->Sumw2()
sumcalonum->Divide(sumcaloden)
sumcalonum->SetTitle("")
sumcalonum->SetXTitle("pPt (pPt*cosh(#eta)/#Sigmacalo>0.2)")
sumcalonum->SetYTitle("eff")
sumcalonum->GetYaxis()->CenterTitle()
sumcalonum->GetXaxis()->CenterTitle()
sumcalonum->SetAxisRange(0,1.2,"Y")
sumcalonum->SetMarkerColor(kRed)
sumcalonum->Draw("same")
TLine * l70 = new TLine(0,0.7,300,0.7)
l70->SetLineStyle(9)
l70->Draw();

trackTree->Draw("(pPt*mhighPurity)>>num(100,0,300)","","goff")
trackTree->Draw("pPt>>den(100,0,300)","","goff")
trackTree->Draw("(pPt*((mtrkPfEcal+mtrkPfHcal)/cosh(pEta)/pPt>0.2))>>sumcalonum(100,0,300)","","goff")
trackTree->Draw("pPt>>sumcaloden(100,0,300)","","goff")
sumcalonum->Sumw2()
sumcalonum->Divide(sumcaloden)
sumcalonum->SetMarkerColor(kRed)
num->Sumw2()
num->Divide(den)
num->SetTitle("")
num->SetXTitle("pPt")
num->SetYTitle("eff")
num->GetYaxis()->CenterTitle()
num->GetXaxis()->CenterTitle()
num->SetAxisRange(0,1.2,"Y")
num->Draw()
sumcalonum->Draw("same")
TLine * l70 = new TLine(0,0.7,300,0.7)
l70->SetLineStyle(9)
l70->Draw();
TLegend * leg = new TLegend(0.4,0.75,0.8,0.9)
leg->SetBorderSize(0);
leg->SetTextFont(62)
leg->SetTextSize(0.039)
leg->SetLineColor(1)
leg->SetLineStyle(1)
leg->SetLineWidth(1)
leg->SetFillColor(19)
leg->SetFillStyle(0)
leg->AddEntry(num,"highPurity","pl");
leg->AddEntry(sumcalonum,"#Sigmacalo/(pPt*cosh(#eta))>0.2","pl");
leg->Draw()
TLatex * lpthat = new TLatex(0.5,0.7,"#hat{p}_{T}=80")
lpthat->SetNDC(1)
lpthat->Draw()


trackTree->Draw("trkPt*(trkFake==1)*(highPurity)>>num(100,0,300)","","goff")
trackTree->Draw("trkPt*(highPurity)>>den(100,0,300)","","goff")
num->Sumw2()
num->Divide(den)
num->SetTitle("")
num->SetXTitle("trkPt (trkFake==1)(highPurity)")
num->SetYTitle("fake")
num->GetYaxis()->CenterTitle()
num->GetYaxis()->SetTitleOffset(1.2)
num->GetXaxis()->CenterTitle()
num->SetAxisRange(0,0.1,"Y")
num->Draw()
TLine * l01 = new TLine(0,0.01,300,0.01)
l01->SetLineStyle(9)
l01->Draw();



trackTree->Draw("trkPt:(pfEcal+pfHcal)/cosh(trkEta)>>dummy(100,0,300,100,0,300)","","goff")
dummy->SetTitle("")
dummy->SetXTitle("trkPt")
dummy->SetYTitle("#Sigmacalo/cosh(#eta)")
dummy->GetYaxis()->CenterTitle()
dummy->GetYaxis()->SetTitleOffset(1.2)
dummy->GetXaxis()->CenterTitle()
dummy->Draw("colz")
c1->SetLogy(0)

trackTree->Draw("(pfEcal+pfHcal)/cosh(trkEta)/trkPt>>ratio(100,0,5)","","")
ratio->SetTitle("")
ratio->SetXTitle("#Sigmacalo/(trkPt*cosh(#eta))")
ratio->GetXaxis()->CenterTitle()
ratio->Draw("")
c1->SetLogy(1)

trackTree->Draw("trkPt*(trkFake==1)*(highPurity)>>num(100,0,300)","","goff")
trackTree->Draw("trkPt*(highPurity)>>den(100,0,300)","","goff")
num->Sumw2()
num->Divide(den)
num->SetTitle("")
num->SetXTitle("trkPt (trkFake==1)(highPurity)")
num->SetYTitle("fake")
num->GetYaxis()->CenterTitle()
num->GetYaxis()->SetTitleOffset(1.2)
num->GetXaxis()->CenterTitle()
num->SetAxisRange(0,0.1,"Y")
num->Draw()
TLine * l01 = new TLine(0,0.01,300,0.01)
l01->SetLineStyle(9)
l01->Draw();

trackTree->Draw("trkPt*(trkFake==1)*((pfEcal+pfHcal)/cosh(trkEta)/trkPt>0.2)>>numsumcalo(100,0,300)","","goff")
trackTree->Draw("trkPt*((pfEcal+pfHcal)/cosh(trkEta)/trkPt>0.2)>>densumcalo(100,0,300)","","goff")
trackTree->Draw("trkPt*(trkFake==1)*(highPurity)>>num(100,0,300)","","goff")
trackTree->Draw("trkPt*(highPurity)>>den(100,0,300)","","goff")
num->Sumw2()
num->Divide(den)
numsumcalo->Sumw2()
numsumcalo->Divide(densumcalo)
numsumcalo->SetTitle("")
numsumcalo->SetXTitle("trkPt")
numsumcalo->SetYTitle("fake")
numsumcalo->GetYaxis()->CenterTitle()
numsumcalo->GetYaxis()->SetTitleOffset(1.2)
numsumcalo->GetXaxis()->CenterTitle()
numsumcalo->SetAxisRange(0,0.1,"Y")
numsumcalo->SetMarkerColor(kRed)
numsumcalo->Draw()
num->Draw("same")
TLine * l01 = new TLine(0,0.01,300,0.01)
l01->SetLineStyle(9)
l01->Draw();
TLegend * leg = new TLegend(0.2,0.8,0.8,0.9)
leg->SetBorderSize(0);
leg->SetTextFont(62)
leg->SetTextSize(0.039)
leg->SetLineColor(1)
leg->SetLineStyle(1)
leg->SetLineWidth(1)
leg->SetFillColor(19)
leg->SetFillStyle(0)
leg->AddEntry(num,"highPurity","pl");
leg->AddEntry(numsumcalo,"trkPt*cosh(#eta)/#Sigmacalo>0.2","pl");
leg->Draw()
TLatex * lpthat = new TLatex(0.3,0.75,"#hat{p}_{T}=80")
lpthat->SetNDC(1)
lpthat->Draw()




