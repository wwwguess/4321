// rankd.c

#include <ansi.h>

string query_rank(object ob)
{
	if( ob->is_ghost() ) return HIB "�� ��  �� ��" NOR;
	switch(ob->query("gender")) {
	case "Ů��":
		switch(wizhood(ob)) {
			case "(admin)":			return HIW "�� Ů  �� ��" NOR;
			case "(arch)":			return HIY "�� ��ħŮ ��" NOR;
			case "(wizard)":		return HIG "�� ħ  Ů ��" NOR;
			case "(apprentice)":	return HIC "�� СħŮ ��" NOR;
			case "(immortal)":		return HIC "�� ��  Ů ��" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "�� ɱ��ħ ��";
				if( (int)ob->query("thief") > 10 ) return "�� ��  �� ��";
				switch(ob->query("class")) {
					case "bonze":		return "�� ��  �� ��";
					case "taoist":		return "�� Ů  �� ��";
					case "bandit":		return "�� Ů���� ��";
					case "dancer":		return "�� ��  �� ��";
					case "scholar":		return "�� ��  Ů ��";
					case "officer":		return "�� Ů  �� ��";
					case "fighter":		return "�� Ů���� ��";
					case "swordsman":	return "�� Ů��ʿ ��";
					case "alchemist":	return "�� ��  ʿ ��";
					case "shaman":		return "�� ��  ҽ ��";
					case "beggar":		return "�� �л��� ��";
					default:			return "�� ƽ  �� ��";
			}
		}
	default:
		switch(wizhood(ob)) {
			case "(admin)":			return HIW "�� ��  �� ��" NOR;
			case "(arch)":			return HIY "�� ����ʦ ��" NOR;
			case "(wizard)":		return HIG "�� ��  ʦ ��" NOR;
			case "(apprentice)":	return HIC "����ʦѧͽ��" NOR;
			case "(immortal)":		return HIC "�� ��  �� ��" NOR;
			default:
				if( ((int)ob->query("PKS") > 100) &&
					((int)ob->query("PKS") > (int)ob->query("MKS")) )
					return "�� ɱ��ħ ��";
				if( (int)ob->query("thief") > 10 ) return "�� ��  �� ��";
				switch(ob->query("class")) {
					case "bonze":		return "�� ɮ  �� ��";
					case "taoist":		return "�� ��  ʿ ��";
					case "bandit":		return "�� ��  �� ��";
					case "scholar":		return "�� ��  �� ��";
					case "officer":		return "�� ��  �� ��";
					case "fighter":		return "�� ��  �� ��";
					case "swordsman":	return "�� ��  ʿ ��";
					case "alchemist":	return "�� ��  ʿ ��";
					case "shaman":		return "�� ��  ҽ ��";
					case "beggar":		return "�� �л��� ��";
					default:			return "�� ƽ  �� ��";
			}
		}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ̫";
				else return "ʦ̫";
				break;
			case "taoist":
				if( age < 18 ) return "С�ɹ�";
				else return "�ɹ�";
				break;
			default:
				if( age < 18 ) return "С����";
				else if( age < 50 ) return "����";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 18 ) return "Сʦ��";
				else return "��ʦ";
				break;
			case "taoist":
				if( age < 18 ) return "����";
				else return "����";
				break;
			case "fighter":
			case "swordsman":
				if( age < 18 ) return "С�ϵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ǰ��";
				break;
			default:
				if( age < 20 ) return "С�ֵ�";
				else if( age < 50 ) return "׳ʿ";
				else return "��ү��";
				break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				return "����";
				break;
			case "taoist":
				return "��Ů";
				break;
			default:
				if( age < 30 ) return "С����";
				else return "����̫��";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "��ͺ¿";
				else return "��ͺ¿";
				break;
			case "taoist":
				return "��ţ����";
				break;
			default:
				if( age < 20 ) return "С���˵�";
				if( age < 50 ) return "����";
				else return "��ƥ��";
				break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "СŮ��";
				else return "���";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶɮ";
				else return "����";
				break;
			case "taoist":
				return "ƶ��";
				break;
			default:
				if( age < 50 ) return "����";
				else return "��ͷ��";
				break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	age = ob->query("age");
	switch(ob->query("gender")) {
		case "Ů��":
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "ƶ��";
				else return "����";
				break;
			default:
				if( age < 30 ) return "������";
				else return "����";
				break;
			}
		case "����":
		default:
			switch(ob->query("class")) {
			case "bonze":
				if( age < 50 ) return "�������";
				else return "�Ϻ�����";
				break;
			case "taoist":
				return "��ɽ��";
				break;
			default:
				if( age < 50 ) return "��ү��";
				else return "����";
				break;
			}
	}
}
