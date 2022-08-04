#include "TMath.h"
#include <cmath>
#include "TH1F.h"
#include "TF1.h"
#include "TFile.h"

void compare1(){
 TCanvas *can= new TCanvas("can","can",700,500); 
 TFile *ifile = new TFile("/home/guru/Fitting/test/TTToSemiLeptonic_TuneCP5_PSweights_powheg-pythia8_2017.root");
 TFile *ifile1 = new TFile("/home/guru/Fitting/test/TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8_2017_bTagEff.root");
 
 const char *doHist = "yes";
 
 TTree *tree = (TTree*)ifile->Get("Skim");
 TTree *tree1 = (TTree*)ifile1->Get("nominal");

 //const char *var[] =  {"Lepton_pt","Lepton_phi","MET","Lepton_eta","LeadJet_pt","LeadJet_phi","LeadJet_eta", "ST_v2","Mass_v2","ST","Mass","MT","HT_Central_pu","bVsW_ratio","DPHI_LepleadJet","DPHI_LepMet","DR_LepClosestJet","DR_LepleadJet","nBTagMed_DeepFLV","nCentralJets","nFwdJets","DPHI_JetMet","FwdJetEta","FwdJetPt_puT"};
  const char *var[] =  {"nBTagMed_DeepFLV"};

 for(int i = 0; i < sizeof var/sizeof var[0]; i++){
	 tree1->Draw(var[i]); 
	 tree->Draw(var[i],"","same"); ((TH1F*)(gPad->GetListOfPrimitives()->At(1)))->SetLineColor(2);//htemp->SetLineColor(2); // cout<<var[i]<<endl;
	 std::string s = var[i]; s.append(".png");
	 char* title = const_cast<char*>(s.c_str());//converting string to char
	 can->SaveAs(title);
 }



 	
/* const char *hist_name = "_";
 TH1F *hpx = new TH1F; TH1F *hpx1 = new TH1F;
 TIter nextkey(ifile->GetListOfKeys()); 
 TKey *key;
 while ((key = (TKey*)nextkey())){
	 TObject *obj = key->ReadObj(); 
	 hpx = (TH1F*)(obj); 
	 const char *name = hpx->GetName();
	 hpx1 = (TH1F*)ifile1->Get(name);
	 std::string s = name;
	 if (s.find(hist_name) < s.length()){
	   hpx->Draw("hist"); hpx->SetLineColor(4);//blue
	   hpx->SetTitle(name);
	   hpx1->Draw("same hist"); hpx1->SetLineColor(2);//red
	   cout<<name<<endl;
	   s.append(".png");
	   char* title = const_cast<char*>(s.c_str());//converting string to char
	   can->SaveAs(title);
	 }
 }*/
}