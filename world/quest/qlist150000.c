inherit SKILL;

mapping *quest = ({
       ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            60,
                "pot_bonus":            30,
                "score" :               20
        ]),

       ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            50,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "�ǹ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            80,
                "pot_bonus":            40,
                "score" :               20
        ]),

       ([      "quest":                "����÷",
                "quest_type":           "ɱ",
                "time":                 50,
                "exp_bonus":            40,
                "pot_bonus":            15,
                "score" :               15
        ]),
       ([      "quest":                "����ޱ",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            60,
                "pot_bonus":            35,
                "score" :               15
        ]),
       ([      "quest":                "����ͷ��",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            70,
                "pot_bonus":            40,
                "score" :               15
        ]),
        ([      "quest":                "�سǹٱ�",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "��͢��",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               25 
        ]),
        ([      "quest":                "���ϴ�",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               25 
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               30
        ]),
       ([      "quest":                "��ϧ��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "��ӥ",  
               "quest_type":           "ɱ",
               "time":                  300,
               "exp_bonus":             40,
               "pot_bonus":             20,
               "score" :                45 
         ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

