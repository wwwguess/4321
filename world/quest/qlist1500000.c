inherit SKILL;

mapping *quest = ({

        ([      "quest":        "³Î¼á",
                "quest_type":   "É±",
                "time":         350,
                "exp_bonus":    40,
                "pot_bonus":    30,
                "score":        14,
        ]),                         
        ([      "quest":        "ÕÅÈý·á",
                "quest_type":   "É±",
                "time":         450,
                "exp_bonus":    160,
                "pot_bonus":    50,
                "score":        14,
        ]),                         

        ([      "quest":        "ÈËÁé¡¸ÇøÚ¤¡¹",
                "quest_type":   "É±",
                "time":         450,
                "exp_bonus":    140,
                "pot_bonus":    50,
                "score":        14,
        ]),                         

	([	"quest":	"ÑîåÐ",
		"quest_type":	"É±",
                "time":         350,
                "exp_bonus":    120,
                "pot_bonus":    40,
                "score":        14,    
	]),

        ([      "quest":        "ÕÅÎÞ¼É",
                "quest_type":   "É±",
                "time":         400,
                "exp_bonus":    160,
                "pot_bonus":    50,
                "score":        14,
        ]),                    
        ([      "quest":        "Ðþ´È´óÊ¦",
                "quest_type":   "É±",
                "time":         390,
                "exp_bonus":    120,
                "pot_bonus":    50,
                "score":        14,
        ]), 
        ([      "quest":        "Ì«¹«±ç",
                "quest_type":   "Ñ°",
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
