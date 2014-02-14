//                                       0,   1,   2,   3,   4,   5,   6,   7,   8,   9, 10, 11, 12, 13, 14, 15, 16, 17,
  const Int_t CentNoffCut[] = {100000, 350, 320, 300, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
// 5bin                                 70,  64,  60,  52,  48,  44,  37,  30,  24,  20, 16, 12, 10,  8,  6,  4,  2, 0,

//                                       0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10, 11, 12, 13, 14, 15, 16, 17, 18
const Int_t CentNoffCutPbPb[]={100000, 350, 320, 300, 280, 260, 240, 220, 185, 150, 120, 100, 80, 60, 50, 40, 30, 20, 10, 0};
//                                       0,        1,   2,   3,   4,   5,   6,   7,   8,  9,     10,     11,         12, 13, 14, 15, 16, 17, 18,
const Int_t MergedNoff6[] =   {100000, 350,      300, 260, 240, 220, 185, 150, 120, 100, 80,     50,     30,         5};

//                                       0,             1,        2,   3,   4,   5,   6,  7,                         8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
const Int_t MergedNoff8[] =   {100000, 350,           260,      220, 185, 150, 120, 100, 80,                         5};

int getNoff(int N) {
	int cent = 18;
	while ( CentNoffCut[cent] <= N ) cent--;
	return cent;
}

int getNoffPbPb(int N) {
	int cent = 19;
	while ( CentNoffCutPbPb[cent] <= N ) cent--;
	return cent;
}



int getNoff6(int N) {
	int cent = 13;
	while ( MergedNoff6[cent] <= N ) cent--;
	return cent;
}

int getNoff8(int N) {
	int cent = 9;
	while ( MergedNoff8[cent] <= N ) cent--;
	return cent;

}

//int getNoffGen(int N) {
//	int cent = 1;
//	while ( pCent[cent] > N ) cent++;
//	cent--;
//	return cent;
//}
