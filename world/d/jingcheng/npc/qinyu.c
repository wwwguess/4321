// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("����", ({ "qin yu", "qin" ,"yu" }));
	set("title",GRN"�������ܹ�"NOR);
	set("long",
	"�����ǽ����������ˣ�����С�ڽ�������������ؽ��������Σ����ܹܵ�\n"
	"��Ȩ��������\n");
	set("gender", "����");
	set("age", 42);
	set("attitude", "heroism");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 80000);
	set_skill("dodge",70);
	set_skill("unarmed", 60);
	set_skill("sword", 80);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"��������˵�����������̫ƽ��������ƽ����Ҫ�ú����ξ�������\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
	add_action("do_answer", "answer");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
		if( me->query_temp("baishi") )
			me->delete_temp("baishi");
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	if( random(10) >5 
	&& (me->query("title") == "ƽ��" || me->query("title") == "��Ů" ))
	{
		command("say "+RANK_D->query_respect(me)+"��������Ϊ��Ч����ʱ��\n"
		+RANK_D->query_respect(me)+"�β������ҽ�������\n");
		command("smile");
	}
}

int do_answer(string arg)
{
	object ob;
	
	ob = this_player();

	if( !arg ) return notify_fail("��Ҫ�ش�ʲô��\n");
	if( strsrch(arg,"��ʦ") != -1 ){
		ob->set_temp("baishi", 1);
		message_vision("$N���˵�˵���ҽ�������λ�Ժգ����ո�ǿ���ڽ�����Ҳ�Ǵ���\n"
		"����,"+ob->query("name")+"�������ҶԵط���.\n", this_object());
		return 1;
	} else {
		message_vision("$N�ܲ����˵Ŀ���$n�������˵�������ɲ�������������֮�˽�ȥ��\n"
		, this_object(), ob);
		ob->move("/d/jingcheng/xw7");
		return 1;
	}
}
