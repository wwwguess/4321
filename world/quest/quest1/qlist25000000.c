inherit SKILL;

mapping *quest = ({
	([	"quest":	"‘ÏŒÔ÷˜",
		"quest_type":	"…±",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"[1;37mΩ”π[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	160,
		"shen_type":	1,
	]),

	([	"quest":	"æ©≥«µÿÕº",
		"quest_type":	"—∞",
		"exp_bonus":	160,
		"shen_type":	1,
	]),

	([	"quest":	"∑ÔªÀ",
		"quest_type":	"…±",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"»À¡È°∏«¯⁄§°π",
		"quest_type":	"…±",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"[32m–°¡ÿ[2;37;0m",
		"quest_type":	"…±",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
