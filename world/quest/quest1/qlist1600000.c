inherit SKILL;

mapping *quest = ({
	([	"quest":	"ÀèÉú",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"ÇúÁé·ç",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"ÊÌÎÀ",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"Âí¾ãÎª",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"ÓàºéÐË",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"À¶Ö¹Æ¼",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;35m×ÏËªÑª²õÒÂ[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;35mÄ§±Þôæçç[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;33mÈí½ðÊø´ø[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[32m´©»¨ÉßÓ°Ð¬[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"ÅíÓÐ¾´",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"²·Ó¥",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"Íäµ¶",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"Î¤Ò»Ð¦",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"Ðþ¿à´óÊ¦",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"ÐþÄÑ´óÊ¦",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"¼ò³¤ÀÏ",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33mÇØ¸è[2;37;0m",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33m¶àÇéµ¶[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"Áº³¤ÀÏ",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"Â³ÓÐ½Å",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"Ðþ±¯´óÊ¦",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"³É²»ÓÅ",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"°×É«³¤ÉÀ",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"è¨Â×",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;36m±¦À¶¶ÐÉÀ[2;37;0m",
		"quest_type":	"Ñ°",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"¶¡´ºÇï",
		"quest_type":	"É±",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
