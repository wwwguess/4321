inherit SKILL;

mapping *quest = ({
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 600,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               9 
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               9 
        ]),
        ([      "quest":                "�϶ӳ�",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            30,
                "pot_bonus":            12,
                "score" :               5
        ]),
        ([      "quest":                "��������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8
        ]),
        ([      "quest":                "����»",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            20,
                "pot_bonus":            15,
                "score" :               8 
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            30,
                "score" :               8
        ]),
       ([      "quest":                "�ϱ�",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               5
        ]),
       ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               15 
        ]),
       ([      "quest":                "Բ��",
                "quest_type":           "ɱ",
                "time":                 100,
                "exp_bonus":            10,
                "pot_bonus":            10,
                "score" :               8
        ]),
/*       ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
       ([      "quest":                "�ϱ�",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 540,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               8
        ]),
        ([      "quest":                "�󱸱�",
                "quest_type":           "ɱ",
                "time":                 480,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "�ÿ�",
                "quest_type":           "ɱ",
                "time":                 200,
                "exp_bonus":            30,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            30,
                "score" :               10 
        ]),
        ([      "quest":                "������Ů",
                "quest_type":           "ɱ",
                "time":                 400,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 150,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               5 
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            40,
                "pot_bonus":            20,
                "score" :               8 
        ]),
        ([      "quest":                "��ɮ��",
                "quest_type":           "ɱ",
                "time":                 500,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               8 
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 300,
                "exp_bonus":            20,
                "pot_bonus":            10,
                "score" :               3
        ]),
*/
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

