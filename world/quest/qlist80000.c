inherit SKILL;

mapping *quest = ({
        ([      "quest":                "�سǹٱ�",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "����ͷ��",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "ܽ��",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "����¥",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
       ([      "quest":                "��ϧ��",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15
        ]),
       ([      "quest":                "�سǹٱ�",  
               "quest_type":           "ɱ",
               "time":                  500,
               "exp_bonus":             40,
               "pot_bonus":             20,
               "score" :                8
         ]),
});

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

