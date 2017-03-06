inherit SKILL;

mapping *quest = ({
	([	"quest":	"∫È∆ﬂπ´",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"Ω–ªØº¶",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"[32m”Ò÷Ò’»[2;37;0m",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"…Û≈–πŸ",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"¡ı¬ﬁπ¯",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"∂…ΩŸ",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"∂…∂Ú",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"∂…ƒ—",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"∑Á«Â—Ô",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"’≈Œﬁº…",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"∞◊…´≥§≈€",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	" •ª¡Ó",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"ª∆“© ¶",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"[32m”ÒÛÔ[2;37;0m",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"’≈»˝∑·",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"[32m’ÊŒ‰Ω£[2;37;0m",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"¥Ôƒ¶¿œ◊Ê",
		"quest_type":	"…±",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"Ω∏’’÷",
		"quest_type":	"—∞",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
