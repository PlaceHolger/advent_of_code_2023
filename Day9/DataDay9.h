#pragma once

// constexpr int NUM_NUMBERS = 6;
// int s_Data[][NUM_NUMBERS] =
// {
// {0, 3, 6, 9, 12, 15},
// {1, 3, 6, 10, 15, 21},
// {10,13, 16, 21, 30, 45}
// };


constexpr unsigned int NUM_NUMBERS = 21;
int s_Data[][NUM_NUMBERS]
{
{16, 22, 27, 23, 4, -16, 23, 267, 1025, 2943, 7407, 17445, 39670, 88339, 193607, 417868, 887273, 1851158, 3792224, 7628687, 15083115},
{12, 27, 53, 97, 184, 369, 757, 1550, 3165, 6502, 13489, 28103, 58181, 118520, 236055, 458342, 867210, 1600341, 2884757, 5087813, 8793398},
{3, 9, 23, 45, 75, 113, 159, 213, 275, 345, 423, 509, 603, 705, 815, 933, 1059, 1193, 1335, 1485, 1643},
{14, 21, 42, 87, 173, 334, 631, 1162, 2072, 3563, 5904, 9441, 14607, 21932, 32053, 45724, 63826, 87377, 117542, 155643, 203169},
{6, 13, 20, 27, 34, 41, 48, 55, 62, 69, 76, 83, 90, 97, 104, 111, 118, 125, 132, 139, 146},
{18, 28, 38, 48, 58, 68, 78, 88, 98, 108, 118, 128, 138, 148, 158, 168, 178, 188, 198, 208, 218},
{21, 33, 40, 47, 73, 158, 375, 850, 1793, 3543, 6630, 11857, 20405, 33964, 54893, 86412, 132829, 199805, 294660, 426723, 607729},
{5, 11, 28, 62, 114, 176, 227, 229, 123, -175, -778, -1832, -3520, -6066, -9739, -14857, -21791, -30969, -42880, -58078, -77186},
{24, 40, 75, 158, 329, 650, 1234, 2297, 4245, 7835, 14509, 27104, 51294, 98315, 189749, 365429, 696074, 1303683, 2396426, 4333544, 7754453},
{18, 23, 29, 46, 96, 212, 448, 922, 1929, 4181, 9250, 20305, 43249, 88396, 172934, 324721, 588708, 1038939, 1802431, 3107544, 5380614},
{23, 48, 93, 172, 303, 512, 850, 1439, 2577, 4950, 10022, 20709, 42513, 85461, 167621, 322006, 611043, 1157808, 2213227, 4297234, 8485467},
{-5, 1, 16, 41, 89, 207, 507, 1216, 2767, 5970, 12327, 24602, 47877, 91653, 174402, 333999, 651945, 1308548, 2704118, 5713694, 12198267},
{6, 29, 72, 158, 337, 698, 1389, 2653, 4895, 8818, 15726, 28221, 51759, 97922, 190866, 379323, 758008, 1504863, 2945432, 5665084, 10707897},
{9, 12, 14, 16, 18, 23, 61, 248, 912, 2857, 7918, 20117, 47998, 109127, 238298, 501654, 1019615, 2002014, 3798866, 6969266, 12368366},
{17, 22, 22, 7, -38, -133, -303, -578, -993, -1588, -2408, -3503, -4928, -6743, -9013, -11808, -15203, -19278, -24118, -29813, -36458},
{-2, 4, 18, 55, 139, 307, 619, 1172, 2109, 3609, 5862, 9109, 14010, 22956, 43541, 96348, 230584, 553042, 1278506, 2813195, 5887325},
{8, 15, 28, 69, 174, 408, 898, 1887, 3825, 7548, 14661, 28355, 55092, 107964, 213209, 422581, 836414, 1645965, 3210142, 6193077, 11808762},
{16, 42, 93, 189, 363, 674, 1225, 2187, 3843, 6689, 11662, 20608, 37156, 68227, 126480, 234080, 428266, 769300, 1351491, 2318111, 3881153},
{22, 28, 29, 28, 44, 131, 412, 1147, 2869, 6647, 14589, 30812, 63325, 127656, 253684, 498111, 966448, 1850438, 3489669, 6469940, 11775962},
{10, 22, 64, 147, 279, 478, 797, 1361, 2416, 4390, 7966, 14167, 24453, 40830, 65971, 103349, 157382, 233590, 338764, 481147, 670627},
{26, 44, 80, 147, 257, 416, 626, 905, 1352, 2314, 4756, 10993, 26015, 59722, 130486, 270571, 534070, 1008160, 1828632, 3200823, 5427261},
{10, 13, 25, 59, 130, 257, 465, 787, 1266, 1957, 2929, 4267, 6074, 8473, 11609, 15651, 20794, 27261, 35305, 45211, 57298},
{22, 34, 53, 80, 110, 130, 129, 142, 361, 1361, 4516, 12738, 31795, 72709, 156208, 321132, 640567, 1253344, 2426426, 4679304, 9031095},
{-3, 3, 14, 32, 60, 112, 238, 564, 1347, 3045, 6402, 12548, 23114, 40362, 67330, 107992, 167433, 252039, 369702, 530040, 744632},
{9, 6, 1, -6, -15, -26, -39, -54, -71, -90, -111, -134, -159, -186, -215, -246, -279, -314, -351, -390, -431},
{8, 19, 30, 41, 52, 63, 74, 85, 96, 107, 118, 129, 140, 151, 162, 173, 184, 195, 206, 217, 228},
{12, 28, 56, 112, 219, 400, 680, 1122, 1935, 3705, 7813, 17117, 36988, 76803, 152011, 286901, 518214, 899754, 1508166, 2450062, 3870689},
{4, 18, 45, 100, 211, 419, 778, 1355, 2230, 3496, 5259, 7638, 10765, 14785, 19856, 26149, 33848, 43150, 54265, 67416, 82839},
{14, 27, 62, 122, 200, 276, 326, 367, 589, 1672, 5468, 16376, 44007, 108213, 248366, 540095, 1124752, 2259977, 4404234, 8354542, 15465362},
{10, 22, 40, 63, 103, 210, 507, 1241, 2865, 6190, 12701, 25249, 49587, 97767, 195548, 398210, 823495, 1718635, 3594121, 7486884, 15473014},
{14, 34, 81, 182, 390, 802, 1584, 3006, 5499, 9763, 16982, 29248, 50393, 87661, 155200, 281530, 525422, 1008672, 1981041, 3943806, 7877282},
{12, 6, 3, 23, 101, 286, 644, 1284, 2444, 4698, 9375, 19317, 40145, 82250, 163780, 314954, 584100, 1045886, 1812291, 3046947, 4983573},
{13, 21, 32, 52, 86, 138, 211, 307, 427, 571, 738, 926, 1132, 1352, 1581, 1813, 2041, 2257, 2452, 2616, 2738},
{17, 35, 58, 79, 89, 86, 96, 217, 705, 2144, 5802, 14399, 33741, 76089, 166928, 358407, 755996, 1571412, 3227213, 6560698, 13212768},
{17, 31, 59, 122, 252, 488, 875, 1475, 2402, 3896, 6454, 11039, 19391, 34467, 61040, 106490, 181823, 302957, 492317, 780784, 1210046},
{11, 13, 19, 31, 63, 168, 488, 1351, 3457, 8223, 18396, 39097, 79555, 156016, 296889, 552619, 1016132, 1867206, 3470206, 6587672, 12837496},
{16, 29, 54, 116, 265, 600, 1300, 2668, 5219, 9890, 18523, 34882, 66641, 129080, 251748, 490245, 946750, 1805263, 3391104, 6269484, 11405501},
{14, 27, 57, 121, 242, 458, 839, 1513, 2706, 4807, 8477, 14831, 25734, 44266, 75427, 127171, 211878, 348395, 564801, 902077, 1418890},
{7, 20, 34, 49, 65, 82, 100, 119, 139, 160, 182, 205, 229, 254, 280, 307, 335, 364, 394, 425, 457},
{1, 6, 11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96, 101},
{11, 27, 54, 101, 191, 376, 755, 1502, 2915, 5494, 10051, 17860, 30889, 52245, 87140, 144991, 243747, 418245, 735396, 1320359, 2399651},
{2, 8, 29, 83, 199, 423, 835, 1581, 2927, 5359, 9789, 17981, 33374, 62532, 117469, 219074, 401880, 720802, 1262037, 2164843, 3671777},
{6, 24, 54, 96, 150, 216, 294, 384, 486, 600, 726, 864, 1014, 1176, 1350, 1536, 1734, 1944, 2166, 2400, 2646},
{10, 19, 51, 124, 260, 486, 847, 1434, 2430, 4183, 7326, 12972, 22998, 40360, 69185, 113940, 176032, 244249, 271543, 122978, -535002},
{-2, -4, -14, -20, 14, 157, 520, 1272, 2677, 5175, 9538, 17144, 30453, 53895, 95688, 171741, 313968, 587314, 1122914, 2179488, 4251816},
{10, 2, -8, -10, 16, 111, 367, 983, 2360, 5278, 11264, 23369, 47724, 96431, 192545, 378084, 726118, 1357970, 2466328, 4344512, 7421136},
{9, 22, 62, 142, 278, 503, 886, 1552, 2699, 4608, 7642, 12230, 18832, 27881, 39698, 54376, 71629, 90602, 109638, 125998, 135530},
{-2, -1, 13, 46, 97, 157, 212, 250, 272, 307, 431, 790, 1627, 3313, 6382, 11570, 19858, 32519, 51169, 77822, 114949},
{18, 43, 87, 167, 324, 645, 1288, 2508, 4685, 8358, 14272, 23448, 37289, 57738, 87507, 130399, 191748, 279005, 402501, 576421, 820026},
{-8, -3, 21, 87, 247, 597, 1292, 2561, 4722, 8197, 13527, 21387, 32601, 48157, 69222, 97157, 133532, 180141, 239017, 312447, 402987},
{1, 15, 44, 102, 209, 386, 650, 1009, 1457, 1969, 2496, 2960, 3249, 3212, 2654, 1331, -1055, -4861, -10508, -18486, -29359},
{5, 1, -2, 6, 59, 235, 682, 1661, 3639, 7499, 14980, 29518, 57729, 111857, 213604, 399865, 731009, 1302477, 2260610, 3823774, 6310015},
{1, 9, 37, 102, 234, 477, 887, 1529, 2484, 3904, 6221, 10771, 21422, 48445, 117084, 285457, 680175, 1564375, 3463249, 7388968, 15233734},
{-3, -3, -1, 11, 59, 207, 588, 1446, 3189, 6453, 12177, 21689, 36803, 59927, 94182, 143532, 212925, 308445, 437475, 608871, 833147},
{10, 8, 4, -1, 1, 26, 99, 259, 588, 1312, 3062, 7435, 18059, 42442, 94973, 201543, 406366, 781704, 1441336, 2558759, 4391269},
{10, 15, 18, 27, 59, 146, 351, 801, 1756, 3756, 7920, 16506, 33869, 67961, 132485, 249722, 453870, 794437, 1338782, 2172261, 3393567},
{7, 15, 41, 104, 240, 511, 1006, 1830, 3083, 4847, 7237, 10652, 16512, 29023, 58918, 130730, 296023, 656207, 1400169, 2864048, 5623160},
{-8, -4, 15, 66, 176, 382, 731, 1280, 2096, 3256, 4847, 6966, 9720, 13226, 17611, 23012, 29576, 37460, 46831, 57866, 70752},
{11, 15, 15, 11, 3, -9, -25, -45, -69, -97, -129, -165, -205, -249, -297, -349, -405, -465, -529, -597, -669},
{-1, 2, 8, 24, 76, 213, 509, 1071, 2071, 3838, 7075, 13309, 25742, 50751, 100388, 196360, 376127, 701946, 1273914, 2248326, 3862968},
{11, 12, 10, -4, -30, -41, 52, 467, 1667, 4541, 10659, 22594, 44276, 81300, 141049, 232411, 364763, 545762, 777320, 1048944, 1327390},
{9, 11, 12, 20, 63, 215, 648, 1733, 4223, 9564, 20404, 41417, 80649, 151761, 277849, 498056, 879093, 1535245, 2662704, 4597458, 7910851},
{21, 22, 23, 43, 114, 293, 701, 1602, 3535, 7522, 15407, 30447, 58395, 109537, 202601, 372448, 685608, 1272236, 2392115, 4569768, 8866201},
{17, 27, 37, 47, 57, 67, 77, 87, 97, 107, 117, 127, 137, 147, 157, 167, 177, 187, 197, 207, 217},
{18, 42, 72, 103, 130, 150, 170, 224, 408, 956, 2402, 5903, 13836, 30828, 65432, 132724, 258166, 483158, 872788, 1526383, 2591566},
{23, 30, 36, 41, 45, 48, 50, 51, 51, 50, 48, 45, 41, 36, 30, 23, 15, 6, -4, -15, -27},
{14, 31, 52, 83, 148, 308, 690, 1526, 3202, 6317, 11752, 20749, 35000, 56746, 88886, 135096, 199958, 289099, 409340, 568855, 777340},
{4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34, 37, 40, 43, 46, 49, 52, 55, 58, 61, 64},
{14, 26, 44, 76, 143, 283, 574, 1197, 2563, 5538, 11840, 24799, 50942, 103413, 209274, 424645, 865170, 1765883, 3597017, 7286172, 14643193},
{12, 27, 49, 69, 87, 136, 330, 950, 2594, 6451, 14824, 32143, 66919, 135472, 268945, 526276, 1017696, 1946291, 3679643, 6870089, 12651367},
{11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96, 101, 106, 111},
{10, 35, 74, 146, 282, 527, 958, 1744, 3300, 6630, 14020, 30337, 65320, 137420, 279964, 550689, 1046022, 1921877, 3423206, 5925084, 9988734},
{20, 29, 40, 59, 108, 247, 607, 1436, 3177, 6629, 13289, 26035, 50387, 96675, 183550, 343396, 630338, 1131693, 1983878, 3393971, 5668318},
{8, 24, 59, 134, 284, 569, 1103, 2113, 4045, 7744, 14750, 27772, 51427, 93361, 165904, 288451, 490806, 817776, 1335357, 2138914, 3363822},
{11, 25, 55, 105, 179, 281, 415, 585, 795, 1049, 1351, 1705, 2115, 2585, 3119, 3721, 4395, 5145, 5975, 6889, 7891},
{19, 37, 74, 159, 334, 661, 1245, 2294, 4257, 8117, 15987, 32302, 66195, 136227, 279739, 571067, 1156243, 2317357, 4588524, 8958785, 17217096},
{-2, 9, 41, 103, 219, 443, 870, 1652, 3057, 5656, 10790, 21562, 44740, 94217, 197246, 406018, 820326, 1634301, 3236137, 6423499, 12866391},
{5, -1, -8, -9, 10, 70, 199, 432, 811, 1385, 2210, 3349, 4872, 6856, 9385, 12550, 16449, 21187, 26876, 33635, 41590},
{19, 32, 45, 58, 71, 84, 97, 110, 123, 136, 149, 162, 175, 188, 201, 214, 227, 240, 253, 266, 279},
{22, 37, 55, 71, 94, 167, 396, 1005, 2447, 5608, 12151, 25096, 49895, 96676, 185249, 356351, 696284, 1389007, 2822275, 5796409, 11921644},
{22, 47, 92, 163, 266, 410, 610, 889, 1282, 1854, 2764, 4460, 8230, 17669, 42342, 106334, 266942, 653145, 1540604, 3491025, 7600370},
{23, 38, 73, 146, 277, 488, 805, 1274, 2012, 3332, 6035, 12106, 26379, 60395, 140880, 327309, 746281, 1655398, 3556625, 7389446, 14848405},
{10, 34, 81, 160, 274, 417, 573, 715, 811, 876, 1179, 2852, 9421, 30324, 88549, 236536, 588096, 1380274, 3089189, 6639788, 13773628},
{17, 32, 52, 70, 76, 73, 108, 318, 991, 2642, 6104, 12634, 24034, 42787, 72208, 116610, 181485, 273700, 401708, 575774, 808216},
{-4, 7, 32, 78, 155, 279, 498, 962, 2061, 4658, 10451, 22528, 46285, 91178, 174513, 330071, 627521, 1214340, 2401733, 4831449, 9782898},
{-1, 1, -1, -2, 13, 71, 214, 503, 1023, 1889, 3253, 5312, 8317, 12583, 18500, 26545, 37295, 51441, 69803, 93346, 123197},
{14, 25, 55, 119, 234, 420, 706, 1143, 1844, 3111, 5790, 12143, 27772, 65506, 152698, 344108, 743534, 1538777, 3056905, 5851463, 10843458},
{-7, -7, 2, 25, 72, 160, 317, 595, 1112, 2172, 4561, 10190, 23357, 53033, 116746, 246846, 500187, 972563, 1819588, 3286119, 5746790},
{24, 51, 91, 144, 210, 289, 381, 486, 604, 735, 879, 1036, 1206, 1389, 1585, 1794, 2016, 2251, 2499, 2760, 3034},
{-6, -8, -7, -4, 9, 70, 282, 871, 2293, 5443, 12063, 25532, 52395, 105321, 208785, 409850, 798384, 1544682, 2969297, 5672672, 10775633},
{18, 38, 74, 128, 197, 273, 343, 389, 388, 312, 128, -202, -721, -1477, -2523, -3917, -5722, -8006, -10842, -14308, -18487},
{14, 14, 6, -15, -54, -116, -206, -329, -490, -694, -946, -1251, -1614, -2040, -2534, -3101, -3746, -4474, -5290, -6199, -7206},
{0, 4, 22, 78, 215, 499, 1023, 1911, 3322, 5454, 8548, 12892, 18825, 26741, 37093, 50397, 67236, 88264, 114210, 145882, 184171},
{15, 19, 27, 58, 141, 316, 650, 1285, 2551, 5196, 10802, 22466, 45823, 90469, 171801, 313223, 548567, 924441, 1502037, 2357706, 3581329},
{28, 49, 76, 114, 185, 353, 769, 1757, 3977, 8715, 18361, 37142, 72176, 134903, 242928, 422277, 710018, 1157133, 1831442, 2820274, 4232451},
{2, -5, 0, 35, 133, 356, 819, 1728, 3430, 6476, 11736, 20729, 36639, 67155, 131593, 277209, 613962, 1384465, 3098432, 6781691, 14423617},
{-2, 7, 41, 121, 269, 517, 931, 1662, 3062, 5945, 12131, 25493, 53858, 112344, 229132, 455405, 882418, 1670639, 3098937, 5646285, 10124879},
{15, 19, 18, 9, -6, -15, 9, 113, 369, 879, 1780, 3249, 5508, 8829, 13539, 20025, 28739, 40203, 55014, 73849, 97470},
{9, 14, 33, 89, 229, 533, 1128, 2215, 4117, 7356, 12767, 21657, 36017, 58795, 94238, 148311, 229201, 347914, 518973, 761225, 1098765},
{8, 23, 51, 104, 202, 386, 739, 1423, 2763, 5438, 10883, 22095, 45241, 92932, 191019, 392729, 807586, 1658885, 3393971, 6888230, 13809204},
{6, 3, 10, 41, 110, 231, 418, 685, 1046, 1515, 2106, 2833, 3710, 4751, 5970, 7381, 8998, 10835, 12906, 15225, 17806},
{12, 12, 16, 37, 101, 264, 650, 1525, 3438, 7497, 15913, 33051, 67399, 135147, 266525, 516779, 984800, 1844138, 3393654, 6138665, 10918457},
{9, 30, 68, 138, 276, 551, 1072, 2001, 3595, 6307, 10985, 19236, 34096, 61304, 111765, 206261, 384197, 719228, 1346090, 2504950, 4612204},
{23, 38, 66, 121, 224, 409, 731, 1285, 2251, 3984, 7170, 13069, 23864, 43131, 76439, 132081, 221927, 362378, 575386, 889489, 1340792},
{16, 28, 40, 52, 64, 76, 88, 100, 112, 124, 136, 148, 160, 172, 184, 196, 208, 220, 232, 244, 256},
{17, 30, 61, 119, 219, 397, 747, 1501, 3179, 6842, 14487, 29629, 58121, 109269, 197305, 343287, 577501, 942446, 1496489, 2318283, 3512047},
{-1, 5, 14, 37, 100, 253, 588, 1271, 2598, 5105, 9816, 18826, 36619, 72851, 147828, 302628, 616809, 1237973, 2429186, 4642459, 8629254},
{16, 36, 76, 164, 342, 666, 1206, 2046, 3284, 5032, 7416, 10576, 14666, 19854, 26322, 34266, 43896, 55436, 69124, 85212, 103966},
{-5, -3, 12, 63, 182, 411, 809, 1475, 2612, 4686, 8786, 17372, 35707, 74388, 153464, 308525, 598601, 1114243, 1980956, 3346921, 5332708},
{14, 26, 38, 50, 62, 74, 86, 98, 110, 122, 134, 146, 158, 170, 182, 194, 206, 218, 230, 242, 254},
{2, -4, -19, -52, -115, -221, -369, -502, -417, 401, 3053, 9640, 23844, 51688, 102447, 189584, 331368, 550394, 870413, 1307468, 1850007},
{21, 43, 82, 139, 220, 346, 563, 952, 1639, 2805, 4696, 7633, 12022, 18364, 27265, 39446, 55753, 77167, 104814, 139975, 184096},
{-8, -16, -17, 2, 54, 155, 326, 590, 966, 1484, 2301, 4109, 9224, 24092, 64560, 166325, 404748, 930980, 2035275, 4253332, 8536722},
{-2, 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38},
{12, 33, 69, 137, 269, 529, 1047, 2087, 4183, 8402, 16827, 33411, 65487, 126554, 241758, 459276, 874624, 1682767, 3288727, 6538653, 13194051},
{5, 11, 36, 85, 167, 311, 593, 1176, 2363, 4661, 8852, 16065, 27841, 46181, 73565, 112928, 167577, 241031, 336764, 457829, 606339},
{5, 0, 6, 43, 134, 309, 628, 1231, 2423, 4814, 9565, 18848, 36718, 70725, 134771, 253948, 472385, 865492, 1558424, 2753105, 4766758},
{20, 31, 42, 53, 64, 75, 86, 97, 108, 119, 130, 141, 152, 163, 174, 185, 196, 207, 218, 229, 240},
{17, 34, 57, 94, 167, 331, 710, 1554, 3321, 6788, 13195, 24426, 43231, 73493, 120544, 191534, 295857, 445638, 656285, 947110, 1342023},
{19, 22, 16, 1, -16, -13, 61, 313, 960, 2430, 5532, 11711, 23385, 44323, 79959, 137439, 225057, 350542, 517400, 718181, 923118},
{12, 20, 36, 60, 92, 132, 180, 236, 300, 372, 452, 540, 636, 740, 852, 972, 1100, 1236, 1380, 1532, 1692},
{15, 28, 66, 154, 345, 743, 1533, 3025, 5728, 10495, 18847, 33738, 61349, 115157, 224805, 454707, 941713, 1968938, 4106276, 8470690, 17196453},
{26, 54, 104, 181, 285, 412, 556, 719, 953, 1484, 3011, 7356, 18816, 46948, 112339, 258637, 577588, 1260474, 2701490, 5699779, 11842279},
{-5, 0, 13, 48, 130, 307, 671, 1382, 2697, 5034, 9163, 16738, 31609, 62754, 130392, 278202, 597329, 1273687, 2682530, 5580428, 11497888},
{8, 23, 49, 86, 133, 194, 288, 465, 841, 1695, 3749, 8922, 22170, 55570, 136666, 324373, 737550, 1603839, 3339673, 6676646, 12854891},
{7, 18, 29, 40, 51, 62, 73, 84, 95, 106, 117, 128, 139, 150, 161, 172, 183, 194, 205, 216, 227},
{10, 24, 44, 69, 95, 111, 110, 139, 432, 1714, 5858, 17254, 45544, 110822, 253017, 547981, 1133786, 2251864, 4308844, 7966159, 14265585},
{-5, -2, 6, 18, 42, 106, 277, 693, 1613, 3490, 7072, 13536, 24660, 43038, 72343, 117643, 185775, 285782, 429418, 631726, 911694},
{25, 49, 82, 120, 164, 225, 336, 574, 1090, 2143, 4134, 7640, 13481, 22991, 39079, 69707, 137760, 306259, 738049, 1829516, 4498299},
{28, 39, 59, 115, 256, 569, 1203, 2401, 4540, 8179, 14115, 23447, 37648, 58645, 88907, 131541, 190396, 270175, 376555, 516315, 697472},
{11, 22, 42, 82, 162, 312, 578, 1053, 1983, 4058, 9103, 21549, 51304, 118974, 264819, 563384, 1146435, 2237670, 4203680, 7626820, 13407030},
{13, 32, 67, 140, 285, 548, 987, 1672, 2685, 4120, 6083, 8692, 12077, 16380, 21755, 28368, 36397, 46032, 57475, 70940, 86653},
{16, 33, 54, 83, 134, 242, 480, 986, 2021, 4120, 8486, 17955, 39204, 87515, 196569, 437797, 957362, 2044827, 4257394, 8639335, 17100774},
{9, 16, 28, 45, 77, 154, 347, 816, 1911, 4366, 9654, 20646, 42906, 87373, 176023, 353702, 712286, 1438821, 2909549, 5870876, 11783816},
{8, 6, 12, 48, 156, 403, 877, 1669, 2836, 4346, 6024, 7554, 8652, 9615, 12577, 23971, 58912, 148486, 351260, 770724, 1580844},
{10, 34, 83, 183, 372, 704, 1257, 2145, 3534, 5662, 8863, 13595, 20472, 30300, 44117, 63237, 89298, 124314, 170731, 231487, 310076},
{8, 20, 36, 53, 68, 78, 80, 71, 48, 8, -52, -135, -244, -382, -552, -757, -1000, -1284, -1612, -1987, -2412},
{8, 24, 64, 148, 311, 624, 1225, 2369, 4520, 8531, 15994, 29900, 55846, 104185, 193758, 358183, 656084, 1187050, 2115368, 3703412, 6355581},
{5, 15, 30, 49, 71, 95, 120, 145, 169, 191, 210, 225, 235, 239, 236, 225, 205, 175, 134, 81, 15},
{20, 50, 100, 187, 348, 653, 1224, 2260, 4071, 7142, 12288, 21029, 36419, 64717, 118496, 222024, 419946, 790371, 1463632, 2649684, 4685450},
{19, 31, 52, 89, 164, 327, 670, 1344, 2599, 4900, 9234, 17847, 35889, 74868, 159497, 340530, 717567, 1477557, 2956756, 5736005, 10781030},
{18, 39, 72, 138, 278, 564, 1112, 2106, 3859, 6958, 12565, 22975, 42565, 79305, 147043, 268821, 481528, 842249, 1436726, 2390408, 3882632},
{4, 10, 15, 19, 22, 24, 25, 25, 24, 22, 19, 15, 10, 4, -3, -11, -20, -30, -41, -53, -66},
{17, 26, 56, 136, 308, 628, 1180, 2113, 3711, 6506, 11444, 20114, 35050, 60116, 100984, 165715, 265453, 415242, 634976, 950492, 1394816},
{25, 37, 60, 118, 244, 489, 953, 1860, 3725, 7710, 16362, 35110, 75232, 159574, 333227, 682794, 1369993, 2688371, 5156120, 9663710, 17702660},
{4, 8, 33, 90, 191, 348, 577, 927, 1566, 2968, 6257, 13776, 29961, 62612, 124665, 236581, 429480, 749160, 1261153, 2056982, 3261795},
{13, 25, 58, 131, 276, 546, 1035, 1922, 3551, 6559, 12064, 21925, 39086, 68016, 115257, 190092, 305345, 478325, 731926, 1095895, 1608280},
{8, 7, 17, 55, 139, 281, 476, 687, 826, 731, 139, -1345, -4283, -9443, -17842, -30793, -49956, -77393, -115627, -167705, -237265},
{5, 22, 61, 137, 265, 460, 737, 1111, 1597, 2210, 2965, 3877, 4961, 6232, 7705, 9395, 11317, 13486, 15917, 18625, 21625},
{15, 14, 17, 28, 53, 111, 267, 709, 1908, 4922, 11933, 27153, 58340, 119414, 235217, 450591, 848077, 1582290, 2945281, 5487158, 10231495},
{2, 9, 28, 68, 137, 258, 498, 1015, 2135, 4478, 9159, 18097, 34472, 63377, 112719, 194430, 326056, 532799, 850094, 1326810, 2029171},
{22, 34, 46, 53, 55, 67, 142, 416, 1181, 3001, 6930, 15013, 31533, 66065, 140600, 305315, 671836, 1480416, 3230374, 6924401, 14511151},
{18, 34, 63, 125, 258, 526, 1027, 1901, 3338, 5586, 8959, 13845, 20714, 30126, 42739, 59317, 80738, 108002, 142239, 184717, 236850},
{27, 52, 102, 187, 321, 526, 843, 1369, 2346, 4335, 8515, 17154, 34306, 66795, 125554, 227394, 397285, 671238, 1099884, 1752853, 2724063},
{23, 38, 55, 78, 115, 182, 314, 595, 1239, 2789, 6549, 15431, 35510, 78803, 168285, 347274, 697739, 1377040, 2692175, 5248108, 10237257},
{25, 38, 63, 120, 243, 496, 1004, 2001, 3903, 7429, 13817, 25215, 45369, 80781, 142570, 249338, 431421, 736992, 1240579, 2054666, 3345159},
{28, 41, 54, 67, 80, 93, 106, 119, 132, 145, 158, 171, 184, 197, 210, 223, 236, 249, 262, 275, 288},
{-6, 0, 15, 44, 101, 212, 418, 778, 1372, 2304, 3705, 5736, 8591, 12500, 17732, 24598, 33454, 44704, 58803, 76260, 97641},
{4, 28, 65, 121, 220, 415, 796, 1496, 2709, 4761, 8325, 14968, 28410, 57238, 120465, 258450, 553719, 1170131, 2426846, 4940384, 9902961},
{6, 7, 15, 36, 76, 141, 237, 370, 546, 771, 1051, 1392, 1800, 2281, 2841, 3486, 4222, 5055, 5991, 7036, 8196},
{24, 33, 45, 62, 77, 83, 95, 191, 590, 1804, 4931, 12217, 28162, 61797, 131542, 275661, 574402, 1195504, 2484736, 5141196, 10551151},
{23, 41, 68, 104, 149, 203, 266, 338, 419, 509, 608, 716, 833, 959, 1094, 1238, 1391, 1553, 1724, 1904, 2093},
{22, 42, 68, 105, 161, 238, 323, 380, 347, 146, -277, -830, -906, 1697, 13721, 53857, 170028, 477110, 1234650, 2999191, 6910095},
{-9, -1, 22, 61, 119, 200, 304, 418, 503, 477, 194, -581, -2201, -5170, -10180, -18152, -30281, -48085, -73458, -108727, -156713},
{11, 16, 21, 26, 31, 36, 41, 46, 51, 56, 61, 66, 71, 76, 81, 86, 91, 96, 101, 106, 111},
{7, 13, 33, 88, 211, 463, 966, 1970, 3984, 8020, 16029, 31654, 61492, 117150, 218504, 398730, 711877, 1243999, 2129161, 3571988, 5878841},
{26, 54, 107, 191, 316, 512, 855, 1506, 2775, 5254, 10135, 19972, 40418, 83980, 177798, 379260, 806629, 1698071, 3523848, 7197074, 14465457},
{7, 6, 4, 13, 65, 221, 583, 1306, 2603, 4745, 8094, 13284, 21806, 37503, 69932, 141398, 301131, 653436, 1413420, 3017283, 6339755},
{8, 13, 26, 47, 76, 113, 158, 211, 272, 341, 418, 503, 596, 697, 806, 923, 1048, 1181, 1322, 1471, 1628},
{14, 19, 31, 61, 140, 340, 804, 1785, 3694, 7157, 13081, 22729, 37804, 60542, 93814, 141237, 207294, 297463, 418355, 577861, 785308},
{18, 25, 41, 74, 132, 223, 355, 536, 774, 1077, 1453, 1910, 2456, 3099, 3847, 4708, 5690, 6801, 8049, 9442, 10988},
{13, 39, 87, 171, 318, 573, 1009, 1765, 3152, 5886, 11539, 23368, 47825, 97318, 195247, 385056, 746111, 1420737, 2658839, 4889321, 8831144},
{10, 8, 14, 34, 74, 141, 255, 482, 1006, 2285, 5397, 12804, 30003, 69026, 155797, 345601, 755687, 1633870, 3501675, 7448656, 15726061},
{6, 11, 25, 69, 172, 364, 663, 1064, 1547, 2130, 3002, 4780, 8943, 18505, 38998, 79845, 156212, 291437, 520143, 892151, 1477318},
{27, 50, 84, 135, 218, 372, 697, 1431, 3090, 6700, 14160, 28802, 56287, 106157, 194788, 351446, 631221, 1142968, 2109356, 3994435, 7771240},
{9, 31, 66, 114, 175, 249, 336, 436, 549, 675, 814, 966, 1131, 1309, 1500, 1704, 1921, 2151, 2394, 2650, 2919},
{8, 7, 7, 8, 10, 22, 98, 426, 1513, 4538, 11998, 28875, 64756, 137733, 281650, 559617, 1089152, 2088679, 3962843, 7457584, 13938920},
{-5, -7, -9, -11, -2, 54, 247, 779, 2078, 5020, 11348, 24426, 50527, 100927, 195162, 365902, 666005, 1178435, 2029861, 3408899, 5590116},
{10, 16, 34, 74, 147, 274, 521, 1081, 2432, 5608, 12628, 27136, 55313, 107130, 198019, 351047, 599686, 991280, 1591318, 2488630, 3801631},
{9, 8, 21, 66, 172, 391, 830, 1721, 3552, 7290, 14748, 29193, 56376, 106318, 196477, 357514, 644161, 1156577, 2084086, 3797672, 7049008},
{14, 40, 88, 183, 380, 785, 1580, 3064, 5738, 10495, 19048, 34867, 65134, 124613, 242953, 477946, 938949, 1827706, 3509661, 6640837, 12400447},
{15, 25, 39, 64, 129, 294, 653, 1337, 2538, 4600, 8260, 15178, 28989, 57277, 115164, 231711, 461221, 903259, 1738853, 3298396, 6194405},
{9, 6, 6, 11, 31, 107, 353, 1029, 2669, 6320, 14014, 29709, 61115, 123102, 243845, 475664, 914050, 1731530, 3239870, 6009120, 11104366},
{26, 37, 48, 75, 147, 313, 670, 1432, 3073, 6602, 14068, 29452, 60189, 119691, 231437, 435496, 798808, 1431239, 2510444, 4320037, 7307627},
{3, -1, -10, -24, -43, -67, -96, -130, -169, -213, -262, -316, -375, -439, -508, -582, -661, -745, -834, -928, -1027},
{18, 43, 89, 169, 300, 508, 853, 1501, 2897, 6147, 13824, 31625, 71718, 159389, 345977, 733436, 1519704, 3080095, 6109095, 11860445, 22542764},
{17, 38, 63, 88, 109, 122, 123, 108, 73, 14, -73, -192, -347, -542, -781, -1068, -1407, -1802, -2257, -2776, -3363},
{3, 2, 10, 40, 110, 248, 497, 920, 1605, 2670, 4268, 6592, 9880, 14420, 20555, 28688, 39287, 52890, 70110, 91640, 118258},
{21, 37, 57, 85, 131, 212, 354, 601, 1040, 1854, 3418, 6456, 12280, 23135, 42677, 76614, 133543, 226019, 371895, 595975, 932025},
{14, 28, 56, 121, 265, 567, 1177, 2386, 4774, 9508, 18898, 37365, 73056, 140538, 265518, 493797, 909482, 1673256, 3102528, 5835085, 11151679},
{13, 31, 73, 156, 302, 533, 869, 1334, 1975, 2899, 4333, 6712, 10800, 17849, 29801, 49538, 81185, 130471, 205153, 315508, 474898},
{-1, -10, -9, 16, 78, 189, 360, 601, 921, 1328, 1829, 2430, 3136, 3951, 4878, 5919, 7075, 8346, 9731, 11228, 12834},
{1, 10, 33, 77, 148, 252, 400, 620, 988, 1712, 3344, 7262, 16674, 38591, 87590, 192932, 412066, 856321, 1739510, 3468242, 6804651},
{2, 19, 60, 137, 265, 461, 749, 1184, 1908, 3251, 5909, 11312, 22519, 46478, 99470, 219319, 490975, 1097216, 2415107, 5194716, 10885594},
{7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12, -13},
{13, 24, 44, 89, 197, 451, 1016, 2204, 4587, 9194, 17866, 33915, 63351, 117117, 215018, 392358, 710721, 1274860, 2258304, 3941069, 6763777},
{1, -4, 1, 26, 80, 183, 394, 857, 1858, 3876, 7615, 14048, 24625, 42043, 72406, 130287, 249223, 501620, 1034021, 2126310, 4286814},
{7, 20, 36, 46, 41, 20, 1, 35, 223, 736, 1838, 3912, 7489, 13280, 22211, 35461, 54503, 81148, 117592, 166466, 230889},
{16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96},
{-1, 3, 12, 46, 137, 336, 738, 1542, 3172, 6494, 13173, 26223, 50812, 95393, 173241, 304485, 518733, 858397, 1382834, 2173428, 3339747}
};