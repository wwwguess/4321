inherit SKILL;

mapping *quest = ({
	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"[1;37m��ӹ[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	160,
		"shen_type":	1,
	]),

	([	"quest":	"���ǵ�ͼ",
		"quest_type":	"Ѱ",
		"exp_bonus":	160,
		"shen_type":	1,
	]),

	([	"quest":	"���",
		"quest_type":	"ɱ",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"���顸��ڤ��",
		"quest_type":	"ɱ",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

	([	"quest":	"[32mС��[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
