//NPC:/d/suzhou/npc/jiang.c
//by dwolf
//97.11.4
//changed by tlang
//97.12.4

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"��С��"NOR, ({"jiang xiaochuan", "jiang" }));
	set("title", HIW"������ͷ"NOR);
	set("long",
	"�����ھֵĸ�����ͷ����������ͷ���̫�������ھֻ����������ƹܡ�\n"
	);

	set("gender", "����");
	set("attitude", "heroism");
	
	set("age", 25);
	set("shen_type", 10);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 800);
	set("max_gin", 300);
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("combat_exp", 200000);
	set("score", 10000);
	set("apply/attack",  40);
	set("apply/defense", 40);

	set_skill("force", 80);
	set_skill("blade", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("cibei-dao", 80);
	set_skill("hunyuan-yiqi", 80);
        set_skill("strike", 80);
	set_skill("sanhua-zhang", 80);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");


	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("gold", 1);
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
	add_action("do_accept", "accept");
	add_action("do_report", "report");

/*	if(!( ob = find_living("longwu")) )
	ob = load_object("/d/suzhou/npc/longwu");
	message_vision(HIY "$N�����������������ͷ�ã�\n" NOR, this_object());*/
}

void greeting(object me)
{
	if( !me || environment(me) != environment() || !me->query("mark/����") ) return;
       	command("say ��Ϊ���ҵ�һ�ֺò��£�������С�㵽���ݣ����ͬ��(accept)��\n");
}

int do_accept()
{
	object me, ob, obj;
	me=this_player();
	
	if( !me->query("mark/����") ) return 0;
	else {
	if( me->query("mark/��ʼ") )
		return notify_fail("����ô�����������£�\n");
	command("haha");
	command("say ����ǽ��Ϻ���������ǧ��.����ȵ��ſڴ�����λ�����֡�\n");
	ob=new("/d/suzhou/npc/gsnan");
	/*obj=new("/d/suzhou/npc/fighter");*/
	ob->move("/d/suzhou/bjdting");
	/*obj->move("/d/suzhou/bjdting");
	me->set("mark/��ʼ", 1);*/
		return 1;
	}
	return 1;	
}

int do_report()
{
	object me,ob;
	me=this_player();

	if( !me->query("mark/�ɹ�") )
		return notify_fail("�㻹û��������񣬱���ʲô��������\n");
	command("haha");
	command("say �����ġ����Ǹ����ٺ��\n");
	ob=new("obj/money/gold.c");
	ob->move(me);
	me->add("combat_exp", 1000);
	me->delete("mark/�ɹ�");
		return 1;
}	
		 