// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("����", ({ "dai zhong", "dai" ,"zhong" }));
	set("title",GRN"��վվ��"NOR);
	set("nickname", RED"����̫��"NOR);
	set("long",
	"����̫����˵�ǽ������ܵ������ˡ�����������һǧ��ҹ�а˰١�������\n"
	"����ʲô�����£������ǵ�һ��֪���ġ�\n");
	set("gender", "����");
	set("age", 42);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 20);
	set("combat_exp", 50000);
	set_skill("dodge",70);
	set_skill("unarmed", 50);
	set_temp("apply/defense", 40);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"���ڿ�����˵�������ȱϾ���Ѫ�����ģ���ʱ��Ҳ�û����������԰ɡ���\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	message_vision("���ڶ���$N΢΢һЦ��\n",me);
}
