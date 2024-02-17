/*
Date: February 17, 2024
Author: Dan Gabbay

The tables below represent delays in microseconds from zero-crossing to firing
pulse required to achieve a certain level of power in % of maximum power.
*/

// Steps of 0.4%, 50 Hz
const unsigned short powerToDelayTbale1_50_Hz[251] = {
9999, 9148, 8924, 8765, 8638, 8530, 8435, 8349, 8271, 8199, 8131, 8068, 8008, 7951, 7897, 7845,
7795, 7747, 7700, 7655, 7611, 7569, 7528, 7487, 7448, 7410, 7372, 7336, 7300, 7265, 7230, 7196,
7163, 7130, 7098, 7066, 7035, 7004, 6973, 6943, 6914, 6885, 6856, 6827, 6799, 6771, 6743, 6716,
6689, 6662, 6636, 6610, 6584, 6558, 6532, 6507, 6482, 6457, 6432, 6407, 6383, 6359, 6335, 6311,
6287, 6263, 6240, 6217, 6194, 6170, 6148, 6125, 6102, 6080, 6057, 6035, 6013, 5990, 5968, 5946,
5925, 5903, 5881, 5860, 5838, 5817, 5795, 5774, 5753, 5732, 5711, 5690, 5669, 5648, 5627, 5606,
5586, 5565, 5544, 5524, 5503, 5483, 5462, 5442, 5421, 5401, 5381, 5361, 5340, 5320, 5300, 5280,
5260, 5239, 5219, 5199, 5179, 5159, 5139, 5119, 5099, 5079, 5059, 5039, 5019, 4999, 4979, 4959,
4939, 4919, 4899, 4879, 4859, 4839, 4819, 4799, 4779, 4759, 4738, 4718, 4698, 4678, 4658, 4637,
4617, 4597, 4577, 4556, 4536, 4515, 4495, 4474, 4454, 4433, 4412, 4392, 4371, 4350, 4329, 4308,
4287, 4266, 4245, 4224, 4203, 4181, 4160, 4138, 4117, 4095, 4073, 4052, 4030, 4008, 3985, 3963,
3941, 3918, 3896, 3873, 3850, 3828, 3804, 3781, 3758, 3735, 3711, 3687, 3663, 3639, 3615, 3591,
3566, 3541, 3516, 3491, 3466, 3440, 3414, 3388, 3362, 3336, 3309, 3282, 3255, 3227, 3199, 3171,
3142, 3113, 3084, 3055, 3025, 2994, 2963, 2932, 2900, 2868, 2835, 2802, 2768, 2733, 2698, 2662,
2626, 2588, 2550, 2511, 2470, 2429, 2387, 2343, 2298, 2251, 2203, 2153, 2101, 2047, 1990, 1930,
1867, 1799, 1727, 1649, 1563, 1468, 1360, 1233, 1074, 850, 0};

