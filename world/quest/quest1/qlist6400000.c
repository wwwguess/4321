inherit SKILL;

mapping *quest = ({
	([	"quest":	"���߹�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"�л���",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"[32m������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"���й�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"���޹�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"�ɽ�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"�ɶ�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"���޼�",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"��ɫ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"ʥ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"��ҩʦ",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"[32m����[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"[32m���佣[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"��Ħ����",
		"quest_type":	"ɱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

	([	"quest":	"�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	140,
		"shen_type":	1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
