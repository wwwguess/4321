inherit SKILL;

mapping *quest = ({
	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	150,
		"shen_type":	0,
	]),

	([	"quest":	"�Ż�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	150,
		"shen_type":	0,
	]),

	([	"quest":	"���",
		"quest_type":	"ɱ",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

	([	"quest":	"[1;32m������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

	([	"quest":	"��ɫ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	150,
		"shen_type":	1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