// Steps of 0.4%, 60 Hz
const unsigned short powerToDelayTbale1_60_Hz[251] = {
8332, 7623, 7436, 7304, 7198, 7108, 7029, 6957, 6892, 6832, 6776, 6723, 6673, 6626, 6581, 6537,
6496, 6455, 6417, 6379, 6343, 6307, 6273, 6239, 6207, 6175, 6144, 6113, 6083, 6054, 6025, 5997,
5969, 5942, 5915, 5888, 5862, 5836, 5811, 5786, 5761, 5737, 5713, 5689, 5666, 5642, 5619, 5597,
5574, 5552, 5530, 5508, 5486, 5465, 5443, 5422, 5401, 5380, 5360, 5339, 5319, 5299, 5279, 5259,
5239, 5219, 5200, 5180, 5161, 5142, 5123, 5104, 5085, 5066, 5047, 5029, 5010, 4992, 4974, 4955,
4937, 4919, 4901, 4883, 4865, 4847, 4829, 4812, 4794, 4776, 4759, 4741, 4724, 4706, 4689, 4672,
4654, 4637, 4620, 4603, 4586, 4569, 4552, 4535, 4518, 4501, 4484, 4467, 4450, 4433, 4416, 4400,
4383, 4366, 4349, 4333, 4316, 4299, 4282, 4266, 4249, 4232, 4216, 4199, 4182, 4166, 4149, 4132,
4116, 4099, 4082, 4066, 4049, 4032, 4016, 3999, 3982, 3965, 3949, 3932, 3915, 3898, 3881, 3864,
3847, 3831, 3814, 3797, 3780, 3763, 3746, 3728, 3711, 3694, 3677, 3660, 3642, 3625, 3608, 3590,
3573, 3555, 3537, 3520, 3502, 3484, 3466, 3448, 3430, 3412, 3394, 3376, 3358, 3339, 3321, 3303,
3284, 3265, 3246, 3228, 3209, 3189, 3170, 3151, 3132, 3112, 3092, 3073, 3053, 3033, 3012, 2992,
2972, 2951, 2930, 2909, 2888, 2867, 2845, 2824, 2802, 2780, 2757, 2735, 2712, 2689, 2666, 2642,
2618, 2594, 2570, 2545, 2520, 2495, 2469, 2443, 2417, 2390, 2362, 2335, 2306, 2278, 2248, 2218,
2188, 2157, 2125, 2092, 2058, 2024, 1989, 1952, 1915, 1876, 1836, 1794, 1751, 1705, 1658, 1608,
1555, 1499, 1439, 1374, 1303, 1223, 1133, 1027, 895, 708, 0};

// Steps of 1%, 50 Hz
const unsigned short powerToDelayTbale2_50_Hz[101] = {
9999, 8839, 8530, 8309, 8131, 7979, 7845, 7723, 7611, 7507, 7410, 7318, 7230, 7146, 7066, 6989,
6914, 6841, 6771, 6703, 6636, 6571, 6507, 6444, 6383, 6323, 6263, 6205, 6148, 6091, 6035, 5979,
5925, 5870, 5817, 5764, 5711, 5658, 5606, 5555, 5503, 5452, 5401, 5350, 5300, 5250, 5199, 5149,
5099, 5049, 4999, 4949, 4899, 4849, 4799, 4748, 4698, 4648, 4597, 4546, 4495, 4443, 4392, 4340,
4287, 4234, 4181, 4128, 4073, 4019, 3963, 3907, 3850, 3793, 3735, 3675, 3615, 3554, 3491, 3427,
3362, 3295, 3227, 3157, 3084, 3009, 2932, 2852, 2768, 2680, 2588, 2491, 2387, 2275, 2153, 2019,
1867, 1689, 1468, 1159, 0};

// Steps of 1%, 60 Hz
const unsigned short powerToDelayTbale2_60_Hz[101] = {
8332, 7366, 7108, 6924, 6776, 6649, 6537, 6436, 6343, 6256, 6175, 6098, 6025, 5955, 5888, 5824,
5761, 5701, 5642, 5585, 5530, 5475, 5422, 5370, 5319, 5269, 5219, 5171, 5123, 5076, 5029, 4983,
4937, 4892, 4847, 4803, 4759, 4715, 4672, 4629, 4586, 4543, 4501, 4459, 4416, 4374, 4333, 4291,
4249, 4207, 4166, 4124, 4082, 4041, 3999, 3957, 3915, 3873, 3831, 3788, 3746, 3703, 3660, 3616,
3573, 3529, 3484, 3439, 3394, 3349, 3303, 3256, 3209, 3161, 3112, 3063, 3012, 2961, 2909, 2856,
2802, 2746, 2689, 2630, 2570, 2508, 2443, 2376, 2306, 2233, 2157, 2075, 1989, 1895, 1794, 1682,
1555, 1407, 1223, 966, 0};