// jiang ����ʤ

#include <ansi.h>

inherit NPC;

void create()
{
	seteuid(getuid());

	set_name("����ʤ", ({ "jiang baisheng", "jiang", "baisheng" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "������������κ��˫֮����֮�ױ��ӳ���\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_kee", 400);
	set("eff_kee", 400);
	set("kee", 400);
	set("eff_gin", 200);
	set("gin", 200);
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 30);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 50000);

	set_skill("force", 80); 
	set_skill("unarmed", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("fight_times", 0);	

	setup();
        
}

int accept_fight(object ob)
{
	object me  = this_object();
		
	me->set("eff_kee", me->query("max_kee"));
	me->set("kee",     me->query("max_kee"));
	me->set("gin",   me->query("eff_gin"));
	me->set("force",  me->query("max_force"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	if ( me->query("fight_times") >= 10 )
		return notify_fail("����ʤ�Ѿ�ȫ��������ſ�ڵ��ϴ�ڵش��Ŵ�����\n");	

	me->add("fight_times", 1);

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_kee, his_max_kee;

	if ( !present(ob, environment()) ) return 1; 

	my_max_kee  = me->query("max_kee");
	his_max_kee = ob->query("max_kee");

	if( me->is_fighting() ) 
	{
		if (( (int)me->query("kee")*100 / my_max_kee) <= 80 ) 
		{
			say(GRN "\n����ʤ˵���� κ���������£����ò����� �����˼������Ųߣ����޲��ˣ����޲�ʤ��\n" NOR);
			say(GRN "\n����ʤ˵���� κ����һ�仰�����°��´���������ֱǰ�� ����ѩ�����ﴳ����ɽ�𺣾͸�ȥ��\n" NOR);
			message_vision(HIY "\n����ʤ˵�꣬ȫ��֪������ð������һ����������������������ȭ��Ҳ���ͺö౶��\n" NOR, ob);

			me->set("eff_kee", me->query("max_kee"));
			me->set("kee",     me->query("max_kee"));
			me->set("gin",   me->query("eff_gin"));
			me->set("force",  me->query("max_force"));
		}
		else if (( (int)ob->query("kee")*100 / his_max_kee) < 50 ) 
		{
			say(GRN "\n����ʤ˵���� ������С�Ӹ��һ�����һ����أ���ȥ����ʮ�������ɣ�\n");
			return 1;
		}

		if ( present(ob, environment()) ) call_out("checking", 1, me, ob);
	}

	return 1;  
}
