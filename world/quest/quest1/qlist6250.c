inherit SKILL;

mapping *quest = ({
	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"�ɵ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"��ʬ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"���۷�",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"���¼Ҷ�",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"���Ǵ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[31m��ʦʦ[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[30m���[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[33m�����[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"�������",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"���ƹ�",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"��ͨ",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"�Ʋ�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"[35m���Ķ�[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"�ر�",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"���¼Ҷ�",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����������",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����Ů",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"��ëȹ",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"�η�����",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"�಼ɮ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"��ɺ",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"ϧ��",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"������ɮ",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"�಼����",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"ɮ��",
		"quest_type":	"Ѱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����ͤ",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"����ɮ",
		"quest_type":	"ɱ",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
