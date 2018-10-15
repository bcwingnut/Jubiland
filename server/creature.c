#include "creature.h"

const int CREATURE_MAX_HP[CREATURE_CATEGORIES_NUM][CREATURE_MAX_LEVEL + 1] = {
        {0, 100,  200,  300,  400,  500,  600,  700,  800,  900,  1000,  1100,  1200,  1300,  1400,  1500,  1600,  1700,  1800,  1900,  2000},
        {0, 200,  400,  600,  800,  1000, 1200, 1400, 1600, 1800, 2000,  2200,  2400,  2600,  2800,  3000,  3200,  3400,  3600,  3800,  4000},
        {0, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 20000}
};

const int CREATURE_ATTACK[CREATURE_CATEGORIES_NUM][CREATURE_MAX_LEVEL + 1] = {
        {0, 2,  4,  6,  8,  10, 12, 14, 16, 18, 20,  22,  24,  26,  28,  30,  32,  34,  36,  38,  40},
        {0, 4,  8,  12, 16, 20, 24, 28, 32, 36, 40,  44,  48,  52,  56,  60,  64,  68,  72,  76,  80},
        {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200}
};

const int CREATURE_EXP[CREATURE_CATEGORIES_NUM][CREATURE_MAX_LEVEL + 1] = {
        {0, 2,  4,  6,  8,  10, 12, 14, 16, 18, 20,  22,  24,  26,  28,  30,  32,  34,  36,  38,  40},
        {0, 4,  8,  12, 16, 20, 24, 28, 32, 36, 40,  44,  48,  52,  56,  60,  64,  68,  72,  76,  80},
        {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200}
};

