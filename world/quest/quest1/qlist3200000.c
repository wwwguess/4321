inherit SKILL;

mapping *quest = ({
	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"[34m��Ҷ��[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"�������",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	-1,
	]),

	([	"quest":	"[1;33mŭ������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	-1,
	]),

	([	"quest":	"[32m��������[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	-1,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"��ɫ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"�ſ���",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"��ɫ����",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"������",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"���ݶ�",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"¹ƤСѥ",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"[1;32m����[1;35m���δ�[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"���񱦽�",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"����",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"ѩ���",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"���µ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"�ֲ�����",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"�ݼ���",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"�ֲ������",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"����Ⱥ",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"ҹ��",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"˿��",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"һ������Ʊ",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	0,
	]),

	([	"quest":	"[33m���[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"[32m���ҵ�[2;37;0m",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"ѩ��Ƥ",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"�ⲻƽ",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"[35m�¹�Ӣ[2;37;0m",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	1,
	]),

	([	"quest":	"�½���",
		"quest_type":	"ɱ",
		"exp_bonus":	130,
		"shen_type":	-1,
	]),

	([	"quest":	"˪�µ�",
		"quest_type":	"Ѱ",
		"exp_bonus":	130,
		"shen_type":	-1,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
