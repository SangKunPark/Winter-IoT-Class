//frequency value [us]
#define NOTE_4C   3822
#define NOTE_4CS  3608
#define NOTE_4D   3405
#define NOTE_4DS  3214
#define NOTE_4E   3034
#define NOTE_4F   2863
#define NOTE_4FS  2703
#define NOTE_4G   2551
#define NOTE_4GS  2408
#define NOTE_4A   2273
#define NOTE_4AS  2145
#define NOTE_4B   2025

#define NOTE_5C   1911
#define NOTE_5CS  1804
#define NOTE_5D   1703
#define NOTE_5DS  1607
#define NOTE_5E   1517
#define NOTE_5F   1432
#define NOTE_5FS  1351
#define NOTE_5G   1276
#define NOTE_5GS  1204
#define NOTE_5A   1136
#define NOTE_5AS  1073
#define NOTE_5B   1012

#define NOTE_6C   956
#define NOTE_6CS  902
#define NOTE_6D   851
#define NOTE_6DS  804
#define NOTE_6E   758
#define NOTE_6F   716
#define NOTE_6FS  676
#define NOTE_6G   638
#define NOTE_6GS  602
#define NOTE_6A   568
#define NOTE_6AS  536
#define NOTE_6B   506

#define NOTE_7C   478
#define NOTE_7CS  451
#define NOTE_7D   426
#define NOTE_7DS  402
#define NOTE_7E   379
#define NOTE_7F   358
#define NOTE_7FS  338
#define NOTE_7G   319
#define NOTE_7GS  301
#define NOTE_7A   284
#define NOTE_7AS  268
#define NOTE_7B   253

/*
#define NOTE_8C   239
#define NOTE_8CS  225
#define NOTE_8D   213
#define NOTE_8DS  201
#define NOTE_8E   179
#define NOTE_8F   169
#define NOTE_8FS  159
#define NOTE_8G   150
#define NOTE_8GS  142
#define NOTE_8A   134
#define NOTE_8AS  134
#define NOTE_8B   127
*/

int NationalAnthemM[] = {
  NOTE_4G, NOTE_5C, NOTE_4B, NOTE_4A,
  NOTE_5C, NOTE_4G, NOTE_4E, NOTE_4G,
  NOTE_5C, NOTE_5D, NOTE_5E, NOTE_5F, NOTE_5E,
  NOTE_5D, 0,
  NOTE_5G, NOTE_5F, NOTE_5E, NOTE_5D,
  NOTE_5C, NOTE_4B, NOTE_4A, NOTE_4G, NOTE_4E,
  NOTE_4G, NOTE_5C, NOTE_5D, NOTE_5D, NOTE_5E,
  NOTE_5C, 0, 
  NOTE_4B, NOTE_5C, NOTE_5D, NOTE_4B,
  NOTE_5E, NOTE_5F, NOTE_5G, NOTE_5E,
  NOTE_5D, NOTE_5C, NOTE_4B, NOTE_5C,
  NOTE_5D, 0,
  NOTE_5G, NOTE_5F, NOTE_5E, NOTE_5D,
  NOTE_5C, NOTE_4B, NOTE_4A, NOTE_4G, NOTE_4E,
  NOTE_4G, NOTE_5C, NOTE_5D, NOTE_5D, NOTE_5E,
  NOTE_5C, 0
};
// 4분음표 = 2
int NationalAnthemR[] = {
  2, 3, 1, 2,
  2, 2, 2, 2,
  2, 1, 1, 3, 1,
  6, 2,
  3, 1, 2, 2,
  2, 1, 1, 2, 2,
  2, 2, 1, 1, 2,
  6, 2,
  3, 1, 2, 2,
  3, 1, 2, 2,
  2, 2, 2, 2,
  6, 2,
  3, 1, 2, 2,
  2, 1, 1, 2, 2,
  2, 2, 1, 1, 2,
  6, 2
};

int SchoolBellM[] = {
 NOTE_5G, NOTE_5G, NOTE_5A, NOTE_5A, NOTE_5G, NOTE_5G, NOTE_5E, 
 NOTE_5G, NOTE_5G, NOTE_5E, NOTE_5E, NOTE_5D, 0,
 NOTE_5G, NOTE_5G, NOTE_5A, NOTE_5A, NOTE_5G, NOTE_5G, NOTE_5E,
 NOTE_5G, NOTE_5E, NOTE_5D, NOTE_5E, NOTE_5C, 0
};

int SchoolBellR[] = {
 2, 2, 2, 2, 2, 2, 4,
 2, 2, 2, 2, 6, 2,
 2, 2, 2, 2, 2, 2, 4,
 2, 2, 2, 2, 6, 2
};

int RabbitM[] = {
  NOTE_5G, NOTE_5E, NOTE_5E, NOTE_5G, NOTE_5E, NOTE_5C,
  NOTE_5D, NOTE_5E, NOTE_5D, NOTE_5C, NOTE_5E, NOTE_5G,
  NOTE_6C, NOTE_5G, NOTE_6C, NOTE_5G, NOTE_6C, NOTE_5G, NOTE_5E,
  NOTE_5G, NOTE_5D, NOTE_5F, NOTE_5E, NOTE_5D, NOTE_5C
};

float RabbitR[] = {
  2, 1, 1, 1, 1, 2,
  2, 1, 1, 1, 1, 2,
  1.5, 0.5, 1, 1, 1, 1, 2,
  2, 1, 1, 1, 1, 2
};
