
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
