inherit SKILL;

mapping *quest = ({
	([	"quest":	"Ϯ��",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"�շ�ɮ",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"��ɴȹ",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[33m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[33m������[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[33mŮ����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[33m���[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"С԰��",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"�÷�",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"���³�",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"���¼�",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"԰����",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"���",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"��ȹ",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"[35m������[2;37;0m[33m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"ͭ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"����ʵ",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"��",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"�ÿ�",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"�ſ�",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	0,
	]),

	([	"quest":	"��å",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"������",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"[1;37mӭ��[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"[35m������[2;37;0m[33m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"ͭ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"ҹ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"�ƽ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

	([	"quest":	"԰��",
		"quest_type":	"ɱ",
		"exp_bonus":	20,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
