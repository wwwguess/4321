inherit SKILL;

mapping *quest = ({
	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"�廨Ь",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"ɵ��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"�ɻ��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"�ϻ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"���",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"[1;35m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"��ū",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"������ʦ",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"[35m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"�Ҳ��������",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"ɨ��ɮ",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"С��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"С��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"���ϰ�",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"���ϴ�",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"���޻�",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"ˮ���",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"Բ��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"[35m������[2;37;0m[33m����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"ͭ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"�ﳤ��",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	1,
	]),

	([	"quest":	"С����",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	0,
	]),

	([	"quest":	"���¼Ҷ�",
		"quest_type":	"ɱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

	([	"quest":	"���Ǵ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	30,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
