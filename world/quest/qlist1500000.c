inherit SKILL;

mapping *quest = ({

        ([      "quest":        "�μ�",
                "quest_type":   "ɱ",
                "time":         350,
                "exp_bonus":    40,
                "pot_bonus":    30,
                "score":        14,
        ]),                         
        ([      "quest":        "������",
                "quest_type":   "ɱ",
                "time":         450,
                "exp_bonus":    160,
                "pot_bonus":    50,
                "score":        14,
        ]),                         

        ([      "quest":        "���顸��ڤ��",
                "quest_type":   "ɱ",
                "time":         450,
                "exp_bonus":    140,
                "pot_bonus":    50,
                "score":        14,
        ]),                         

	([	"quest":	"����",
		"quest_type":	"ɱ",
                "time":         350,
                "exp_bonus":    120,
                "pot_bonus":    40,
                "score":        14,    
	]),

        ([      "quest":        "���޼�",
                "quest_type":   "ɱ",
                "time":         400,
                "exp_bonus":    160,
                "pot_bonus":    50,
                "score":        14,
        ]),                    
        ([      "quest":        "���ȴ�ʦ",
                "quest_type":   "ɱ",
                "time":         390,
                "exp_bonus":    120,
                "pot_bonus":    50,
                "score":        14,
        ]), 
        ([      "quest":        "̫����",
                "quest_type":   "Ѱ",
                "time":         250,
                "exp_bonus":    30,
                "pot_bonus":    20,
                "score":        14,      
	]),              
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}          
