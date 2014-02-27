
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
	"NA", 								// 10 1+2+3 pPb HLT std closed
	"NA", 								// 11 4+5+6 pPb HLT std Recurrence
	"NA", 								// 12 7+8+9 pPb HLT std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1/", 		// 13 pPb noeff HLT std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_rereco/", 	// 14 pPb noeff rereco HLT noeff std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm1_rerevers/", 	// 15 pPb noeff reverse HLT noeff std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2/", 		// 16 pPb noeff HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_rereco/", 	// 17 pPb noeff rereco HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v12_cm2_rerevers/", 	// 18 pPb noeff reverse HLT noeff std Recurrence
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3/", 		// 19 pPb noeff HLT noeff std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_rereco/", 	// 20 pPb noeff rereco HLT noeff std Recursive
	"../test/pPb_HLT_rfp24_Noff_noacc_noeff_v11_cm3_rerevers/", 	// 21 pPb noeff reverse HLT noeff std Recursive
	"NA", 								// 22 13+14+15 pPb HLT std closed
	"NA", 								// 23 16+17+18 pPb HLT std Recurrence
	"NA", 								// 24 19+20+21 pPb HLT std Recursive
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1/", 		// 25 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_rereco/", 		// 26 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_reverse/", 	// 27 pPb MB std closed
	"NA", 								// 28 25+26+27 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2/", 		// 29 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_rereco/", 		// 30 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm2_reverse/", 	// 31 pPb MB std closed
	"NA", 								// 32 29+30+31 pPb MB std closed
	"../PbPb/PbPb_MB_rfp24_Noff_noadd_eff_cm1/", 			// 33 PbPb MB ppreco std closed
	"../test/pPb_Hijing_MB/", 					// 34 pPb HIJING MB v2=0 non-flow std closed
	"../PbPb/PbPb_MB_rfp24_Noff_noacc_eff_old_cm1/", 		// 35 PbPb MB ppreco old std closed
	"../test/pPb_Hijing_MB_v2_05_f01/", 				// 36 pPb HIJING MB v2=0.05, fv2=0.01 std closed
	"../test/pPb_Hijing_MB_v2_05_f01_mod2/", 			// 37 pPb HIJING MB v2=0.05, fv2=0.01 with non-flow std closed
	"../test/pPb_Hijing_MB_v2_05_f00/", 				// 38 pPb HIJING MB v2=0.05, fv2=0.00 std closed
	"../test/pPb_Hijing_MB_v2_05_f01_ep2/", 			// 39+36 pPb HIJING MB v2=0.05, fv2=0.01 std closed
	"../test/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1/", 		// 40 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1_rereco/", 	// 41 pPb MB std closed
	"../test/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1_reverse/", 	// 42 pPb MB std closed
	"NA", 								// 43 40+41+42 pPb MB std closed
	"../test/pPb_Hijing_MB_v2_00_f00/", 				// 44 pPb HIJING MB v2=0 std closed
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT/", 	// 45 pPb HLT sys
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT_rereco/", 	// 46 pPb HLT sys
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT_reverse/", 	// 47 pPb HLT sys
	"NA",									// 48  45+46+47 pPb HLT sys
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose/", 		// 49 pPb HLT sysTrkLoose
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_rereco/", 	// 50 pPb HLT sysTrkLoose
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_reverse/", 	// 51 pPb HLT sysTrkLoose
	"NA", 									// 52 49+50+51 pPb HLT sysTrkLoose
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose/", 		// 53 pPb MB sysTrkLoose
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_rereco/", 	// 54 pPb MB sysTrkLoose
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_reverse/", 	// 55 pPb MB sysTrkLoose
	"NA", 									// 56 53+54+55 pPb MB sysTrkLoose
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight/", 		// 57 pPb HLT sysTrkTight
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_rereco/", 	// 58 pPb HLT sysTrkTight
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_reverse/", 	// 59 pPb HLT sysTrkTight
	"NA", 									// 60 57+58+59 pPb HLT sysTrkTight
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight/", 		// 61 pPb MB sysTrkTight
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_rereco/", 	// 62 pPb MB sysTrkTight
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_reverse/", 	// 63 pPb MB sysTrkTight
	"NA", 									// 64 61+62+63 pPb MB sysTrkTight
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU/", 			// 65 pPb HLT sysPU
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU_rereco/", 		// 66 pPb HLT sysPU
	"../test/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU_reverse/", 		// 67 pPb HLT sysPU
	"NA", 									// 68 65+66+67 pPb HLT sysPU
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU/", 			// 69 pPb MB sysPU
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU_rereco/", 		// 70 pPb MB sysPU
	"../test/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU_reverse/", 		// 71 pPb MB sysPU
	"NA", 									// 72 69+70+71 pPb MB sysPU
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
	"txt/pPb_Hijing_MB/",					// 34
	"txt/PbPb_MB_rfp24_Noff_noacc_eff_old_cm1/",		// 35
	"txt/pPb_Hijing_MB_v2_05_f01/",				// 36
	"txt/pPb_Hijing_MB_v2_05_f01_mod2/",			// 37
	"txt/pPb_Hijing_MB_v2_05_f00/",				// 38
	"txt/pPb_Hijing_MB_v2_05_f01_ep2/",			// 39
	"txt/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1/",		// 40
	"txt/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1_rereco/",	// 41
	"txt/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1_reverse/",	// 42
	"txt/pPb_MB_rfp24_Noff_noacc_noeff_v12_cm1_full/",	// 43
	"txt/pPb_Hijing_MB_v2_00_f00/",				// 44
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT/",	// 45
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT_rereco/",	// 46
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT_reverse/",	// 47
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysHLT_full/",	// 48
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose/",	// 49
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_rereco/",		// 50
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_reverse/",	// 51
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_full/",		// 52
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose/",			// 53
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_rereco/",		// 54
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_reverse/",		// 55
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkLoose_full/",		// 56
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight/",		// 57
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_rereco/",		// 58
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_reverse/",	// 59
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_full/",		// 60
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight/",			// 61
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_rereco/",		// 62
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_reverse/",		// 63
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysTrkTight_full/",		// 64
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU/",			// 65
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU_rereco/",		// 66
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU_reverse/",		// 67
	"txt/pPb_HLT_rfp24_Noff_noacc_eff_v12_cm1_sysPU_full/",			// 68
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU/",			// 69
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU_rereco/",		// 70
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU_reverse/",		// 71
	"txt/pPb_MB_rfp24_Noff_noacc_eff_v12_cm1_sysPU_full/",			// 72
};
