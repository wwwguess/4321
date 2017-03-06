// necromancy.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_skill_usage(string usage) { return usage=="spells"; }

int valid_learn(object me) { return 1; }

int cast_spell(object me, string arg)
{
	string spl, trg;
	object target;

	if( sscanf(arg, "%s %s", spl, trg)==2 )	{
		if( !objectp(target = present(trg, environment(me))) )
			return notify_fail("��Ҫ��˭ʩչ���������\n");
	} else {
		spl = arg;
		target = 0;
	}
	if( file_size(__DIR__"necromancy/" + spl + ".c")<=0 )
		return notify_fail("éɽ����֮��û�����ַ�����\n");

	notify_fail("���ַ�������ֱ��ʩչ��\n");
	return (int)call_other(__DIR__"necromancy/" + spl, "cast_spell", me, target);
}

int scratch_spell(object me, object sheet, string arg)
{
	string spl, trg;
	object target;

	if( !arg || sscanf(arg, "%s %s", spl, trg)!=2 ) {
		spl = arg;
		trg = 0;
	}

	if( file_size(__DIR__"necromancy/" + spl + ".c")<=0 )
		return notify_fail("éɽ����֮��û�����ַ��䡣\n");

	notify_fail("���ַ�����û�л��ɷ���ķ�����\n");

	return (int)call_other(__DIR__"necromancy/" + spl, "scratch_spell", me, sheet, trg);
}

int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"
			+ bug->name() + "�ɣ�\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ����޷����С�\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("���Ŀ�����������⣬��ʼ��ϰéɽ�����еķ���....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("��������˼һ�ң������һֻ��Ŀ������" + bug->name() + "��\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("��Ļ�������" + bug->name() + "��ס������������ɣ�\n");
	}	
	else return 1;
}
