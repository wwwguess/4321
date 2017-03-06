inherit SKILL;

mapping *quest = ({
       ([      "quest":                "»¤Ôº",
                "quest_type":           "É±",
                "time":                 240,
                "exp_bonus":            30,
                "pot_bonus":            10,
                "score" :               10
        ]),                 
       ([      "quest":                "¹Ù±ø",
                "quest_type":           "É±",
                "time":                 330,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),                 
       ([      "quest":                "ÍÁ·ËÌ½ÉÚ",
                "quest_type":           "É±",
                "time":                 200,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               10
        ]),                 
       ([      "quest":                "ÀîÐÅ",
                "quest_type":           "É±",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               20
        ]),

       ([      "quest":                "ºÕÔì»ù",
                "quest_type":           "É±",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "ÀÇ¹·",
                "quest_type":           "É±",
                "time":                 300,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               20
        ]),

       ([      "quest":                "À¶ÓêÃ·",
                "quest_type":           "É±",
                "time":                 50,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               15
        ]),
       ([      "quest":                "À¶óãÞ±",
                "quest_type":           "É±",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "ÍÁ·ËÊ×Áì",
                "quest_type":           "É±",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            35,
                "score" :               15
        ]),
       ([      "quest":                "·èÀÏÍ·×Ó",
                "quest_type":           "É±",
                "time":                 400,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
        ([      "quest":                "ÊØ³Ç¹Ù±ø",
                "quest_type":           "É±",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "ÄªÐÀ·¼",
                "quest_type":           "É±",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "ÐÏÇ§»Û",
                "quest_type":           "É±",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "Ü½ÔÆ",
                "quest_type":           "É±",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "ÃÎÓñÂ¥",
                "quest_type":           "É±",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
       ([      "quest":                "°²Ï§åÇ",
                "quest_type":           "É±",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "Îä¹Ù",
                "quest_type":           "É±",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "ÏØ³Ç¹Ù±ø",  
               "quest_type":           "É±",
               "time":                  300,
               "exp_bonus":             30,
               "pot_bonus":             20,
               "score" :                8
         ]),
       ([      "quest":                "±£ïÚ",
               "quest_type":           "É±",
               "time":                  100,
               "exp_bonus":             30,
               "pot_bonus":             20,
               "score" :                8
         ]),                 
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