const int CREATURE_CATEGORY[CREATURE_NUM] = {
        2, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 2, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 2, 0, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0, 2, 1, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0,
        0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 1, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 2, 1, 0, 0, 0, 2, 2, 1, 0, 0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0,
        2, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 2, 1, 0, 0, 2, 0, 0, 0, 1,
        0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 2, 0, 1, 0, 0, 0, 0, 2, 0, 0,
        0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 2, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 1, 2, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1,
        0, 0, 2, 1, 0, 0, 0, 0, 1, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 2, 2, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0,
        0, 0, 0, 1, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 1, 0, 0, 0, 2, 0, 0, 0, 2, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
        0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 1, 0,
        0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 1, 1,
        0, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const int CREATURE_LEVEL[CREATURE_NUM] = {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
        6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
        11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
        12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
        13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
        13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
        14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14,
        14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
        15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16,
        16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
        17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
        18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18,
        18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
        19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19,
        19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
        20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20

};

const int CREATURE_INIT_POSITION[CREATURE_NUM][2] = {
        {3,   12},
        {3,   9},
        {9,   2},
        {0,   6},
        {0,   16},
        {1,   9},
        {2,   2},
        {7,   4},
        {2,   6},
        {3,   0},
        {11,  10},
        {5,   1},
        {6,   2},
        {1,   14},
        {3,   0},
        {5,   5},
        {7,   5},
        {3,   15},
        {3,   7},
        {5,   8},
        {9,   13},
        {12,  3},
        {5,   1},
        {8,   8},
        {7,   16},
        {5,   18},
        {11,  4},
        {9,   12},
        {0,   6},
        {4,   20},
        {6,   17},
        {11,  10},
        {14,  8},
        {10,  1},
        {10,  0},
        {11,  5},
        {3,   12},
        {11,  5},
        {6,   6},
        {10,  12},
        {11,  5},
        {9,   1},
        {6,   16},
        {11,  8},
        {16,  8},
        {10,  7},
        {8,   2},
        {17,  9},
        {7,   10},
        {6,   12},
        {11,  2},
        {7,   3},
        {6,   12},
        {19,  7},
        {4,   9},
        {2,   14},
        {12,  18},
        {10,  3},
        {12,  6},
        {10,  12},
        {12,  3},
        {10,  4},
        {12,  1},
        {7,   10},
        {1,   17},
        {4,   25},
        {8,   22},
        {1,   28},
        {10,  13},
        {14,  10},
        {12,  16},
        {7,   8},
        {20,  7},
        {1,   28},
        {8,   6},
        {6,   11},
        {18,  13},
        {19,  8},
        {21,  3},
        {12,  10},
        {22,  6},
        {9,   26},
        {16,  11},
        {15,  9},
        {7,   27},
        {2,   24},
        {13,  8},
        {5,   22},
        {9,   27},
        {8,   22},
        {14,  14},
        {28,  6},
        {5,   17},
        {22,  12},
        {5,   15},
        {21,  3},
        {1,   33},
        {7,   31},
        {7,   18},
        {11,  16},
        {18,  10},
        {9,   19},
        {15,  18},
        {12,  22},
        {15,  14},
        {4,   34},
        {21,  13},
        {25,  8},
        {9,   28},
        {17,  13},
        {13,  10},
        {5,   24},
        {1,   23},
        {23,  2},
        {11,  14},
        {13,  28},
        {34,  3},
        {24,  6},
        {20,  7},
        {29,  9},
        {5,   30},
        {23,  9},
        {17,  11},
        {13,  11},
        {5,   31},
        {11,  31},
        {20,  14},
        {4,   28},
        {11,  20},
        {13,  20},
        {3,   29},
        {7,   33},
        {8,   27},
        {20,  16},
        {17,  22},
        {10,  23},
        {12,  25},
        {2,   34},
        {38,  10},
        {24,  11},
        {10,  22},
        {8,   20},
        {39,  8},
        {27,  4},
        {28,  17},
        {26,  21},
        {28,  10},
        {12,  35},
        {19,  23},
        {24,  23},
        {31,  18},
        {15,  29},
        {19,  13},
        {2,   43},
        {37,  10},
        {23,  19},
        {24,  7},
        {16,  20},
        {2,   35},
        {9,   26},
        {16,  17},
        {2,   53},
        {12,  24},
        {37,  14},
        {23,  20},
        {8,   25},
        {38,  4},
        {31,  16},
        {20,  27},
        {37,  14},
        {9,   27},
        {33,  15},
        {15,  32},
        {1,   46},
        {13,  36},
        {6,   41},
        {9,   41},
        {40,  2},
        {41,  5},
        {19,  32},
        {19,  35},
        {40,  3},
        {21,  28},
        {38,  8},
        {44,  2},
        {42,  5},
        {46,  8},
        {25,  12},
        {4,   51},
        {3,   50},
        {26,  16},
        {14,  24},
        {16,  32},
        {8,   40},
        {41,  1},
        {2,   52},
        {2,   40},
        {12,  45},
        {6,   36},
        {26,  17},
        {3,   52},
        {42,  5},
        {29,  29},
        {32,  21},
        {8,   38},
        {2,   47},
        {32,  25},
        {25,  27},
        {11,  40},
        {45,  15},
        {41,  14},
        {7,   44},
        {47,  2},
        {19,  25},
        {1,   62},
        {13,  41},
        {12,  32},
        {10,  46},
        {38,  20},
        {17,  28},
        {31,  25},
        {2,   57},
        {34,  29},
        {41,  19},
        {35,  16},
        {47,  4},
        {4,   52},
        {34,  21},
        {12,  49},
        {2,   48},
        {45,  11},
        {2,   47},
        {19,  28},
        {10,  41},
        {53,  6},
        {43,  14},
        {39,  14},
        {34,  22},
        {28,  37},
        {47,  17},
        {51,  9},
        {43,  24},
        {10,  55},
        {23,  43},
        {11,  42},
        {2,   55},
        {32,  34},
        {25,  29},
        {35,  17},
        {10,  40},
        {32,  32},
        {35,  32},
        {8,   54},
        {20,  40},
        {56,  11},
        {31,  26},
        {8,   46},
        {34,  34},
        {39,  12},
        {7,   45},
        {49,  14},
        {46,  9},
        {6,   52},
        {22,  39},
        {17,  50},
        {2,   69},
        {12,  57},
        {55,  12},
        {10,  49},
        {49,  19},
        {45,  19},
        {56,  11},
        {9,   60},
        {35,  37},
        {55,  12},
        {34,  34},
        {40,  33},
        {63,  7},
        {58,  7},
        {51,  8},
        {62,  13},
        {59,  15},
        {30,  45},
        {2,   70},
        {12,  55},
        {5,   61},
        {53,  6},
        {30,  43},
        {64,  5},
        {5,   67},
        {4,   80},
        {28,  44},
        {59,  7},
        {69,  8},
        {11,  51},
        {49,  12},
        {29,  33},
        {5,   57},
        {68,  2},
        {31,  38},
        {20,  50},
        {35,  36},
        {44,  35},
        {4,   62},
        {46,  24},
        {49,  15},
        {1,   69},
        {66,  1},
        {3,   73},
        {17,  45},
        {55,  14},
        {41,  24},
        {26,  40},
        {50,  15},
        {38,  33},
        {64,  18},
        {50,  28},
        {64,  9},
        {44,  21},
        {51,  12},
        {60,  13},
        {7,   58},
        {55,  28},
        {7,   64},
        {30,  41},
        {58,  13},
        {13,  66},
        {61,  16},
        {43,  22},
        {13,  66},
        {52,  18},
        {81,  2},
        {11,  63},
        {68,  0},
        {37,  48},
        {4,   74},
        {58,  21},
        {58,  15},
        {9,   74},
        {61,  12},
        {29,  47},
        {33,  54},
        {12,  66},
        {60,  19},
        {31,  48},
        {21,  53},
        {60,  21},
        {19,  55},
        {63,  18},
        {51,  21},
        {55,  17},
        {17,  57},
        {85,  1},
        {46,  24},
        {5,   81},
        {47,  39},
        {46,  26},
        {31,  40},
        {53,  18},
        {11,  60},
        {51,  25},
        {7,   68},
        {47,  35},
        {55,  23},
        {39,  44},
        {14,  70},
        {48,  38},
        {23,  69},
        {59,  22},
        {56,  35},
        {10,  64},
        {6,   80},
        {60,  24},
        {33,  47},
        {7,   85},
        {41,  42},
        {14,  67},
        {53,  22},
        {4,   74},
        {74,  19},
        {63,  19},
        {61,  19},
        {51,  38},
        {75,  15},
        {2,   95},
        {86,  4},
        {46,  45},
        {45,  38},
        {38,  55},
        {3,   83},
        {84,  7},
        {50,  41},
        {32,  52},
        {16,  70},
        {90,  10},
        {2,   87},
        {16,  82},
        {21,  71},
        {0,   81},
        {58,  31},
        {41,  54},
        {6,   88},
        {19,  62},
        {49,  32},
        {1,   89},
        {59,  35},
        {59,  30},
        {10,  87},
        {59,  22},
        {31,  62},
        {76,  19},
        {3,   92},
        {34,  52},
        {21,  72},
        {43,  44},
        {50,  36},
        {88,  9},
        {27,  63},
        {31,  63},
        {75,  24},
        {51,  33},
        {49,  53},
        {61,  27},
        {31,  60},
        {85,  9},
        {88,  6},
        {21,  71},
        {77,  10},
        {96,  4},
        {91,  10},
        {31,  55},
        {87,  2},
        {35,  68},
        {8,   86},
        {68,  36},
        {78,  9},
        {68,  22},
        {66,  36},
        {2,   87},
        {24,  63},
        {81,  20},
        {34,  67},
        {60,  37},
        {1,   89},
        {49,  46},
        {43,  65},
        {83,  7},
        {79,  28},
        {43,  61},
        {2,   98},
        {25,  65},
        {22,  80},
        {100, 8},
        {94,  14},
        {6,   102},
        {59,  37},
        {3,   97},
        {24,  73},
        {14,  93},
        {26,  76},
        {87,  11},
        {69,  33},
        {93,  6},
        {8,   102},
        {34,  60},
        {35,  59},
        {71,  39},
        {7,   105},
        {111, 6},
        {30,  76},
        {53,  51},
        {4,   98},
        {9,   92},
        {66,  42},
        {78,  19},
        {34,  79},
        {9,   106},
        {39,  70},
        {37,  60},
        {49,  53},
        {53,  45},
        {48,  54},
        {77,  30},
        {81,  29},
        {52,  46},
        {9,   105},
        {65,  46},
        {46,  53},
        {15,  97},
        {84,  32},
        {37,  77},
        {20,  96},
        {87,  12},
        {3,   101},
        {100, 5},
        {114, 4},
        {28,  86},
        {22,  95},
        {3,   118},
        {38,  74},
        {21,  98},
        {6,   113},
        {44,  62},
        {102, 4},
        {107, 10},
        {91,  22},
        {20,  98},
        {5,   117},
        {39,  73},
        {49,  59},
        {10,  121},
        {73,  40},
        {6,   113},
        {86,  32},
        {28,  83},
        {36,  69},
        {94,  11},
        {118, 5},
        {33,  76},
        {64,  41},
        {63,  49},
        {39,  68},
        {2,   120},
        {23,  85},
        {40,  64},
        {13,  107},
        {74,  37},
        {21,  102},
        {15,  103},
        {96,  20},
        {90,  32},
        {47,  64},
        {109, 9},
        {65,  57},
        {23,  83},
        {19,  95},
        {98,  27},
        {104, 10},
        {88,  20},
        {33,  74},
        {39,  80},
        {105, 16},
        {114, 2},
        {50,  68},
        {107, 2},
        {73,  50},
        {63,  48},
        {98,  24},
        {42,  84},
        {6,   107},
        {78,  46},
        {64,  51},
        {48,  71},
        {114, 2},
        {19,  91},
        {95,  24},
        {60,  57},
        {74,  41},
        {10,  109},
        {71,  55},
        {46,  76},
        {35,  92},
        {105, 8},
        {117, 6},
        {113, 1},
        {51,  65},
        {103, 23},
        {9,   120},
        {12,  111},
        {82,  46},
        {24,  100},
        {88,  45},
        {4,   114},
        {99,  19},
        {67,  53},
        {13,  107},
        {19,  102},
        {66,  53},
        {110, 12},
        {36,  88},
        {69,  66},
        {107, 19},
        {45,  71},
        {44,  77},
        {113, 7},
        {92,  38},
        {17,  109},
        {6,   119},
        {75,  50},
        {118, 2},
        {101, 22},
        {53,  77},
        {79,  50},
        {29,  106},
        {63,  73},
        {58,  62},
        {14,  110},
        {27,  110},
        {113, 16},
        {113, 10},
        {93,  40},
        {56,  64},
        {28,  101},
        {28,  93},
        {16,  118},
        {48,  87},
        {17,  122},
        {103, 24},
        {94,  32},
        {92,  40},
        {21,  107},
        {101, 24},
        {87,  44},
        {84,  38},
        {65,  61},
        {83,  46},
        {39,  91},
        {31,  97},
        {76,  57},
        {24,  116},
        {34,  92},
        {76,  61},
        {33,  91},
        {30,  98},
        {87,  48},
        {110, 20},
        {45,  83},
        {48,  83},
        {78,  61},
        {65,  61},
        {93,  35},
        {38,  94},
        {31,  97},
        {40,  87},
        {47,  85},
        {78,  64},
        {67,  64},
        {76,  63},
        {51,  87},
        {82,  54},
        {58,  72},
        {72,  62},
        {51,  95},
        {108, 35},
        {81,  52},
        {112, 26},
        {64,  76},
        {56,  79},
        {84,  49},
        {42,  95},
        {32,  110},
        {81,  56},
        {83,  56},
        {48,  90},
        {104, 36},
        {68,  65},
        {39,  100},
        {87,  62},
        {60,  78},
        {48,  86},
        {37,  103},
        {38,  110},
        {62,  72},
        {75,  76},
        {77,  73},
        {67,  73},
        {42,  110},
        {51,  94},
        {50,  85},
        {63,  76},
        {101, 40},
        {53,  99},
        {42,  93},
        {39,  109},
        {67,  69},
        {44,  106},
        {72,  63},
        {69,  70},
        {86,  66},
        {63,  75},
        {47,  95},
        {104, 51},
        {94,  44},
        {79,  67},
        {62,  91},
        {74,  71},
        {69,  86},
        {109, 47},
        {101, 51},
        {89,  50},
        {60,  91},
        {77,  67},
        {86,  58},
        {62,  95},
        {84,  67},
        {55,  89},
        {54,  87},
        {43,  97},
        {59,  88},
        {66,  92},
        {102, 49},
        {42,  110},
        {87,  56},
        {52,  98},
        {102, 49},
        {67,  82},
        {56,  102},
        {97,  45},
        {58,  85},
        {38,  122},
        {52,  95},
        {111, 35},
        {107, 41},
        {37,  105},
        {72,  78},
        {94,  61},
        {66,  85},
        {87,  58},
        {86,  59},
        {64,  96},
        {47,  106},
        {109, 44},
        {99,  58},
        {104, 44},
        {52,  98},
        {55,  106},
        {69,  83},
        {71,  87},
        {63,  99},
        {54,  91},
        {97,  66},
        {98,  60},
        {53,  95},
        {84,  66},
        {87,  71},
        {102, 46},
        {42,  112},
        {85,  68},
        {110, 53},
        {60,  101},
        {95,  60},
        {104, 48},
        {94,  58},
        {98,  65},
        {99,  50},
        {112, 37},
        {70,  90},
        {53,  114},
        {96,  67},
        {54,  107},
        {57,  95},
        {62,  100},
        {89,  63},
        {73,  92},
        {73,  95},
        {62,  97},
        {75,  90},
        {91,  65},
        {82,  75},
        {65,  89},
        {58,  104},
        {110, 43},
        {83,  84},
        {104, 51},
        {74,  84},
        {78,  85},
        {62,  93},
        {94,  69},
        {58,  103},
        {100, 68},
        {88,  75},
        {73,  94},
        {84,  80},
        {76,  78},
        {64,  90},
        {111, 63},
        {107, 67},
        {51,  118},
        {85,  72},
        {89,  82},
        {56,  109},
        {103, 69},
        {106, 58},
        {87,  87},
        {109, 55},
        {67,  98},
        {81,  81},
        {98,  66},
        {60,  116},
        {107, 57},
        {104, 66},
        {76,  98},
        {81,  83},
        {61,  109},
        {93,  70},
        {85,  86},
        {91,  86},
        {99,  76},
        {89,  82},
        {64,  101},
        {60,  110},
        {62,  102},
        {111, 58},
        {102, 60},
        {77,  89},
        {61,  111},
        {98,  70},
        {108, 55},
        {79,  89},
        {101, 68},
        {98,  66},
        {87,  89},
        {73,  108},
        {88,  92},
        {88,  83},
        {93,  84},
        {102, 77},
        {64,  105},
        {86,  82},
        {83,  91},
        {89,  84},
        {111, 64},
        {69,  101},
        {77,  92},
        {89,  94},
        {99,  82},
        {106, 61},
        {100, 70},
        {81,  89},
        {76,  102},
        {92,  93},
        {108, 69},
        {82,  99},
        {97,  75},
        {89,  92},
        {77,  99},
        {87,  90},
        {109, 68},
        {90,  81},
        {100, 68},
        {80,  105},
        {103, 84},
        {88,  98},
        {91,  79},
        {91,  83},
        {78,  98},
        {96,  91},
        {87,  99},
        {78,  100},
        {76,  98},
        {86,  95},
        {108, 68},
        {82,  93},
        {81,  92},
        {94,  82},
        {107, 78},
        {81,  108},
        {85,  98},
        {97,  74},
        {88,  83},
        {98,  78},
        {105, 68},
        {106, 70},
        {90,  94},
        {74,  104},
        {88,  103},
        {93,  98},
        {81,  96},
        {87,  93},
        {103, 78},
        {79,  112},
        {88,  100},
        {80,  104},
        {74,  101},
        {106, 77},
        {95,  84},
        {94,  88},
        {96,  82},
        {95,  92},
        {91,  98},
        {79,  106},
        {83,  102},
        {79,  104},
        {103, 85},
        {99,  93},
        {90,  99},
        {86,  101},
        {92,  90},
        {78,  102},
        {97,  96},
        {91,  99},
        {85,  110},
        {110, 70},
        {87,  108},
        {88,  90},
        {87,  92},
        {107, 90},
        {95,  90},
        {84,  111},
        {100, 91},
        {88,  104},
        {86,  107},
        {91,  99},
        {92,  95},
        {97,  84},
        {89,  108},
        {90,  95},
        {106, 90},
        {91,  90},
        {86,  103},
        {99,  101},
        {102, 96},
        {85,  108},
        {101, 98},
        {91,  92},
        {88,  108},
        {90,  96},
        {100, 100},
        {99,  100},
        {91,  104},
        {95,  107},
        {90,  99},
        {91,  101},
        {102, 97},
        {93,  99},
        {95,  105},
        {97,  90},
        {104, 89},
        {102, 86},
        {89,  97},
        {94,  110},
        {101, 85},
        {101, 103},
        {95,  105},
        {93,  101},
        {93,  109},
        {95,  109},
        {99,  95},
        {102, 95},
        {100, 100},
        {108, 89},
        {102, 95},
        {109, 94},
        {96,  109},
        {101, 103},
        {104, 93},
        {105, 100},
        {101, 103},
        {94,  111},
        {102, 95},
        {97,  110},
        {100, 101},
        {107, 89},
        {101, 96},
        {105, 88},
        {100, 100},
        {100, 95},
        {96,  95},
        {108, 88},
        {99,  107},
        {103, 93},
        {103, 106},
        {96,  96},
        {101, 93},
        {100, 95},
        {99,  105},
        {104, 95},
        {107, 89},
        {99,  95},
        {94,  101},
        {99,  102},
        {99,  106},
        {99,  112},
        {97,  109},
        {97,  107},
        {102, 110},
        {103, 111},
        {107, 99},
        {102, 93},
        {102, 103},
        {100, 108},
        {99,  100},
        {105, 105},
        {107, 97},
        {98,  99},
        {102, 107},
        {98,  106},
        {102, 101},
        {102, 109},
        {99,  108},
        {104, 100},
        {100, 109},
        {104, 97},
        {104, 110},
        {101, 114},
        {103, 114},
        {105, 101},
        {100, 107},
        {100, 111},
        {108, 106}
};

const int CREATURE_REFRESH_INTERVAL_SEC[CREATURE_CATEGORIES_NUM] = {60, 300, 3600};
