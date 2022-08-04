#include "TMath.h"
#include <cmath>
#include "TH1F.h"
#include "TF1.h"
#include "TFile.h"

void compare(){
 TCanvas *can= new TCanvas("can","can",700,500); 
 TFile *ifile = new TFile("/home/guru/Fitting/nuisance_hist_6chan_noFwdStop_50bins_wqcdy.root");

 TH1F *hpx = new TH1F; TH1F *hpx1 = new TH1F;TH1F *hpx2 = new TH1F;
 TIter nextkey(ifile->GetListOfKeys()); 
 TKey *key;
 while ((key = (TKey*)nextkey())){
	 TObject *obj = key->ReadObj(); 
	 hpx = (TH1F*)(obj); 
	 const char *name = hpx->GetName();

	 std::string s = name;
	 if (s.find("plus") < s.length()||s.find("minus") < s.length()||s.find("signal") < s.length()||s.find("DATA") < s.length()) continue;
	 	 
	 std::string name_UD_p = name; std::string name_UD_m = name;	
	 name_UD_p.append("__UD__plus"); name_UD_m.append("__UD__minus");
	 char* title_p = const_cast<char*>(name_UD_p.c_str());
	 char* title_m = const_cast<char*>(name_UD_m.c_str());
 	 hpx1 = (TH1F*)ifile->Get(title_p); hpx2 = (TH1F*)ifile->Get(title_m);
 	 
	 hpx->Draw(""); hpx->SetLineColor(1);//black	 
	 hpx1->Draw("same"); hpx1->SetLineColor(2);//red
	 hpx2->Draw("same"); hpx2->SetLineColor(4);//blue

	 std::string name_str = name; 	 	
	 name_str.append("_UD.png");
	 char* title = const_cast<char*>(name_str.c_str());//converting string to char
	 hpx->SetTitle(title);
	 
	 cout<<name<<endl;
	 can->SaveAs(title);
	 
 }
 
}
//-----------
	 