// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("�����", ({ "suan xiucai" , "suan" , "xiucai" }));
	set("title",CYN"���Ӽ๱��"NOR);
	set("long",
	"���Ӽ����ţ�ר����ʫ��������ӹ����֮�¡�\n");
	set("gender", "����");
	set("age", 22);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 2000);
	set_skill("dodge", 10);
	set_skill("unarmed", 20);
	set_temp("apply/defense", 5);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"�����ҡͷ���Ե�����������ǰ�����޹⣬���ǵ�����˪����\n",	
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
//void greeting(object me)
//{
//	command("say "+RANK_D->query_respect(me)+"�㿴����ʫд�ÿɺã�\n");
