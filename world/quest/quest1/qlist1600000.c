inherit SKILL;

mapping *quest = ({
	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"���Ϊ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"��ֹƼ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;35m��˪Ѫ����[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;35mħ������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;33m�������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[32m������ӰЬ[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"���о�",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"��ӥ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"�䵶",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"ΤһЦ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"�����ʦ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"���Ѵ�ʦ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33m�ظ�[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[33m���鵶[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"³�н�",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"������ʦ",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"�ɲ���",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"��ɫ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	1,
	]),

	([	"quest":	"���",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"[1;36m��������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	120,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	120,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
