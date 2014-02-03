
char * fname[] = {
	"reserved",		// 0 
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1/", 		// 1 pPb HLT std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_rereco/", 	// 2 pPb rereco HLT std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_reverse/", 	// 3 pPb reverse HLT std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm2/", 		// 4 pPb HLT std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm2_rereco/", 	// 5 pPb HLT std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm2_reverse/", 	// 6 pPb HLT std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3/", 		// 7 pPb HLT std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3_rereco/", 	// 8 pPb HLT std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3_reverse/", 	// 9 pPb HLT std Recursive
	"NA", 		// 10 1+2+3 pPb HLT std closed
	"NA", 		// 11 4+5+6 pPb HLT std Recurrence
	"NA", 		// 12 7+8+9 pPb HLT std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1/", 		// 13 pPb noeff HLT std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_rereco/", 	// 14 pPb noeff rereco HLT noeff std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_rerevers/", 	// 15 pPb noeff reverse HLT noeff std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2/", 		// 16 pPb noeff HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_rereco/", 	// 17 pPb noeff rereco HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_rerevers/", 	// 18 pPb noeff reverse HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3/", 		// 19 pPb noeff HLT noeff std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_rereco/", 	// 20 pPb noeff rereco HLT noeff std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_rerevers/", 	// 21 pPb noeff reverse HLT noeff std Recursive
	"NA", 		// 22 13+14+15 pPb HLT std closed
	"NA", 		// 23 16+17+18 pPb HLT std Recurrence
	"NA", 		// 24 19+20+21 pPb HLT std Recursive
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1/", 		// 25 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_rereco/", 		// 26 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_reverse/", 	// 27 pPb MB std closed
	"NA", 		// 28 25+26+27 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2/", 		// 29 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_rereco/", 		// 30 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_reverse/", 	// 31 pPb MB std closed
	"NA", 		// 32 29+30+31 pPb MB std closed
	"../PbPb/PbPb_MB_rfp24_Noff_noadd_eff_cm1/", 	// 33 PbPb MB ppreco std closed
};


char * ftxt[] = {
	"txt/test/", 			// 0
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1/",		// 1
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_rereco/",	// 2
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_reverse/",	// 3
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm2/",		// 4
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm2_rereco/",	// 5
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm2_reverse/",	// 6
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3/",		// 7
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3_rereco/",	// 8
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3_reverse/",	// 9
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_full/",	// 10
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm2_full/",	// 11
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v11_cm3_full/",	// 12
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1/",		// 13
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_rereco/",	// 14
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_reverse/",	// 15
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2/",		// 16
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_rereco/",	// 17
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_reverse/",	// 18
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3/",		// 19
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_rereco/",	// 20
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_reverse/",	// 21
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_full/",	// 22
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_full/",	// 23
	"txt/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_full/",	// 24
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1/",		// 25
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_rereco/",	// 26
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_reverse/",	// 27
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_full/",	// 28
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2/",		// 29
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_rereco/",	// 30
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_reverse/",	// 31
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_full/",	// 32
	"txt/PbPb_MB_rfp24_Noff_noadd_eff_cm1/",		// 33

};
