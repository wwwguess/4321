// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 
inherit F_VENDOR;
void create()
{
	set_name("������", ({ "dong pusheng" , "dong" , "pusheng" }));
	set("title","�����ƹ�");
	set("nickname", HIW"һë����"NOR); 
	set("long",
	"�����������ǳ�����������壬������������һ�������ҼҴ�ҵ���ڼ��϶�����Ϊ�˾�����\n"
	"���Ƿ����󡣶�������š�һë���Ρ����������ģ�����������ȴ���м����֡�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("per", 15);
	set("force", 50);
	set("max_force", 50);
	set("force_factor", 2);
	set("combat_exp", random(100000));
	set_skill("dodge", 30);
	set_skill("unarmed", 40);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"������������к�����������˾��ܷ��ģ�����۸񹫵���ͯ�����ۡ���\n",	
        }) );
	carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
	object me;
    	::init();
//       add_action("do_vendor_list","list");
//       add_action("do_buy","buy");
//       add_action("do_sell","sell");
//       add_action("do_value","value");
    	if( interactive(me = this_player()) && !is_fighting() ) 
	{
        	remove_call_out("greeting");
        	call_out("greeting", 3, me);
        	return;
        }
}
void greeting(object me)
{
	command("say "+RANK_D->query_respect(me)+"���תת��������ʲô����ġ�\n");
	command("whisper "+(string)me->query("id")+" ���������Ʒ��"+RANK_D->query_respect(me)
	+"�����ʲô���������Ķ��������Խ������ꡣ���ֺ��ˣ����ܷ��ġ�\n");
}
