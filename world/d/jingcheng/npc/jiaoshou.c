// Created by ysg
// data: 1997.10.17
               
#include <ansi.h> 
inherit NPC; 

void create()
{
	set_name("����", ({ "jiao shou" , "jiao" , "shou" }));
	set("title",YEL"���Ӽ����"NOR);
	set("long",
	"���Ӽ�Ľ��ڣ�����ͨ��ĥ����ʫ�ʸ踳����һ�����о�,�ÿ������Ӽ��ѧ���ǽ����Ρ�\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "peaceful");
	set("str", 15);
	set("int", 15);
	set("con", 15);
	set("dex", 15);
	set("combat_exp", 4000);
	set_skill("dodge", 10);
	set_skill("unarmed", 20);
	set_temp("apply/defense", 10);
	setup();
        set("chat_chance", 10);
        set("chat_msg", ({
        	"���ڿ�����������£��İ��кõ�����������԰���\n",	
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
//	command("say "+RANK_D->query_respect(me)+"�������Ȥ���������������\n");
