//NPC:/d/suzhou/npc/fighter.c 
//by dwolf
//97.11.4
//changed by tlang
         
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"������"NOR, ({ "tangzi shou", "shou", "fighter" }));
	set("age", 22);
	set("gender", "����");
	set("long", "�����ھֵĵ��ӣ��书��Ȼ��̫�ߣ����Ը�һ�����˴´����ࡣ\n");
	set("attitude", "heroism");

	set("str", 28);
	set("dex", 26);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 30);
	set_temp("apply/armor", 50);


        set("chat_chance_combat", 2);
	set("chat_msg_combat", ({
		"�����ھ�����Զ�����׿����\n",
		"С�ֵܣ�������������Ǳ��ڵģ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{   
        object ob; 
        ob = this_player();
	add_action("do_leave", "leave");

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, ob);    
}

void greeting(object me)
{
	object obj;
	obj = this_object();
	
	if( !me || environment(me) != environment() || !me->query("mark/����") )return;
       	obj->set_leader(me);
	me->set("mark/��ʼ", 1);
	command("say ����һ·ͬ�У����ָ�̡�\n");
}

int do_leave()
{
	object ob,me;
	me=this_player();
	ob=this_object();

	if( !me->query("mark/�ɹ�") )
		return notify_fail("����û��ɣ�����ô���뿪�㣿\n");
	ob->set_leader(0);
	destruct(ob);
	command("say ��������ˣ��Ҹ��뿪���ˡ�\n");
		return 1;
}	



